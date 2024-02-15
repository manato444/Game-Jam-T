#pragma once
#pragma once

#include"Character.h"
#include "UI_T.h"

//”ÍˆÍUŒ‚ƒLƒƒƒ‰_ŽqƒNƒ‰ƒX
class Range : public Character
{
private:

	Vector2D Playerlocation;
	Vector2D Enemylocation;
	UI_T* ui;

	float hp;		//‘Ì—Í
	float power;	//UŒ‚—Í

	bool is_Attack;

	//‰æ‘œƒf[ƒ^Ši”[
	int graphic;

	//“G‚©ƒvƒŒƒCƒ„[‚©{ 1:ƒvƒŒƒCƒ„[, 2: “G }
	int type;

public:

	Range();
	~Range();

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