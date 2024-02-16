#include"Character.h"
#include"DxLib.h"
#include"Kiba.h"

Kiba::Kiba() : hp(NULL), power(NULL), graphic(NULL), type(NULL), Playerlocation(0.0f), Enemylocation(0.0f), ui(nullptr),
is_Attack(false), ExPoint(0), Money(0)
{
}

Kiba::~Kiba()
{
	DeleteGraph(graphic);
}

void Kiba::Initialize()
{

	hp = 500;
	power = 100;
	ExPoint = 50;
	Money = 200;

	graphic = LoadGraph("Resource/images/car_man.png");

	ui = new UI_T;

	Playerlocation = ui->GetPlayerSiro();
	Enemylocation = ui->GetEnemySiro();

	//エラーチェック
	if (graphic == -1)
	{
		throw("Resource/images/car_man.pngがありません\n");
	}

}

void Kiba::Update()
{
	//移動処理()
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

void Kiba::Draw()
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

void Kiba::SetType(int type)
{
	this->type = type;
}

Vector2D Kiba::GetPlayerLocation()
{
	return this->Playerlocation;
}

Vector2D Kiba::GetEnemyLocation()
{
	return this->Enemylocation;
}

void Kiba::SetSubHp(int Damege)
{
	this->hp -= Damege;
}

int Kiba::GetPower()
{
	return power;
}

void Kiba::SetAttackflg(bool b)
{
	is_Attack = b;
}

bool Kiba::HpCheck()
{
	bool rex = (hp <= 0);
	return rex;
}

int Kiba::WaitAttackTime()
{
	return 30;
}


void Kiba::SetPlayerLocation(Vector2D p)
{
	Playerlocation = p;
}

void Kiba::SetEnemyLocation(Vector2D e)
{
	Enemylocation = e;
}

int Kiba::GetExPoint()
{
	return ExPoint;
}

int Kiba::GetMoney()
{
	return Money;
}