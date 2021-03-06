#pragma once
#include "SkillEffect.h"
#include "CharacterAnimation.h"
#include "FieldObject.h"

namespace game_framework {
	class Character{
	public:
		Character();
		Character(Character const & other);
		~Character();
		int serialNumber;
		int CharacterID;
		bool isAi;

		bool GetAlive();
		int  GetX1();					// Chracter
		int  GetY1();					// Chracter
		int  GetX2();					// Chracter
		int  GetY2();					// Chracter
		int	 GetDir();
		int	 GetHealth();
		void isGettingDamage(int Damage);
		int GetDistance();
		int GetMovingTime(boolean isLeft);
		int GetSkillSignal();
		int GetMovingUp_Down();
		int GetAnimationState();
		int GetRunCurrent();
		boolean GetCalculateDamageRequest();
		void Initialize();

		int itemId;
		int itemType;
		// -1 none
		// 0 Heavy Object
		// 1 weapon
		void SetPickup(bool flag, int itemId, int type);
		void Pickup(FieldObject* other);
		void DropItem(FieldObject *other);
		void ResetItem();

		virtual void SetCharacter() = 0;
		virtual void OnShow(vector<pair<int, int>>theOthersPosition , int mainTime)=0;
		virtual void OnMove() = 0;
		void SetMovingDown(bool flag);
		void SetMovingLeft(bool flag);
		void SetMovingRight(bool flag);
		void SetMovingUp(bool flag);
		void SetRunning(bool flag);
		void SetJumpping(bool flag);
		void SetDefense(bool flag);
		void SetAlive(bool flag);
		void SetXY(int X, int Y);
		void SetDir(int dir);
		void SetMapBorder(int mapID);
		void SetCalculateDamageRequest(boolean val);
		void SetAbonormalStatus(int characterID,boolean val);
		void ClearAbonormalStatus();
		void ClearWeaponState();
		virtual void SetAttack(bool flag) = 0;
		virtual void SetKnock(bool flag, int Dir, int AttState)=0;
		virtual void SetSkill(int createdTimes) =0;
		virtual void ClearSkill() = 0;
		void InputKeyDown(UINT nChar, int Time , int playerID);
		void InputKeyUp(UINT nChar, int playerID);
		boolean IsInBorder(int mapID);
		boolean IsStatic();
		boolean  DistanceAccumulatorReset();
		
		virtual int HitEnemy(Character* enemy) = 0;
		virtual void DetectSkillDamage(vector<pair<int, int>> theOthersPosition, int *n) = 0;
		virtual void EnemyAiMode(int anotherCharacterPosX,int anotherCharacterPosY, int createdTimes) = 0;
		vector <SkillEffect*> frozenPunchs;

		//basic informtion
		int characterNumber;
		int HealthPoint;
		int InnerHealPoint;
		int Mana;
		int InnerMana;
		int AttackPoint;
		int DefencePoint;
		bool isAlive;
		bool isWalking;
		bool isHitting;
		bool isRunning;
		bool StopRun;

		bool isCarryItem;
		bool isDropItem;
		bool isNearItem;
		//Spawn Something
		bool signalSpawnSword;
		bool FrozenSwordMode;

		vector<vector<int>> allItemPositsion;
		vector<vector<int>> GetAllItemPosition();

		void NearItem(int tx1, int ty1, int tx2, int ty2, int owner);

		bool isAttacking;
		bool isGettingHit;
		//call Attack & Defense
		virtual void ShowDefense() = 0;
		virtual void ShowRoll () = 0;
		virtual void ShowAttack() = 0;
		virtual void ShowKnock() = 0;
		void ShowFrozen();
		void ShowDead();
		int FrozenCount = 0;

		int AttackState = 0;
		int specialState = 0;
		virtual bool isAttackFrame() = 0;

		int leftTime = 0;
		int rightTime = 0;
		vector<int>skillsEffect_InFieldNumber;
		vector<pair<int, int>> hittedTable;
		vector<pair<int,boolean>> statusTable;
		vector<vector<int>> hittedLog;

		int KeyBoardInputTime;
		int CurrentTime;
		friend class SkillEffect;
	protected:
		CMovingBitmap photoSticker;
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
		bool isMovingDown;
		bool isMovingLeft;
		bool isMovingRight;
		bool isMovingUp;
		int walkedDistance;
		
		bool UnMovable=false;
		//for jump
		bool isJumpping;
		bool isRising;
		int JumpYposTemp;
		int YVelocity;
		int InitialVelocity;
		bool island;

		//Defense
		bool isDefense;
		int DefenseCount = 0;
		//Attack
		int LastAttackState = 0;
		int AttackCount = 0;
		int AttackLong = 0;
		int AttackAccumulator = 0;
		
		int KnockState = 0;
		int LastKnockState = 0;
		int KnockCount = 0;
		int DamageAccumulator = 0;
		int KnockSpeed;
		int skillSignal;

		virtual void CallSpecial() = 0;

		virtual bool AttackReach() = 0;

		CharacterAnimation Animation;
		string name;
		
		//Animation Properties
		int AnimationState;
		int AnimationCount = 0;
		//Jump
		int JumpCount = 0;
		int JumpCountTemp = 0;
		//Run
		int RunCount = 0;
		//Defense
		//Roll
		int RollCount = 0;
		//basic function
		
		
		time_t L_start, L_finish;
		time_t R_start, R_finish;
		void SetMoving();
	private:
		//CMovingBitmap shadow;
		//CMovingBitmap nameImg;
		
		//basic information
		int speed=2;
		boolean calculateDamage_Request;
		//hit box
		//int HitRectangle(int tx1, int ty1, int tx2, int ty2);
		virtual int HitRectangle(int tx1, int ty1, int tx2, int ty2) = 0;

		//keyInput
		int LastInputTime;
		int Diff;
		UINT LastInput;
	};
	
	class Freeze:public Character {
	public:
		//change to freeze
		Freeze(int num,int mapID);
		virtual void OnShow(vector<pair<int, int>>theOthersPosition ,int mainTime) override;
		virtual void OnMove() override;
		virtual void EnemyAiMode(int anotherCharacterPosX, int anotherCharacterPosY, int createdTimes) override;
		//for frozenPunch
		void ShowFrozenPunch();

		virtual void SetAttack(bool flag) override;
		virtual void ShowAttack() override;
		virtual void SetCharacter() override;
		virtual void SetSkill(int createdTimes) override;
		virtual void ClearSkill() override;
		virtual int HitEnemy(Character* enemy) override;
		virtual bool isAttackFrame() override;
		void EffectObjectAliveManager(int mainTime);
		
		~Freeze();
		//Knock
		virtual void ShowKnock() override;
		virtual void SetKnock(bool flag, int Dir, int AttState) override;

		//Movement
		virtual void ShowDefense() override;
		virtual void ShowRoll() override;
		//Special Attack;
		virtual void CallSpecial() override;

		int SpCount=0;
		void InitSpecialAttack();
		void ShowSpecialAttack();
		virtual void DetectSkillDamage(vector<pair<int, int>> theOthersPosition, int *n) override;
		void CallfrozenWaves();
		void CallfrozenPunchs();
		void CallfrozenStorms();
		void CallfrozenSwords();
		friend class CGameStateRun;

	protected:
		CMovingBitmap frozenWavesAnimation[2][6];
		CMovingBitmap frozenPunchsAnimation[2][8];
		CMovingBitmap frozenStormsAnimation[2][9];
		CMovingBitmap frozenSwordsAnimation[2][5];
		virtual bool AttackReach() override;

	private:
		virtual int HitRectangle(int tx1, int ty1, int tx2, int ty2) override;
		vector <SkillEffect*> frozenWaves, frozenSwords, frozenStorms;
	};
	
	class Henry :public Character {
	public:
		//change to freeze
		Henry(int num, int mapID);
		virtual void OnShow(vector<pair<int, int>>theOthersPosition, int mainTime) override;
		virtual void OnMove() override;
		virtual void EnemyAiMode(int anotherCharacterPosX, int anotherCharacterPosY , int createdTimes) override;
		virtual void SetAttack(bool flag) override;
		virtual void ShowAttack() override;
		virtual void SetCharacter() override;
		virtual void SetSkill(int createdTimes) override;
		virtual void ClearSkill() override;
		virtual int HitEnemy(Character* enemy) override;
		virtual bool isAttackFrame() override;
		void EffectObjectAliveManager(int mainTime);
		~Henry();
		//Knock
		virtual void ShowKnock() override;
		virtual void SetKnock(bool flag, int Dir, int AttState) override;

		//Movement
		virtual void ShowDefense() override;
		virtual void ShowRoll() override;
		//Special Attack;
		virtual void CallSpecial() override;

		int SpCount = 0;
		void InitSpecialAttack();
		void ShowSpecialAttack();

		virtual void DetectSkillDamage(vector<pair<int, int>> theOthersPosition, int *n) override;
		void CallairWave();
		void CallpierceArrow();
		void CallarrowRain();
		void CalldemonicSong();
	protected:
		CMovingBitmap airWaveAnimation[2][6];
		CMovingBitmap pierceArrowAnimation[2][4];
		CMovingBitmap arrowRainAnimation[2][8];
		CMovingBitmap demonicSongAnimation[2][4];
		virtual bool AttackReach() override;

	private:
		virtual int HitRectangle(int tx1, int ty1, int tx2, int ty2) override;
		vector <SkillEffect*> arrow, airwave, pierceArrow, arrowRain, demonicSong, downArrow, upArrow, downArrow2;
		vector <int>  frozenWaves_Duration;
	};
	
	class Woody :public Character {
	public:
		//change to freeze
		Woody(int num, int mapID);
		virtual void OnShow(vector<pair<int, int>>theOthersPosition, int mainTime) override;
		virtual void OnMove() override;
		virtual void EnemyAiMode(int anotherCharacterPosX, int anotherCharacterPosY,int createdTimes) override;
		virtual void SetAttack(bool flag) override;
		virtual void ShowAttack() override;
		virtual void SetCharacter() override;
		virtual void SetSkill(int createdTimes) override;
		virtual void ClearSkill() override;
		virtual int HitEnemy(Character* enemy) override;
		virtual bool isAttackFrame() override;
		void EffectObjectAliveManager(int mainTime);
		~Woody();
		//Knock
		virtual void ShowKnock() override;
		virtual void SetKnock(bool flag, int Dir, int AttState) override;

		//Movement
		virtual void ShowDefense() override;
		virtual void ShowRoll() override;
		//Special Attack;
		virtual void CallSpecial() override;

		int SpCount = 0;
		void InitSpecialAttack();
		void ShowSpecialAttack();

		virtual void DetectSkillDamage(vector<pair<int, int>> theOthersPosition, int *n) override;
		void CallEnergyBlast();
		void CallFootKnife();
		void CallDemonFoot();
		void CallTank();
		void CallTeleportation();

	protected:
		CMovingBitmap energyBlastAnimation[2][12];
		CMovingBitmap footKnifeAnimation[2][7];
		CMovingBitmap demonFootAnimation[2][11];
		CMovingBitmap tankAnimation[2][7];
		CMovingBitmap teleportationAnimation[2][9];
		virtual bool AttackReach() override;

	private:
		virtual int HitRectangle(int tx1, int ty1, int tx2, int ty2) override;
		vector <SkillEffect*> energyBlast, energyBlast2;
		vector <int>  frozenWaves_Duration;
	};
}