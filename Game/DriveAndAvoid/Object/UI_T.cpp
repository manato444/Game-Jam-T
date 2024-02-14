#include "UI_T.h"
#include "DxLib.h"

UI_T::UI_T() : Money(0), MaxMoney(0),Level(0)
{

}

UI_T::~UI_T() {

}

void UI_T::Initialize() {

}

void UI_T::Update() {

}

void UI_T::Draw()const{
	DrawBox(0, 400, 640, 480, 0x000000, TRUE);
	for (int i = 0; i < 4; i++)
	{
		DrawBox(30 + 60 * i, 410, 80 + 60 * i, 460, 0xffffff, TRUE);
	}

	DrawFormatString(40, 20, 0xff0000, "Money %06d / %06d", this->Money, this->MaxMoney);

	DrawFormatString(40, 40, 0xff0000, "Level %04d", this->Level);
}

void UI_T::Finalize() {

}

void UI_T::SetMoney(int Money, int MaxMoney) {
	this->Money = Money;
	this->MaxMoney = MaxMoney;
}

void UI_T::SetLevel(int Level) {
	this->Level = Level;
}
