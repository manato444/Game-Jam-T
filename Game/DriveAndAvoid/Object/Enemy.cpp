#include"Enemy.h"
#include"DxLib.h"

Enemy::Enemy(int type, int handle) : type(type), image(handle),
									 speed(0.0f),location(0.0f),box_size(0.0f)
{
}

Enemy::~Enemy()
{
}

//初期化処理
void Enemy::Initialize()
{

	//出現させるX座標パターンを取得
	float random_x = (float)(GetRand(4) * 105 + 40);

	//float random_y = (float)(GetRand(4) * 320 + 40);


	//生成位置の設定
	location = Vector2D(random_x, -50.0f);

	//location = Vector2D(650.0f, random_y);

	
	//当たり判定の設定
	box_size = Vector2D(26.0f, 54.0f);

	//速さの設定
	speed = (float)(this->type * 2);

}

void Enemy::Update(float speed)
{
	//位置情報に移動量を加算する
	location += Vector2D(0.0f, this->speed + speed - 27);

	//location += Vector2D(this->speed + speed - 23, 0.0f);

}

void Enemy::Movement()
{

}

void Enemy::Draw() const
{
	//敵画像の描画
	DrawRotaGraphF(location.x, location.y, 1.0, 0.0, image, TRUE);

	//DrawRotaGraphF(location.x, location.y, 1.0, PI/2, image, TRUE);

}

void Enemy::Finalize()
{
}

//敵のタイプを取得
int Enemy::GetType() const
{
	return type;
}

//位置情報を取得
Vector2D Enemy::GetLocation() const
{
	return location;
}

//当たり判定の大きさを取得
Vector2D Enemy::GetBoxSize() const
{
	return box_size;
}