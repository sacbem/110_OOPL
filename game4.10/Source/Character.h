#include <vector>
namespace game_framework {
	class Character
	{
	public:
		Character();
		~Character();
		int  GetX1();					// Chracter���W�� x �y��
		int  GetY1();					// Chracter���W�� y �y��
		int  GetX2();					// Chracter�k�U�� x �y��
		int  GetY2();					// Chracter�k�U�� y �y��
		void Initialize();
		void LoadBitmap();
		void OnShow();
		void OnMove();
		void SetMovingDown(bool flag);
		void SetMovingLeft(bool flag);
		void SetMovingRight(bool flag);
		void SetMovingUp(bool flag);
		void SetRunning(bool flag);
		void SetJump(bool flag);
		void SetAttack(bool flag);
		void SetDefense(bool flag);
		void SetXY(int X, int Y);

	protected:
		CAnimation Animation;
		CAnimation Walking;
		CAnimation Attacking;
		int xPos, yPos;
		//judge
		//basic movement
		bool isRunning;
		bool isMovingDown;			// �O�_���b���U����
		bool isMovingLeft;			// �O�_���b��������
		bool isMovingRight;			// �O�_���b���k����
		bool isMovingUp;			// �O�_���b���W����
		bool isJumpping;
		//Attack
		bool isAttacking;
		bool isDefending;
	};
}