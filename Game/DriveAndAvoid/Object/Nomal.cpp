#include"Normal.h"
#include"DxLib.h"

Nomal::Nomal() : hp(NULL), power(NULL), graphic(NULL), type(NULL), Playerlocation(0.0f), Enemylocation(0), ui(nullptr)
{
}

Nomal::~Nomal()
{
	DeleteGraph(graphic);
}

void Nomal::Initialize()
{
	hp = 100;
	power = 10;
	graphic = LoadGraph("Resource/images/walking2_man.png");

	ui = new UI_T;

	Playerlocation = ui->GetPlayerSiro();
	Enemylocation = ui->GetEnemySiro();

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
		Playerlocation += move;
	}
	else if (type == 2)
	{
		Vector2D move = Vector2D(-1.0f, 0.0f);
		Enemylocation += move;
	}
}


void Nomal::Draw()
{
	if (type == 1)
	{
		DrawRotaGraph(Playerlocation.x, Playerlocation.y, 0.3, 0.0, graphic, TRUE, TRUE);
	}
	else if (type == 2)
	{
		DrawRotaGraph(Enemylocation.x, Enemylocation.y, 0.3, 0.0, graphic, TRUE);
	}
}

void Nomal::SetType(int type)
{
	this->type = type;
}