#pragma once
#include "KamataEngine.h"

//ゲームシーン
class GameScene {
public:
	//初期化
	void Initialize();
	~GameScene();
	//更新
	void Update();
	// 描画
	void Draw();


	//テクスチャハンドル
	uint32_t textureHandle_ = 0;
	// スプライト
	KamataEngine::Sprite* sprite_ = nullptr;
};
