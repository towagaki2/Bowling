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

	int GameNumber = 0;
	int Start = 0;

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
		//スタート画面。
		if (Start == 0)
		{
			static char errorMessage[10 * 1024];
			sprintf(errorMessage, "ボーリング始めますか？。");
			if (MessageBox(NULL, errorMessage, "スタート！！", MB_YESNO) != IDNO) {

				Start++;
			}
			else
			{
				break;
			}
		}
		//スコアと終わる判定。
		if (b_ball.GetThorw() == 2) {
			if (GameNumber >= 1)
			{
			
				static char errorMessage[10 * 1024];
				sprintf(errorMessage, "TOTAL SCORE :%d\nやりまっか？", b_pin.GetScore());
				if (MessageBox(NULL, errorMessage, "スコア", MB_YESNO) == IDNO) {
					Start=0;
				}	
				b_ball.SetThorw(0);
				b_pin.SetScore(0);
				for (int i = 0; i < 10; i++) {
					b_pin.SetNumber(i);
				}
				GameNumber = 0;
			}
			else
			{
				static char errorMessage[10 * 1024];
				sprintf(errorMessage, "%dフレーム目の SCORE :%dです。",++GameNumber, b_pin.GetScore());
				MessageBox(NULL, errorMessage, "スコア", MB_OK);
				b_ball.SetThorw(0);
				for (int i = 0; i < 10; i++) {
					b_pin.SetNumber(i);
				}
				
			}
		}
	}
}