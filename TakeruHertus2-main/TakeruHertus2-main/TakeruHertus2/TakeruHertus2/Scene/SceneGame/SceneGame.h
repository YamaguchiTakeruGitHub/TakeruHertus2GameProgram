#pragma once
#include "../Base/SceneBase.h"
#include "SceneGameCommon.h"

class SceneGame : public SceneBase
{
private:
	std::shared_ptr<Player> m_player;

	/*�ϐ��錾*/
	bool m_isLoading;

public:
	SceneGame();
	~SceneGame()override;

	void Init() override;
	void Update() override;
	void Draw() override;
	void Final() override;
};

