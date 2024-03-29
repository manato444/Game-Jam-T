#include"Character.h"
#include"DxLib.h"
#include"Tank.h"

Tank::Tank() : hp(NULL), power(NULL), graphic(NULL), type(NULL),Playerlocation(0.0f), Enemylocation(0.0f), ui(nullptr),
is_Attack(false), ExPoint(0), Money(0)
{
}

Tank::~Tank()
{
	DeleteGraph(graphic);
}

void Tank::Initialize()
{
	hp = 180;
	power = 8;
	ExPoint = 10;
	Money = 50;

	graphic = LoadGraph("Resource/images/war_shield_man.png");

	ui = new UI_T;

	Playerlocation = ui->GetPlayerSiro();
	Enemylocation = ui->GetEnemySiro();

	//エラーチェック
	if (graphic == -1)
	{
		throw("Resource/images/war_shield_man.pngがありません\n");
	}
}

void Tank::Update()
{
	//移動処理
	if (type == 1)
	{
		if (is_Attack)
		{

		}
		else
		{
			Vector2D move = Vector2D(0.5f, 0.0f);
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
			Vector2D move = Vector2D(-0.5f, 0.0f);
			Enemylocation += move;
		}
	}
}

void Tank::Draw()
{
	if (type == 1)
	{
		DrawRotaGraph(Playerlocation.x, Playerlocation.y, 0.3, 0.0, graphic, TRUE, TRUE);
	}
	else if (type == 2)
	{
		DrawRotaGraph(Enemylocation.x, Enemylocation.y, 0.3, 0.0, graphic, TRUE, FALSE);
	}
}

void Tank::SetType(int type)
{
	this->type = type;
}

Vector2D Tank::GetPlayerLocation()
{
	return this->Playerlocation;
}

Vector2D Tank::GetEnemyLocation()
{
	return this->Enemylocation;
}

void Tank::SetSubHp(int Damege)
{
	this->hp -= Damege;
}

int Tank::GetPower()
{
	return power;
}

void Tank::SetAttackflg(bool b)
{
	is_Attack = b;
}

bool Tank::HpCheck()
{
	bool rex = (hp <= 0);
	return rex;
}

int Tank::WaitAttackTime()
{
	return 50;
}

void Tank::SetPlayerLocation(Vector2D p)
{
	Playerlocation = p;
}

void Tank::SetEnemyLocation(Vector2D e)
{
	Enemylocation = e;
}

int Tank::GetExPoint()
{
	return ExPoint;
}

int Tank::GetMoney()
{
	return Money;
}