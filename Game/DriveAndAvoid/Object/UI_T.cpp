#include "UI_T.h"
#include "DxLib.h"

UI_T::UI_T() : Money(0), MaxMoney(0),Level(0),Cursor(0),Ex(0),MaxExPoint(0),Green(NULL),Siro(NULL),NormalMan(NULL),
ShieldMan(NULL),RangeMan(NULL),CarMan(NULL),PlayerHP(0),EnemyHP(0),Player(false),Enemy(false)
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
		throw("Resource/images/bg_green.jpgがありません\n");
	}
	if (Siro == -1) 
	{
		throw("Resource/images/siro.pngがありません\n");
	}
	if (NormalMan == -1)
	{
		throw("Resource/images/walking2_man.pngがありません\n");
	}
	if (ShieldMan == -1)
	{
		throw("Resource/images/war_shield_man.pngがありません\n");
	}
	if (RangeMan == -1)
	{
		throw("Resource/images/Range.pngがありません\n");
	}
	if (CarMan == -1)
	{
		throw("Resource/images/car_man.pngがありません\n");
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

	DrawFormatString(40, 40, 0xff0000, "Level %d / 8", this->Level + 1);

	DrawFormatString(40, 60, 0xff0000, "Exp %04d /Next %04d", this->Ex, this->MaxExPoint);

	DrawFormatString(60, 300, 0xff0000, "PlayerHP \n %d", this->PlayerHP);
	DrawFormatString(550, 300, 0xff0000, "EnemyHP \n %d", this->EnemyHP);

	DrawRotaGraph(60, 440, 0.14, 0, NormalMan, TRUE, TRUE);
	DrawFormatString(60, 450, 0xff0000, "20");
	DrawRotaGraph(140, 440, 0.14, 0, ShieldMan, TRUE, TRUE);
	DrawFormatString(140, 450, 0xff0000, "50");
	DrawRotaGraph(220, 440, 0.07, 0, RangeMan, TRUE);
	DrawFormatString(220, 450, 0xff0000, "120");
	DrawRotaGraph(300, 440, 0.14, 0, CarMan, TRUE);
	DrawFormatString(300, 450, 0xff0000, "200");

	if (Player || Enemy)
	{
		//SetFontSize(200);
		if (Player)
		{
			DrawFormatString(200, 150, 0xff0000, "Playerの勝利");
		}
		else if(Enemy)
		{
			DrawFormatString(200, 150, 0xff0000, "Enemyの勝利");
		}
		//SetFontSize(60);
		DrawFormatString(200, 300, 0xff0000, "Bボタンでタイトルへ");
	}
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

void UI_T::SetHP(int PlayerHP, int EnemyHP)
{
	this->PlayerHP = PlayerHP;
	this->EnemyHP = EnemyHP;
}