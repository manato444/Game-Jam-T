#pragma once
#pragma once

#include"Character.h"

//騎馬キャラ_子クラス
class Kiba : public Character
{
private:

	Vector2D location;

	float hp;		//体力
	float power;	//攻撃力

	//画像データ格納
	int graphic;

	//敵かプレイヤーか{ 1:プレイヤー, 2: 敵 }
	int type;

public:

	Kiba();
	~Kiba();

	virtual void Initialize() override;
	virtual void Draw() override;
	virtual void Update() override;


	void SetType(int type) { this->type = type; }

};