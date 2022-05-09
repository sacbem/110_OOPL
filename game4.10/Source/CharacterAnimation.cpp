#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CharacterAnimation.h"
namespace game_framework {
	CharacterAnimation::CharacterAnimation() {

	}
	void CharacterAnimation::LoadWoody() {
		//normal state right
		Normal[0].AddBitmap(FIRZEN_NORMAL4, RGB(0, 0, 0));
		Normal[0].AddBitmap(FIRZEN_NORMAL3, RGB(0, 0, 0));
		Normal[0].AddBitmap(FIRZEN_NORMAL2, RGB(0, 0, 0));
		Normal[0].AddBitmap(FIRZEN_NORMAL1, RGB(0, 0, 0));
		//normal state left
		Normal[1].AddBitmap(FIRZEN_NORMAL4_REVERSE, RGB(0, 0, 0));
		Normal[1].AddBitmap(FIRZEN_NORMAL3_REVERSE, RGB(0, 0, 0));
		Normal[1].AddBitmap(FIRZEN_NORMAL2_REVERSE, RGB(0, 0, 0));
		Normal[1].AddBitmap(FIRZEN_NORMAL1_REVERSE, RGB(0, 0, 0));
		//walk right
		Walk[0].AddBitmap(FIRZEN_WALK1, RGB(0, 0, 0));
		Walk[0].AddBitmap(FIRZEN_WALK2, RGB(0, 0, 0));
		Walk[0].AddBitmap(FIRZEN_WALK3, RGB(0, 0, 0));
		Walk[0].AddBitmap(FIRZEN_WALK4, RGB(0, 0, 0));
		Walk[0].AddBitmap(FIRZEN_WALK3, RGB(0, 0, 0));
		Walk[0].AddBitmap(FIRZEN_WALK2, RGB(0, 0, 0));
		//walk left
		Walk[1].AddBitmap(FIRZEN_WALK1_REVERSE, RGB(0, 0, 0));
		Walk[1].AddBitmap(FIRZEN_WALK2_REVERSE, RGB(0, 0, 0));
		Walk[1].AddBitmap(FIRZEN_WALK3_REVERSE, RGB(0, 0, 0));
		Walk[1].AddBitmap(FIRZEN_WALK4_REVERSE, RGB(0, 0, 0));
		Walk[1].AddBitmap(FIRZEN_WALK3_REVERSE, RGB(0, 0, 0));
		Walk[1].AddBitmap(FIRZEN_WALK2_REVERSE, RGB(0, 0, 0));

		//Run right
		Run[0].AddBitmap(FIRZEN_RUN1, RGB(0, 0, 0));
		Run[0].AddBitmap(FIRZEN_RUN2, RGB(0, 0, 0));
		Run[0].AddBitmap(FIRZEN_RUN3, RGB(0, 0, 0));
		Run[0].AddBitmap(FIRZEN_RUN2, RGB(0, 0, 0));
		//run left
		Run[1].AddBitmap(FIRZEN_RUN1_REVERSE, RGB(0, 0, 0));
		Run[1].AddBitmap(FIRZEN_RUN2_REVERSE, RGB(0, 0, 0));
		Run[1].AddBitmap(FIRZEN_RUN3_REVERSE, RGB(0, 0, 0));
		Run[1].AddBitmap(FIRZEN_RUN2_REVERSE, RGB(0, 0, 0));

		RunStop[0].LoadBitmapA(".\\res\\Firzen\\Firzen_1\\firzen_1_19.bmp", RGB(0, 0, 0));
		RunStop[1].LoadBitmapA(".\\res\\Firzen\\Firzen_1_reverse\\firzen_1_reverse_10.bmp", RGB(0, 0, 0));

		//jump
		Jump[0][0].LoadBitmapA(".\\res\\Firzen\\Firzen_0\\firzen_0_60.bmp", RGB(0, 0, 0));
		Jump[0][1].LoadBitmapA(".\\res\\Firzen\\Firzen_0\\firzen_0_61.bmp", RGB(0, 0, 0));
		Jump[0][2].LoadBitmapA(".\\res\\Firzen\\Firzen_0\\firzen_0_62.bmp", RGB(0, 0, 0));
		Jump[0][3].LoadBitmapA(".\\res\\Firzen\\Firzen_0\\firzen_0_63.bmp", RGB(0, 0, 0));

		Jump[1][0].LoadBitmapA(".\\res\\Firzen\\Firzen_0_reverse\\firzen_0_reverse_69.bmp", RGB(0, 0, 0));
		Jump[1][1].LoadBitmapA(".\\res\\Firzen\\Firzen_0_reverse\\firzen_0_reverse_68.bmp", RGB(0, 0, 0));
		Jump[1][2].LoadBitmapA(".\\res\\Firzen\\Firzen_0_reverse\\firzen_0_reverse_67.bmp", RGB(0, 0, 0));
		Jump[1][3].LoadBitmapA(".\\res\\Firzen\\Firzen_0_reverse\\firzen_0_reverse_66.bmp", RGB(0, 0, 0));

		Defense[0][0].LoadBitmapA(".\\res\\Firzen\\Firzen_0\\firzen_0_56.bmp", RGB(0, 0, 0));
		Defense[0][1].LoadBitmapA(".\\res\\Firzen\\Firzen_0\\firzen_0_57.bmp", RGB(0, 0, 0));
		Defense[1][0].LoadBitmapA(".\\res\\Firzen\\Firzen_0_reverse\\firzen_0_reverse_53.bmp", RGB(0, 0, 0));
		Defense[1][1].LoadBitmapA(".\\res\\Firzen\\Firzen_0_reverse\\firzen_0_reverse_52.bmp", RGB(0, 0, 0));

		Roll[0][0].LoadBitmapA(".\\res\\Firzen\\Firzen_0\\firzen_0_58.bmp", RGB(0, 0, 0));
		Roll[0][1].LoadBitmapA(".\\res\\Firzen\\Firzen_0\\firzen_0_59.bmp", RGB(0, 0, 0));
		Roll[0][2].LoadBitmapA(".\\res\\Firzen\\Firzen_0\\firzen_0_69.bmp", RGB(0, 0, 0));
		Roll[1][0].LoadBitmapA(".\\res\\Firzen\\Firzen_0_reverse\\firzen_0_reverse_51.bmp", RGB(0, 0, 0));
		Roll[1][1].LoadBitmapA(".\\res\\Firzen\\Firzen_0_reverse\\firzen_0_reverse_50.bmp", RGB(0, 0, 0));
		Roll[1][2].LoadBitmapA(".\\res\\Firzen\\Firzen_0_reverse\\firzen_0_reverse_60.bmp", RGB(0, 0, 0));
	}
	
	void CharacterAnimation::LoadFreeze() {
		//normal state right
		Normal[0].AddBitmap(FREEZE_NORMAL4, RGB(0, 0, 0));
		Normal[0].AddBitmap(FREEZE_NORMAL3, RGB(0, 0, 0));
		Normal[0].AddBitmap(FREEZE_NORMAL2, RGB(0, 0, 0));
		Normal[0].AddBitmap(FREEZE_NORMAL1, RGB(0, 0, 0));
		//normal state left
		Normal[1].AddBitmap(FREEZE_NORMAL4_REVERSE, RGB(0, 0, 0));
		Normal[1].AddBitmap(FREEZE_NORMAL3_REVERSE, RGB(0, 0, 0));
		Normal[1].AddBitmap(FREEZE_NORMAL2_REVERSE, RGB(0, 0, 0));
		Normal[1].AddBitmap(FREEZE_NORMAL1_REVERSE, RGB(0, 0, 0));
		//walk right
		Walk[0].AddBitmap(FREEZE_WALK1, RGB(0, 0, 0));
		Walk[0].AddBitmap(FREEZE_WALK2, RGB(0, 0, 0));
		Walk[0].AddBitmap(FREEZE_WALK3, RGB(0, 0, 0));
		Walk[0].AddBitmap(FREEZE_WALK4, RGB(0, 0, 0));
		Walk[0].AddBitmap(FREEZE_WALK3, RGB(0, 0, 0));
		Walk[0].AddBitmap(FREEZE_WALK2, RGB(0, 0, 0));
		//walk left
		Walk[1].AddBitmap(FREEZE_WALK1_REVERSE, RGB(0, 0, 0));
		Walk[1].AddBitmap(FREEZE_WALK2_REVERSE, RGB(0, 0, 0));
		Walk[1].AddBitmap(FREEZE_WALK3_REVERSE, RGB(0, 0, 0));
		Walk[1].AddBitmap(FREEZE_WALK4_REVERSE, RGB(0, 0, 0));
		Walk[1].AddBitmap(FREEZE_WALK3_REVERSE, RGB(0, 0, 0));
		Walk[1].AddBitmap(FREEZE_WALK2_REVERSE, RGB(0, 0, 0));

		//Run right
		Run[0].AddBitmap(FREEZE_RUN1, RGB(0, 0, 0));
		Run[0].AddBitmap(FREEZE_RUN2, RGB(0, 0, 0));
		Run[0].AddBitmap(FREEZE_RUN3, RGB(0, 0, 0));
		Run[0].AddBitmap(FREEZE_RUN2, RGB(0, 0, 0));
		//run left
		Run[1].AddBitmap(FREEZE_RUN1_REVERSE, RGB(0, 0, 0));
		Run[1].AddBitmap(FREEZE_RUN2_REVERSE, RGB(0, 0, 0));
		Run[1].AddBitmap(FREEZE_RUN3_REVERSE, RGB(0, 0, 0));
		Run[1].AddBitmap(FREEZE_RUN2_REVERSE, RGB(0, 0, 0));

		RunStop[0].LoadBitmapA(".\\res\\Freeze\\Freeze_1\\freeze_1_44.bmp", RGB(0, 0, 0));
		RunStop[1].LoadBitmapA(".\\res\\Freeze\\Freeze_1_reverse\\freeze_1_reverse_45.bmp", RGB(0, 0, 0));

		//jump
		Jump[0][0].LoadBitmapA(".\\res\\Freeze\\Freeze_0\\freeze_0_60.bmp", RGB(0, 0, 0));
		Jump[0][1].LoadBitmapA(".\\res\\Freeze\\Freeze_0\\freeze_0_61.bmp", RGB(0, 0, 0));
		Jump[0][2].LoadBitmapA(".\\res\\Freeze\\Freeze_0\\freeze_0_62.bmp", RGB(0, 0, 0));
		Jump[0][3].LoadBitmapA(".\\res\\Freeze\\Freeze_0\\freeze_0_63.bmp", RGB(0, 0, 0));

		Jump[1][0].LoadBitmapA(".\\res\\Freeze\\Freeze_0_reverse\\freeze_0_reverse_69.bmp", RGB(0, 0, 0));
		Jump[1][1].LoadBitmapA(".\\res\\Freeze\\Freeze_0_reverse\\freeze_0_reverse_68.bmp", RGB(0, 0, 0));
		Jump[1][2].LoadBitmapA(".\\res\\Freeze\\Freeze_0_reverse\\freeze_0_reverse_67.bmp", RGB(0, 0, 0));
		Jump[1][3].LoadBitmapA(".\\res\\Freeze\\Freeze_0_reverse\\freeze_0_reverse_66.bmp", RGB(0, 0, 0));

		Defense[0][0].LoadBitmapA(".\\res\\Freeze\\Freeze_0\\freeze_0_56.bmp", RGB(0, 0, 0));
		Defense[0][1].LoadBitmapA(".\\res\\Freeze\\Freeze_0\\freeze_0_57.bmp", RGB(0, 0, 0));
		Defense[1][0].LoadBitmapA(".\\res\\Freeze\\Freeze_0_reverse\\freeze_0_reverse_53.bmp", RGB(0, 0, 0));
		Defense[1][1].LoadBitmapA(".\\res\\Freeze\\Freeze_0_reverse\\freeze_0_reverse_52.bmp", RGB(0, 0, 0));

		Roll[0][0].LoadBitmapA(".\\res\\Freeze\\Freeze_0\\freeze_0_58.bmp", RGB(0, 0, 0));
		Roll[0][1].LoadBitmapA(".\\res\\Freeze\\Freeze_0\\freeze_0_59.bmp", RGB(0, 0, 0));
		Roll[0][2].LoadBitmapA(".\\res\\Freeze\\Freeze_0\\freeze_0_69.bmp", RGB(0, 0, 0));
		Roll[1][0].LoadBitmapA(".\\res\\Freeze\\Freeze_0_reverse\\freeze_0_reverse_51.bmp", RGB(0, 0, 0));
		Roll[1][1].LoadBitmapA(".\\res\\Freeze\\Freeze_0_reverse\\freeze_0_reverse_50.bmp", RGB(0, 0, 0));
		Roll[1][2].LoadBitmapA(".\\res\\Freeze\\Freeze_0_reverse\\freeze_0_reverse_60.bmp", RGB(0, 0, 0));
		//Attack
		NormalAttack1[0][0].LoadBitmap(".\\res\\Freeze\\Freeze_0\\freeze_0_10.bmp", RGB(0, 0, 0));
		NormalAttack1[0][1].LoadBitmap(".\\res\\Freeze\\Freeze_0\\freeze_0_11.bmp", RGB(0, 0, 0));
		NormalAttack1[1][0].LoadBitmap(".\\res\\Freeze\\Freeze_0_reverse\\freeze_0_reverse_19.bmp", RGB(0, 0, 0));
		NormalAttack1[1][1].LoadBitmap(".\\res\\Freeze\\Freeze_0_reverse\\freeze_0_reverse_18.bmp", RGB(0, 0, 0));

		NormalAttack2[0][0].LoadBitmap(".\\res\\Freeze\\Freeze_0\\freeze_0_12.bmp", RGB(0, 0, 0));
		NormalAttack2[0][1].LoadBitmap(".\\res\\Freeze\\Freeze_0\\freeze_0_13.bmp", RGB(0, 0, 0));
		NormalAttack2[1][0].LoadBitmap(".\\res\\Freeze\\Freeze_0_reverse\\freeze_0_reverse_17.bmp", RGB(0, 0, 0));
		NormalAttack2[1][1].LoadBitmap(".\\res\\Freeze\\Freeze_0_reverse\\freeze_0_reverse_16.bmp", RGB(0, 0, 0));

		NormalAttack3[0][0].LoadBitmap(".\\res\\Freeze\\Freeze_0\\freeze_0_17.bmp", RGB(0, 0, 0));
		NormalAttack3[0][1].LoadBitmap(".\\res\\Freeze\\Freeze_0\\freeze_0_18.bmp", RGB(0, 0, 0));
		NormalAttack3[0][2].LoadBitmap(".\\res\\Freeze\\Freeze_0\\freeze_0_19.bmp", RGB(0, 0, 0));
		NormalAttack3[1][0].LoadBitmap(".\\res\\Freeze\\Freeze_0_reverse\\freeze_0_reverse_12.bmp", RGB(0, 0, 0));
		NormalAttack3[1][1].LoadBitmap(".\\res\\Freeze\\Freeze_0_reverse\\freeze_0_reverse_11.bmp", RGB(0, 0, 0));
		NormalAttack3[1][2].LoadBitmap(".\\res\\Freeze\\Freeze_0_reverse\\freeze_0_reverse_10.bmp", RGB(0, 0, 0));

		HeavyAttack[0][0].LoadBitmap(".\\res\\Freeze\\Freeze_1\\freeze_1_32.bmp", RGB(0, 0, 0));
		HeavyAttack[0][1].LoadBitmap(".\\res\\Freeze\\Freeze_1\\freeze_1_33.bmp", RGB(0, 0, 0));
		HeavyAttack[0][2].LoadBitmap(".\\res\\Freeze\\Freeze_1\\freeze_1_34.bmp", RGB(0, 0, 0));
		HeavyAttack[0][3].LoadBitmap(".\\res\\Freeze\\Freeze_1\\freeze_1_35.bmp", RGB(0, 0, 0));
		HeavyAttack[0][4].LoadBitmap(".\\res\\Freeze\\Freeze_1\\freeze_1_36.bmp", RGB(0, 0, 0));
		HeavyAttack[1][0].LoadBitmap(".\\res\\Freeze\\Freeze_1_reverse\\freeze_1_reverse_37.bmp", RGB(0, 0, 0));
		HeavyAttack[1][1].LoadBitmap(".\\res\\Freeze\\Freeze_1_reverse\\freeze_1_reverse_36.bmp", RGB(0, 0, 0));
		HeavyAttack[1][2].LoadBitmap(".\\res\\Freeze\\Freeze_1_reverse\\freeze_1_reverse_35.bmp", RGB(0, 0, 0));
		HeavyAttack[1][3].LoadBitmap(".\\res\\Freeze\\Freeze_1_reverse\\freeze_1_reverse_34.bmp", RGB(0, 0, 0));
		HeavyAttack[1][4].LoadBitmap(".\\res\\Freeze\\Freeze_1_reverse\\freeze_1_reverse_33.bmp", RGB(0, 0, 0));

		JumpAttack[0][0].LoadBitmap(".\\res\\Freeze\\Freeze_0\\freeze_0_14.bmp", RGB(0, 0, 0));
		JumpAttack[0][1].LoadBitmap(".\\res\\Freeze\\Freeze_0\\freeze_0_15.bmp", RGB(0, 0, 0));
		JumpAttack[0][2].LoadBitmap(".\\res\\Freeze\\Freeze_0\\freeze_0_16.bmp", RGB(0, 0, 0));
		JumpAttack[1][0].LoadBitmap(".\\res\\Freeze\\Freeze_0_reverse\\freeze_0_reverse_15.bmp", RGB(0, 0, 0));
		JumpAttack[1][1].LoadBitmap(".\\res\\Freeze\\Freeze_0_reverse\\freeze_0_reverse_14.bmp", RGB(0, 0, 0));
		JumpAttack[1][2].LoadBitmap(".\\res\\Freeze\\Freeze_0_reverse\\freeze_0_reverse_13.bmp", RGB(0, 0, 0));

		JumpHeavyAttack[0][0].LoadBitmap(".\\res\\Freeze\\Freeze_1\\freeze_1_37.bmp", RGB(0, 0, 0));
		JumpHeavyAttack[0][1].LoadBitmap(".\\res\\Freeze\\Freeze_1\\freeze_1_38.bmp", RGB(0, 0, 0));
		JumpHeavyAttack[0][2].LoadBitmap(".\\res\\Freeze\\Freeze_1\\freeze_1_39.bmp", RGB(0, 0, 0));
		JumpHeavyAttack[1][0].LoadBitmap(".\\res\\Freeze\\Freeze_1_reverse\\freeze_1_reverse_32.bmp", RGB(0, 0, 0));
		JumpHeavyAttack[1][1].LoadBitmap(".\\res\\Freeze\\Freeze_1_reverse\\freeze_1_reverse_31.bmp", RGB(0, 0, 0));
		JumpHeavyAttack[1][2].LoadBitmap(".\\res\\Freeze\\Freeze_1_reverse\\freeze_1_reverse_30.bmp", RGB(0, 0, 0));
		//Knock
		Knock[0][0].LoadBitmap(".\\res\\Freeze\\Freeze_0\\freeze_0_53.bmp", RGB(0, 0, 0));
		Knock[0][1].LoadBitmap(".\\res\\Freeze\\Freeze_0\\freeze_0_54.bmp", RGB(0, 0, 0));
		Knock[0][2].LoadBitmap(".\\res\\Freeze\\Freeze_0\\freeze_0_55.bmp", RGB(0, 0, 0));
		Knock[1][0].LoadBitmap(".\\res\\Freeze\\Freeze_0_reverse\\freeze_0_reverse_56.bmp", RGB(0, 0, 0));
		Knock[1][1].LoadBitmap(".\\res\\Freeze\\Freeze_0_reverse\\freeze_0_reverse_55.bmp", RGB(0, 0, 0));
		Knock[1][2].LoadBitmap(".\\res\\Freeze\\Freeze_0_reverse\\freeze_0_reverse_54.bmp", RGB(0, 0, 0));

		Knock2[0][0].LoadBitmap(".\\res\\Freeze\\Freeze_0\\freeze_0_46.bmp", RGB(0, 0, 0));
		Knock2[0][1].LoadBitmap(".\\res\\Freeze\\Freeze_0\\freeze_0_47.bmp", RGB(0, 0, 0));
		Knock2[0][2].LoadBitmap(".\\res\\Freeze\\Freeze_0\\freeze_0_48.bmp", RGB(0, 0, 0));
		Knock2[1][0].LoadBitmap(".\\res\\Freeze\\Freeze_0_reverse\\freeze_0_reverse_43.bmp", RGB(0, 0, 0));
		Knock2[1][1].LoadBitmap(".\\res\\Freeze\\Freeze_0_reverse\\freeze_0_reverse_42.bmp", RGB(0, 0, 0));
		Knock2[1][2].LoadBitmap(".\\res\\Freeze\\Freeze_0_reverse\\freeze_0_reverse_41.bmp", RGB(0, 0, 0));
		
		KnockFront[0][0].LoadBitmap(".\\res\\Freeze\\Freeze_0\\freeze_0_30.bmp", RGB(0, 0, 0));
		KnockFront[0][1].LoadBitmap(".\\res\\Freeze\\Freeze_0\\freeze_0_31.bmp", RGB(0, 0, 0));
		KnockFront[0][2].LoadBitmap(".\\res\\Freeze\\Freeze_0\\freeze_0_32.bmp", RGB(0, 0, 0));
		KnockFront[0][3].LoadBitmap(".\\res\\Freeze\\Freeze_0\\freeze_0_33.bmp", RGB(0, 0, 0));
		KnockFront[0][4].LoadBitmap(".\\res\\Freeze\\Freeze_0\\freeze_0_34.bmp", RGB(0, 0, 0));
		KnockFront[0][5].LoadBitmap(".\\res\\Freeze\\Freeze_0\\freeze_0_35.bmp", RGB(0, 0, 0));
		KnockFront[0][6].LoadBitmap(".\\res\\Freeze\\Freeze_0\\freeze_0_36.bmp", RGB(0, 0, 0));
		KnockFront[1][0].LoadBitmap(".\\res\\Freeze\\Freeze_0_reverse\\freeze_0_reverse_39.bmp", RGB(0, 0, 0));
		KnockFront[1][1].LoadBitmap(".\\res\\Freeze\\Freeze_0_reverse\\freeze_0_reverse_38.bmp", RGB(0, 0, 0));
		KnockFront[1][2].LoadBitmap(".\\res\\Freeze\\Freeze_0_reverse\\freeze_0_reverse_37.bmp", RGB(0, 0, 0));
		KnockFront[1][3].LoadBitmap(".\\res\\Freeze\\Freeze_0_reverse\\freeze_0_reverse_36.bmp", RGB(0, 0, 0));
		KnockFront[1][4].LoadBitmap(".\\res\\Freeze\\Freeze_0_reverse\\freeze_0_reverse_35.bmp", RGB(0, 0, 0));
		KnockFront[1][5].LoadBitmap(".\\res\\Freeze\\Freeze_0_reverse\\freeze_0_reverse_34.bmp", RGB(0, 0, 0));
		KnockFront[1][6].LoadBitmap(".\\res\\Freeze\\Freeze_0_reverse\\freeze_0_reverse_33.bmp", RGB(0, 0, 0));

		KnockBack[0][0].LoadBitmap(".\\res\\Freeze\\Freeze_0\\freeze_0_40.bmp", RGB(0, 0, 0));
		KnockBack[0][1].LoadBitmap(".\\res\\Freeze\\Freeze_0\\freeze_0_41.bmp", RGB(0, 0, 0));
		KnockBack[0][2].LoadBitmap(".\\res\\Freeze\\Freeze_0\\freeze_0_42.bmp", RGB(0, 0, 0));
		KnockBack[0][3].LoadBitmap(".\\res\\Freeze\\Freeze_0\\freeze_0_43.bmp", RGB(0, 0, 0));
		KnockBack[0][4].LoadBitmap(".\\res\\Freeze\\Freeze_0\\freeze_0_44.bmp", RGB(0, 0, 0));
		KnockBack[0][5].LoadBitmap(".\\res\\Freeze\\Freeze_0\\freeze_0_45.bmp", RGB(0, 0, 0));
		KnockBack[0][6].LoadBitmap(".\\res\\Freeze\\Freeze_0\\freeze_0_36.bmp", RGB(0, 0, 0));
		KnockBack[1][0].LoadBitmap(".\\res\\Freeze\\Freeze_0_reverse\\freeze_0_reverse_49.bmp", RGB(0, 0, 0));
		KnockBack[1][1].LoadBitmap(".\\res\\Freeze\\Freeze_0_reverse\\freeze_0_reverse_48.bmp", RGB(0, 0, 0));
		KnockBack[1][2].LoadBitmap(".\\res\\Freeze\\Freeze_0_reverse\\freeze_0_reverse_47.bmp", RGB(0, 0, 0));
		KnockBack[1][3].LoadBitmap(".\\res\\Freeze\\Freeze_0_reverse\\freeze_0_reverse_46.bmp", RGB(0, 0, 0));
		KnockBack[1][4].LoadBitmap(".\\res\\Freeze\\Freeze_0_reverse\\freeze_0_reverse_45.bmp", RGB(0, 0, 0));
		KnockBack[1][5].LoadBitmap(".\\res\\Freeze\\Freeze_0_reverse\\freeze_0_reverse_44.bmp", RGB(0, 0, 0));
		KnockBack[1][6].LoadBitmap(".\\res\\Freeze\\Freeze_0_reverse\\freeze_0_reverse_33.bmp", RGB(0, 0, 0));
	}

	void CharacterAnimation::LoadHenry() {
		//normal state right
		Normal[0].AddBitmap(HENRY_NORMAL4, RGB(0, 0, 0));
		Normal[0].AddBitmap(HENRY_NORMAL3, RGB(0, 0, 0));
		Normal[0].AddBitmap(HENRY_NORMAL2, RGB(0, 0, 0));
		Normal[0].AddBitmap(HENRY_NORMAL1, RGB(0, 0, 0));
		//normal state left
		Normal[1].AddBitmap(HENRY_NORMAL4_REVERSE, RGB(0, 0, 0));
		Normal[1].AddBitmap(HENRY_NORMAL3_REVERSE, RGB(0, 0, 0));
		Normal[1].AddBitmap(HENRY_NORMAL2_REVERSE, RGB(0, 0, 0));
		Normal[1].AddBitmap(HENRY_NORMAL1_REVERSE, RGB(0, 0, 0));
		//walk right
		Walk[0].AddBitmap(HENRY_WALK1, RGB(0, 0, 0));
		Walk[0].AddBitmap(HENRY_WALK2, RGB(0, 0, 0));
		Walk[0].AddBitmap(HENRY_WALK3, RGB(0, 0, 0));
		Walk[0].AddBitmap(HENRY_WALK4, RGB(0, 0, 0));
		Walk[0].AddBitmap(HENRY_WALK3, RGB(0, 0, 0));
		Walk[0].AddBitmap(HENRY_WALK2, RGB(0, 0, 0));
		//walk left
		Walk[1].AddBitmap(HENRY_WALK1_REVERSE, RGB(0, 0, 0));
		Walk[1].AddBitmap(HENRY_WALK2_REVERSE, RGB(0, 0, 0));
		Walk[1].AddBitmap(HENRY_WALK3_REVERSE, RGB(0, 0, 0));
		Walk[1].AddBitmap(HENRY_WALK4_REVERSE, RGB(0, 0, 0));
		Walk[1].AddBitmap(HENRY_WALK3_REVERSE, RGB(0, 0, 0));
		Walk[1].AddBitmap(HENRY_WALK2_REVERSE, RGB(0, 0, 0));

		//Run right
		Run[0].AddBitmap(HENRY_RUN1, RGB(0, 0, 0));
		Run[0].AddBitmap(HENRY_RUN2, RGB(0, 0, 0));
		Run[0].AddBitmap(HENRY_RUN3, RGB(0, 0, 0));
		Run[0].AddBitmap(HENRY_RUN2, RGB(0, 0, 0));
		//run left
		Run[1].AddBitmap(HENRY_RUN1_REVERSE, RGB(0, 0, 0));
		Run[1].AddBitmap(HENRY_RUN2_REVERSE, RGB(0, 0, 0));
		Run[1].AddBitmap(HENRY_RUN3_REVERSE, RGB(0, 0, 0));
		Run[1].AddBitmap(HENRY_RUN2_REVERSE, RGB(0, 0, 0));

		RunStop[0].LoadBitmapA(".\\res\\Henry\\Henry_1\\henry_1_19.bmp", RGB(0, 0, 0));
		RunStop[1].LoadBitmapA(".\\res\\Henry\\Henry_1_reverse\\henry_1_reverse_10.bmp", RGB(0, 0, 0));

		//jump
		Jump[0][0].LoadBitmapA(".\\res\\Henry\\Henry_0\\henry_0_60.bmp", RGB(0, 0, 0));
		Jump[0][1].LoadBitmapA(".\\res\\Henry\\Henry_0\\henry_0_61.bmp", RGB(0, 0, 0));
		Jump[0][2].LoadBitmapA(".\\res\\Henry\\Henry_0\\henry_0_62.bmp", RGB(0, 0, 0));
		Jump[0][3].LoadBitmapA(".\\res\\Henry\\Henry_0\\henry_0_63.bmp", RGB(0, 0, 0));

		Jump[1][0].LoadBitmapA(".\\res\\Henry\\Henry_0_reverse\\henry_0_reverse_69.bmp", RGB(0, 0, 0));
		Jump[1][1].LoadBitmapA(".\\res\\Henry\\Henry_0_reverse\\henry_0_reverse_68.bmp", RGB(0, 0, 0));
		Jump[1][2].LoadBitmapA(".\\res\\Henry\\Henry_0_reverse\\henry_0_reverse_67.bmp", RGB(0, 0, 0));
		Jump[1][3].LoadBitmapA(".\\res\\Henry\\Henry_0_reverse\\henry_0_reverse_66.bmp", RGB(0, 0, 0));

		Defense[0][0].LoadBitmapA(".\\res\\Henry\\Henry_0\\henry_0_56.bmp", RGB(0, 0, 0));
		Defense[0][1].LoadBitmapA(".\\res\\Henry\\Henry_0\\henry_0_57.bmp", RGB(0, 0, 0));
		Defense[1][0].LoadBitmapA(".\\res\\Henry\\Henry_0_reverse\\henry_0_reverse_53.bmp", RGB(0, 0, 0));
		Defense[1][1].LoadBitmapA(".\\res\\Henry\\Henry_0_reverse\\henry_0_reverse_52.bmp", RGB(0, 0, 0));

		//this need add 0_19 && reverse_10
		Roll[0][0].LoadBitmapA(".\\res\\Henry\\Henry_0\\henry_0_16.bmp", RGB(0, 0, 0));
		Roll[0][1].LoadBitmapA(".\\res\\Henry\\Henry_0\\henry_0_17.bmp", RGB(0, 0, 0));
		Roll[0][2].LoadBitmapA(".\\res\\Henry\\Henry_0\\henry_0_18.bmp", RGB(0, 0, 0));
		Roll[1][0].LoadBitmapA(".\\res\\Henry\\Henry_0_reverse\\henry_0_reverse_13.bmp", RGB(0, 0, 0));
		Roll[1][1].LoadBitmapA(".\\res\\Henry\\Henry_0_reverse\\henry_0_reverse_12.bmp", RGB(0, 0, 0));
		Roll[1][2].LoadBitmapA(".\\res\\Henry\\Henry_0_reverse\\henry_0_reverse_11.bmp", RGB(0, 0, 0));
	}
	CharacterAnimation::~CharacterAnimation() {

	}
}
