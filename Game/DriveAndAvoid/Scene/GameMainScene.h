#pragma once

#include"SceneBase.h"
#include"../Object/Enemy_T.h"
#include"../Object/Player_T.h"
#include"../Object/UI_T.h"


class GameMainScene : public SceneBase
{
private:
	int mileage;		 //走行距離

	Enemy_T* enemy;		 //敵

	//Character* chara;
	UI_T* ui;
	Player_T* pt;      //プレイヤー

	int sound; //BGM
	int image;	//?

	int SoundEffect[10];

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
	//void ReadHighScore();

	//当たり判定
	//bool IsHitCheck(Player* p, Enemy_T* e);
	//bool IsHitCheck(Player* p, Item* i);
};

