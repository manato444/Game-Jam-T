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

	Vector2D GetPlayerSiro();
	Vector2D GetEnemySiro();
};

