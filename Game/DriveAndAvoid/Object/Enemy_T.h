#pragma once
class Enemy_T
{
private:
	int Hp;
	int enemy_popcount;

public:
	//コンストラクタ(インスタンス生成時に最初に呼ばれる関数)
	Enemy_T();

	//デストラクタ
	~Enemy_T();

	void Initialize();				//初期化処理
	void Update(float speed);		//更新処理
	void Draw() const;              //描画処理
	void Finalize();				//終了時処理
	void Move();

	int GetHp();
	void randomchar();
};

