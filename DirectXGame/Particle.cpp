#include "Particle.h"
#include "algorithm"

using namespace KamataEngine;
using namespace MathUtility;

Particle::~Particle() {

	// パーティクルの解放
	for (Particle* particle : particles_) {
		delete particle;
	}
	particles_.clear();
}

void Particle::Initialize(Model* model, Vector3 position, Vector3 velocity) {

	// NULLポインタチェック
	assert(model);
	// 引数として受け取ったデータをメンバ変数に記録する
	model_ = model;
	velocity_ = velocity;
	// ワールド変換の初期化
	worldTransform_.Initialize();
	// 色の設定
	objectColor_.Initialize();
	color_ = {1, 1, 0, 1};
	worldTransform_.translation_ = position;
	// 大きさ
	worldTransform_.scale_ = {0.2f, 0.2f, 0.2f};
}

void Particle::Update() {

	// 移動
	worldTransform_.translation_ += velocity_;
	// 行列を更新
	worldTransform_.UpdateMatrix();
	// 色変更オブジェクトに色の数値を設定する
	objectColor_.SetColor(color_);
	// 終了なら何もしない
	if (isFinished_) {
		return;
	}

	// カウンターを1フレーム分の秒数進める
	counter_ += 1.0f / 60.0f;

	// 存続時間の上限に達したら
	if (counter_ >= kDuration) {
		counter_ = kDuration;
		// 終了扱いにする
		isFinished_ = true;
	}

	// フェード処理
	color_.w = std::clamp(1.0f - counter_ / kDuration, 0.0f, 1.0f);
}

void Particle::Draw(Camera& camera) {

	// 3Dモデル描画
	model_->Draw(worldTransform_, camera, &objectColor_);
}
