#include "Effect.h"
using namespace KamataEngine;
#include <random>

void Effect::Initialize(KamataEngine::Model* model, KamataEngine::Vector3 pos) {
	std::random_device seed_Generator;
	std::mt19937 RandomEngine(seed_Generator());
	std::uniform_real_distribution<float> RandomSize(0.0f, 1.0f);
	std::uniform_real_distribution<float> RandomRotation(-1.0f, 1.0f);
	// NULLポインタチェック
	assert(model);
	model_ = model;

	// Vector3 rotate = Vector3(0.0f, 0.0f, RandomRotation(RandomEngine));
	worldTransform_.scale_.y = RandomSize(RandomEngine) * 10.0f;
	worldTransform_.rotation_.z = RandomRotation(RandomEngine) * 20.0f;
	// worldTransform_.rotation_ = rotate;
	worldTransform_.translation_ = pos;
	// 色の初期化
	objectColor_.Initialize();
	color_ = Vector4(1, 1, 1, 1);
	// ワールド変換データの初期化
	worldTransform_.Initialize();
}

void Effect::Update() {
	// 終了なら何もしない
	if (isFinished_) {
		return;
	}

	// カウンターを1フレーム粉の秒数進める
	counter_ += 1.0f / 60.0f;

	// 存在時間の上限に達したら
	if (counter_ >= kDuration) {
		counter_ = kDuration;
		// 終了扱いにする
		isFinished_ = true;
	}
	// 色変更オブジェクトに色の数値を設定する
	objectColor_.SetColor(color_);
	// フェード処理
	color_.w = std::clamp(1.0f - counter_ / kDuration, 0.0f, 1.0f);

	worldTransform_.UpdateMatrix();
}

void Effect::Draw(Camera& camera) { model_->Draw(worldTransform_, camera, &objectColor_); }

bool Effect::IsFinished() { return isFinished_; }
