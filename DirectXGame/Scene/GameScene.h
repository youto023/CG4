#pragma once
#include "KamataEngine.h"
#include "../Object/Effect.h"


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

	////パーティクル3Dモデルデータ
	// Model* modelParticle_ = nullptr;
	//  カメラの初期化
	KamataEngine::Camera camera_;

	KamataEngine::Model* modelEffect_;
	//エフェクト
	std::list<Effect*> effectes_;
};
