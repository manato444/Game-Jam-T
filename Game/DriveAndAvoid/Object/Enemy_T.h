#pragma once

#include "Character.h"


#define _MAX_ENEMY_CHARACTOR_ 10

class Enemy_T
{
private:
	int Hp;
	int enemy_popcount;

	Character** chara;

	int charaCount;
	int AttackCount;
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

	int GetHp() { return Hp; }
	bool HpCheck();
	void randomchar();
	int GetCharaCount() { return this->charaCount; }

	void SetAttackCount() { AttackCount = 50; }
	Character** GetCharacter(int count);
};

