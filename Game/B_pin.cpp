#include "stdafx.h"
#include "B_pin.h"
#include "B_ball.h"


B_pin::B_pin()
{
	//cmoファイルの読み込み。
	m_model.Init(L"Assets/modelData/unityChan.cmo");

	m_position.z = -500.0f;
	m_position.y = 0.0f;
	m_charaCon.Init(10.0f, 50.0f, m_position);
}


B_pin::~B_pin()
{

}

void B_pin::Move()
{
	CVector3 posball = CVector3::Zero();				//ボールとピンとの距離。
	posball = m_ball->GetPosition() - m_pos;			//ピンとボールの距離の計算。

	if (posball.Length() < 30.0f)
	{
		m_moveSpeed.z -= 1000.0f;
		fly += 1;
	}
	if (m_pos.z <= -20000.0f&&m_ball->Thorw==2)
	{
		m_pos = m_position;
		m_moveSpeed.z = 0.0f;
	}
	m_pos += m_moveSpeed;
}

void B_pin::Turn()
{

}

void B_pin::Update()
{
	
	//移動処理。
	Move();
	//回転処理
	Turn();

	

	//ワールド行列の更新。
	m_model.UpdateWorldMatrix(m_pos, m_rotation, m_scale);

}

void B_pin::Draw()
{
	m_model.Draw(
		g_camera3D.GetViewMatrix(),
		g_camera3D.GetProjectionMatrix()
	);
}