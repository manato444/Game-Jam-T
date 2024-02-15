#include "Player_T.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"
#include "Normal.h"
#include "Tank.h"
#include "Range.h"
#include "Kiba.h"

float Player_T::stick2[2] = {};
Vector2D Player_T::stick[2] = {};

Player_T::Player_T() : Hp(0), Cursor(0), is_Pause(false), Money(0), Level(0), Count(0), ButtonCount(0)
{
	chara = new Character * [_MAX_CHARACTOR_];
	for (int i = 0; i < _MAX_CHARACTOR_; i++)
	{
		chara[i] = nullptr;
	}
}

Player_T::~Player_T()
{

}

void Player_T::Initialize()
{
	charaCount = 0;
	Hp = 1000;
	Cursor = 0;
}

void Player_T::Update()
{
	InputControlUi();

	//操作不可状態であれば、自身を回転させる
	if (is_Pause)
	{
		//もう一度Startボタンを押すと、Pause解除
		if (InputControl::GetButtonDown(XINPUT_BUTTON_START))
		{
			is_Pause = false;
		}
		return;
	}

	for (charaCount = 0; charaCount < _MAX_CHARACTOR_; charaCount++)
	{
		if (chara[charaCount] == nullptr)
		{
			break;
		}

		chara[charaCount]->SetType(1);
		chara[charaCount]->Update();
	}

	ExManager();

	if (Count >= 50)
	{
		MoneyManager();
		Count = 0;
	}
	else
	{
		Count++;
	}
}

void Player_T::Draw() const
{
	for (int i = 0; i < _MAX_CHARACTOR_; i++)
	{
		if (chara[i] == nullptr)
		{
			break;
		}
		chara[i]->Draw();
	}

	DrawFormatString(20, 20, 0xffffff, "StickX = %lf", this->SetLeft_Stick_X());
}

void Player_T::Finalize()
{
	//キャラに画像が入っていたら
	for (int i = 0; i < _MAX_CHARACTOR_; i++)
	{
		if (chara[i] != nullptr)
		{
			delete chara[i];
			chara[i] = nullptr;
		}
	}
}

//左スティックの値をセット
float Player_T::SetLeft_Stick_X()
{
	stick2[0] = InputControl::GetLeft_Stick_X();

	return stick2[0];
}

//左スティックの値をセット
float Player_T::SetLeft_Stick_Y()
{
	stick2[1] = InputControl::GetLeft_Stick_Y();

	return stick2[1];
}

//右スティックの値をセット
float Player_T::SetRight_Stick_X()
{
	stick[0] = InputControl::GetLeft_Stick_Y();

	return stick2[0];
}

void Player_T::InputControlUi()
{
	if (!is_Pause)
	{

		//STARTボタンでPause
		/*if (InputControl::GetButtonDown(XINPUT_BUTTON_START))
		{
			is_Pause = true;
		}*/

		//十字移動処理
		if (InputControl::GetButtonDown(XINPUT_BUTTON_DPAD_LEFT))
		{
			Cursor--;
			if (Cursor < 0)
			{
				Cursor = 3;
			}
		}
		if (InputControl::GetButtonDown(XINPUT_BUTTON_DPAD_RIGHT))
		{
			Cursor++;
			if (Cursor > 3)
			{
				Cursor = 0;
			}
		}

		//スティック移動処理
		if (Player_T::SetLeft_Stick_X())
		{
			if (stick2[0] >= 0.1f && ButtonCount == 0)
			{
				Cursor++;
				ButtonCount++;
				if (Cursor > 3)
				{
					Cursor = 0;
				}
			}
			else if (stick2[0] <= -0.1f && ButtonCount == 0)
			{
				Cursor--;
				ButtonCount++;
				if (Cursor < 0)
				{
					Cursor = 3;
				}
			}
			else if (stick2[0] < 0.1f && stick2[0] > -0.1f)
			{
				Cursor;
				ButtonCount = 0;
			}
		}

		if (InputControl::GetRightStick)
		{
			if (stick[0].x >= 0.1f)
			{
				Cursor++;
				if (Cursor > 4)
				{
					Cursor = 0;
				}
			}
			else if (stick[0].x <= -0.1f)
			{
				Cursor--;
				if (Cursor < 0)
				{
					Cursor = 4;
				}
			}
			else if (stick[0].x == 0.0f)
			{
				Cursor;
			}
		}

		if (InputControl::GetButtonDown(XINPUT_BUTTON_A))
		{
			if (charaCount < _MAX_CHARACTOR_ && chara[charaCount] == nullptr)
			{
				PopCharactor();
			}
		}
	}
	else
	{
		if (InputControl::GetLeft_Stick_Y)
		{

		}
		if (InputControl::GetButton(XINPUT_BUTTON_DPAD_UP))
		{

		}
		if (InputControl::GetButton(XINPUT_BUTTON_DPAD_DOWN))
		{

		}
	}
}

void Player_T::DecreaseCastleHp(float Attack)
{
	this->Hp -= Attack;
}

void Player_T::SetExPoint(int point)
{
	this->ExPoint += point;

}

void Player_T::ExManager()
{
	if (Level == 4 && ExPoint > MaxExPoint[Level])
	{
		ExPoint = MaxExPoint[Level];
	}
	else if (ExPoint >= MaxExPoint[Level])
	{
		ExPoint = ExPoint - MaxExPoint[Level];
		Level++;
	}
}

void Player_T::MoneyManager()
{
	if (MaxMoney[Level] > Money) {
		Money += 2;
	}

}

void Player_T::PopCharactor()
{
	if (Cursor == 0)
	{
		chara[charaCount] = new Nomal;
		chara[charaCount]->Initialize();
	}
	else if (Cursor == 1)
	{
		chara[charaCount] = new Tank;
		chara[charaCount]->Initialize();
	}
	else if (Cursor == 2)
	{
		chara[charaCount] = new Range;
		chara[charaCount]->Initialize();
	}
	else if (Cursor == 3)
	{
		chara[charaCount] = new Kiba;
		chara[charaCount]->Initialize();
	}
}