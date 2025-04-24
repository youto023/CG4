#include "Particle.h"

using namespace MathUtility;

void Particle::Initialize(Model* model) {

	//NULLポインタチェック
	assert(model);
	//引数として受け取ったデータをメンバ変数に記録する
	model_ = model;
	// ワールド変換の初期化
	worldTransform_.Initialize();
	//色の設定
	objectColor_.Initialize();
	color_ = {1, 1, 0, 1};

}

void Particle::Update() {

	//移動
	worldTransform_.translation_ += {0.0f, 0.1f, 0.0f};
	//行列を更新
	worldTransform_.UpdateMatrix();
	//色変更オブジェクトに色の数値を設定する
	objectColor_.SetColor(color_);
}

void Particle::Draw(Camera& camera) {

	//3Dモデル描画
	model_->Draw(worldTransform_, camera,&objectColor_);
}
