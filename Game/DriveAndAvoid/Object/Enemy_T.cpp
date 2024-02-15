#include "Enemy_T.h"
#include "DxLib.h"
#include "Normal.h"
#include "Tank.h"
#include "Range.h"
#include "Kiba.h"

Enemy_T::Enemy_T() : Hp(0), AttackCount(0)
{
	chara = new Character * [_MAX_ENEMY_CHARACTOR_];
	for (int i = 0; i < _MAX_ENEMY_CHARACTOR_; i++)
	{
		chara[i] = nullptr;
	}
}

Enemy_T::~Enemy_T()
{
}

//‰Šú‰»ˆ—
void Enemy_T::Initialize()
{
	Hp = 1000;
	enemy_popcount = 0;
	charaCount = 0;
	AttackCount = 100;
}

void Enemy_T::Update()
{
	if (enemy_popcount >= 300)
	{
		randomchar();
		enemy_popcount = 0;
	}
	else
	{
		enemy_popcount++;
	}

	for (charaCount = 0; charaCount < _MAX_ENEMY_CHARACTOR_; charaCount++)
	{
		if (chara[charaCount] == nullptr)
		{
			break;
		}

		chara[charaCount]->SetType(2);
		chara[charaCount]->Update();
	}
}

void Enemy_T::randomchar()
{
	int num = rand() % 100 + 1;

	if (num <= 60)
	{
		if (charaCount < _MAX_ENEMY_CHARACTOR_ && chara[charaCount] == nullptr)
		{
			chara[charaCount] = new Nomal;
			chara[charaCount]->Initialize();
		}
	}
	else if (num <= 85)
	{
		if (charaCount < _MAX_ENEMY_CHARACTOR_ && chara[charaCount] == nullptr)
		{
			chara[charaCount] = new Tank;
			chara[charaCount]->Initialize();
		}
	}
	else if (num <= 95)
	{
		if (charaCount < _MAX_ENEMY_CHARACTOR_ && chara[charaCount] == nullptr)
		{
			chara[charaCount] = new Range;
			chara[charaCount]->Initialize();
		}
	}
	else
	{
		if (charaCount < _MAX_ENEMY_CHARACTOR_ && chara[charaCount] == nullptr)
		{
			chara[charaCount] = new Kiba;
			chara[charaCount]->Initialize();
		}
	}

}

void Enemy_T::Draw() const
{
	for (int i = 0; i < _MAX_ENEMY_CHARACTOR_; i++)
	{
		if (chara[i] == nullptr)
		{
			break;
		}
		chara[i]->Draw();
	}

	//DrawFormatString(20, 20, 0xffffff, "charaCount = %d", this->charaCount);
}



void Enemy_T::Finalize()
{
	for (int i = 0; i < _MAX_ENEMY_CHARACTOR_; i++)
	{
		if (chara[i] != nullptr)
		{
			delete chara[i];
		}

		chara[i] = nullptr;
	}
}

void Enemy_T::EnemyCastleHp(float Attack)
{
	this->Hp -= Attack;

	//HP‚ð‚O‚ÅŽ~‚ß‚é
	if (Hp < 0)
	{
		Hp = 0;
	}

}

bool Enemy_T::HpCheck()
{
	bool rex = (Hp <= 0);
	return rex;
}

Character** Enemy_T::GetCharacter(int count)
{
	return chara;
}