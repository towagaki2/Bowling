#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	

	//cmoファイルの読み込み。
	m_model.Init(L"Assets/modelData/unityChan.cmo");

	PowerGauge.Init(L"Assets/modelData/teku.cmo");

	//tkaファイルの読み込み。
	m_animationClips[0].Load(L"Assets/animData/walk.tka");
	m_animationClips[0].SetLoopFlag(true);

	m_animationClips[1].Load(L"Assets/animData/run.tka");
	m_animationClips[1].SetLoopFlag(true);
	//アニメーションの初期化。
	m_animation.Init(
		m_model,			//アニメーションを流すスキンモデル。
							//これでアニメーションとスキンモデルが関連付けされる。
		m_animationClips,	//アニメーションクリップの配列。
		2					//アニメーションクリップの数。
	);

	m_position.y = 0.0f;
	m_charaCon.Init(10.0f, 50.0f, m_position);

}


Player::~Player()
{
}

void Player::Move()
{
	//プレイヤーの移動処理。
	if (GetAsyncKeyState('D')) {
		//Dキーが押された。
		m_moveSpeed.x -= 5.0f;
	}
	if (GetAsyncKeyState('A')) {
		//Aキーが押された。
		m_moveSpeed.x += 5.0f;
	}
	//if (GetAsyncKeyState('W')) {
	//	//Wキーが押された。
	//	m_moveSpeed.z -= 5.0f;
	//}
	//if (GetAsyncKeyState('S')) {
	//	//Sキーが押された。
	//	m_moveSpeed.z += 5.0f;
	//}
	m_position = m_moveSpeed;
}

void Player::Turn()
{

}

void Player::Update()
{
	//移動処理。
	Move();
	//回転処理
	Turn();

	//ワールド行列の更新。
	PowerGauge.UpdateWorldMatrix({150.0f,5.0f,0.0f}, CQuaternion::Identity(), { 0.2f,0.01f,0.1f });
	m_model.UpdateWorldMatrix(m_position, m_rotation, m_scale);

}

void Player::Draw()
{
	m_model.Draw(
		g_camera3D.GetViewMatrix(), 
		g_camera3D.GetProjectionMatrix()
	);	
	PowerGauge.Draw(
		g_camera3D.GetViewMatrix(),
		g_camera3D.GetProjectionMatrix()
	);
}