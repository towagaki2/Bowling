#include "stdafx.h"
#include "system/system.h"
#include "Player.h"
#include "B_ball.h"
#include "B_pinManager.h"
#include "level/Level.h"
#include "BackGround.h"


///////////////////////////////////////////////////////////////////
// �E�B���h�E�v���O�����̃��C���֐��B
///////////////////////////////////////////////////////////////////
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	//�Q�[���̏������B
	InitGame(hInstance, hPrevInstance, lpCmdLine, nCmdShow, "Game");

	//�J�������������B
	g_camera3D.SetPosition({ 0.0f, 300.0f, 300.0f });
	g_camera3D.SetTarget({ 0.0f, 200.0f, 0.0f });
	g_camera3D.SetFar(10000.0f);
	g_camera2D.SetPosition({ 0.0f, 10.0f, 1.0f });
	g_camera2D.SetTarget({ 0.0f, 0.0f, 0.0f });
	g_camera2D.SetFar(10000.0f);
	g_camera2D.Update();
	

	//�v���C���[
	Player player;
	//��
	B_ball b_ball;
	b_ball.Setplayer(&player);
	//�s��
	B_pinManager b_pin(&b_ball);
	//b_pin.Setball(&b_ball);
	//�o�b�N�O�����h
	BackGround background;

	//�Q�[�����[�v�B
	while (DispatchWindowMessage() == true)
	{
		//�`��J�n�B
		g_graphicsEngine->BegineRender();
		//�Q�[���p�b�h�̍X�V�B	
		for (auto& pad : g_pad) {
			pad.Update();
		}
		//�����G���W���̍X�V�B
		g_physics.Update();
		
		//�v���C���[�̍X�V�B
		player.Update();
		//�ʂ̍X�V�B
		b_ball.Update();
		//�s���̍X�V�B
		b_pin.Update();
		//�o�b�N�O�����h�̍X�V�B
		background.Update();
		//�ʂ̕`��B
		b_ball.Draw();
		//�o�b�N�O�����h�̕`��B
		background.Draw();
		//�s���̕`��B
		b_pin.Draw();
		//�v���C���[�̕`��B
		player.Draw();	
		//�J�����̍X�V�B
		g_camera3D.Update();
		//�`��I���B
		g_graphicsEngine->EndRender();
	}
}