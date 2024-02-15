#pragma once

#include"Character.h"
#include "UI_T.h"

//タンクキャラ_子クラス
class Tank : public Character
{
private:

	Vector2D Playerlocation;
	Vector2D Enemylocation;
	UI_T* ui;

	float hp;		//体力
	float power;	//攻撃力

	bool is_Attack;

	//画像データ格納
	int graphic;

	//敵かプレイヤーか{ 1:プレイヤー, 2: 敵 }
	int type;

public:

	Tank();
	~Tank();

	virtual void Initialize() override;
	virtual void Draw() override;
	virtual void Update() override;


	//void SetType(int type) { this->type = type; }
	virtual void  SetType(int type) override;
	virtual Vector2D GetPlayerLocation() override;
	virtual Vector2D GetEnemyLocation() override;

	virtual void SetSubHp(int Damege) override;
	virtual int GetPower() override;
	virtual void SetAttackflg(bool b) override;
	virtual bool HpCheck() override;
	virtual int WaitAttackTime() override;

	virtual void SetPlayerLocation(Vector2D p) override;
	virtual void SetEnemyLocation(Vector2D e) override;
};