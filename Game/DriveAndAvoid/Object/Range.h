#pragma once
#pragma once

#include"Character.h"

class Range : public Character
{
private:

	float hp;		//�̗�
	float power;	//�U����


	//�摜�f�[�^�i�[
	int* graphic;

public:

	virtual void Initialize() override;
	virtual void Draw() override;
	virtual void Update() override;

};