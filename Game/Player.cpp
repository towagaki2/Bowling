#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	

	//cmo�t�@�C���̓ǂݍ��݁B
	m_model.Init(L"Assets/modelData/unityChan.cmo");

	PowerGauge.Init(L"Assets/modelData/teku.cmo");

	//tka�t�@�C���̓ǂݍ��݁B
	m_animationClips[0].Load(L"Assets/animData/walk.tka");
	m_animationClips[0].SetLoopFlag(true);

	m_animationClips[1].Load(L"Assets/animData/run.tka");
	m_animationClips[1].SetLoopFlag(true);
	//�A�j���[�V�����̏������B
	m_animation.Init(
		m_model,			//�A�j���[�V�����𗬂��X�L�����f���B
							//����ŃA�j���[�V�����ƃX�L�����f�����֘A�t�������B
		m_animationClips,	//�A�j���[�V�����N���b�v�̔z��B
		2					//�A�j���[�V�����N���b�v�̐��B
	);

	m_position.y = 0.0f;
	m_charaCon.Init(10.0f, 50.0f, m_position);

}


Player::~Player()
{
}

void Player::Move()
{
	//�v���C���[�̈ړ������B
	if (GetAsyncKeyState('D')) {
		//D�L�[�������ꂽ�B
		m_moveSpeed.x -= 5.0f;
	}
	if (GetAsyncKeyState('A')) {
		//A�L�[�������ꂽ�B
		m_moveSpeed.x += 5.0f;
	}
	//if (GetAsyncKeyState('W')) {
	//	//W�L�[�������ꂽ�B
	//	m_moveSpeed.z -= 5.0f;
	//}
	//if (GetAsyncKeyState('S')) {
	//	//S�L�[�������ꂽ�B
	//	m_moveSpeed.z += 5.0f;
	//}
	m_position = m_moveSpeed;
}

void Player::Turn()
{

}

void Player::Update()
{
	//�ړ������B
	Move();
	//��]����
	Turn();

	//���[���h�s��̍X�V�B
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