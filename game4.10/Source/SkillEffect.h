#pragma once
#include "GameObject.h"
namespace game_framework {
    class SkillEffect {
    public:
        SkillEffect(int skillID, int createdTimes, int direction, int xPos, int yPos);
        int SkillsProcess(vector<pair<int, int>> theOthersPosition, int duration);
        void SkillsFeedbackStatus(vector<pair<int, int>>  theOthersPosition);
        boolean GarbageCollectorTimer(int duration);
        //void GarbageCollector();
        ~SkillEffect();
        int createdTime;
        void OnShow();
        void SetEffectObj(int direction, int x, int y);//x :�}�⪺ X ; y :�}�⪺Y
        int xPos, yPos;
    protected:
        int direction;
        int AnimationState;
        int AnimationCount[3];
        int timeCount;
        vector<string> feedbackStatus;
        vector<GameObject*> effectObj;
    private:
        int skillID;
        void CreatEffectObj();

        enum class skillsIdTable {
            frozenWave, frozenPunch, frozenSword, frozenStorm
        };
    };

}