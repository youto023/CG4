#include "GameScene.h"
#include <random>

using namespace KamataEngine;
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
	//乱数の初期化
	srand((unsigned)time(NULL));
}

void GameScene::Update() {

	for (Particle* particle : particles_) {
		// パーティクルの更新
		particle->Update();
	}

	// 終了フラグの立ったパーティクルを削除
	particles_.remove_if([](Particle* particle) {
		if (particle->isFinished_) {
			delete particle;
			return true;
		}
		return false;
	});

	//確率で発生
	if (rand() % 20 == 0) {
		Vector3 randomPosition = {distribution(randomEngine) * 30.0f, distribution(randomEngine) * 20.0f, 0};
		ParticleBorn(randomPosition);
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

void GameScene::ParticleBorn(Vector3 position) {

	// パーティクルの生成
	for (int i = 0; i < 150; i++) {
		// 生成
		Particle* particle = new Particle();
		// 移動量
		Vector3 velocity = {distribution(randomEngine), distribution(randomEngine), 0};
		// パーティクルの初期化
		particle->Initialize(modelParticle_, position, velocity);
		// リストに追加
		particles_.push_back(particle);

		Normalize(velocity);
		velocity *= distribution(randomEngine);
		velocity *= 0.1f;
	}
}
