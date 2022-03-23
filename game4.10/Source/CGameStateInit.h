#include "InitalPageMenu.h"
#include <memory>
namespace game_framework {
	class CGameStateInit : public CGameState {
	public:
		CGameStateInit(CGame* g);
		void OnInit();  								// �C������Ȥιϧγ]�w
		void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		void OnKeyUp(UINT, UINT, UINT); 				// �B�z��LUp���ʧ@
		void OnLButtonDown(UINT nFlags, CPoint point);  // �B�z�ƹ����ʧ@
        void OnMouseMove(UINT nFlags, CPoint point);	// �B�z�ƹ����ʧ@
        ~CGameStateInit();
	protected:
		void OnShow();									// ��ܳo�Ӫ��A���C���e��
	private:
		CMovingBitmap logo, selectCharacterMenu,black;	// csie��logo
        shared_ptr<StartBtn> startBtn;
        shared_ptr<SettingBtn> settingBtn;
        vector<int> bitmap;
        CAnimation attackScreen;
        int keyCount;
        int cursorXY[2];
        int cursorClickLift;
        boolean mouseEnable;
        boolean selectEnter;
	};
}
