#include "InitalPageMenu.h"
#include "SelCharacterConfig.h"
#include <memory>
namespace game_framework {
	class CGameStateInit : public CGameState {
	public:
		CGameStateInit(CGame* g);
		void OnInit();  								// 遊戲的初值及圖形設定
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnKeyUp(UINT, UINT, UINT); 				// 處理鍵盤Up的動作
		void OnLButtonDown(UINT nFlags, CPoint point);  // 處理滑鼠的動作
		void OnMouseMove(UINT nFlags, CPoint point);	// 處理滑鼠的動作
		void ScreenClear();
		void SetAnimation();
		void SetCountdownAni();
		void SetPhotoStickers();
		~CGameStateInit();
	protected:
		void OnShow();									// 顯示這個狀態的遊戲畫面
	private:
		CMovingBitmap logo,black;	// csie的logo
		CMovingBitmap AboutInfo,KeyInfo;
		bool isAbout;
		bool isKey;
		CAnimation attackScreen,countDown; //需改名 還沒選角的動畫 
		StartBtn * startBtn;
		SettingBtn * settingBtn;
		AboutBtn * aboutBtn;
		KeyBtn * keyBtn;
		SelectCharacterMenu* selectCharacterMenu;
		PhotoSticker *photoSticker_1P, *photoSticker_2P;
		Seclecter* photoSticker_seclecter;
		vector<int> bitmap;
		vector<int> picStickers{ PHOTOSTICKER_WOODY,PHOTOSTICKER_FREEZE,PHOTOSTICKER_HENRY}, picIDs{BITMAP_NUMBER_0,BITMAP_NUMBER_1,BITMAP_NUMBER_2}, picNames{NAME_WOODY,NAME_FREEZE,NAME_HENRY};
		//".\\res\\Woody\\woody_f.bmp",
		int keyCount;
		int cursorXY[2];
		int cursorClickLift;
		int characterID[2];
		int characterIsSeclected ;
		int loadedImg;
		int enterCounter;
		boolean MOUSE_ENABLE,SELECT_ENTER,SELECTOR_ENABLE;
 
		
	};
}
