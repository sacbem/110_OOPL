#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Enemy.h"
#include "Character.h"

namespace game_framework {
	
	Character::Character() {
		Initialize();
	}

	Character::~Character() {

	}

	int Character::HitEnemy(Enemy *enemy) {
		DelayCounter--;

		if(DelayCounter<0){
			DelayCounter = Delay;
			return HitRectangle(enemy->GetX1()+20, enemy->GetY1()+20, enemy->GetX2()-20, enemy->GetY2()-20);
		}
		else {
			return 0;
		}
	}

	int Character::HitRectangle(int tx1, int ty1, int tx2, int ty2) {
		int x1 = xPos;
		int y1 = yPos;
		int x2 = x1 + Animation.Width();
		int y2 = y1 + Animation.Height();


		if (tx2 >= x1 && ty2 >= y1 && tx1 <= x2 && ty1 <= y2) {
			return 1;
		}
		else {
			return 0;
		}
	}

	bool Character::GetAlive() {
		return isAlive;
	}

	int Character::GetX1() {
		return xPos;
	}

	int Character::GetX2() {
		return xPos + Animation.Width();
	}

	int Character::GetY1() {
		return yPos;
	}

	int Character::GetY2() {
		return yPos + Animation.Height();
	}

	int Character::GetHealth() {
		return HealthPoint;
	}

	int Character::GetDir() {
		return direction;
	}

	void Character::Initialize() {
		DelayCounter = 0;
		Delay = 10;

		Animation.SetDelayCount(5);
		AnimationReverse.SetDelayCount(5);
		Walking.SetDelayCount(5);
		WalkingReverse.SetDelayCount(5);
		Attacking.SetDelayCount(5);
		AttackingReverse.SetDelayCount(5);
		Jump.SetDelayCount(3);
		JumpReverse.SetDelayCount(3);
		Running.SetDelayCount(5);
		RunningReverse.SetDelayCount(5);
		Knock.SetDelayCount(5);
		KnockBack.SetDelayCount(5);
		KnockReverse.SetDelayCount(5);
		KnockBackReverse.SetDelayCount(5);
		Getup.SetDelayCount(5);
		GetupReverse.SetDelayCount(5);

		xPos = 200;
		yPos = 200;
		InitialVelocity = 10;
		YVelocity = InitialVelocity;
		isGettingUp = isGettingHit = isDefending = isAttacking = isJumpping = isWalking = isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;
		direction = 1;

		HealthPoint = 1000;
		AttackPoint = 10;
		DefencePoint = 5;
	}

	void Character::LoadBitmap() {
		//Normal
		Animation.AddBitmap(IDB_PLAYER1_NORMAL4, RGB(0, 0, 0));
		Animation.AddBitmap(IDB_PLAYER1_NORMAL3, RGB(0, 0, 0));
		Animation.AddBitmap(IDB_PLAYER1_NORMAL2, RGB(0, 0, 0));
		Animation.AddBitmap(IDB_PLAYER1_NORMAL1, RGB(0, 0, 0));

		//Normal Reverse
		AnimationReverse.AddBitmap(IDB_PLAYER1_NORMAL4_REVERSE, RGB(0, 0, 0));
		AnimationReverse.AddBitmap(IDB_PLAYER1_NORMAL3_REVERSE, RGB(0, 0, 0));
		AnimationReverse.AddBitmap(IDB_PLAYER1_NORMAL2_REVERSE, RGB(0, 0, 0));
		AnimationReverse.AddBitmap(IDB_PLAYER1_NORMAL1_REVERSE, RGB(0, 0, 0));

		//Walking
		Walking.AddBitmap(IDB_PLAYER1_WALK1, RGB(0, 0, 0));
		Walking.AddBitmap(IDB_PLAYER1_WALK2, RGB(0, 0, 0));
		Walking.AddBitmap(IDB_PLAYER1_WALK3, RGB(0, 0, 0));
		Walking.AddBitmap(IDB_PLAYER1_WALK4, RGB(0, 0, 0));
		Walking.AddBitmap(IDB_PLAYER1_WALK3, RGB(0, 0, 0));
		Walking.AddBitmap(IDB_PLAYER1_WALK2, RGB(0, 0, 0));
		Walking.AddBitmap(IDB_PLAYER1_WALK1, RGB(0, 0, 0));

		//Walking Reverse
		WalkingReverse.AddBitmap(IDB_PLAYER1_WALK1_REVERSE, RGB(0, 0, 0));
		WalkingReverse.AddBitmap(IDB_PLAYER1_WALK2_REVERSE, RGB(0, 0, 0));
		WalkingReverse.AddBitmap(IDB_PLAYER1_WALK3_REVERSE, RGB(0, 0, 0));
		WalkingReverse.AddBitmap(IDB_PLAYER1_WALK4_REVERSE, RGB(0, 0, 0));
		WalkingReverse.AddBitmap(IDB_PLAYER1_WALK3_REVERSE, RGB(0, 0, 0));
		WalkingReverse.AddBitmap(IDB_PLAYER1_WALK2_REVERSE, RGB(0, 0, 0));
		WalkingReverse.AddBitmap(IDB_PLAYER1_WALK1_REVERSE, RGB(0, 0, 0));

		//Attack
		Attacking.AddBitmap(IDB_PLAYER1_ATTACK6, RGB(0, 0, 0));
		Attacking.AddBitmap(IDB_PLAYER1_ATTACK5, RGB(0, 0, 0));
		Attacking.AddBitmap(IDB_PLAYER1_ATTACK4, RGB(0, 0, 0));
		Attacking.AddBitmap(IDB_PLAYER1_ATTACK3, RGB(0, 0, 0));
		Attacking.AddBitmap(IDB_PLAYER1_ATTACK2, RGB(0, 0, 0));
		Attacking.AddBitmap(IDB_PLAYER1_ATTACK1, RGB(0, 0, 0));

		//Attack Reverse
		AttackingReverse.AddBitmap(IDB_PLAYER1_ATTACK6_REVERSE, RGB(0, 0, 0));
		AttackingReverse.AddBitmap(IDB_PLAYER1_ATTACK5_REVERSE, RGB(0, 0, 0));
		AttackingReverse.AddBitmap(IDB_PLAYER1_ATTACK4_REVERSE, RGB(0, 0, 0));
		AttackingReverse.AddBitmap(IDB_PLAYER1_ATTACK3_REVERSE, RGB(0, 0, 0));
		AttackingReverse.AddBitmap(IDB_PLAYER1_ATTACK2_REVERSE, RGB(0, 0, 0));
		AttackingReverse.AddBitmap(IDB_PLAYER1_ATTACK1_REVERSE, RGB(0, 0, 0));

		//Jump
		Jump.AddBitmap(IDB_PLAYER1_JUMP1, RGB(0, 0, 0));
		Jump.AddBitmap(IDB_PLAYER1_JUMP2, RGB(0, 0, 0));
		Jump.AddBitmap(IDB_PLAYER1_JUMP1, RGB(0, 0, 0));
		Jump.AddBitmap(IDB_PLAYER1_JUMP3, RGB(0, 0, 0));
		Jump.AddBitmap(IDB_PLAYER1_JUMP3, RGB(0, 0, 0));
		Jump.AddBitmap(IDB_PLAYER1_JUMP3, RGB(0, 0, 0));
		Jump.AddBitmap(IDB_PLAYER1_JUMP3, RGB(0, 0, 0));
		Jump.AddBitmap(IDB_PLAYER1_JUMP3, RGB(0, 0, 0));
		Jump.AddBitmap(IDB_PLAYER1_JUMP3, RGB(0, 0, 0));

		//Jump Reverse
		JumpReverse.AddBitmap(IDB_PLAYER1_JUMP1_REVERSE, RGB(0, 0, 0));
		JumpReverse.AddBitmap(IDB_PLAYER1_JUMP2_REVERSE, RGB(0, 0, 0));
		JumpReverse.AddBitmap(IDB_PLAYER1_JUMP1_REVERSE, RGB(0, 0, 0));
		JumpReverse.AddBitmap(IDB_PLAYER1_JUMP3_REVERSE, RGB(0, 0, 0));
		JumpReverse.AddBitmap(IDB_PLAYER1_JUMP3_REVERSE, RGB(0, 0, 0));
		JumpReverse.AddBitmap(IDB_PLAYER1_JUMP3_REVERSE, RGB(0, 0, 0));
		JumpReverse.AddBitmap(IDB_PLAYER1_JUMP3_REVERSE, RGB(0, 0, 0));
		JumpReverse.AddBitmap(IDB_PLAYER1_JUMP3_REVERSE, RGB(0, 0, 0));
		JumpReverse.AddBitmap(IDB_PLAYER1_JUMP3_REVERSE, RGB(0, 0, 0));

		//Running
		Running.AddBitmap(IDB_PLAYER1_RUN2, RGB(0, 0, 0));
		Running.AddBitmap(IDB_PLAYER1_RUN3, RGB(0, 0, 0));
		Running.AddBitmap(IDB_PLAYER1_RUN2, RGB(0, 0, 0));
		Running.AddBitmap(IDB_PLAYER1_RUN1, RGB(0, 0, 0));

		//Running Reverse
		RunningReverse.AddBitmap(IDB_PLAYER1_RUN2_REVERSE, RGB(0, 0, 0));
		RunningReverse.AddBitmap(IDB_PLAYER1_RUN3_REVERSE, RGB(0, 0, 0));
		RunningReverse.AddBitmap(IDB_PLAYER1_RUN2_REVERSE, RGB(0, 0, 0));
		RunningReverse.AddBitmap(IDB_PLAYER1_RUN1_REVERSE, RGB(0, 0, 0));
		
		//Knock
		Knock.AddBitmap(IDB_PLAYER1_KNOCK5, RGB(0, 0, 0));
		Knock.AddBitmap(IDB_PLAYER1_KNOCK5, RGB(0, 0, 0));
		Knock.AddBitmap(IDB_PLAYER1_KNOCK4, RGB(0, 0, 0));
		Knock.AddBitmap(IDB_PLAYER1_KNOCK3, RGB(0, 0, 0));
		Knock.AddBitmap(IDB_PLAYER1_KNOCK2, RGB(0, 0, 0));
		Knock.AddBitmap(IDB_PLAYER1_KNOCK1, RGB(0, 0, 0));

		KnockReverse.AddBitmap(IDB_PLAYER1_KNOCK5_REVERSE, RGB(0, 0, 0));
		KnockReverse.AddBitmap(IDB_PLAYER1_KNOCK5_REVERSE, RGB(0, 0, 0));
		KnockReverse.AddBitmap(IDB_PLAYER1_KNOCK4_REVERSE, RGB(0, 0, 0));
		KnockReverse.AddBitmap(IDB_PLAYER1_KNOCK3_REVERSE, RGB(0, 0, 0));
		KnockReverse.AddBitmap(IDB_PLAYER1_KNOCK2_REVERSE, RGB(0, 0, 0));
		KnockReverse.AddBitmap(IDB_PLAYER1_KNOCK1_REVERSE, RGB(0, 0, 0));

		KnockBack.AddBitmap(IDB_PLAYER1_KNOCKBACK5, RGB(0, 0, 0));
		KnockBack.AddBitmap(IDB_PLAYER1_KNOCKBACK5, RGB(0, 0, 0));
		KnockBack.AddBitmap(IDB_PLAYER1_KNOCKBACK4, RGB(0, 0, 0));
		KnockBack.AddBitmap(IDB_PLAYER1_KNOCKBACK3, RGB(0, 0, 0));
		KnockBack.AddBitmap(IDB_PLAYER1_KNOCKBACK2, RGB(0, 0, 0));
		KnockBack.AddBitmap(IDB_PLAYER1_KNOCKBACK1, RGB(0, 0, 0));

		KnockBackReverse.AddBitmap(IDB_PLAYER1_KNOCKBACK5_REVERSE, RGB(0, 0, 0));
		KnockBackReverse.AddBitmap(IDB_PLAYER1_KNOCKBACK5_REVERSE, RGB(0, 0, 0));
		KnockBackReverse.AddBitmap(IDB_PLAYER1_KNOCKBACK4_REVERSE, RGB(0, 0, 0));
		KnockBackReverse.AddBitmap(IDB_PLAYER1_KNOCKBACK3_REVERSE, RGB(0, 0, 0));
		KnockBackReverse.AddBitmap(IDB_PLAYER1_KNOCKBACK2_REVERSE, RGB(0, 0, 0));
		KnockBackReverse.AddBitmap(IDB_PLAYER1_KNOCKBACK1_REVERSE, RGB(0, 0, 0));

		//getup
		Getup.AddBitmap(IDB_PLAYER1_GETUP2, RGB(0, 0, 0));
		Getup.AddBitmap(IDB_PLAYER1_GETUP2, RGB(0, 0, 0));
		Getup.AddBitmap(IDB_PLAYER1_GETUP1, RGB(0, 0, 0));
		Getup.AddBitmap(IDB_PLAYER1_KNOCK5, RGB(0, 0, 0));

		GetupReverse.AddBitmap(IDB_PLAYER1_GETUP2_REVERSE, RGB(0, 0, 0));
		GetupReverse.AddBitmap(IDB_PLAYER1_GETUP2_REVERSE, RGB(0, 0, 0));
		GetupReverse.AddBitmap(IDB_PLAYER1_GETUP1_REVERSE, RGB(0, 0, 0));
		GetupReverse.AddBitmap(IDB_PLAYER1_KNOCK5_REVERSE, RGB(0, 0, 0));

		GetupBack.AddBitmap(IDB_PLAYER1_GETUP2, RGB(0, 0, 0));
		GetupBack.AddBitmap(IDB_PLAYER1_GETUP2, RGB(0, 0, 0));
		GetupBack.AddBitmap(IDB_PLAYER1_GETUPBACK1, RGB(0, 0, 0));
		GetupBack.AddBitmap(IDB_PLAYER1_KNOCKBACK5, RGB(0, 0, 0));

		GetupBackReverse.AddBitmap(IDB_PLAYER1_GETUP2_REVERSE, RGB(0, 0, 0));
		GetupBackReverse.AddBitmap(IDB_PLAYER1_GETUP2_REVERSE, RGB(0, 0, 0));
		GetupBackReverse.AddBitmap(IDB_PLAYER1_GETUP1_REVERSE, RGB(0, 0, 0));
		GetupBackReverse.AddBitmap(IDB_PLAYER1_KNOCKBACK5_REVERSE, RGB(0, 0, 0));
	}

	void Character::OnMove() {
		int speed = 5;
		if (isRunning == true) {
			speed = 10;
		}
		Animation.OnMove();
		AnimationReverse.OnMove();

		if (isRunning) {
			Running.OnMove();
			RunningReverse.OnMove();
		}

		if (isAttacking) {
			Attacking.OnMove();
			AttackingReverse.OnMove();
		}

		if (isGettingHit) {
			Knock.OnMove();
		}

		if (isGettingUp) {
			Getup.OnMove();
		}

		if (isJumpping || isGettingHit) {
			Jump.OnMove();
			JumpReverse.OnMove();
			if (isRising) {
				if (YVelocity > 0) {
					yPos -= YVelocity;
					YVelocity--;
				}
				else {
					isRising = false;
					YVelocity = 1;
				}
			}
			else if (!isRising) {
				if (yPos < JumpYposTemp - 1) {
					yPos += YVelocity;
					YVelocity++;
				}
				else {
					yPos = JumpYposTemp - 1;
					YVelocity = InitialVelocity;
					isJumpping = false;
					if (isGettingHit == true) {
						isGettingHit = false;
						SetGettingUp(true);
					}
				}
			}
		}

		if (isMovingLeft) {
			xPos -= speed;
			isWalking = true;
			direction = 0;
		}
		if (isMovingRight) {
			xPos += speed;
			isWalking = true;
			direction = 1;
		}
		if (isMovingUp && !isJumpping) {
			yPos -= speed;
			isWalking = true;
		}
		if (isMovingDown && !isJumpping) {
			yPos += speed;
			isWalking = true;
		}
		if (isWalking) {
			Walking.OnMove();
			WalkingReverse.OnMove();
		}
		if (isMovingLeft==false && isMovingRight == false && isMovingUp == false && isMovingDown == false) {
			isWalking = false;
		}
		if (isGettingHit) {
			if (hitDirection) {
				xPos += 7;
			}
			else if(!hitDirection){
				xPos -= 7;
			}
		}
	}

	void Character::SetMovingDown(bool flag) {
		isMovingDown = flag;
	}

	void Character::SetMovingUp(bool flag) {
		isMovingUp = flag;
	}

	void Character::SetMovingLeft(bool flag) {
		isMovingLeft = flag;
	}

	void Character::SetMovingRight(bool flag) {
		isMovingRight = flag;
	}

	void Character::SetGettingUp(bool flag) {
		isGettingUp = flag;
		Getup.Reset();
	}

	void Character::SetWalking(bool flag) {
		isWalking = flag;
	}

	void Character::SetAttack(bool flag) {
		isAttacking = flag;
		Attacking.Reset();
		AttackingReverse.Reset();
	}

	void Character::SetDefense(bool flag) {
		isDefending = flag;
	}

	void Character::SetRunning(bool flag) {
		isRunning = flag;
		Running.Reset();
		RunningReverse.Reset();
	}

	void Character::SetJump(bool flag) {
		if (!isJumpping) {
			Jump.Reset();
			JumpReverse.Reset();
			isJumpping = flag;
			YVelocity = 10;
			JumpYposTemp = yPos+1;
			isRising = true;
		}
	}

	void Character::SetGettingHit(bool flag, int Dir) {
		if (isGettingHit == false) {
			//reset animation
			Knock.Reset();
			KnockReverse.Reset();
			KnockBack.Reset();
			KnockBackReverse.Reset();
			//give
			isGettingHit = flag;
			hitDirection = Dir;
			YVelocity = 10;
			JumpYposTemp = yPos + 1;
			isRising = true;
		}
	}

	void Character::SetAlive(bool flag) {
		isAlive = flag;
	}

	void Character::SetXY(int X, int Y) {
		xPos = X;
		yPos = Y;
	}

	void Character::ShowNormal(int Dir) {
		if (Dir == 0) {
			AnimationReverse.SetTopLeft(xPos, yPos);
			AnimationReverse.OnShow();
		}
		else if (Dir == 1) {
			//right
			Animation.SetTopLeft(xPos, yPos);
			Animation.OnShow();
		}
	}

	void Character::ShowWalking(int Dir) {
		if (Dir == 0) {
			//left
			WalkingReverse.SetTopLeft(xPos, yPos);
			WalkingReverse.OnShow();
		}
		else if (Dir == 1) {
			//right
			Walking.SetTopLeft(xPos, yPos);
			Walking.OnShow();
		}
	}

	void Character::ShowAttacking(int Dir) {
		if (Dir == 0) {
			//left
			AttackingReverse.SetTopLeft(xPos, yPos);
			AttackingReverse.OnShow();
		}
		else if (Dir == 1) {
			//right
			Attacking.SetTopLeft(xPos, yPos);
			Attacking.OnShow();
		}
	}

	void Character::ShowJump(int Dir) {
		if (Dir == 0) {
			//left
			JumpReverse.SetTopLeft(xPos, yPos);
			JumpReverse.OnShow();
		}
		else if (Dir == 1) {
			//right
			Jump.SetTopLeft(xPos, yPos);
			Jump.OnShow();
		}
	}

	void Character::ShowRun(int Dir) {
		if (Dir == 0) {
			//left
			RunningReverse.SetTopLeft(xPos, yPos);
			RunningReverse.OnShow();
		}
		else if (Dir == 1) {
			//right
			Running.SetTopLeft(xPos, yPos);
			Running.OnShow();
		}
	}

	void Character::ShowKnock(int Dir, int HitDir) {
		if (Dir == 0) {
			if (HitDir == 1) {
				KnockBackReverse.SetTopLeft(xPos, yPos);
				KnockBackReverse.OnShow();
				if (KnockBackReverse.IsFinalBitmap()) {
					isGettingHit = false;
				}
			}
			else if (HitDir == 0) {
				KnockReverse.SetTopLeft(xPos, yPos);
				KnockReverse.OnShow();
				if (KnockReverse.IsFinalBitmap()) {
					isGettingHit = false;
				}
			}
		}
		else if (Dir == 1) {
			if (HitDir == 1) {
				KnockBack.SetTopLeft(xPos, yPos);
				KnockBack.OnShow();
				if (KnockBack.IsFinalBitmap()) {
					isGettingHit = false;
				}
			}
			else if (HitDir == 0) {
				Knock.SetTopLeft(xPos, yPos);
				Knock.OnShow();
				if (Knock.IsFinalBitmap()) {
					isGettingHit = false;
				}
			}
		}
	}

	void Character::ShowGettingUP(int Dir) {
		if (Dir == 0) {
			//left
			KnockReverse.SetTopLeft(xPos, yPos);
			KnockReverse.OnShow();
		}
		else if (Dir == 1) {
			//right
			Getup.SetTopLeft(xPos, yPos);
			Getup.OnShow();
			if (Getup.IsFinalBitmap()) {
				isGettingUp = false;
			}
		}
	}

	void Character::OnShow() {
		if (isJumpping == true) {
			ShowJump(direction);
		}
		else if (isAttacking == true || (isAttacking == true && isWalking == true)) {
			ShowAttacking(direction);
		}
		else if (isRunning == true && isAttacking == false) {
			ShowRun(direction);
		}
		else if (isWalking == true && isAttacking == false) {
			ShowWalking(direction);
		}
		else if (isGettingHit == true) {
			ShowKnock(direction, hitDirection);
		}
		else if (isGettingUp) {
			ShowGettingUP(direction);
		}
		else {
			//Normal Animation
			ShowNormal(direction);
		}
	}
}