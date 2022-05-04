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

namespace game_framework {
	CGameStateRun::CGameStateRun(CGame* g)
		: CGameState(g)
	{
		//EnemyTest = new Character();
		HealthPlayer1 = new HealthBar();
		//HealthPlayer2 = new HealthBar();
        maps = new MapGenerator();
		//_CrtDumpMemoryLeaks();
	}

	void CGameStateRun::OnBeginState()
	{
		
		//EnemyTest->SetXY(500, 200);
		//_CrtDumpMemoryLeaks();

	}
    void  CGameStateRun::MapSlide() {
        if (PlayerTest->isWalking) {
            //TRACE("--------------- %d -------------%d \n", PlayerTest->isRunning, PlayerTest->GetDistance());
            if (PlayerTest->GetDir()) {
                maps->ScenesCamera(true, 0);
            }
            else {
                maps->ScenesCamera(false, 0);
            }

        }
        else if (PlayerTest->GetDistance() > 50) {
          
            if (PlayerTest->GetDir()) {
                maps->ScenesCamera(true, 1);
            }
            else {
                maps->ScenesCamera(false, 1);
            }
            PlayerTest->SetAccumulator(PlayerTest->GetX1(), PlayerTest->GetY1());

        }
		//_CrtDumpMemoryLeaks();

    }
	void CGameStateRun::OnMove()						// ���ʹC������
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
        MapSlide();

	}

	void CGameStateRun::OnInit()  								// �C������Ȥιϧγ]�w
	{
		ShowInitProgress(33);	// ���ӫe�@�Ӫ��A���i�סA���B�i�׵���33%
		//
		// �}�l���J���
		//

		//
		// ��������Loading�ʧ@�A�����i��
		//
		ShowInitProgress(50);
		Sleep(300); // ��C�A�H�K�ݲM���i�סA��ڹC���ЧR����Sleep							

		//
		// ��OnInit�ʧ@�|����CGameStaterOver::OnInit()�A�ҥH�i���٨S��100%
		//

        maps->Load(0);
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