#pragma once

#include"Character.h"
#include "UI_T.h"

//ノーマルキャラ_子クラス
class Nomal : public Character
{
private:

	Vector2D Playerlocation;
	Vector2D Enemylocation;
	UI_T* ui;

	float hp;		//体力
	float power;	//攻撃力

	//画像データ格納
	int graphic;

	//敵かプレイヤーか{ 1:プレイヤー, 2: 敵 }
	int type;

public:

	Nomal();
	~Nomal();

	virtual void Initialize() override;
	virtual void Draw() override;
	virtual void Update() override;

	virtual void  SetType(int type) override;

};