#pragma once

#include "Character.h"


#define _MAX_ENEMY_CHARACTOR_ 10

class Enemy_T
{
private:
	int Hp;
	int enemy_popcount;

	Character** chara;

	int charaCount;
	int AttackCount;
public:
	//コンストラクタ(インスタンス生成時に最初に呼ばれる関数)
	Enemy_T();

	//デストラクタ
	~Enemy_T();

	void Initialize();				//初期化処理
	void Update();		//更新処理
	void Draw() const;              //描画処理
	void Finalize();				//終了時処理

	void EnemyCastleHp(float Attack);

	int GetHp() { return Hp; }
	bool HpCheck();
	void randomchar();
	int GetCharaCount() { return this->charaCount; }

	void SetAttackCount() { AttackCount = 50; }
	Character** GetCharacter(int count);
};

