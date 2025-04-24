#include "GameScene.h"
#include <random>

using namespace MathUtility;

std::random_device seedGenerator;
std::mt19937 randomEngine(seedGenerator());
std::uniform_real_distribution<float> distribution(-1.0f, 1.0f);

// デストラクタ
GameScene::~GameScene() {

	delete modelParticle_;
	for (Particle* particle : particles_) {
		delete particle;
	}
}

void GameScene::Initialize() {

	// 3Dモデルデータの生成
	modelParticle_ = Model::CreateSphere(4, 4);
	// カメラの初期化
	camera_.Initialize();
	// パーティクルの生成
	for (int i = 0; i < 150; i++) {
		// 生成
		Particle* particle = new Particle();
		// 位置
		Vector3 position = {0.0,0.0f,0.0f};
		//移動量
		Vector3 velocity = {distribution(randomEngine), distribution(randomEngine), 0};
		// パーティクルの初期化
		particle->Initialize(modelParticle_, position,velocity);
		// リストに追加
		particles_.push_back(particle);

		Normalize(velocity);
		velocity *= distribution(randomEngine);
		velocity *= 0.1f;
	}

}

void GameScene::Update() {

	for (Particle* particle : particles_) {

		// パーティクルの更新
		particle->Update();
	}
}

void GameScene::Draw() {

	// DirectXCommon　インスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();
	// 3Dモデル描画処理
	Model::PreDraw(dxCommon->GetCommandList());
	for (Particle* particle : particles_) {
		// パーティクルの描画
		particle->Draw(camera_);
	}
	// 3Dモデル描画処理
	Model::PostDraw();
}
