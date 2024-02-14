#pragma once
class UI_T
{
private:
	int Money;
	int MaxMoney;
	int Level;
public:
	UI_T();
	~ UI_T();
	void Initialize();
	void Update();
	void Draw() const;
	void Finalize();

	void SetMoney(int Money, int MaxMoney);
	void SetLevel(int Level);

};

