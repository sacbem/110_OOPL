#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include <string> 
#include "CGameStateRun.h"
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
#define  _CRTDBG_MAP_ALLOC
#include  < stdlib.h >
#include  < crtdbg.h >
#define Forest 0
#define HKC 1
#define BC 2
using namespace skillTable;
namespace game_framework {
	CGameStateRun::CGameStateRun(CGame* g) : CGameState(g) {
		characterList.reserve(2);
		theOthersPosition.reserve(2);
		//characterList[1] = new Character();
		HealthPlayer1 = new HealthBar();
		HealthPlayer2 = new HealthBar();
		maps = new Map(BC);
		
		//GenerationTime = clock();

	}

	void CGameStateRun::OnBeginState()
	{
		//_CrtDumpMemoryLeaks();
		for (int i = 0; i < 2; i++) {
			theOthersPosition.push_back(pair<int, int>(0, 0));
		}
		TimePassed = 0;
	}
   
	void CGameStateRun::OnMove()	{					// 移動遊戲元素
		//maps->drops[0]->OnMove();
		maps->drops[0]->OnMove();
		CleanCounter++;
		if (CleanCounter >= 10) {
			CleanCounter = 0;
			if (characterList[1]->GetHealth() <= 0) {
				characterList[1]->SetAlive(false);
			}
		}

		SetAbonormalStatus();
		//TRACE("OnMove %d\n",statusTableAll.empty());
		characterList[0]->OnMove();
		characterList[1]->OnMove();
		//Reset
		int x = 0;
		for (auto i : characterList) {
			tables[x++] = i->specialState;
		}

		SetAllCharacterPosition();
		
		int num0 = 0;
		int num1 = 0;
		for (auto i : characterList) {
			num1 = 0;
			for (auto j : characterList) {
				if (num0 != num1) {
					if (i->HitEnemy(j) && i->isAttacking) {
						if (j->HealthPoint >= 0) {
							j->SetKnock(true, i->GetDir(), i->AttackState);
							j->isGettingDamage(i->AttackPoint);
						}
					}
				}
				num1++;
			}
			num0++;
		}

		maps->ResetCharactAccumulator(characterList[0]->GetDistance(), characterList[0]->GetDistance());
		//characterList[1]->OnMove();
		characterList[0]->DistanceAccumulatorReset();

		maps->ScenesCamera(characterList[0]->DistanceAccumulatorReset(), characterList[0]->isRunning, characterList[0]->GetDir(), characterList[0]->GetDistance());

		CalculateDamage(theOthersPosition);

		//boxTest->Throw(true, characterList[0]->GetDir());
		int num = 0;
		int num2 = 0;
		for (auto i : maps->drops) {
			for (auto j : characterList) {
				if (i->HitPlayer(num2, j->GetX1(), j->GetY1(), j->GetX2(), j->GetY2(), j->isAttacking)) {
					if (j->isDropItem == false && j->isCarryItem == false && j->GetSkillSignal() == -1) {
						if (i->GetState() == 0) {
							j->SetPickup(true, num);
							i->SetState(1);
							i->SetOwner(num2);
						}
					}
				}
				if (i->GetOwner() == num2 && j->itemId == num) {
					if (i->GetState() == 1) {
						j->Pickup((maps->drops[num]));
					}
				}
				num2++;
			}
			num++;
		}
		
	}

	void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
	{
		ShowInitProgress(33);	// 接個前一個狀態的進度，此處進度視為33%
		ShowInitProgress(50);
		Sleep(300);

		maps->Load();
		HealthPlayer1->init();
		HealthPlayer2->init();

		HealthPlayer1->OnLoad(0, 0);
		HealthPlayer2->OnLoad(400, 0);
		switch (maps->GetMapID()) {
		case Forest:
			CAudio::Instance()->Load(Forest, "bgm\\stage1.wav");	// 載入編號0的聲音ding.wav
			CAudio::Instance()->Play(Forest, true);
			break;
		case HKC:
			//CAudio::Instance()->Load(HKC, "bgm\\stage2.wav");	// 載入編號0的聲音ding.wav
			//CAudio::Instance()->Play(HKC, true);
			break;
		case BC:
			//CAudio::Instance()->Load(BC, "bgm\\stage3.wav");	// 載入編號0的聲音ding.wav
			//CAudio::Instance()->Play(BC, true);
			break;
		default:
			break;
		}

	}

	void CGameStateRun::SetAbonormalStatus() {
		int x = 0;
		for (auto i : characterList) {
			i->specialState = tables[x++];
		}
	}

	void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
		characterList[0]->InputKeyDown(nChar, CurrentTime,0);
		characterList[1]->InputKeyDown(nChar, CurrentTime,1);
		frozenPunchList.insert(frozenPunchList.begin(), characterList[0]->frozenPunchs.begin(), characterList[0]->frozenPunchs.end());

		//Reset item state
		for (auto i : characterList) {
			if (i->isDropItem == true) {
				maps->drops[i->itemId]->liftUp(false, i->GetX1(), i->GetY1(), i->GetDir());
				i->isCarryItem = false;
				i->isDropItem = false;
				i->itemId = -1;
			}
		}
	}

	void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) {
		characterList[0]->InputKeyUp(nChar,0);
		characterList[1]->InputKeyUp(nChar,1);
	}

	void CGameStateRun::SetAllCharacterPosition() {
		for (int i = 0; i < characterList.size(); i++) {
			theOthersPosition[i].first = characterList[i]->GetX1();
			theOthersPosition[i].second = characterList[i]->GetY1();
		}
	}
	void  CGameStateRun::CalculateDamage(vector<pair<int, int>> theOthersPosition) {

		for (int i = 0; i < 2; i++) {
			if (this->game->selectCharacterID[i] == 0) {
				static_cast<Woody*>(characterList[i])->DetectSkillDamage(theOthersPosition, tables);
			}
			else if (this->game->selectCharacterID[i] == 1) {
				static_cast<Freeze*>(characterList[i])->DetectSkillDamage(theOthersPosition, tables);
			}
			else if (this->game->selectCharacterID[i] == 2) {
				static_cast<Henry*>(characterList[i])->DetectSkillDamage(theOthersPosition, tables);
			}
		}
		//statusTable = characterList[0]->statusTable;
		if (characterList[0]->GetCalculateDamageRequest() || characterList[1]->GetCalculateDamageRequest()) {
			for (auto& u : characterList) {
				for (auto& i : u->hittedTable) { /// issue :可能不會改 !!!
					if (i.first == 0) {
						characterList[0]->isGettingDamage(i.second);
					}
					else if (i.first == 1) {
						characterList[1]->isGettingDamage(i.second);
					}
				}
			}
			if (!characterList[0]->hittedTable.empty()) {
				pair<int, int>().swap(characterList[0]->hittedTable[0]);
			}
			if (!characterList[1]->hittedTable.empty()) {
				pair<int, int>().swap(characterList[1]->hittedTable[0]);
			}
			characterList[0]->SetCalculateDamageRequest(false);
			characterList[1]->SetCalculateDamageRequest(false);
		}
	}
	boolean CompareC(Character* obj1, Character* obj2) {
		return obj1->GetY1() < obj2->GetY1();
	}
	boolean CompareF(FieldObject* obj1, FieldObject* obj2) {
		return obj1->GetY() < obj2->GetY();
	}
	boolean CompareFP(SkillEffect* s1, SkillEffect* s2) {
		return s1->yPos < s2->yPos;
	}

	void CGameStateRun::SortedShow() {
		vector<FieldObject*> dropCopy;
		vector<Character*> characterListCopy;
		vector<SkillEffect*> frozenPunchListCopy;
		vector<int> showSequence(3, 0), sequenceValue_Y(3, 0);
		boolean dropEmpty = maps->drops.empty(), characterEmpty = characterList.empty(), frozemPunchEmpty = frozenPunchList.empty();
		int totalSize = maps->drops.size() + characterList.size() + frozenPunchList.size();

		if (!dropEmpty) {
			dropCopy.assign(maps->drops.begin(), maps->drops.end());
			std::sort(dropCopy.begin(), dropCopy.end(), CompareF);
			sequenceValue_Y[0] = dropCopy[0]->GetY();
		}
		else {
			showSequence[0] = -1;
			sequenceValue_Y[0] = 10000;
		}
		if (!characterEmpty) {
			characterListCopy.assign(characterList.begin(), characterList.end());
			std::sort(characterListCopy.begin(), characterListCopy.end(), CompareC);
			sequenceValue_Y[1] = characterListCopy[0]->GetY1();
		}
		else {
			showSequence[1] = -1;
			sequenceValue_Y[1] = 10000;
		}
		if (!frozemPunchEmpty) {
			frozenPunchListCopy.assign(frozenPunchList.begin(), frozenPunchList.end());
			std::sort(frozenPunchList.begin(), frozenPunchList.end(), CompareFP);
			sequenceValue_Y[2] = frozenPunchListCopy[0]->yPos;
		}
		else {
			showSequence[2] = -1;
			sequenceValue_Y[2] = 10000;
		}

		for (int i = 0; i < totalSize; i++) {
			auto showingIndex = std::min_element(sequenceValue_Y.begin(), sequenceValue_Y.end()) - sequenceValue_Y.begin();
			switch (showingIndex) {
			case 0:
				dropCopy[showSequence[0]]->ShowAnimation();
				TRACE("xPos %d yPos %d \n" , dropCopy[showSequence[0]]->GetX(), dropCopy[showSequence[0]]->GetY());
				if (showSequence[0] < maps->drops.size()-1) {
					showSequence[0] += 1;
					sequenceValue_Y[0] = dropCopy[showSequence[0]]->GetY();
					
				}
				else {
					sequenceValue_Y[0] = 1000;
				}
				break;
			case 1:
				characterListCopy[showSequence[1]]->OnShow(theOthersPosition, CurrentTime);
				if (showSequence[1] < characterList.size() - 1) {
					showSequence[1] += 1;
					sequenceValue_Y[1] = characterListCopy[showSequence[1]]->GetY1();
				}
				else {
					sequenceValue_Y[1] = 1000;
				}
				break;
			case 2:
				frozenPunchListCopy[showSequence[2]]->OnShow();
				if (showSequence[2] < frozenPunchListCopy.size() - 1) {
					showSequence[2]++;
					sequenceValue_Y[2] = frozenPunchListCopy[showSequence[2]]->yPos;
				}
				else {
					sequenceValue_Y[2] = 1000;
				}
				break;
			default:
				break;
			}

		}
	}
	
	void CGameStateRun::OnShow(){
		boolean showStatus;
		//get character
		if (GetCharacter == false ){
			maps->drops.push_back(new FieldObject(0, maps->GetMapID()));
			switch (this->game->selectCharacterID[0]){
			case 0:
				characterList.push_back(new Woody(0 ,maps->GetMapID()));
				registSerialNumber = 0;
				break;
			case 1:
				characterList.push_back(new Freeze(0, maps->GetMapID()));
				registSerialNumber = 1;
				break;
			case 2:
				characterList.push_back(new Henry(0, maps->GetMapID()));
				registSerialNumber = 2;
				break;
			default:
				characterList.push_back(new Freeze(0, maps->GetMapID()));
				registSerialNumber = 1;

				break;
			}
			characterList[0]->SetXY(200, 400);
			characterList[0]->SetCharacter();

			switch (this->game->selectCharacterID[1]) {
			case 0:
				//registSerialNumber == 0 ? 1 : 1
				characterList.push_back(new Woody(1, maps->GetMapID()));
				break;
			case 1:
				characterList.push_back(new Freeze(1, maps->GetMapID()));
				break;
			case 2:
				characterList.push_back(new Henry(1, maps->GetMapID()));
				break;
			default:
				characterList.push_back(new Freeze(1, maps->GetMapID()));
				break;
			}
			characterList[1]->SetXY(400, 401);
			characterList[1]->SetCharacter();
			
			SetAllCharacterPosition();


			GetCharacter = true;
			//load HealthBar small character
			HealthPlayer1->loadSmallImg(this->game->selectCharacterID[0]);
			HealthPlayer2->loadSmallImg(this->game->selectCharacterID[1]);

			GenerationTime = clock();
		}
		CurrentTime = clock();
		TimePassed = (CurrentTime - GenerationTime);
		MapAniCount++;
		if (MapAniCount < 50) {
			showStatus = true;
		}
		else if (MapAniCount <= 100) {
			showStatus = false;
			if (MapAniCount >= 100) {
				MapAniCount = 0;
			}
		}
	
		maps->PrintMap(showStatus);

		SortedShow();

		HealthPlayer1->OnShow(characterList[0]->HealthPoint, characterList[0]->InnerHealPoint, characterList[0]->Mana, characterList[0]->InnerMana);
		HealthPlayer2->OnShow(characterList[1]->HealthPoint, characterList[1]->InnerHealPoint, characterList[1]->Mana, characterList[1]->InnerMana);
	
	}

	CGameStateRun::~CGameStateRun(){
		delete maps, HealthPlayer1, HealthPlayer2;
		vector<Character*>().swap(characterList);
	
	}
}