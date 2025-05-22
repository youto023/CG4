#include "Effect.h"
using namespace KamataEngine;
#include <random>
std::random_device seed_Generator;
std::mt19937 RandomEngine(seed_Generator());
std::uniform_real_distribution<float> RandomSize(0.0f, 1.0f);
std::uniform_real_distribution<float> RandomRotation(-1.0f, 1.0f);
void Effect::Initialize(KamataEngine::Model* model, KamataEngine::Vector3 pos) {
	// NULLポインタチェック
	assert(model);
	model_ = model;

	worldTransform_.Initialize();
	// Vector3 rotate = Vector3(0.0f, 0.0f, RandomRotation(RandomEngine));
	worldTransform_.scale_.y = RandomSize(RandomEngine) * 10.0f;
	worldTransform_.rotation_.z = RandomRotation(RandomEngine) * 20.0f;
	// worldTransform_.rotation_ = rotate;
	worldTransform_.translation_ = pos;
}

void Effect::Update() { worldTransform_.UpdateMatrix(); }

void Effect::Draw(Camera& camera) { model_->Draw(worldTransform_, camera); }
