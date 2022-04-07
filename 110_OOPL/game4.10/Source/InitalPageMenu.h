#include <vector>
namespace game_framework {


    class MenuBtn
    {
    public:
        MenuBtn();
        virtual void OnShow()= 0;					// �N�ϧζK��e��
        virtual void buttonTouch() = 0;
        virtual void Load() = 0;
    
    protected:
        vector<vector<int>> posistion_XY;					// �ϧΥ��W���y��  
        vector <CMovingBitmap> Btn;
        CMovingBitmap btnNClick;
        CMovingBitmap btnClick;
    };
    /////////////////////////////////////// StartBtn(Derived) ///////////////////////////////////////
    class StartBtn :public MenuBtn {
    public:
        StartBtn();
        virtual void buttonTouch() override;
        virtual void Load() override;
        virtual void OnShow() override;
        ~StartBtn();
    
    };
    /////////////////////////////////////// SettingBtn(Derived) ///////////////////////////////////////
    class SettingBtn :public MenuBtn {
    public:
        SettingBtn();
        virtual void buttonTouch() override;
        virtual void Load() override;
        virtual void OnShow() override;
        ~SettingBtn();
    };
}