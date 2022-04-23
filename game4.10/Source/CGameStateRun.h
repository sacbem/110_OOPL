#include "Character.h"
#include "MapGenerator.h"
#include "HealthBar.h"
#include <ctime>
namespace game_framework {
	class CGameStateRun : public CGameState {
	public:
		CGameStateRun(CGame* g);
		~CGameStateRun();
		void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		void OnInit();  								// �C������Ȥιϧγ]�w
		void OnKeyDown(UINT, UINT, UINT);
		void OnKeyUp(UINT, UINT, UINT);
        void MapSlide();
	protected:
		void OnMove();									// ���ʹC������
		void OnShow();									// ��ܳo�Ӫ��A���C���e��
	private:
		//Player & other
		Character PlayerTest;
		//Character* EnemyTest;
        MapGenerator* maps;
		HealthBar* HealthPlayer1;
		//HealthBar* HealthPlayer2;
		int CleanCounter=0;
	};
}
