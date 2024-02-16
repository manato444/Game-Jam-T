#include"GameMainScene.h"
#include"../Object/RankingData.h"
#include"DxLib.h"
#include<math.h>
#include "../Utility/InputControl.h"
#include "../Object/Character.h"

GameMainScene::GameMainScene() : image(NULL), sound(NULL), mileage(0), enemy(nullptr), pt(nullptr), ui(nullptr),
PlayerWin(false), EnemyWin(false)
{
}

GameMainScene::~GameMainScene()
{
}

//初期化処理
void GameMainScene::Initialize()
{
	//item_image = LoadGraph("Resource/images/gasoline.bmp");
	
	//↓飾り
	image = LoadGraph("Resource/images/supana.bmp");

	//BGM(気分で変える)
	//sound = LoadSoundMem("Resource/sound/BreakItDown.mp3");
	//sound = LoadSoundMem("Resource/sound/HappyMoment.mp3");
	sound = LoadSoundMem("Resource/sound/LoveAndGold.mp3");

	//ボリューム（BGM）
	ChangeVolumeSoundMem(255 * 70 / 100, sound);

	//背景（地面）のフィルター
	//GraphFilter(back_ground, DX_GRAPH_FILTER_LEVEL, 35, 210, 120, 0, 255);
	//GraphFilter(back_ground, DX_GRAPH_FILTER_GAUSS, 32, 10);


	//エラーチェック
	/*if (back_ground == -1)
	{
		throw("Resource/images/back.bmpがありません\n");
	}
	if (result == -1)
	{
		throw("Resource/images/car.bmpがありません\n");
	}
	if (barrier_image == -1)
	{
		throw("Resource/images/barrier.pngがありません\n");
	}
	if (item_image == -1)
	{
		throw("Resource/images/gasoline.bmpがありません");
	}*/

	//オブジェクトの生成
	enemy = new Enemy_T;
	enemy->Initialize();

	ui = new UI_T;
	ui->Initialize();
	
	for (int i = 0; i < _MAX_CHARACTOR_; i++)
	{
		PlayerTime[i] = 100;
		EnemyTime[i] = 100;
		PlayerSiroAttack[i] = 100;
		EnemySiroAttack[i] = 100;
	}

	//chara = new Character;
	pt = new Player_T;
	pt->Initialize();

	//オブジェクトの初期化
	//player->Initialize();

	/*for (int i = 0; i < 10; i++)
	{
		enemy[i] = nullptr;
	}*/
	//for (int i = 0; i < 10; i++)
	//{
	//	item = nullptr;
	//}
}

//更新処理
eSceneType GameMainScene::Update()
{
	if (PlayerWin || EnemyWin)
	{
		ui->PlayerWin(PlayerWin);
		ui->EnemyWin(EnemyWin);

		if (InputControl::GetButtonDown(XINPUT_BUTTON_B))
		{
			//WaitTimer(300);
			return eSceneType::E_TITLE;
		}
	}
	else
	{
		if (InputControl::GetButtonDown(XINPUT_BUTTON_START))
		{
			//WaitTimer(300);
			return eSceneType::E_TITLE;
		}

		//BGM再生
		PlaySoundMem(sound, DX_PLAYTYPE_LOOP, FALSE);

		//プレイヤーの更新
		//player->Update();
		pt->Update();
		enemy->Update();

		//プレイヤーの攻撃
		for (int PlayerCount = 0; PlayerCount < _MAX_CHARACTOR_; PlayerCount++)
		{
			Character** c = pt->GetCharacter(PlayerCount);
			if (c[PlayerCount] == nullptr)
			{
				break;
			}

			for (int EnemyCount = 0; EnemyCount < _MAX_CHARACTOR_; EnemyCount++)
			{
				Character** ec = enemy->GetCharacter(EnemyCount);
				if (ec[EnemyCount] == nullptr)
				{
					if (EnemyCount == 0)
					{
						c[PlayerCount]->SetAttackflg(false);
					}

					break;
				}

				//ec[EnemyCount]->SetEnemyLocation(c[PlayerCount]->GetEnemyLocation());

				if (c[PlayerCount]->GetPlayerLocation().x + 50 >= ec[EnemyCount]->GetEnemyLocation().x
					&& c[PlayerCount]->GetPlayerLocation().x <= ec[EnemyCount]->GetEnemyLocation().x)
				{
					c[PlayerCount]->SetAttackflg(true);

					if (PlayerTime[PlayerCount] >= c[PlayerCount]->WaitAttackTime())
					{
						ec[EnemyCount]->SetSubHp(c[PlayerCount]->GetPower());
						PlayerTime[PlayerCount] = 0;
					}
					else
					{
						PlayerTime[PlayerCount]++;
					}

					if (ec[EnemyCount]->HpCheck())
					{
						pt->SetExPoint(ec[EnemyCount]->GetExPoint());
						pt->SetMoney(ec[EnemyCount]->GetMoney() / 2);
						delete ec[EnemyCount];
						ec[EnemyCount] = nullptr;
						for (int i = (EnemyCount + 1); i < _MAX_CHARACTOR_; i++) { // 次の値を調べる処理

							//iがヌルポインタだったらブレイク
							if (ec[i] == nullptr) {
								break;
							}

							ec[i - 1] = ec[i];       //i - 1に現在の値を代入する
							ec[i] = nullptr;          //iにヌルポインタを代入する
						}
					}

					break;
				}
				else
				{
					c[PlayerCount]->SetAttackflg(false);
				}
			}

			if (c[PlayerCount]->GetPlayerLocation().x + 50 >= ui->GetEnemySiro().x
				&& c[PlayerCount]->GetPlayerLocation().x <= ui->GetEnemySiro().x)
			{
				c[PlayerCount]->SetAttackflg(true);
				if (PlayerSiroAttack[PlayerCount] >= c[PlayerCount]->WaitAttackTime())
				{
					enemy->EnemyCastleHp(c[PlayerCount]->GetPower());
					PlayerSiroAttack[PlayerCount] = 0;
				}
				else
				{
					PlayerSiroAttack[PlayerCount]++;
				}

				if (enemy->HpCheck())
				{
					PlayerWin = true;
					break;
				}
			}
		}

		//敵の攻撃
		for (int EnemyCount = 0; EnemyCount < _MAX_CHARACTOR_; EnemyCount++)
		{
			Character** ec = enemy->GetCharacter(EnemyCount);
			if (ec[EnemyCount] == nullptr)
			{
				break;
			}

			for (int PlayerCount = 0; PlayerCount < _MAX_CHARACTOR_; PlayerCount++)
			{
				Character** c = pt->GetCharacter(PlayerCount);
				if (c[PlayerCount] == nullptr)
				{
					if (PlayerCount == 0)
					{
						ec[EnemyCount]->SetAttackflg(false);
					}
					break;
				}

				//c[PlayerCount]->SetPlayerLocation(ec[EnemyCount]->GetPlayerLocation());

				if (ec[EnemyCount]->GetEnemyLocation().x - 50 <= c[PlayerCount]->GetPlayerLocation().x
					&& ec[EnemyCount]->GetEnemyLocation().x >= c[PlayerCount]->GetPlayerLocation().x)
				{
					ec[EnemyCount]->SetAttackflg(true);

					if (EnemyTime[EnemyCount] >= ec[EnemyCount]->WaitAttackTime())
					{
						c[PlayerCount]->SetSubHp(ec[EnemyCount]->GetPower());
						EnemyTime[EnemyCount] = 0;
					}
					else
					{
						EnemyTime[EnemyCount]++;
					}

					if (c[PlayerCount]->HpCheck())
					{
						delete c[PlayerCount];
						c[PlayerCount] = nullptr;
						for (int i = (PlayerCount + 1); i < _MAX_CHARACTOR_; i++) { // 次の値を調べる処理

							//iがヌルポインタだったらブレイク
							if (c[i] == nullptr) {
								break;
							}

							c[i - 1] = c[i];       //i - 1に現在の値を代入する
							c[i] = nullptr;          //iにヌルポインタを代入する
						}
					}

					break;
				}
				else
				{
					ec[EnemyCount]->SetAttackflg(false);
				}
			}

			if (ec[EnemyCount]->GetEnemyLocation().x - 50 <= ui->GetPlayerSiro().x
				&& ec[EnemyCount]->GetEnemyLocation().x >= ui->GetPlayerSiro().x)
			{
				ec[EnemyCount]->SetAttackflg(true);
				if (EnemySiroAttack[EnemyCount] >= ec[EnemyCount]->WaitAttackTime())
				{
					pt->DecreaseCastleHp(ec[EnemyCount]->GetPower());
					EnemySiroAttack[EnemyCount] = 0;
				}
				else
				{
					EnemySiroAttack[EnemyCount]++;
				}

				if (pt->HpCheck())
				{
					EnemyWin = true;
					break;
				}
			}
		}

		ui->SetCursor(pt->GetCursor());

		ui->SetMoney(pt->GetMoney(), pt->GetMaxMoney());

		ui->SetEx(pt->GetExPoint(), pt->GetMaxExPoint());

		ui->SetLevel(pt->GetLevel());

		ui->SetHP(pt->GetCastleHp(), enemy->GetHp());
		/*
		if (flg == 0)
		{
			chara = new Nomal;
			chara->Initialize();
			flg = 1;
		}
		*/

		//移動距離の更新
		//mileage += (int)player->GetSpeed() + 2;

		//敵生成処理
		/*if (mileage / 20 % 60 == 0)
		{
			for (int i = 0; i < 10; i++)
			{
				if (enemy[i] == nullptr)
				{
					int type = GetRand(3) % 3;
					enemy[i] = new Enemy_T(type, enemy_image[type]);
					enemy[i]->Initialize();
					break;
				}
			}
		}*/

		//アイテム生成
		/*if (mileage / 20 % (GetRand(250) + 10) == 0)
		{
			for (int i = 0; i < 10; i++)
			{
				if (item == nullptr)
				{
					int type = item_image;
					item = new Item(item_image);
					item->Initialize();
					break;
				}
			}
		}*/

		//アイテムの更新と当たり判定
		//for (int i = 0; i < 10; i++)
		//{
		//	if (item != nullptr)
		//	{
		//		item->Update(player->GetSpeed());

		//		//画面外に行ったら、削除
		//		if (item->GetLocation().y >= 640.0f)
		//		{
		//			item->Finalize();
		//			delete item;
		//			item = nullptr;
		//		}

		//		//当たり判定の確認
		//		if (IsHitCheck(player, item))
		//		{
		//			player->FuelUp();
		//			if (player->GetFuel() < 85000.0f)
		//			{
		//				//燃料回復
		//				player->DecreaseFuel(+7000.0f);

		//				if (player->GetFuel() > 85000.0f)	
		//				{
		//					player->GetFuel();
		//				}
		//			}
		//			item->Finalize();
		//			delete item;
		//			item = nullptr;
		//		}
		//	}
		//}

		//敵の更新と当たり判定チェック
		//for (int i = 0; i < 10; i++)
		//{
		//	if (enemy[i] != nullptr)
		//	{
		//		enemy[i]->Update(player->GetSpeed());

		//		//画面外に行ったら、敵を削除してスコア加算
		//		if (enemy[i]->GetLocation().y >= 640.0f)
		//		{
		//			enemy_count[enemy[i]->GetType()]++;
		//			enemy[i]->Finalize();
		//			delete enemy[i];
		//			enemy[i] = nullptr;
		//		}

		//		//当たり判定の確認
		//		if (IsHitCheck(player, enemy[i]))
		//		{
		//			player->SetActive(false);
		//			player->DecreaseHp(-160.0f);
		//			player->CarCrash();
		//			enemy[i]->Finalize();
		//			delete enemy[i];
		//			enemy[i] = nullptr;
		//		}
		//	}
		//}

		/*
		//startボタンでタイトルへ


		//Yボタンでリザルトへ
		if (InputControl::GetButtonDown(XINPUT_BUTTON_Y))
		{
			return eSceneType::E_RESULT;
		}
		*/
		//プレイヤーの燃料か体力が0未満なら、リザルトに遷移する
		/*if (player->GetFuel() < 0.0f || player->GetHp() < 0.0f)
		{
			return eSceneType::E_RESULT;
		}*/
	}

	return GetNowScene();
}

//描画処理
void GameMainScene::Draw() const
{
	
	//背景画像の描画
	/*DrawGraph(0, mileage % 480 - 480, back_ground, TRUE);
	DrawGraph(0, mileage % 480, back_ground, TRUE);*/

	/*********背景画像の描画(横スクロール)****************
	DrawGraph(mileage % 480 - 480, 0, back_ground, TRUE);
	DrawGraph(mileage % 480, 0, back_ground, TRUE);
	******************************************************/

	//chara->Draw();

	ui->Draw();

	pt->Draw();
	enemy->Draw();

}

//終了時処理
void GameMainScene::Finalize()
{
	//BGMを止める
	StopSoundMem(sound);

	//スコアを計算する
	mileage = mileage / 10;
	int score = (mileage * 10);
		
	/*for (int i = 0; i < 3; i++)
	{
		score += (i + 1) * 50 * enemy_count[i];
	}*/

	//リザルトデータの書き込み
	//FILE* fp = nullptr;

	////ファイルオープン
	//errno_t result = fopen_s(&fp, "Resource/dat/result_data.csv", "w");

	////エラーチェック
	//if (result != 0)
	//{
	//	throw("Resource/dat/result_data.csvが開けません\n");
	//}

	////スコアを保存
	//fprintf(fp, "%d,\n", score);
	//fprintf(fp, "%d,\n", mileage);

	////避けた数と得点を保存
	//for (int i = 0; i < 3; i++)
	//{
	//	fprintf(fp, "%d,\n", enemy_count[i]);
	//}

	////ファイルクローズ
	//fclose(fp);

	//動的確保したオブジェクトを削除する
	/*player->Finalize();
	delete player;*/

	pt->Finalize();
	delete pt;

	enemy->Finalize();
	delete enemy;
}

//現在のシーン情報を取得
eSceneType GameMainScene::GetNowScene() const
{
	return eSceneType::E_MAIN;
}

//ハイスコアの読み込み
//void GameMainScene::ReadHighScore()
//{
//	RankingData data;
//	data.Initialize();
//
//	high_score = data.GetScore(0);
//
//	data.Finalize();
//}

//当たり判定処理（プレーヤーと敵）
//bool GameMainScene::IsHitCheck(Player* p, Enemy_T* e)
//{
//	//プレイヤーがバリアを貼っていたら、当たり判定を無視する
//	if (p->IsBarrier())
//	{
//		return false;
//	}
//
//	//敵情報が無ければ、当たり判定を無視する
//	if (e == nullptr)
//	{
//		return false;
//	}
//
//	//位置情報の差分を取得
//	/*Vector2D diff_location = p->GetLocation() - e->GetLocation();*/
//
//	//当たり判定サイズの大きさを取得
//	/*Vector2D box_ex = p->GetBoxSize() + e->GetBoxSize();*/
//
//	//コリジョンデータより位置情報の差分が小さいなら、ヒット判定とする
//	/*return ((fabsf(diff_location.x) < box_ex.x) && (fabsf(diff_location.y) < box_ex.y));*/
//}


//アイテム当たり判定
//bool GameMainScene::IsHitCheck(Player* p, Item* i)
//{
//
//	//アイテム情報が無ければ、当たり判定を無視する
//	if (i == nullptr)
//	{
//		return false;
//	}
//
//	//位置情報の差分を取得
//	Vector2D diff_location = p->GetLocation() - i->GetLocation();
//
//	//当たり判定サイズの大きさを取得
//	Vector2D box_ex = p->GetBoxSize() + i->GetBoxSize();
//
//	//コリジョンデータより位置情報の差分が小さいなら、ヒット判定とする
//	return ((fabsf(diff_location.x) < box_ex.x) && (fabsf(diff_location.y) < box_ex.y));
//}