#pragma once
#include "../Base/SceneBase.h"
#include "SceneGameCommon.h"

class SceneGame : public SceneBase
{
private:
	std::shared_ptr<Player> m_player;//�v���C���[
	std::shared_ptr<Camera> m_camera;//�J����

	/*�ϐ��錾*/
	bool m_isLoading;//���[�h�����ǂ���
	bool m_isOpenMenu;//���j���[���J���Ă��邩�ǂ���

public:
	SceneGame();
	~SceneGame()override;

	void Init() override;
	void Update() override;
	void Draw() override;
	void Final() override;
};

