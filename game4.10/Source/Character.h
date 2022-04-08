namespace game_framework {
	class Character
	{
	public:
		Character();
		~Character();
		int HitEnemy(Character* enemy);
		bool GetAlive();
		int  GetX1();					// Chracter���W�� x �y��
		int  GetY1();					// Chracter���W�� y �y��
		int  GetX2();					// Chracter�k�U�� x �y��
		int  GetY2();					// Chracter�k�U�� y �y��
		int	 GetDir();
		int	 GetHealth();
		void Initialize();
		void SetCharacter(int num);
		void LoadPlayer0();
		void LoadPlayer1();
		void LoadFirzen();
		void LoadFreeze();
		void LoadHenry();
		void OnShow();
		void OnMove();
		void SetMovingDown(bool flag);
		void SetMovingLeft(bool flag);
		void SetMovingRight(bool flag);
		void SetMovingUp(bool flag);
		void SetWalking(bool flag);
		void SetJump(bool flag);
		void SetRunning(bool flag);
		void SetAttack(bool flag);
		void SetDefense(bool flag);
		void SetGettingHit(bool flag, int Dir);
		void SetGettingUp(bool flag);
		void SetAlive(bool flag);
		void SetXY(int X, int Y);
        int GetDistance();
        void SetAccumulator(int, int);
		void SetMapBorder(int mapID);
		//basic informtion
		bool getCharacter;
		int characterNumber;
		string name;
		int HealthPoint;
		int AttackPoint;
		int DefencePoint;
		bool isAlive;
		bool isGettingHit;
		bool isGettingUp;

		//Jumping
		bool isJumpping;
		//Running
		bool isRunning;
		//Attack
		bool isAttacking;
		//Defend
		bool isDefending;

	protected:
		//CMovingBitmap shadow;
		//CMovingBitmap nameImg;
        CMovingBitmap photoSticker;
		CAnimation Animation;		// normal state
		CAnimation AnimationReverse;// normal state reverse

		CAnimation Walking;
		CAnimation WalkingReverse;
		CAnimation Attacking;
		CAnimation AttackingReverse;
		CAnimation Jump;
		CAnimation JumpReverse;
		CAnimation Running;
		CAnimation RunningReverse;
		CAnimation Knock;
		CAnimation KnockReverse;
		CAnimation KnockBack;
		CAnimation KnockBackReverse;
		CAnimation Getup;
		CAnimation GetupReverse;
		CAnimation GetupBack;
		CAnimation GetupBackReverse;

		void ShowNormal(int Dir);
		void ShowWalking(int Dir);
		void ShowAttacking(int Dir);
		void ShowJump(int Dir);
		void ShowRun(int Dir);
		void ShowGettingUP(int Dir,int HitDir);
		void ShowKnock(int Dir, int HitDir);
        void DistaceAccumulator();

		int DelayCounter;
		int Delay;
		int xPos, yPos;
		int xMapBorderMax, yMapBorderMax;
		int xMapBorderMin, yMapBorderMin;
        int xAccumulator, yAccumulator;
		//judge
		//direction
		int direction;				// 0=Left 1=Right
		int hitDirection;
		//basic movement
		bool isWalking;
		bool isMovingDown;			// �O�_���b���U����
		bool isMovingLeft;			// �O�_���b��������
		bool isMovingRight;			// �O�_���b���k����
		bool isMovingUp;			// �O�_���b���W����
		bool isRising;
		int JumpYposTemp;
		int YVelocity;
		int InitialVelocity;
        int walkedDistance;
	private:
		int HitRectangle(int tx1, int ty1, int tx2, int ty2);
	};
}