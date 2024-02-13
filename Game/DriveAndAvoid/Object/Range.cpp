#include"Character.h"
#include"DxLib.h"
#include"Range.h"

Range::Range() : hp(NULL), power(NULL), graphic(NULL), type(NULL), location(0.0f)
{
}

Range::~Range()
{
}

void Range::Initialize()
{
	hp = 500;
	power = 20;

	graphic = LoadGraph("Resource/images/kiba.png");

	//エラーチェック
	if (graphic == -1)
	{
		throw("Resource/images/kiba.pngがありません\n");
	}
}

void Range::Update()
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

void Range::Draw()
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