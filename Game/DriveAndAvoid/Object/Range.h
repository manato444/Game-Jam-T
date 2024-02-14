#pragma once
#pragma once

#include"Character.h"

//”ÍˆÍUŒ‚ƒLƒƒƒ‰_ŽqƒNƒ‰ƒX
class Range : public Character
{
private:

	Vector2D location;

	float hp;		//‘Ì—Í
	float power;	//UŒ‚—Í


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

};