#pragma once

#include <KamataEngine.h>

using namespace KamataEngine;

// パーティクル
class Particle {
public:

	void Initialize(Model*model);
	void Update();
	void Draw(Camera& camera);

private:

	// ワールド変換データ
	WorldTransform worldTransform_;
	// モデル
	Model* model_ = nullptr;
	//色変更オブジェクト
	ObjectColor objectColor_;
	//色の数値
	Vector4 color_;

};
