#pragma once
#pragma once

#include"Character.h"
#include "UI_T.h"

//�R�n�L����_�q�N���X
class Kiba : public Character
{
private:

	Vector2D Playerlocation;
	Vector2D Enemylocation;
	UI_T* ui;

	float hp;		//�̗�
	float power;	//�U����

	//�摜�f�[�^�i�[
	int graphic;

	//�G���v���C���[��{ 1:�v���C���[, 2: �G }
	int type;

public:

	Kiba();
	~Kiba();

	virtual void Initialize() override;
	virtual void Draw() override;
	virtual void Update() override;


	//void SetType(int type) { this->type = type; }
	virtual void  SetType(int type) override;

};