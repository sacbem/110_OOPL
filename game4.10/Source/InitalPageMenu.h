namespace game_framework {
    /////////////////////////////////////////////////////////////////////////////
    // �o��class���ѥi�H����L�ηƹ�������l
    // �����N�i�H��g���ۤv���{���F
    /////////////////////////////////////////////////////////////////////////////

    class MenuBtn
    {
    public:
        MenuBtn();
        void Initialize(int positionX, int positionY);				// �]�w�ϧΪ�l��
        void OnShow();					// �N�ϧζK��e��
        virtual void buttonTouch() = 0;
        virtual void Load() = 0;				// ���J�ϧ�
        //void SetXY(int nx, int ny);		// �]�w���W���y��
       
    protected:
        int x, y;					// �ϧΥ��W���y��  
        CMovingBitmap Btn;
    };

    class StartBtn :public MenuBtn {
    public:
        StartBtn();
        void status();
        virtual void buttonTouch() override;
        virtual void Load() override;
        ~StartBtn();
    };
    class SettingBtn :public MenuBtn {
    public:
        SettingBtn();
        void status();
        virtual void buttonTouch() override;
        virtual void Load() override;
        ~SettingBtn();
    };
}