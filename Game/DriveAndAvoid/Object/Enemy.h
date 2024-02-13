#pragma once

#include"../Utility/Vector2D.h"

#define PI    3.1415926535897932384626433832795f

class Enemy
{
private:

	int type;				//タイプ
	int image;				//画像
	float speed;			//速さ
	Vector2D location;		//位置情報
	Vector2D box_size;		//当たり判定の大きさ

	//int angle;

	

public:

	//コンストラクタ(インスタンス生成時に最初に呼ばれる関数)
	Enemy(int type, int handle);

	//デストラクタ
	~Enemy();

	void Initialize();				//初期化処理
	void Update(float speed);		//更新処理
	void Draw() const;				//描画処理
	void Finalize();				//終了時処理
	void Movement();

	int GetType() const;			//タイプ取得
	Vector2D GetLocation() const;	//位置情報の取得
	Vector2D GetBoxSize() const;	//当たり判定の大きさを取得
	
};