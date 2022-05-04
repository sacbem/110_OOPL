#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include <string> 
#include "CGameStateRun.h"
#include <fstream>
#include <string>
using namespace std;
#define  _CRTDBG_MAP_ALLOC
#include  < stdlib.h >
#include  < crtdbg.h >
#define Forest 100
namespace game_framework {
	CGameStateRun::CGameStateRun(CGame* g)
		: CGameState(g)
	{
		//EnemyTest = new Character();
		HealthPlayer1 = new HealthBar();
		//HealthPlayer2 = new HealthBar();
        maps = new Map(Forest);
		//_CrtDumpMemoryLeaks();
	}

	void CGameStateRun::OnBeginState()
	{
		//EnemyTest->SetXY(500, 200);
		//_CrtDumpMemoryLeaks();
	}
   
	void CGameStateRun::OnMove()						// 移動遊戲元素
	{
		CleanCounter++;
		if (CleanCounter >= 10) {
			CleanCounter = 0;
			/*
			if (EnemyTest->GetHealth() <= 0) {
				EnemyTest->SetAlive(false);
			}
			*/
		}

		PlayerTest->OnMove();
		//EnemyTest->OnMove();
		maps->ResetCharactAccumulator(PlayerTest->GetDistance(), PlayerTest->GetDistance());
		maps->ScenesCamera(PlayerTest->isRunning, PlayerTest->GetDir(), PlayerTest->GetDistance());
	}

	void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
	{
		ShowInitProgress(33);	// 接個前一個狀態的進度，此處進度視為33%
		ShowInitProgress(50);
		Sleep(300);

        maps->Load(Forest);
		HealthPlayer1->init();
		//HealthPlayer2->init();
		HealthPlayer1->OnLoad(0, 0);
		//HealthPlayer2->OnLoad(400, 0);
		//_CrtDumpMemoryLeaks();

	}

	void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		PlayerTest->InputKeyDown(nChar);
	}

	void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		PlayerTest->InputKeyUp(nChar);
	}

	void CGameStateRun::OnShow(){
		
		//get character
		if (GetCharacter == false ){ // && EnemyTest->getCharacter == false) {
			ifstream ifs;
			char buffer[2];
			ifs.open("CharacterSelected.txt");
			ifs.read(buffer, sizeof(buffer));
			ifs.close();
			PlayerTest = new Freeze();
			PlayerTest->SetXY(200, 200);
			PlayerTest->SetCharacter();
			//EnemyTest->SetCharacter(buffer[1] - '0');
			PlayerTest->getCharacter = true;
			GetCharacter = true;
			//EnemyTest->getCharacter = true;
			//load HealthBar small character
			HealthPlayer1->loadSmallImg(1);
			//HealthPlayer2->loadSmallImg(buffer[1] - '0');
		}

        maps->PrintMap();
		PlayerTest->OnShow();
		//EnemyTest->OnShow();
		HealthPlayer1->OnShow(PlayerTest->HealthPoint);
		//HealthPlayer2->OnShow(EnemyTest->HealthPoint);
		//_CrtDumpMemoryLeaks();
	}
    CGameStateRun::~CGameStateRun(){
		delete maps, HealthPlayer1;//, HealthPlayer2;
    }
}