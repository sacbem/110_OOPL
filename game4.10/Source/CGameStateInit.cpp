#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CGameStateInit.h"
//#include "InitalPageMenu.h"

namespace game_framework {
	CGameStateInit::CGameStateInit(CGame* g): CGameState(g)
	{
        settingBtn = new SettingBtn();
        startBtn = new StartBtn();
	}


	void CGameStateInit::OnInit()
	{
		//
		// ��ϫܦh�ɡAOnInit���J�Ҧ����ϭn��ܦh�ɶ��C���קK���C�����H
		//     �������@�СA�C���|�X�{�uLoading ...�v�A���Loading���i�סC
		//
		ShowInitProgress(0);	// �@�}�l��loading�i�׬�0%
		//
		// �}�l���J���
		//
        startBtn->Load();
        settingBtn->Load();
		logo.LoadBitmap(IDB_BITMAP3);
		Sleep(300);				// ��C�A�H�K�ݲM���i�סA��ڹC���ЧR����Sleep
		//
		// ��OnInit�ʧ@�|����CGameStaterRun::OnInit()�A�ҥH�i���٨S��100%
		//
	}

	void CGameStateInit::OnBeginState()
	{
        keyCount = 0;
        cursorClickLift = 0;
	}
    
    void CGameStateInit:: OnMouseMove(UINT nFlags, CPoint point) {
        cursorXY[0] = point.x;
        cursorXY[1] = point.y;
    }
	void CGameStateInit::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_ESC = 27;
		const char KEY_ENTER = 13;
        const char KEY_W = 87;
        const char KEY_A = 65;
        const char KEY_S = 83;
        const char KEY_D = 68;
 
        
	}

	void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
	{
        //TRACE("The value of nFlags is %d\n",  nFlags);
        cursorClickLift = nFlags;

        if (point.x >= 545 && point.x <= 745) {
            if (point.y >= 260 && point.y <= 280) {
                if (nFlags == 1) {
                    GotoGameState(GAME_STATE_RUN);		// ������GAME_STATE_RUN
                } 
            }
        }
        else if (point.x >= 525 && point.x <= 765) {
            if (point.y >= 300 && point.y <= 320) {
                if (nFlags == 1) {
                    PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE, 0, 0);	// �����C��
                }
            }
        }
	}


	void CGameStateInit::OnShow()
	{
		//
		// �K�Wlogo
		//
		logo.SetTopLeft(0, 0);
		logo.ShowBitmap();

        startBtn->OnShow();
        settingBtn->OnShow();

        if (cursorXY[0]>= 545 && cursorXY[0] <= 745) {
            if (cursorXY[1] >= 260 && cursorXY[1] <= 280) {
                startBtn->buttonTouch();
                settingBtn->OnShow();
            }
        }
        if (cursorXY[0] >= 525 && cursorXY[0] <= 765) {
            if (cursorXY[1] >= 300 && cursorXY[1] <= 320) {
                settingBtn->buttonTouch();
                startBtn->OnShow();
            }
        }
    

		//
		// Demo�ù��r�����ϥΡA���L�}�o�ɽкɶq�קK�����ϥΦr���A���CMovingBitmap����n
		//
		CDC* pDC = CDDraw::GetBackCDC();			// ���o Back Plain �� CDC 
		CFont f, * fp;
		f.CreatePointFont(160, "Times New Roman");	// ���� font f; 160���16 point���r
		fp = pDC->SelectObject(&f);					// ��� font f
		pDC->SetBkColor(RGB(0, 0, 0));
		pDC->SetTextColor(RGB(255, 255, 0));

		pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
		CDDraw::ReleaseBackCDC();					// �� Back Plain �� CDC
	}

    CGameStateInit::~CGameStateInit()
    {
        delete startBtn;
        delete settingBtn;
    }
}