#include"Normal.h"
#include"DxLib.h"

Nomal::Nomal() : hp(NULL), power(NULL), graphic(NULL), type(NULL), location(0.0f)
{
}

Nomal::~Nomal()
{
}

void Nomal::Initialize()
{

	hp = 100;
	power = 10;
	graphic = LoadGraph("Resource/images/walking2_man.png");

	//エラーチェック
	if (graphic == -1)
	{
		throw("Resource/images/walking2_man.pngがありません\n");
	}

}

void Nomal::Update()
{
	//移動処理
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


void Nomal::Draw()
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