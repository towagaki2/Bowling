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
 
	int fly = 0;										//当たったフラグ。

private:
	void Move();		//移動処理。
	void Turn();		//回転処理　

	B_ball* m_ball= nullptr;							//ボール情報。

	CVector3 m_pos = CVector3::Zero();
	SkinModel m_model;									//スキンモデル。
	CVector3 m_position = CVector3::Zero();				//ピン座標。
	
	CVector3 m_scale = CVector3::One();					//拡大率。
	CVector3 m_moveSpeed = CVector3::Zero();			//移動速度。
	CQuaternion m_rotation = CQuaternion::Identity();	//回転。								
	CharacterController m_charaCon;						//キャラクターコントローラーを追加。
};

