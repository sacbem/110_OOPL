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
	CGameStateRun::CGameStateRun(CGame* g): CGameState(g){
		TRACE("Begin Player 1 %d\n", g->SelectCharacterID[0]);
		TRACE("Begin Player 2 %d\n", g->SelectCharacterID[1]);
		CharacterList.reserve(2);
		//EnemyTest = new Character();
		HealthPlayer1 = new HealthBar();
		HealthPlayer2 = new HealthBar();
        maps = new Map(Forest);
		charactersPosition.resize(1); // resize 為腳色數量 : 1
		//GenerationTime = clock();

	}

	void CGameStateRun::OnBeginState()
	{
		//_CrtDumpMemoryLeaks();
		for (int i = 0; i < 2; i++) {
			charactersPosition[0].push_back(200);
		}
		TimePassed = 0;
	}
   
	void CGameStateRun::OnMove()						// 移動遊戲元素
	{
		CleanCounter++;
		if (CleanCounter >= 10) {
			CleanCounter = 0;
			if (EnemyTest->GetHealth() <= 0) {
				EnemyTest->SetAlive(false);
			}
		}

		PlayerTest->OnMove();
		EnemyTest->OnMove();
		if (PlayerTest->HitEnemy(EnemyTest) && PlayerTest->isAttacking) {
			if (EnemyTest->HealthPoint > 0) {
				//int hitDirection = PlayerTest->GetDir();
				EnemyTest->SetKnock(true, PlayerTest->GetDir(), PlayerTest->AttackState);
				EnemyTest->isGettingDamage(PlayerTest->AttackPoint);
			}
		}
		maps->ResetCharactAccumulator(PlayerTest->GetDistance(), PlayerTest->GetDistance());
		//EnemyTest->OnMove();
		PlayerTest->DistanceAccumulatorReset();
		maps->ScenesCamera(PlayerTest->isRunning, PlayerTest->GetDir(), PlayerTest->GetDistance());
	}

	void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
	{
		ShowInitProgress(33);	// 接個前一個狀態的進度，此處進度視為33%
		ShowInitProgress(50);
		Sleep(300);

        maps->Load(Forest);
		HealthPlayer1->init();
		HealthPlayer2->init();

		HealthPlayer1->OnLoad(0, 0);
		HealthPlayer2->OnLoad(400, 0);

	}

	void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags){
		PlayerTest->InputKeyDown(nChar);
	}

	void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags){
		PlayerTest->InputKeyUp(nChar);
	}

	void CGameStateRun::OnShow(){
		TRACE("Begin Player 1 %d\n", this->game->SelectCharacterID[0]);
		TRACE("Begin Player 2 %d\n", this->game->SelectCharacterID[1]);
		//get character
		if (GetCharacter == false ){ // && EnemyTest->getCharacter == false) {
			PlayerTest = new Freeze();
			PlayerTest->SetXY(200, 200);
			PlayerTest->SetCharacter();

			EnemyTest = new Freeze();
			EnemyTest->SetXY(400,200);
			EnemyTest->SetCharacter();
			
			//EnemyTest->SetCharacter(buffer[1] - '0');
			PlayerTest->getCharacter = true;
			EnemyTest->getCharacter = true;
			
			GetCharacter = true;
			//load HealthBar small character
			HealthPlayer1->loadSmallImg(this->game->SelectCharacterID[0]);
			HealthPlayer2->loadSmallImg(this->game->SelectCharacterID[1]);

			GenerationTime = clock();
		}
		CurrentTime = clock();
		TimePassed = CurrentTime - GenerationTime/1000;
		//TRACE("TimePassed %d\n", TimePassed);
		
        maps->PrintMap();
		PlayerTest->OnShow();
		EnemyTest->OnShow();
		HealthPlayer1->OnShow(PlayerTest->HealthPoint, PlayerTest->InnerHealPoint, PlayerTest->Mana, PlayerTest->InnerMana);
		HealthPlayer2->OnShow(EnemyTest->HealthPoint, EnemyTest->InnerHealPoint, EnemyTest->Mana, EnemyTest->InnerMana);
		//_CrtDumpMemoryLeaks();
		maps->DynamicScence(PlayerTest->GetDir(), PlayerTest->GetDistance());
		
		CDC* pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC
		CFont f, * fp;
		f.CreatePointFont(160, "Times New Roman");	// 產生 font f; 160表示16 point的字
		fp = pDC->SelectObject(&f);					// 選用 font f
		pDC->SetBkColor(RGB(0, 0, 0));
		pDC->SetTextColor(RGB(255, 255, 0));

		CString str;
		str.Format("%d", PlayerTest->GetMovingTime(PlayerTest->GetDir()));
		pDC->TextOut(120, 220, str);
		pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
		CDDraw::ReleaseBackCDC();
	}
    CGameStateRun::~CGameStateRun(){
		delete maps, HealthPlayer1, HealthPlayer2, PlayerTest, EnemyTest;

		for (auto& i : CharacterList) {
			delete i;
		}
    }
}