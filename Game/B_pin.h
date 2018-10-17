#pragma once
#include "character/CharacterController.h"
#include "B_ball.h"
class B_ball;

class B_pin
{
public:
	B_pin();
	~B_pin();
	void Update();
	void Draw();

	void Setball(B_ball* b_ball)
	{
		m_ball = b_ball;
	}
	void Setpin(CVector3 b_pin)
	{
		m_position = b_pin;
		m_position.z -= 500.0f;
		m_pos = m_position;
	}
 
	int fly = 0;										//���������t���O�B

private:
	void Move();		//�ړ������B
	void Turn();		//��]�����@

	B_ball* m_ball= nullptr;							//�{�[�����B

	CVector3 m_pos = CVector3::Zero();
	SkinModel m_model;									//�X�L�����f���B
	CVector3 m_position = CVector3::Zero();				//�s�����W�B
	
	CVector3 m_scale = CVector3::One();					//�g�嗦�B
	CVector3 m_moveSpeed = CVector3::Zero();			//�ړ����x�B
	CQuaternion m_rotation = CQuaternion::Identity();	//��]�B								
	CharacterController m_charaCon;						//�L�����N�^�[�R���g���[���[��ǉ��B
};

