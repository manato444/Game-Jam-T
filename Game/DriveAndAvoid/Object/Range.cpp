#include"Character.h"
#include"DxLib.h"
#include"Range.h"

Range::Range() : hp(NULL), power(NULL), graphic(NULL), type(NULL), Playerlocation(0.0f), Enemylocation(0.0f), ui(nullptr)
{
}

Range::~Range()
{
	DeleteGraph(graphic);
}

void Range::Initialize()
{
	hp = 500;
	power = 20;

	graphic = LoadGraph("Resource/images/Range.png");

	ui = new UI_T;

	Playerlocation = ui->GetPlayerSiro();
	Enemylocation = ui->GetEnemySiro();

	//エラーチェック
	if (graphic == -1)
	{
		throw("Resource/images/Range.pngがありません\n");
	}
}

void Range::Update()
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

void Range::Draw()
{
	if (type == 1)
	{
		DrawRotaGraph(Playerlocation.x, Playerlocation.y, 0.3, 0.0, graphic, TRUE);
	}
	else if (type == 2)
	{
		DrawRotaGraph(Enemylocation.x, Enemylocation.y, 0.3, 0.0, graphic, TRUE, TRUE);
	}
}

void Range::SetType(int type)
{
	this->type = type;
}