#pragma once


#include"../Utility/Vector2D.h"
#include"DxLib.h"

#define CHARACTER_SPEED 1.0f


//�L�����N�^�[�̎��
enum CharacterType
{
	Nomal,	//�m�[�}��
	Tank,	//�^���N
	Range,	//�͈͍U��
	Kiba	//�R�n
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

};