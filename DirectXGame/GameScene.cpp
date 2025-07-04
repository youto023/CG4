#include "GameScene.h"
using namespace KamataEngine;

void GameScene::Initialize() {
	// ファイル名を指定してテクスチャを読み込む
	textureHandle_ = TextureManager::Load("texture.png");
	// スプライトインスタンスの生成
	sprite_ = Sprite::Create(textureHandle_, {0,0});

}

void GameScene::Update() {}

void GameScene::Draw() {}
