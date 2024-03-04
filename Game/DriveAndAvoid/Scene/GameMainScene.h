#pragma once

#include"SceneBase.h"
#include"../Object/Enemy_T.h"
#include"../Object/Player_T.h"
#include"../Object/UI_T.h"

#define _MAX_CHARACTOR_ 30

class GameMainScene : public SceneBase
{
private:
	int mileage;		 //���s����

	Enemy_T* enemy;		 //�G

	//Character* chara;
	UI_T* ui;
	Player_T* pt;      //�v���C���[

	int sound; //BGM
	int image;	//?
	int E_image;

	int SoundEffect[10];
	int SE1;

	int PlayerTime[_MAX_CHARACTOR_];
	int EnemyTime[_MAX_CHARACTOR_];

	int PlayerSiroAttack[_MAX_CHARACTOR_];
	int EnemySiroAttack[_MAX_CHARACTOR_];

	bool PlayerWin;
	bool EnemyWin;



public:
	GameMainScene();
	virtual ~GameMainScene();

	virtual void Initialize() override;
	virtual eSceneType Update() override;
	virtual void Draw() const override;
	virtual void Finalize() override;

	virtual eSceneType GetNowScene() const override;

private:

	//�n�C�X�R�A�ǂݍ��ݏ���
	//void ReadHighScore();

	//�����蔻��
	//bool IsHitCheck(Player* p, Enemy_T* e);
	//bool IsHitCheck(Player* p, Item* i);
};

