#pragma once
#pragma once

#include"Character.h"

//�͈͍U���L����_�q�N���X
class Range : public Character
{
private:

	Vector2D location;

	float hp;		//�̗�
	float power;	//�U����


	//�摜�f�[�^�i�[
	int graphic;

	//�G���v���C���[��{ 1:�v���C���[, 2: �G }
	int type;

public:

	Range();
	~Range();

	virtual void Initialize() override;
	virtual void Draw() override;
	virtual void Update() override;

	//void SetType(int type) { this->type = type; }
	virtual void  SetType(int type) override;

};