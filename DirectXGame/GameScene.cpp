#include "GameScene.h"
using namespace KamataEngine;

void GameScene::Initialize() {
	// ファイル名を指定してテクスチャを読み込む
	textureHandle_ = TextureManager::Load("texture.png");
	// スプライトインスタンスの生成
	sprite_ = Sprite::Create(textureHandle_, {0,0});

}
 GameScene::~GameScene(){
	// スプライトの解放
	delete sprite_;
 }
void GameScene::Update() {}

void GameScene::Draw() {
	// DirectCommonインスタンスの取得
	DirectCommon* directCommon = DirectCommon::GetInstance();
	// スプライトの描画
	sprite_->Draw(directCommon);
	// 描画を実行
	directCommon->Present();

}

