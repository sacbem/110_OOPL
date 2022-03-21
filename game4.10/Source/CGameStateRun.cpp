#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CGameStateRun.h"

namespace game_framework {
	CGameStateRun::CGameStateRun(CGame* g)
		: CGameState(g)
	{
		PlayerTest = new Character();
	}

	CGameStateRun::~CGameStateRun()
	{
		delete PlayerTest;
	}

	void CGameStateRun::OnBeginState()
	{
		PlayerTest->Initialize();
	}

	void CGameStateRun::OnMove()						// ���ʹC������
	{
		PlayerTest->OnMove();
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
	}

	void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_LEFT = 0x25; // keyboard���b�Y
		const char KEY_UP = 0x26; // keyboard�W�b�Y
		const char KEY_RIGHT = 0x27; // keyboard�k�b�Y
		const char KEY_DOWN = 0x28; // keyboard�U�b�Y
		const char KEY_SPACE = 0x20; // keyboard SPACE
		//if (nChar == KEY_LEFT)
			
		//if (nChar == KEY_RIGHT)
			//sister.SetMovingRight(true);
		// if (nChar == KEY_UP)
			// sister.SetJumpimg(true);
		if (nChar == KEY_LEFT) {
			PlayerTest->SetMovingLeft(true);
			PlayerTest->SetRunning(true);
		}
		if (nChar == KEY_RIGHT) {
			PlayerTest->SetMovingRight(true);
			PlayerTest->SetRunning(true);
		}
		if (nChar == KEY_UP) {
			PlayerTest->SetMovingUp(true);
			PlayerTest->SetRunning(true);
		}
		if (nChar == KEY_DOWN) {
			PlayerTest->SetMovingDown(true);
			PlayerTest->SetRunning(true);
		}
		if (nChar == KEY_SPACE)
			PlayerTest->SetAttack(true);
	}

	void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_LEFT = 0x25; // keyboard���b�Y
		const char KEY_UP = 0x26; // keyboard�W�b�Y
		const char KEY_RIGHT = 0x27; // keyboard�k�b�Y
		const char KEY_DOWN = 0x28; // keyboard�U�b�Y
		const char KEY_SPACE = 0x20; // keyboard SPACE
		//if (nChar == KEY_LEFT)
			//sister.SetMovingLeft(false);
		//if (nChar == KEY_RIGHT)
			//sister.SetMovingRight(false);

		if (nChar == KEY_LEFT) {
			PlayerTest->SetMovingLeft(false);
			PlayerTest->SetRunning(false);
		}
		if (nChar == KEY_RIGHT) {
			PlayerTest->SetMovingRight(false);
			PlayerTest->SetRunning(false);
		}
		if (nChar == KEY_UP) {
			PlayerTest->SetMovingUp(false);
			PlayerTest->SetRunning(false);
		}
		if (nChar == KEY_DOWN) {
			PlayerTest->SetMovingDown(false);
			PlayerTest->SetRunning(false);
		}
		if (nChar == KEY_SPACE)
			PlayerTest->SetAttack(false);
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
	}
}