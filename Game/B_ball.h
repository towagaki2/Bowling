#pragma once
#include "character/CharacterController.h"
#include "Player.h"
class Player;

class B_ball
{
public:
	B_ball();
	~B_ball();
	void Update();
	void Draw();

	CVector3 GetPosition()
	{
		return m_position;
	}
	CVector3 GetMoveSpeed()
	{
		return m_moveSpeed;
	}
	int GetThorw()
	{
		return Thorw;
	}
	void SetThorw(int Main)
	{
		Thorw = Main;
	}
	void Setplayer(Player* player)
	{
		m_player = player;
	}

	
private:
	void Power();		//�p���[�����B
	void Move();		//�ړ������B
	void Turn();		//��]�����B�@

	int Thorw = 0;

	Player* m_player = nullptr;							//�v���C���[���B

	SkinModel m_model;									//�X�L�����f���B
	Animation m_animation;								//�A�j���[�V�����B
	AnimationClip m_animationClips[2];					//�A�j���[�V�����N���b�v�B
	CVector3 m_position = CVector3::Zero();				//���W�B
	CVector3 m_scale = CVector3::One();					//�g�嗦�B
	CVector3 m_moveSpeed = CVector3::Zero();			//�ړ����x�B
	CQuaternion m_rotation = CQuaternion::Identity();	//��]�B								
	CharacterController m_charaCon;						//�L�����N�^�[�R���g���[���[��ǉ��B
};

