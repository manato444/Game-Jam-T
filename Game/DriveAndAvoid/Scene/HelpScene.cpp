#include"HelpScene.h"
#include"../Utility/InputControl.h"
#include"DxLib.h"

HelpScene::HelpScene() : background_image(NULL)
{
}

HelpScene::~HelpScene()
{
}

//初期化処理
void HelpScene::Initialize()
{
	//画像の読み込み
	//background_image = LoadGraph("Resource/images/Title.bmp");

	background_image = LoadGraph("Resource/images/Title_1.png");
	help_image = LoadGraph("Resource/images/help_1.png");

	//GraphFilter(background_image, DX_GRAPH_FILTER_LEVEL, 30, 210, 120, 0, 255);


	//エラーチェック
	if (background_image == -1)
	{
		throw("Resource/images/Title.bmpがありません");
	}

}


//更新処理
eSceneType HelpScene::Update()
{
	//Bボタンが押されたら、タイトルに戻る
	if (InputControl::GetButtonDown(XINPUT_BUTTON_B))
	{
		return eSceneType::E_TITLE;
	}
	return GetNowScene();
}

//描画処理
void HelpScene::Draw() const
{


	//背景画像の描画
	DrawGraph(0, 0, background_image, FALSE);
	DrawRotaGraph(320, 230, 0.9, 0.0, help_image, FALSE);


	/*
	//ゲーム説明
	SetFontSize(16);
	DrawString(20, 120, "ヘルプ画面", 0x000000, 0);

	DrawString(20, 160, "これは障害物を避けながら", 0x000000, 0);
	DrawString(20, 180, "走り続けるゲームです", 0x000000, 0);
	DrawString(20, 200, "燃料が尽きるか障害物に", 0x000000, 0);
	DrawString(20, 220, "数回当たるとゲームオーバーです。", 0x000000, 0);

	DrawString(150, 450, "---- Bボタンを押してタイトルへ戻る ----", 0x000000, 0);
	*/
}

//終了時処理
void  HelpScene::Finalize()
{
	//読み込んだ画像の削除
	DeleteGraph(background_image);
}

//現在のシーン情報を取得
eSceneType HelpScene::GetNowScene() const
{
	return eSceneType::E_HELP;
}


