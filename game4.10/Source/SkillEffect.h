#pragma once
#include "GameObject.h"
namespace game_framework {
	class SkillEffect {
	public:
		void OnShow(int id_x,int id_y);
		void SetEffectObj(int x, int y);//x :�}�⪺ X ; y :�}�⪺Y       
		SkillEffect(int skillID,int createdTimes);
		boolean SkillsProcess(vector<vector<int>> theOthersPosition, int duration);
		void SkillsFeedbackStatus(vector<vector<int>>  theOthersPosition);
		boolean GarbageCollectorTimer(int duration);
		//void GarbageCollector();
		~SkillEffect();
		int createdTime;
	protected:
		vector<GameObject*> effectObj;
		vector<string> feedbackStatus;
	private:
		int skillID;
		void CreatEffectObj();
		
		enum class skillsIdTable {
			frozenWave, frozenPunch, frozenSword, frozenStorm
		};
	};

}