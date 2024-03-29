#include"TitleScene.h"
#include"../Utility/InputControl.h"
#include"DxLib.h"



TitleScene::TitleScene() : background_image(NULL), menu_image(NULL), sound(NULL),
						   cursor_image(NULL), menu_cursor(0), start_image(),end_image(), help_image()
{
}

TitleScene::~TitleScene()
{
}

//初期化処理
void TitleScene::Initialize()
{

	//画像の読み込み
	//background_image = LoadGraph("Resource/images/Title.bmp");
	//background_image = LoadGraph("Resource/images/End.bmp");
	background_image = LoadGraph("Resource/images/Title_1.png");


	//menu_image = LoadGraph("Resource/images/menu.bmp");

	start_image = LoadGraph("Resource/images/start_m.bmp");
	help_image = LoadGraph("Resource/images/help_m.bmp");
	end_image = LoadGraph("Resource/images/end_m.bmp");



	cursor_image = LoadGraph("Resource/images/cone.bmp");

	//タイトルBGM
	sound = LoadSoundMem("Resource/sound/Title_BGM1.mp3");

	//ボリューム
	ChangeVolumeSoundMem(255 * 60 / 100, sound);
	PlaySoundMem(sound, TRUE);

	//GraphFilter(menu_image, DX_GRAPH_FILTER_HSB, 0, 1, 11, 1);
	//GraphFilter(background_image, DX_GRAPH_FILTER_LEVEL, 30, 210, 120, 0, 255);

	//エラーチェック
	if (background_image == -1)
	{
		throw("Resource/images/Title.bmpがありません\n");
	}
	if (menu_image == -1)
	{
		throw("Resource/images/menu.bmpがありません\n");
	}
	if (cursor_image == -1)
	{
		throw("Resource/images/cone.bmpがありません\n");
	}
	
}


//更新処理
eSceneType TitleScene::Update()
{

	
	bool flg = TRUE;
	//カーソル下移動
	if (InputControl::GetButtonDown(XINPUT_BUTTON_DPAD_DOWN) || CheckHitKey(KEY_INPUT_DOWN) > 0)
	{
		if (flg == TRUE)
		{
			menu_cursor++;
		}
		else
		{
			flg = TRUE;
		}
		flg = FALSE;
		//1番下に到達したら、一番上にする
		if (menu_cursor > 2)
		{
			menu_cursor = 0;
		}
		
	}

	//カーソル上移動
	if (InputControl::GetButtonDown(XINPUT_BUTTON_DPAD_UP) || CheckHitKey(KEY_INPUT_UP) > 0)
	{
		menu_cursor--;
		//1番上に到達したら、一番下にする
		if (menu_cursor < 0)
		{
			menu_cursor = 2;
		}
	}

	//カーソル決定(決定した画面に遷移する)
	if (InputControl::GetButtonDown(XINPUT_BUTTON_B) || CheckHitKey(KEY_INPUT_RETURN))
	{
		switch (menu_cursor) 
		{
		case 0:
			return eSceneType::E_MAIN;
		case 1:
			return eSceneType::E_HELP;
		default:
			return eSceneType::E_END;
		}
	}
	//現在のシーンタイプを返す
	return GetNowScene();
}

//描画処理
void TitleScene::Draw() const
{
	//メニュー虹色
	//GraphFilter(menu_image, DX_GRAPH_FILTER_HSB, 0, 2, 3, 5);

	//タイトル画像の描画
	DrawGraph(0, 0, background_image, FALSE);

	//メニュー画像の描画
	//DrawGraph(120, 200, menu_image, TRUE);

	//メニュー画像の描画(ランキング以外)
	DrawGraph(65, 223, start_image, TRUE);
	DrawGraph(48, 253, help_image, TRUE);
	DrawGraph(25, 285, end_image, TRUE);

	//カーソル画像の描画
	DrawRotaGraph(40, 240 + menu_cursor * 33, 0.7, DX_PI / 2.0, cursor_image, TRUE);

	//DrawGraph(20, 300, menu_image, TRUE);
	//DrawRotaGraph(250, 320 + menu_cursor * 40, 0.7, DX_PI / -2.0, cursor_image, TRUE);
	//DrawString(8, 460, "B:決定", 0xffffff, 0);
}

//終了時処理
void TitleScene::Finalize()
{
	//タイトルBGMストップ
	StopSoundMem(sound);
	
	//読み込んだ画像の削除
	DeleteGraph(background_image);
	DeleteGraph(menu_image);
	DeleteGraph(cursor_image);
}

//現在のシーン情報を取得
eSceneType TitleScene::GetNowScene() const
{
	return eSceneType::E_TITLE;
}