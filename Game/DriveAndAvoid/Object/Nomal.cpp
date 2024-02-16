#include"Normal.h"
#include"DxLib.h"

Nomal::Nomal() : hp(NULL), power(NULL), graphic(NULL), type(NULL), Playerlocation(0.0f), Enemylocation(0), ui(nullptr),
 is_Attack(false), OneAttack(nullptr), ExPoint(0), Money(0)
{
}

Nomal::~Nomal()
{
	DeleteGraph(graphic);
}

void Nomal::Initialize()
{
	hp = 30;
	power = 10;
	ExPoint = 5;
	Money = 20;

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

void Nomal::SetSubHp(int Damege)
{
	this->hp -= Damege;
}

Vector2D Nomal::GetPlayerLocation()
{
	return this->Playerlocation;
}

Vector2D Nomal::GetEnemyLocation()
{
	return this->Enemylocation;
}

int Nomal::GetPower()
{
	return power;
}

int Nomal::GetExPoint()
{
	return ExPoint;
}

void Nomal::SetAttackflg(bool b)
{
	is_Attack = b;
}

bool Nomal::HpCheck()
{
	bool rex = (hp <= 0);
	return rex;
}

int Nomal::WaitAttackTime()
{
	return 40;
}


void Nomal::SetPlayerLocation(Vector2D p)
{
	Playerlocation = p;
}

void Nomal::SetEnemyLocation(Vector2D e)
{
	Enemylocation = e;
}

int Nomal::GetMoney()
{
	return Money;
}