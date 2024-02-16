#pragma once


#include"../Utility/Vector2D.h"
#include"DxLib.h"

#define CHARACTER_SPEED 1.0f

//キャラクターの種類(列挙型)
enum CharacterType
{
	Nomal_type,	//ノーマル
	Tank_type,	//タンク
	Range_type,	//範囲攻撃
	Kiba_type	//騎馬
};


//キャラクターの基底クラス
class Character
{

public:

	//コンストラクタ
	Character() {};

	virtual ~Character() {};

	virtual void Initialize() {};	//初期化処理 
	virtual void Update() {};		//更新処理 
	virtual void Draw() {};			//描画処理 

	virtual void SetType(int type) {};
	virtual void SetSubHp(int Damege) {};
	virtual Vector2D GetPlayerLocation() { return Vector2D(); }
	virtual Vector2D GetEnemyLocation() { return Vector2D(); }

	virtual int GetPower() = 0;
	virtual bool HpCheck() = 0;
	virtual void SetAttackflg(bool b) {};
	virtual int WaitAttackTime() = 0;
	virtual void SetPlayerLocation(Vector2D p) {};
	virtual void SetEnemyLocation(Vector2D e) {};
	virtual int GetExPoint() = 0;
	virtual int GetMoney() = 0;
};