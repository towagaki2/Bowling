#include "stdafx.h"
#include "B_pinManager.h"


B_pinManager::B_pinManager(B_ball* b_ball)
{
	CVector3 m_pos = CVector3::Zero();
	for (int i = 0; i < 10; i++) {
		m_number[i] = new B_pin;
		m_pos = hoge[i]*-1.0f;
		m_pos.x *= 10.0f;
		m_pos.y *= 10.0f;
		m_pos.z *= 10.0f;
		m_number[i]->Setpin(m_pos);
		m_number[i]->Setball(b_ball);
		m_number[i]->Update();
		m_number[i]->Draw();
	}	
	m_ball = b_ball;
}


B_pinManager::~B_pinManager()
{
}
void B_pinManager::Update()
{
	for (int i = 0; i < 10; i++) {

		m_number[i]->Update();
	}

	if (m_ball->GetThorw() == 2)
	{
		for (int i = 0; i < 10; i++) {

			if (m_number[i]->GetFly() ==1)
			{
				score++;
			}
		}
		
	}

	
}
void B_pinManager::Draw()
{

	for (int i = 0; i < 10; i++) {

		m_number[i]->Draw();
	}
}
