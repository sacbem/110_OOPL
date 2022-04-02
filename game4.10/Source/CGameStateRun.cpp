#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include <string> 
#include "CGameStateRun.h"

namespace game_framework {
	CGameStateRun::CGameStateRun(CGame* g)
		: CGameState(g)
	{
		PlayerTest = new Character();
		EnemyTest = new Enemy();
	}

	CGameStateRun::~CGameStateRun()
	{
		delete PlayerTest;
		delete EnemyTest;
	}

	void CGameStateRun::OnBeginState()
	{
		PlayerTest->Initialize();
		EnemyTest->Initialize();
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
		
		//x bound
		if (PlayerTest->GetX1() <= 0) {
			PlayerTest->SetXY(0, PlayerTest->GetY1());
		}
		else if (PlayerTest->GetX2()>=800) {
			PlayerTest->SetXY(800-(PlayerTest->GetX2()-PlayerTest->GetX1()), PlayerTest->GetY1());
		}
		//y bound
		if(PlayerTest->GetY1() <= 0) {
			PlayerTest->SetXY(PlayerTest->GetX1(),0);
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
		if (EnemyTest->GetY1() <= 0) {
			EnemyTest->SetXY(EnemyTest->GetX1(), 0);
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
		
		CDC *pDC = CDDraw::GetBackCDC();			// ���o Back Plain �� CDC
		CFont f, *fp;
		f.CreatePointFont(160, "Times New Roman");	// ���� font f; 160���16 point���r
		fp = pDC->SelectObject(&f);					// ��� font f
		pDC->SetBkColor(RGB(0, 0, 0));
		pDC->SetTextColor(RGB(255, 255, 0));

		CString str;
		str.Format("%d", EnemyTest->GetHealth());
		CString str2;
		str2.Format("%d , %d", PlayerTest->GetX1(), PlayerTest->GetY1());
		pDC->TextOut(120, 220, str);
		pDC->TextOut(120, 320, str2);
		pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
		CDDraw::ReleaseBackCDC();
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

		PlayerTest->LoadBitmap();
		EnemyTest->LoadBitmap();
	}

	void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		time_t LastTime = KeyBoardInputTime;
		time(&KeyBoardInputTime);
		Diff = KeyBoardInputTime - LastTime;

		const char KEY_LEFT = 0x41; // keyboard���b�Y 0x25
		const char KEY_UP = 0x57; // keyboard�W�b�Y 0x26
		const char KEY_RIGHT = 0x44; // keyboard�k�b�Y 0x27
		const char KEY_DOWN = 0x53; // keyboard�U�b�Y 0x28
		const char KEY_SPACE = 0x20; // keyboard SPACE
		const char KEY_CTRL = 0x11; //keyboard ctrl
		//if (nChar == KEY_LEFT)
			
		//if (nChar == KEY_RIGHT)
			//sister.SetMovingRight(true);
		// if (nChar == KEY_UP)
			// sister.SetJumpimg(true);

		if (Diff <= 0) {
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
			PlayerTest->SetWalking(true);

			//EnemyTest->SetMovingLeft(true);
			//EnemyTest->SetWalking(true);
		}
		if (nChar == KEY_RIGHT) {
			PlayerTest->SetMovingRight(true);
			PlayerTest->SetWalking(true);
			
			//EnemyTest-> SetMovingRight(true);
			//EnemyTest-> SetWalking(true);
		}
		if (nChar == KEY_UP) {
			PlayerTest->SetMovingUp(true);
			PlayerTest->SetWalking(true);
		}
		if (nChar == KEY_DOWN) {
			PlayerTest->SetMovingDown(true);
			PlayerTest->SetWalking(true);
		}
		if (nChar == KEY_SPACE) {
			PlayerTest->SetAttack(true);
		}
		if (nChar == KEY_CTRL) {
			PlayerTest->SetJump(true);
		}
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

		if (Diff <= 0) {
			if (nChar == KEY_LEFT && LastInput == KEY_LEFT) {
				PlayerTest->SetMovingLeft(false);
				PlayerTest->SetRunning(false);
			}
			else if (nChar == KEY_RIGHT && LastInput == KEY_RIGHT) {
				PlayerTest->SetMovingRight(false);
				PlayerTest->SetRunning(false);
			}
		}
		if (nChar == KEY_LEFT) {
			PlayerTest->SetMovingLeft(false);
			PlayerTest->SetWalking(false);
			PlayerTest->SetRunning(false);

			EnemyTest->SetMovingLeft(false);
			EnemyTest->SetWalking(false);
		}
		if (nChar == KEY_RIGHT) {
			PlayerTest->SetMovingRight(false);
			PlayerTest->SetRunning(false);
			PlayerTest->SetWalking(false);

			EnemyTest->SetMovingRight(false);
			EnemyTest->SetWalking(false);
		}
		if (nChar == KEY_UP) {
			PlayerTest->SetMovingUp(false);
			PlayerTest->SetWalking(false);
			PlayerTest->SetRunning(false);
		}
		if (nChar == KEY_DOWN) {
			PlayerTest->SetMovingDown(false);
			PlayerTest->SetWalking(false);
		}
		if (nChar == KEY_SPACE) {
			PlayerTest->SetAttack(false);
		}
		LastInput = nChar;
	}

	void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // �B�z�ƹ����ʧ@
	{

	}

	void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
	{

	}

	void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
	{

	}

	void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // �B�z�ƹ����ʧ@
	{

	}

	void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
	{

	}

	void CGameStateRun::OnShow()
	{
		//map.OnShow(); // ��ܦa��
		//sister.OnShow();
		PlayerTest->OnShow();
		EnemyTest->OnShow();
	}
}