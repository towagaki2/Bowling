#include "stdafx.h"
#include "system/system.h"
#include "Player.h"
#include "B_ball.h"
#include "B_pinManager.h"
#include "level/Level.h"
#include "BackGround.h"


///////////////////////////////////////////////////////////////////
// ウィンドウプログラムのメイン関数。
///////////////////////////////////////////////////////////////////
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	//ゲームの初期化。
	InitGame(hInstance, hPrevInstance, lpCmdLine, nCmdShow, "Game");

	//カメラを初期化。
	g_camera3D.SetPosition({ 0.0f, 300.0f, 300.0f });
	g_camera3D.SetTarget({ 0.0f, 200.0f, 0.0f });
	g_camera3D.SetFar(10000.0f);
	g_camera2D.SetPosition({ 0.0f, 10.0f, 1.0f });
	g_camera2D.SetTarget({ 0.0f, 0.0f, 0.0f });
	g_camera2D.SetFar(10000.0f);
	g_camera2D.Update();
	

	//プレイヤー
	Player player;
	//玉
	B_ball b_ball;
	b_ball.Setplayer(&player);
	//ピン
	B_pinManager b_pin(&b_ball);
	//b_pin.Setball(&b_ball);
	//バックグランド
	BackGround background;

	//ゲームループ。
	while (DispatchWindowMessage() == true)
	{
		//描画開始。
		g_graphicsEngine->BegineRender();
		//ゲームパッドの更新。	
		for (auto& pad : g_pad) {
			pad.Update();
		}
		//物理エンジンの更新。
		g_physics.Update();
		
		//プレイヤーの更新。
		player.Update();
		//玉の更新。
		b_ball.Update();
		//ピンの更新。
		b_pin.Update();
		//バックグランドの更新。
		background.Update();
		//玉の描画。
		b_ball.Draw();
		//バックグランドの描画。
		background.Draw();
		//ピンの描画。
		b_pin.Draw();
		//プレイヤーの描画。
		player.Draw();	
		//カメラの更新。
		g_camera3D.Update();
		//描画終了。
		g_graphicsEngine->EndRender();
	}
}