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
		PlayerTest = new Character();
		EnemyTest = new Character();
        maps = new MapGenerator();
		
	}

	void CGameStateRun::OnBeginState()
	{
		PlayerTest->SetXY(200, 200);
		EnemyTest->SetXY(500, 200);
		KeyBoardInputTime = 0;
		LastInputTime = 0;
		

	}
    void  CGameStateRun::MapSlide() {
        if (PlayerTest->isRunning) {
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
			if (EnemyTest->GetHealth() <= 0) {
				EnemyTest->SetAlive(false);
			}
		}

		PlayerTest->OnMove();
		EnemyTest->OnMove();
        MapSlide();
		
		//x bound
		if (PlayerTest->GetX1() <= 0) {
			PlayerTest->SetXY(0, PlayerTest->GetY1());
		}
		else if (PlayerTest->GetX2()>=800) {
			PlayerTest->SetXY(800-(PlayerTest->GetX2()-PlayerTest->GetX1()), PlayerTest->GetY1());
		}
		//y bound
		if(PlayerTest->GetY1() <= 200) {
			if (PlayerTest->isJumpping==false) {
				PlayerTest->SetXY(PlayerTest->GetX1(), 200);
			}
		}
		else if (PlayerTest->GetY2() >= 600) {
			PlayerTest->SetXY(PlayerTest->GetX1(),600- (PlayerTest->GetY2() - PlayerTest->GetY1()));
		}

		//x bound
		if (EnemyTest->GetX1() <= 0) {
			EnemyTest->SetXY(0, EnemyTest->GetY1());
		}
		else if (EnemyTest->GetX2() >= 800) {
			EnemyTest->SetXY(800 - (EnemyTest->GetX2() - EnemyTest->GetX1()), EnemyTest->GetY1());
		}
		//y bound
		if (EnemyTest->GetY1() <= 200) {
			if (EnemyTest->isJumpping==false) {
				EnemyTest->SetXY(EnemyTest->GetX1(), 200);
			}
		}
		else if (EnemyTest->GetY2() >= 600) {
			EnemyTest->SetXY(EnemyTest->GetX1(), 600 - (EnemyTest->GetY2() - EnemyTest->GetY1()));
		}

		if (PlayerTest->HitEnemy(EnemyTest) && PlayerTest->isAttacking) {
			if (EnemyTest->HealthPoint>0) {
				int hitDirection = PlayerTest->GetDir();
				EnemyTest->SetGettingHit(true, hitDirection);
				EnemyTest->HealthPoint -= PlayerTest->AttackPoint;
			}
		}
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

		//_CrtDumpMemoryLeaks();

	}

	void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		Diff = KeyBoardInputTime - LastInputTime;
		LastInputTime = KeyBoardInputTime;

		const char KEY_LEFT = 0x41; // keyboard���b�Y 0x25
		const char KEY_UP = 0x57; // keyboard�W�b�Y 0x26
		const char KEY_RIGHT = 0x44; // keyboard�k�b�Y 0x27
		const char KEY_DOWN = 0x53; // keyboard�U�b�Y 0x28
		const char KEY_SPACE = 0x20; // keyboard SPACE
		const char KEY_CTRL = 0x11; //keyboard ctrl

		if (nChar == KEY_LEFT) {
			if (PlayerTest->isRunning == true) {
				PlayerTest->SetMovingLeft(false);
				PlayerTest->SetMovingRight(false);
				PlayerTest->SetWalking(false);
				PlayerTest->SetRunning(false);
			}
		}
		if (nChar == KEY_RIGHT) {
			if (PlayerTest->isRunning == true) {
				PlayerTest->SetMovingLeft(false);
				PlayerTest->SetMovingRight(false);
				PlayerTest->SetWalking(false);
				PlayerTest->SetRunning(false);
			}
		}

		if (Diff <= 5) {
			if (nChar == KEY_LEFT && LastInput == KEY_LEFT) {
				PlayerTest->SetMovingLeft(true);
				PlayerTest->SetRunning(true);
			}
			else if (nChar == KEY_RIGHT && LastInput == KEY_RIGHT) {
				PlayerTest->SetMovingRight(true);
				PlayerTest->SetRunning(true);
			}
		}
		if (nChar == KEY_LEFT) {
			PlayerTest->SetMovingLeft(true);
		}
		if (nChar == KEY_RIGHT) {
			PlayerTest->SetMovingRight(true);			
		}
		if (nChar == KEY_UP) {
			PlayerTest->SetMovingUp(true);
		}
		if (nChar == KEY_DOWN) {
			PlayerTest->SetMovingDown(true);
		}
		if (nChar == KEY_SPACE) {
			PlayerTest->SetAttack(true);
		}
		if (nChar == KEY_CTRL) {
			PlayerTest->SetJump(true);
		}

		//_CrtDumpMemoryLeaks();

	}

	void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_LEFT = 0x41; // keyboard���b�Y 0x25
		const char KEY_UP = 0x57; // keyboard�W�b�Y 0x26
		const char KEY_RIGHT = 0x44; // keyboard�k�b�Y 0x27
		const char KEY_DOWN = 0x53; // keyboard�U�b�Y 0x28
		const char KEY_SPACE = 0x20; // keyboard SPACE
		//if (nChar == KEY_LEFT)
			//sister.SetMovingLeft(false);
		//if (nChar == KEY_RIGHT)
			//sister.SetMovingRight(false);

		if (nChar == KEY_LEFT) {
			if(PlayerTest->isRunning == false){
				PlayerTest->SetMovingLeft(false);
				PlayerTest->SetWalking(false);
			}

			EnemyTest->SetMovingLeft(false);
			EnemyTest->SetWalking(false);
		}
		if (nChar == KEY_RIGHT) {
			if (PlayerTest->isRunning == false) {
				PlayerTest->SetMovingRight(false);
				PlayerTest->SetWalking(false);
			}
			
			EnemyTest->SetMovingRight(false);
			EnemyTest->SetWalking(false);
		}
		if (nChar == KEY_UP) {
			PlayerTest->SetMovingUp(false);
			PlayerTest->SetWalking(false);
		}
		if (nChar == KEY_DOWN) {
			PlayerTest->SetMovingDown(false);
			PlayerTest->SetWalking(false);
		}
		if (nChar == KEY_SPACE) {
			PlayerTest->SetAttack(false);
		}
		LastInput = nChar;

		//_CrtDumpMemoryLeaks();

	}

	void CGameStateRun::OnShow(){
		//get character
		if (PlayerTest->getCharacter == false && EnemyTest->getCharacter == false) {
			ifstream ifs;
			char buffer[2];
			ifs.open("CharacterSelected.txt");
			ifs.read(buffer, sizeof(buffer));
			ifs.close();
			PlayerTest->SetCharacter(buffer[0] - '0');
			EnemyTest->SetCharacter(buffer[1] - '0');
			PlayerTest->getCharacter = true;
			EnemyTest->getCharacter = true;
		}

        maps->PrintMap();
		PlayerTest->OnShow();
		EnemyTest->OnShow();
		CDC* pDC = CDDraw::GetBackCDC();			// ���o Back Plain �� CDC
		CFont f, * fp;
		f.CreatePointFont(160, "Times New Roman");	// ���� font f; 160���16 point���r
		fp = pDC->SelectObject(&f);					// ��� font f
		pDC->SetBkColor(RGB(0, 0, 0));
		pDC->SetTextColor(RGB(255, 255, 0));

		KeyBoardInputTime++;
		//CString str;
		//str.Format("%d", PlayerTest->GetDir());
		//CString str2;
		//str2.Format("%d , %d", PlayerTest->GetX1(), PlayerTest->GetY1());
		//pDC->TextOut(120, 220, str);
		//pDC->TextOut(120, 320, str2);
		//pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
		//CDDraw::ReleaseBackCDC();
	}
    CGameStateRun::~CGameStateRun(){
        delete PlayerTest, EnemyTest,maps;
    }
}