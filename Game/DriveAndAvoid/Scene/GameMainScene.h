#pragma once

#include"SceneBase.h"
#include"../Object/Player.h"
#include"../Object/Enemy_T.h"
#include"../Object/Item.h"
#include"../Object/Player_T.h"
#include"../Object/UI_T.h"


class GameMainScene : public SceneBase
{
private:

	int high_score;		 //�n�C�X�R�A
	int back_ground;	 //�w�i�摜
	int barrier_image;	 //�o���A�摜
	int mileage;		 //���s����
	int enemy_image[3];	 //�G�摜
	int enemy_count[3];	 //�ʂ�߂����G�J�E���g

	Player* player;		 //�v���C���[
	Enemy_T* enemy;		 //�G

	//Character* chara;
	UI_T* ui;
	Player_T* pt;

	Item* item;		//�A�C�e��
	int item_image;	//�A�C�e���摜

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

	//�n�C�X�R�A�ǂݍ��ݏ���
	void ReadHighScore();

	//�����蔻��
	bool IsHitCheck(Player* p, Enemy_T* e);
	bool IsHitCheck(Player* p, Item* i);
};

