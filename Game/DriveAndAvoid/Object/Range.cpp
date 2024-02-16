#include"Character.h"
#include"DxLib.h"
#include"Range.h"

Range::Range() : hp(NULL), power(NULL), graphic(NULL), type(NULL), Playerlocation(0.0f), Enemylocation(0.0f), ui(nullptr),
is_Attack(false), ExPoint(0), Money(0)
{
}

Range::~Range()
{
	DeleteGraph(graphic);
}

void Range::Initialize()
{
	hp = 100;
	power = 30;
	ExPoint = 20;
	Money = 120;

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
		if (is_Attack)
		{

		}
		else
		{
			Vector2D move = Vector2D(1.0f, 0.0f);
			Playerlocation += move;
		}
	}
	else if (type == 2)
	{
		if (is_Attack)
		{

		}
		else
		{
			Vector2D move = Vector2D(-1.0f, 0.0f);
			Enemylocation += move;
		}
	}
}

void Range::Draw()
{
	if (type == 1)
	{
		DrawRotaGraph(Playerlocation.x, Playerlocation.y, 0.17, 0.0, graphic, TRUE);
	}
	else if (type == 2)
	{
		DrawRotaGraph(Enemylocation.x, Enemylocation.y, 0.17, 0.0, graphic, TRUE, TRUE);
	}
}

void Range::SetType(int type)
{
	this->type = type;
}

Vector2D Range::GetPlayerLocation()
{
	return this->Playerlocation;
}

Vector2D Range::GetEnemyLocation()
{
	return this->Enemylocation;
}

void Range::SetSubHp(int Damege)
{
	this->hp -= Damege;
}

int Range::GetPower()
{
	return power;
}

void Range::SetAttackflg(bool b)
{
	is_Attack = b;
}

bool Range::HpCheck()
{
	bool rex = (hp <= 0);
	return rex;
}

int Range::WaitAttackTime()
{
	return 80;
}


void Range::SetPlayerLocation(Vector2D p)
{
	Playerlocation = p;
}

void Range::SetEnemyLocation(Vector2D e)
{
	Enemylocation = e;
}

int Range::GetExPoint()
{
	return ExPoint;
}

int Range::GetMoney()
{
	return Money;
}