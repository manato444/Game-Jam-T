#pragma once
#include "../Utility/Vector2D.h"
#include "Character.h"


#define _MAX_PLAYER_CHARACTOR_ 10

class Player_T
{
private:
	int Hp;    //���Hp
	bool is_Pause;  //�|�[�Y��?
	int Cursor;     //�J�[�\��
	int Level;      //Level�̊Ǘ�
	int ExPoint;    //�o���l�̊Ǘ�
	int MaxExPoint[4] = { 30,50,70,100 };

	int MaxMoney[5] = { 100,150,200,250,300 };
	int Money;
	int Count;
	int ButtonCount;

	Character** chara;

	int charaCount;
	int AttackCount;

private:
	static float stick2[2];
	static Vector2D stick[2];
	
public:

	//�R���X�g���N�^(�C���X�^���X�������ɍŏ��ɌĂ΂��֐�)
	Player_T();

	//�f�X�g���N�^
	~Player_T();

	void Initialize();		//����������
	void Update();			//�X�V����
	void Draw() const;			//�`�揈��
	void Finalize();		//�I��������

	void DecreaseCastleHp(float Attack);
	void SetExPoint(int point);

	bool Is_PauseCheck() { return this->is_Pause; }
	int GetCursor() { return this->Cursor; }
	int GetCastleHp() { return this->Hp; }
	int GetExPoint() { return this->ExPoint; }
	int GetLevel() { return this->Level; }
	int GetMaxExPoint() { return this->MaxExPoint[Level]; }
	int GetMoney() { return this->Money; }
	int GetMaxMoney() { return this->MaxMoney[Level]; }

	int GetCharaCount() { return this->charaCount; }

	bool HpCheck();
	void SetAttackCount() { AttackCount = 50; }
	Character** GetCharacter();
private:
	void InputControlUi();

	void PopCharactor();

	static float SetLeft_Stick_X();	//���X�e�B�b�NX���W���Z�b�g
	static float SetLeft_Stick_Y();	//���X�e�B�b�NY���W���Z�b�g
	static float SetRight_Stick_X();//�E�X�e�B�b�NY���W���Z�b�g

	void ExManager();
	void MoneyManager();
};

