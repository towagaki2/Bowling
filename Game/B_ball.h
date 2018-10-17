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
	void Power();		//パワー処理。
	void Move();		//移動処理。
	void Turn();		//回転処理。　

	int Thorw = 0;

	Player* m_player = nullptr;							//プレイヤー情報。

	SkinModel m_model;									//スキンモデル。
	Animation m_animation;								//アニメーション。
	AnimationClip m_animationClips[2];					//アニメーションクリップ。
	CVector3 m_position = CVector3::Zero();				//座標。
	CVector3 m_scale = CVector3::One();					//拡大率。
	CVector3 m_moveSpeed = CVector3::Zero();			//移動速度。
	CQuaternion m_rotation = CQuaternion::Identity();	//回転。								
	CharacterController m_charaCon;						//キャラクターコントローラーを追加。
};

