#pragma once
#include "GameObject.h"
namespace game_framework {
    class SkillEffect {
    public:
        SkillEffect(int skillID, int createdTimes, int direction, int xPos, int yPos);
        boolean SkillsProcess(vector<vector<int>> theOthersPosition, int duration);
        void SkillsFeedbackStatus(vector<vector<int>>  theOthersPosition);
        boolean GarbageCollectorTimer(int duration);
        //void GarbageCollector();
        ~SkillEffect();
        int createdTime;
        void OnShow(int id_x, int id_y);
        void SetEffectObj(int direction, int x, int y);//x :�}�⪺ X ; y :�}�⪺Y
    protected:
        int xPos, yPos;
        int direction;
        int AnimationState;
        int AnimationCount;
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