#pragma once
#include "../Base/SceneBase.h"
#include "SceneGameCommon.h"

class SceneGame : public SceneBase
{
private:
	std::shared_ptr<Player> m_player;//プレイヤー
	std::shared_ptr<Camera> m_camera;//カメラ

	/*変数宣言*/
	bool m_isLoading;//ロード中かどうか
	bool m_isOpenMenu;//メニューを開いているかどうか

public:
	SceneGame();
	~SceneGame()override;

	void Init() override;
	void Update() override;
	void Draw() override;
	void Final() override;
};

