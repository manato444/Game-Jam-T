#pragma once
#include"../Utility/Vector2D.h"
class UI_T
{
private:
	int Money;
	int MaxMoney;
	int Level;
	int Green;
	int Siro;
	int Cursor;
	int Ex;
	int MaxExPoint;
	int NormalMan;
	int ShieldMan;
	int RangeMan;
	int CarMan;
	int PlayerHP;
	int EnemyHP;

	bool Player;
	bool Enemy;

public:
	UI_T();
	~ UI_T();
	void Initialize();
	void Update();
	void Draw() const;
	void Finalize();

	void SetMoney(int Money, int MaxMoney);
	void SetLevel(int Level);
	void SetCursor(int cursor);
	void SetEx(int Ex, int MaxExPoint);
	void SetHP(int PlayerHP, int EnemyHP);
	Vector2D GetPlayerSiro();
	Vector2D GetEnemySiro();

	void PlayerWin(bool p) { this->Player = p; }
	void EnemyWin(bool e) { this->Enemy = e; }
};

