#pragma once


#include"../Utility/Vector2D.h"
#include"DxLib.h"

#define CHARACTER_SPEED 1.0f

//�L�����N�^�[�̎��(�񋓌^)
enum CharacterType
{
	Nomal_type,	//�m�[�}��
	Tank_type,	//�^���N
	Range_type,	//�͈͍U��
	Kiba_type	//�R�n
};


//�L�����N�^�[�̊��N���X
class Character
{

public:

	//�R���X�g���N�^
	Character() {};

	virtual ~Character() {};

	virtual void Initialize() {};	//���������� 
	virtual void Update() {};		//�X�V���� 
	virtual void Draw() {};			//�`�揈�� 

	virtual void SetType(int type) {};
	virtual void SetSubHp(int Damege) {};
	virtual Vector2D GetPlayerLocation() { return Vector2D(); }
	virtual Vector2D GetEnemyLocation() { return Vector2D(); }

	virtual int GetPower() = 0;
	virtual bool HpCheck() = 0;
	virtual void SetAttackflg(bool b) {};
	virtual int WaitAttackTime() = 0;
	virtual void SetPlayerLocation(Vector2D p) {};
	virtual void SetEnemyLocation(Vector2D e) {};
	virtual int GetExPoint() = 0;
	virtual int GetMoney() = 0;
};