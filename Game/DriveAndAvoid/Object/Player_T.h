#pragma once
#include "../Utility/Vector2D.h"
#include "Character.h"


#define _MAX_PLAYER_CHARACTOR_ 50

#define _Normal_Money_ 20
#define _Tank_Money_ 50
#define _Range_Money_ 120
#define _Kiba_Money_ 200

class Player_T
{
private:
	int Hp;    //城のHp
	bool is_Pause;  //ポーズか?
	int Cursor;     //カーソル
	int Level;      //Levelの管理
	int ExPoint;    //経験値の管理
	int MaxExPoint[7] = { 30,50,70,100, 150, 300, 350 };

	int MaxMoney[8] = { 100, 150, 200, 250, 300, 500, 800, 1000 };
	int Money;
	int Count;
	int ButtonCount;

	Character** chara;

	int charaCount;
	int AttackCount;

	int SoundEffect[3];

private:
	static float stick2[2];
	static Vector2D stick[2];
	
public:

	//コンストラクタ(インスタンス生成時に最初に呼ばれる関数)
	Player_T();

	//デストラクタ
	~Player_T();

	void Initialize();		//初期化処理
	void Update();			//更新処理
	void Draw() const;			//描画処理
	void Finalize();		//終了時処理

	void DecreaseCastleHp(float Attack);
	void SetExPoint(int point);
	void SetMoney(int money);

	bool Is_PauseCheck() { return this->is_Pause; }
	int GetCursor() { return this->Cursor; }
	int GetCastleHp() { return this->Hp; }
	int GetExPoint() { return this->ExPoint; }
	int GetLevel() { return this->Level; }
	int GetMaxExPoint() { return this->MaxExPoint[Level]; }
	int GetMoney() { return this->Money; }
	int GetMaxMoney() { return this->MaxMoney[Level]; }

	int GetCharaCount() { return this->charaCount; }

	bool HpCheck();
	void SetAttackCount() { AttackCount = 50; }
	Character** GetCharacter(int count);
private:
	void InputControlUi();

	void PopCharactor();

	static float SetLeft_Stick_X();	//左スティックX座標をセット
	static float SetLeft_Stick_Y();	//左スティックY座標をセット
	static float SetRight_Stick_X();//右スティックY座標をセット

	void ExManager();
	void MoneyManager();
};

