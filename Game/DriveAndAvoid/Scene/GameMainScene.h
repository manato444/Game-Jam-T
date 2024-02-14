#pragma once

#include"SceneBase.h"
#include"../Object/Player.h"
#include"../Object/Enemy.h"
#include"../Object/Item.h"
#include"../Object/Player_T.h"
#include"../Object/UI_T.h"


class GameMainScene : public SceneBase
{
private:

	int high_score;		 //ハイスコア
	int back_ground;	 //背景画像
	int barrier_image;	 //バリア画像
	int mileage;		 //走行距離
	int enemy_image[3];	 //敵画像
	int enemy_count[3];	 //通り過ぎた敵カウント

	Player* player;		 //プレイヤー
	Enemy** enemy;		 //敵

	//Character* chara;
	UI_T* ui;
	Player_T* pt;

	Item* item;		//アイテム
	int item_image;	//アイテム画像

	int sound; //BGM
	int image;	//飾り(?)
	int MaxMoney[5] = {100,150,200,250,300};
	int Money;
	int Level;
	int Count;

public:
	GameMainScene();
	virtual ~GameMainScene();

	virtual void Initialize() override;
	virtual eSceneType Update() override;
	virtual void Draw() const override;
	virtual void Finalize() override;

	virtual eSceneType GetNowScene() const override;

private:

	//ハイスコア読み込み処理
	void ReadHighScore();

	//当たり判定
	bool IsHitCheck(Player* p, Enemy* e);
	bool IsHitCheck(Player* p, Item* i);

	void MoneyManager();
};

