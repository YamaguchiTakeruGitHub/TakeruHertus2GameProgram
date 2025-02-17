#pragma once
#include "../Base/SceneBase.h"
#include "SceneGameCommon.h"

class SceneGame : public SceneBase
{
private:
    /*キャラクター*/
	std::shared_ptr<Player> m_player;       //プレイヤー
    std::shared_ptr<EnemyFox> m_enemyFox;   //狐の敵
    /*カメラ*/
	std::shared_ptr<Camera> m_camera;       //カメラ
	/*マップ*/
	std::shared_ptr<TutorialMap> m_tutorialMap;//チュートリアルマップ
	/*フォント*/
	std::shared_ptr<Font> m_font;//フォント

	/*変数宣言*/
	bool m_isLoading;//ロード中かどうか
	bool m_isOpenMenu;//メニューを開いているかどうか

	void PlayerControlCamera();

	/*テスト用変数*/
	VECTOR boxPos;
	VECTOR boxSize;

public:
	SceneGame();
	~SceneGame()override;

	void Init() override;
	void Update() override;
	void Draw() override;
	void Final() override;

	void IsTestPhsycse();

	bool IsTestCheckHitboxCollision(VECTOR _spherePos, float _sphereRadius, VECTOR _boxPos, VECTOR _boxSize);
	VECTOR IsTestCheckBoxResolveCollision(VECTOR _spherePos, float _sphereRadius, VECTOR _boxPos, VECTOR _boxSize);

	bool CheckCapsuleCollision();
	void ResolveCapusleCollision();

};

