#pragma once

#include "KamataEngine.h"
#include "Particle.h"

using namespace KamataEngine;

class GameScene {
public:

	~GameScene();
	void Initialize();
	void Update();
	void Draw();


private:

	//パーティクル3Dモデルデータ
	Model* modelParticle_ = nullptr;
	//カメラ
	Camera camera_;
	// パーティクル　
	Particle* particle_ = nullptr;

};
