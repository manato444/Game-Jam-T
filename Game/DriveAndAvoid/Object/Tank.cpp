#include"Character.h"
#include"DxLib.h"
#include"Tank.h"

Tank::Tank() : hp(NULL), power(NULL), graphic(NULL), type(NULL),location(0.0f)
{
}

Tank::~Tank()
{
}

void Tank::Initialize()
{
	hp = 500;
	power = 20;

	graphic = LoadGraph("Resource/images/war_shield_man.png");

	//�G���[�`�F�b�N
	if (graphic == -1)
	{
		throw("Resource/images/war_shield_man.png������܂���\n");
	}
}

void Tank::Update()
{
	//�ړ�����
	if (type == 1)
	{
		Vector2D move = Vector2D(1.0f, 0.0f);
		location += move;
	}
	else if (type == 2)
	{
		Vector2D move = Vector2D(-1.0f, 0.0f);
		location += move;
	}
}

void Tank::Draw()
{
	if (type == 1)
	{
		DrawRotaGraph(location.x, location.y, 0.3, 0.0, graphic, TRUE);
	}
	else if (type == 2)
	{
		DrawRotaGraph(location.x, location.y, 0.3, 0.0, graphic, TRUE, TRUE);
	}
}

void Tank::SetType(int type)
{
	this->type = type;
}