#include "stdafx.h"
#include "B_ball.h"
#include "Player.h"


B_ball::B_ball()
{
	//cmoファイルの読み込み。
	m_model.Init(L"Assets/modelData/unityChan.cmo");

	m_position.y = 0.0f;
	m_charaCon.Init(10.0f, 50.0f, m_position);

}

B_ball::~B_ball()
{
}

void B_ball::Power()
{
	
}

void B_ball::Move()
{

	static int ballF = 0;		//ボール段階フラグ。
	static int power = 0;		//ボールを投げる強さ。

	m_moveSpeed.x = m_player->GetPosition().x;	
	if (GetAsyncKeyState('K') && ballF == 0&&Thorw<2) {
		//Kキーが押された。
		ballF = 1;
	}
	if (ballF == 1 && power <= 100) {
		//powerが100以下の間powerをプラスし続ける。
		power++;
	}
	if (power > 100)
	{
		power = 5;
	}
	if (ballF == 1 && GetAsyncKeyState('J')) {
		ballF = 2;
	}
	if (ballF == 2)
	{
		m_moveSpeed.z -= power;
		//m_rotation.x -= 1.0f;
	}
	if (m_moveSpeed.z <= -1000.0f)
	{
		ballF = 0;
		Thorw+=1;
	}
	if (ballF == 0)
	{
		m_position.z = 0;
		m_moveSpeed.z = 0;
		power = 0;
		//m_rotation.x = 0;
		
	}
	m_position = m_moveSpeed;
}

void B_ball::Turn()
{
}

void B_ball::Update()
{
	//パワー
	Power();
	//移動処理。
	Move();
	//回転処理
	Turn();
	m_moveSpeed.x += m_player->GetPosition().x;

	//ワールド行列の更新。
	m_model.UpdateWorldMatrix(CVector3::Zero(), CQuaternion::Identity(), CVector3::One());
	m_model.UpdateWorldMatrix(m_position, m_rotation, m_scale);
}

void B_ball::Draw()
{
	m_model.Draw(
		g_camera3D.GetViewMatrix(),
		g_camera3D.GetProjectionMatrix()
	);
}