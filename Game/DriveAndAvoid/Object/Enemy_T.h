#pragma once

#include "Character.h"


#define _MAX_CHARACTOR_ 100

class Enemy_T
{
private:
	int Hp;
	int enemy_popcount;

	Character** chara;

	int charaCount;
public:
	//�R���X�g���N�^(�C���X�^���X�������ɍŏ��ɌĂ΂��֐�)
	Enemy_T();

	//�f�X�g���N�^
	~Enemy_T();

	void Initialize();				//����������
	void Update();		//�X�V����
	void Draw() const;              //�`�揈��
	void Finalize();				//�I��������

	void EnemyCastleHp(float Attack);

	int GetHp();
	void randomchar();
};

