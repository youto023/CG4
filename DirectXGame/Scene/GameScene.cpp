#include "GameScene.h"
using namespace KamataEngine;

#include <random>

//std::random_device seed_Generator;
//std::mt19937 RandomEngine(seed_Generator());
//std::uniform_real_distribution<float> RandomSize(0.0f, 1.0f);
//std::uniform_real_distribution<float> RandomRotation(0.0f, 1.0f);

GameScene::GameScene() {}
GameScene::~GameScene() {

	//// パーティクル3Dモデルデータの解放
	// delete modelParticle_;
	// modelParticle_ = nullptr;
	//  カメラの解放

	delete effect_;
	effect_ = nullptr;

	delete modelEffect_;
	modelEffect_ = nullptr;
}

void GameScene::Initialize() {
	// DirectXCommonインスタンスの取得
	dxCommon_ = DirectXCommon::GetInstance();
	// Inputインスタンスの取得
	input_ = Input::GetInstance();
	// Audioインスタンスの取得
	audio_ = Audio::GetInstance();

	//// 乱数の初期化
	//srand((unsigned)time(NULL));

	//Vector3 size = Vector3(0.0f, 0.0f/*RandomSize(RandomEngine)*/, 0.0f);
	//Vector3 rotate = Vector3(0.0f, 0.0f, 0.0f/*RandomRotation(RandomEngine)*/);

	//// モデルの初期化
	// modelParticle_ = Model::CreateSphere(4, 4);
	//  モデルの初期化
	// modelEffect_->Create();
	modelEffect_ = Model::CreateFromOBJ("Plane");
	// modelEffect_=Model::CreateSphere(4, 4);
	effect_ = new Effect();
	effect_->Initialize(modelEffect_/*,size,rotate*/);

	// カメラの初期化
	camera_.Initialize();
}

void GameScene::Update() { effect_->Update(); }

void GameScene::Draw() {

	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Model::PreDraw(commandList);

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>

	effect_->Draw(camera_);

	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion
}
