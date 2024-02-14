#include"GameMainScene.h"
#include"../Object/RankingData.h"
#include"DxLib.h"
#include<math.h>


GameMainScene::GameMainScene() : high_score(0), back_ground(NULL), barrier_image(NULL), image(NULL),item_image(NULL),
								sound(NULL), mileage(0), player(nullptr), enemy(nullptr), item(nullptr), pt(nullptr), ui(nullptr)
{
	int i;
	for (i = 0; i < 3; i++)
	{
		enemy_image[i] = NULL;
		enemy_count[i] = NULL;
	}
	
}

GameMainScene::~GameMainScene()
{
}

//����������
void GameMainScene::Initialize()
{

	//�����_�l��ǂݍ���
	ReadHighScore();

	//�摜�̓ǂݍ���
	back_ground = LoadGraph("Resource/images/back.bmp");
	//back_ground = LoadGraph("Resource/images/space.bmp");

	barrier_image = LoadGraph("Resource/images/barrier.png");
	int result = LoadDivGraph("Resource/images/car.bmp", 3, 3, 1, 63, 120, enemy_image); 
	//item_image = LoadGraph("Resource/images/gasoline.bmp");
	
	//������
	image = LoadGraph("Resource/images/supana.bmp");

	//BGM(�C���ŕς���)
	//sound = LoadSoundMem("Resource/sound/BreakItDown.mp3");
	//sound = LoadSoundMem("Resource/sound/HappyMoment.mp3");
	sound = LoadSoundMem("Resource/sound/LoveAndGold.mp3");

	//�{�����[���iBGM�j
	ChangeVolumeSoundMem(255 * 70 / 100, sound);

	//�w�i�i�n�ʁj�̃t�B���^�[
	GraphFilter(back_ground, DX_GRAPH_FILTER_LEVEL, 35, 210, 120, 0, 255);
	GraphFilter(back_ground, DX_GRAPH_FILTER_GAUSS, 32, 10);


	//�G���[�`�F�b�N
	if (back_ground == -1)
	{
		throw("Resource/images/back.bmp������܂���\n");
	}
	if (result == -1)
	{
		throw("Resource/images/car.bmp������܂���\n");
	}
	if (barrier_image == -1)
	{
		throw("Resource/images/barrier.png������܂���\n");
	}
	if (item_image == -1)
	{
		throw("Resource/images/gasoline.bmp������܂���");
	}

	//�I�u�W�F�N�g�̐���
	player = new Player;
	enemy = new Enemy_T;
	item = new Item(item_image);
	
	ui = new UI_T;
	ui->Initialize();
	

	//chara = new Character;
	pt = new Player_T;

	//�I�u�W�F�N�g�̏�����
	player->Initialize();

	/*for (int i = 0; i < 10; i++)
	{
		enemy[i] = nullptr;
	}*/
	for (int i = 0; i < 10; i++)
	{
		item = nullptr;
	}
}

//�X�V����
eSceneType GameMainScene::Update()
{

	//BGM�Đ�
	PlaySoundMem(sound, DX_PLAYTYPE_LOOP, FALSE);

	//�v���C���[�̍X�V
	//player->Update();
	pt->Update();
	enemy->Update();

	ui->SetCursor(pt->GetCursor());

	ui->SetMoney(pt->GetMoney(), pt->GetMaxMoney());

	ui->SetEx(pt->GetExPoint(), pt->GetMaxExPoint());
	/*
	if (flg == 0)
	{
		chara = new Nomal;
		chara->Initialize();
		flg = 1;
	}
	*/

	//�ړ������̍X�V
	mileage += (int)player->GetSpeed() + 2;

	//�G��������
	/*if (mileage / 20 % 60 == 0)
	{
		for (int i = 0; i < 10; i++)
		{
			if (enemy[i] == nullptr)
			{
				int type = GetRand(3) % 3;
				enemy[i] = new Enemy_T(type, enemy_image[type]);
				enemy[i]->Initialize();
				break;
			}
		}
	}*/

	//�A�C�e������
	if (mileage / 20 % (GetRand(250) + 10) == 0)
	{
		for (int i = 0; i < 10; i++)
		{
			if (item == nullptr)
			{
				int type = item_image;
				item = new Item(item_image);
				item->Initialize();
				break;
			}
		}
	}
	
	//�A�C�e���̍X�V�Ɠ����蔻��
	for (int i = 0; i < 10; i++)
	{
		if (item != nullptr)
		{
			item->Update(player->GetSpeed());

			//��ʊO�ɍs������A�폜
			if (item->GetLocation().y >= 640.0f)
			{
				item->Finalize();
				delete item;
				item = nullptr;
			}

			//�����蔻��̊m�F
			if (IsHitCheck(player, item))
			{
				player->FuelUp();
				if (player->GetFuel() < 85000.0f)
				{
					//�R����
					player->DecreaseFuel(+7000.0f);

					if (player->GetFuel() > 85000.0f)	
					{
						player->GetFuel();
					}
				}
				item->Finalize();
				delete item;
				item = nullptr;
			}
		}
	}
	
	//�G�̍X�V�Ɠ����蔻��`�F�b�N
	//for (int i = 0; i < 10; i++)
	//{
	//	if (enemy[i] != nullptr)
	//	{
	//		enemy[i]->Update(player->GetSpeed());

	//		//��ʊO�ɍs������A�G���폜���ăX�R�A���Z
	//		if (enemy[i]->GetLocation().y >= 640.0f)
	//		{
	//			enemy_count[enemy[i]->GetType()]++;
	//			enemy[i]->Finalize();
	//			delete enemy[i];
	//			enemy[i] = nullptr;
	//		}

	//		//�����蔻��̊m�F
	//		if (IsHitCheck(player, enemy[i]))
	//		{
	//			player->SetActive(false);
	//			player->DecreaseHp(-160.0f);
	//			player->CarCrash();
	//			enemy[i]->Finalize();
	//			delete enemy[i];
	//			enemy[i] = nullptr;
	//		}
	//	}
	//}

	/*
	//start�{�^���Ń^�C�g����
	if (InputControl::GetButtonDown(XINPUT_BUTTON_START))
	{
		WaitTimer(300);
		return eSceneType::E_TITLE;
	}

	//Y�{�^���Ń��U���g��
	if (InputControl::GetButtonDown(XINPUT_BUTTON_Y))
	{
		return eSceneType::E_RESULT;
	}
	*/
	//�v���C���[�̔R�����̗͂�0�����Ȃ�A���U���g�ɑJ�ڂ���
	if (player->GetFuel() < 0.0f || player->GetHp() < 0.0f)
	{
		return eSceneType::E_RESULT;
	}
	return GetNowScene();
}

//�`�揈��
void GameMainScene::Draw() const
{
	
	//�w�i�摜�̕`��
	/*DrawGraph(0, mileage % 480 - 480, back_ground, TRUE);
	DrawGraph(0, mileage % 480, back_ground, TRUE);*/

	/*********�w�i�摜�̕`��(���X�N���[��)****************
	DrawGraph(mileage % 480 - 480, 0, back_ground, TRUE);
	DrawGraph(mileage % 480, 0, back_ground, TRUE);
	******************************************************/

	//chara->Draw();

	ui->Draw();

	pt->Draw();
	enemy->Draw();

}

//�I��������
void GameMainScene::Finalize()
{
	//BGM���~�߂�
	StopSoundMem(sound);

	//�X�R�A���v�Z����
	mileage = mileage / 10;
	int score = (mileage * 10);
		
	for (int i = 0; i < 3; i++)
	{
		score += (i + 1) * 50 * enemy_count[i];
	}

	//���U���g�f�[�^�̏�������
	FILE* fp = nullptr;

	//�t�@�C���I�[�v��
	errno_t result = fopen_s(&fp, "Resource/dat/result_data.csv", "w");

	//�G���[�`�F�b�N
	if (result != 0)
	{
		throw("Resource/dat/result_data.csv���J���܂���\n");
	}

	//�X�R�A��ۑ�
	fprintf(fp, "%d,\n", score);
	fprintf(fp, "%d,\n", mileage);

	//���������Ɠ��_��ۑ�
	for (int i = 0; i < 3; i++)
	{
		fprintf(fp, "%d,\n", enemy_count[i]);
	}

	//�t�@�C���N���[�Y
	fclose(fp);

	//���I�m�ۂ����I�u�W�F�N�g���폜����
	player->Finalize();
	delete player;

	pt->Finalize();
	delete pt;

	/*for (int i = 0; i < 10; i++)
	{
		if (enemy[i] != nullptr)
		{
			enemy[i]->Finalize();
			delete enemy[i];
			enemy[i] = nullptr;
		}
	}*/
	
	for (int i = 0; i < 10; i++)
	{
		if (item != nullptr)
		{
			item->Finalize();
			delete item;
			item = nullptr;
		}
	}
	delete item;
	delete[] enemy;
}

//���݂̃V�[�������擾
eSceneType GameMainScene::GetNowScene() const
{
	return eSceneType::E_MAIN;
}

//�n�C�X�R�A�̓ǂݍ���
void GameMainScene::ReadHighScore()
{
	RankingData data;
	data.Initialize();

	high_score = data.GetScore(0);

	data.Finalize();
}

//�����蔻�菈���i�v���[���[�ƓG�j
bool GameMainScene::IsHitCheck(Player* p, Enemy_T* e)
{
	//�v���C���[���o���A��\���Ă�����A�����蔻��𖳎�����
	if (p->IsBarrier())
	{
		return false;
	}

	//�G��񂪖�����΁A�����蔻��𖳎�����
	if (e == nullptr)
	{
		return false;
	}

	//�ʒu���̍������擾
	/*Vector2D diff_location = p->GetLocation() - e->GetLocation();*/

	//�����蔻��T�C�Y�̑傫�����擾
	/*Vector2D box_ex = p->GetBoxSize() + e->GetBoxSize();*/

	//�R���W�����f�[�^���ʒu���̍������������Ȃ�A�q�b�g����Ƃ���
	/*return ((fabsf(diff_location.x) < box_ex.x) && (fabsf(diff_location.y) < box_ex.y));*/
}


//�A�C�e�������蔻��
bool GameMainScene::IsHitCheck(Player* p, Item* i)
{

	//�A�C�e����񂪖�����΁A�����蔻��𖳎�����
	if (i == nullptr)
	{
		return false;
	}

	//�ʒu���̍������擾
	Vector2D diff_location = p->GetLocation() - i->GetLocation();

	//�����蔻��T�C�Y�̑傫�����擾
	Vector2D box_ex = p->GetBoxSize() + i->GetBoxSize();

	//�R���W�����f�[�^���ʒu���̍������������Ȃ�A�q�b�g����Ƃ���
	return ((fabsf(diff_location.x) < box_ex.x) && (fabsf(diff_location.y) < box_ex.y));
}