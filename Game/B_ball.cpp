#include "stdafx.h"
#include "B_ball.h"
#include "Player.h"


B_ball::B_ball()
{
	//cmo�t�@�C���̓ǂݍ��݁B
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

	static int ballF = 0;		//�{�[���i�K�t���O�B
	static int power = 0;		//�{�[���𓊂��鋭���B

	m_moveSpeed.x = m_player->GetPosition().x;	
	if (GetAsyncKeyState('K') && ballF == 0&&Thorw<2) {
		//K�L�[�������ꂽ�B
		ballF = 1;
	}
	if (ballF == 1 && power <= 100) {
		//power��100�ȉ��̊�power���v���X��������B
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
	//�p���[
	Power();
	//�ړ������B
	Move();
	//��]����
	Turn();
	m_moveSpeed.x += m_player->GetPosition().x;

	//���[���h�s��̍X�V�B
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