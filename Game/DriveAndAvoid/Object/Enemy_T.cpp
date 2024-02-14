#include "Enemy_T.h"
#include "DxLib.h"

enum Enemy
{
 enemy1,
 enemy2,
 enemy3,
 enemy4
};

Enemy_T::Enemy_T() : Hp(0)
{
}

Enemy_T::~Enemy_T()
{
}

//‰Šú‰»ˆ—
void Enemy_T::Initialize()
{
	Hp = 1000;
	enemy_popcount = 0;
}

void Enemy_T::Update(float speed)
{
	if (enemy_popcount >= 50)
	{
		randomchar();
		enemy_popcount = 0;
	}
	else
	{
		enemy_popcount++;
	}
}

void Enemy_T::randomchar()
{
	int num = rand() % 100 + 1;

	if (num <= 50)
	{
		enemy1;
	}
	else if (num <= 70)
	{
		enemy2;
	}
	else if (num <= 80)
	{
		enemy3;
	}
	else
	{
		enemy4;
	}

}

void Enemy_T::Move()
{
	
}

void Enemy_T::Draw() const
{
	int Normal;
	int tank;
	int Range;
	int Kiba;

	Normal = LoadGraph("Resouce/images/walking2_man.png");
	tank = LoadGraph("Resouce/images/war_shield_man.png");
	Range = LoadGraph("Resouce/images/Range.png");
	Kiba = LoadGraph("Resouce/images/kiba.png");

	DrawTurnGraph(0, 0, Normal, TRUE);
	DrawTurnGraph(0, 0, tank, TRUE);
	DrawTurnGraph(0, 0, Range, TRUE);
	DrawTurnGraph(0, 0, Kiba, TRUE);
}



void Enemy_T::Finalize()
{
}



int Enemy_T::GetHp()
{
	return Hp;
}