#include "UI_T.h"
#include "DxLib.h"

UI_T::UI_T() : Money(0), MaxMoney(0),Level(0),Cursor(0),Ex(0),MaxExPoint(0),Green(NULL),Siro(NULL),NormalMan(NULL),
ShieldMan(NULL),RangeMan(NULL),CarMan(NULL)
{

}

UI_T::~UI_T() {

}

void UI_T::Initialize() 
{
	Green = LoadGraph("Resource/images/bg_green.jpg");
	Siro = LoadGraph("Resource/images/siro.png");
	NormalMan = LoadGraph("Resource/images/walking2_man.png");
	ShieldMan = LoadGraph("Resource/images/war_shield_man.png");
	RangeMan = LoadGraph("Resource/images/Range.png");
	CarMan = LoadGraph("Resource/images/car_man.png");
	if (Green == -1)
	{
		throw("Resource/images/bg_green.jpg‚ª‚ ‚è‚Ü‚¹‚ñ\n");
	}
	if (Siro == -1) 
	{
		throw("Resource/images/siro.png‚ª‚ ‚è‚Ü‚¹‚ñ\n");
	}
	if (NormalMan == -1)
	{
		throw("Resource/images/walking2_man.png‚ª‚ ‚è‚Ü‚¹‚ñ\n");
	}
	if (ShieldMan == -1)
	{
		throw("Resource/images/war_shield_man.png‚ª‚ ‚è‚Ü‚¹‚ñ\n");
	}
	if (RangeMan == -1)
	{
		throw("Resource/images/Range.png‚ª‚ ‚è‚Ü‚¹‚ñ\n");
	}
	if (CarMan == -1)
	{
		throw("Resource/images/car_man.png‚ª‚ ‚è‚Ü‚¹‚ñ\n");
	}
}

void UI_T::Update() {

}

void UI_T::Draw()const{

	DrawRotaGraph(320, 200,1.5,0, Green, TRUE);

	DrawRotaGraph(80, 230,0.4,0, Siro, TRUE);
	DrawRotaGraph(570, 230, 0.4, 0, Siro, TRUE,TRUE);

	

	DrawBox(0, 400, 640, 480, 0x000000, TRUE);
	DrawBox(25 + 80 * Cursor, 405, 95 + 80 * Cursor, 475, 0xff0000, TRUE);
	for (int i = 0; i < 4; i++)
	{
		DrawBox(30 + 80 * i, 410, 90 + 80 * i, 470, 0xffffff, TRUE);
	}
	DrawBox(30 + 80 * Cursor, 410, 90 + 80 * Cursor, 470, 0xff0000, FALSE);

	DrawFormatString(40, 20, 0xff0000, "Money %06d / %06d", this->Money, this->MaxMoney);

	DrawFormatString(40, 40, 0xff0000, "Level %d / 5", this->Level + 1);

	DrawFormatString(40, 60, 0xff0000, "Exp %04d /Next %04d", this->Ex, this->MaxExPoint);

	DrawRotaGraph(60, 440, 0.14, 0, NormalMan, TRUE, TRUE);
	DrawRotaGraph(140, 440, 0.14, 0, ShieldMan, TRUE, TRUE);
	DrawRotaGraph(220, 440, 0.07, 0, RangeMan, TRUE);
	DrawRotaGraph(300, 440, 0.14, 0, CarMan, TRUE);
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

void UI_T::SetCursor(int cursor) {
	this->Cursor = cursor;
}

void UI_T::SetEx(int Ex, int MaxExPoint){
	this->Ex = Ex;
	this->MaxExPoint = MaxExPoint;
}

Vector2D UI_T::GetPlayerSiro() {
	return Vector2D(80, 230);
}

Vector2D UI_T::GetEnemySiro() {
	return Vector2D(570, 230);
}
