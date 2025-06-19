#pragma once
#include "KamataEngine.h"
#include "../Model2/Model2.h"

// ゲームシーン
class GameScene {
public:
	// コンストラクタ
	GameScene();
	// デストラクタ
	~GameScene();
	// 初期化
	void Initialize();
	// 更新
	void Update();
	// 描画
	void Draw();

private:


private:
	KamataEngine::DirectXCommon* dxCommon_ = nullptr;
	KamataEngine::Input* input_ = nullptr;
	KamataEngine::Audio* audio_ = nullptr;

	KamataEngine::Model2* model_ = nullptr;
	uint32_t model2Handle_;

	KamataEngine::Model* model = nullptr;
	
	KamataEngine::WorldTransform worldTransform_ ;


	// カメラの初期化
	KamataEngine::Camera* camera_;
};
