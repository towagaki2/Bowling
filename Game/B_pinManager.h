#pragma once
#include "B_pin.h"
#include"B_ball.h"
class B_pin;



class B_pinManager
{
public:
	B_pinManager(B_ball* b_ball);
	~B_pinManager();	
	void Setball(B_ball* b_ball)
	{
		m_ball = b_ball;
	}
	int GetScore()
	{
		return score;
	}
	void SetScore(int Main)
	{
		score = Main;
	}
	void SetNumber(int Nom)
	{
		m_number[Nom]->SetFly(0);
	}

	void Update();
	
	void Draw();
private:	
	int score=0;
	B_pin *m_pin = nullptr;							//�s�����B
	B_ball* m_ball;									//�{�[�����B
	B_pin* m_number[10];							//�s���̖{���B

	CVector3 hoge[10] = { 
		{0.0f,0.0f,0.0f}
	,{5.0f,0.0f,10.0f},
	{-5.0f,0.0f,10.0f},
	{10.0f,0.f,20.0f},
	{0.0f,0.0f,20.0f},
	{-10.0f,0.0f,20.0f},
	{15.0f,0.0f,30.0f},
	{5.0f,0.0f,30.0f},
	{-5.0f,0.0f,30.0f},
	{-15.0f,0.0f,30.0f} };

};

