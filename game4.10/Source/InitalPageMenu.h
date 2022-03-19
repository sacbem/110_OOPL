#include <vector>
namespace game_framework {
    /////////////////////////////////////////////////////////////////////////////
    // �o��class���ѥi�H����L�ηƹ�������l
    // �����N�i�H��g���ۤv���{���F
    /////////////////////////////////////////////////////////////////////////////

    class MenuBtn
    {
    public:
        MenuBtn();
        void Initialize(vector<vector<int>> positionXY);// �]�w�ϧΪ�l��
        virtual void OnShow()= 0;					// �N�ϧζK��e��
        virtual void buttonTouch() = 0;
        virtual void Load() = 0;
    
    protected:
        vector<vector<int>> posistion_XY;					// �ϧΥ��W���y��  
        vector <CMovingBitmap> Btn;
        CMovingBitmap btnNClick;
        CMovingBitmap btnClick;
    };

    class StartBtn :public MenuBtn {
    public:
        StartBtn();
        virtual void buttonTouch() override;
        virtual void Load() override;
        virtual void OnShow() override;
        ~StartBtn();
    
    };
    class SettingBtn :public MenuBtn {
    public:
        SettingBtn();
        virtual void buttonTouch() override;
        virtual void Load() override;
        virtual void OnShow() override;
        ~SettingBtn();
    };
}