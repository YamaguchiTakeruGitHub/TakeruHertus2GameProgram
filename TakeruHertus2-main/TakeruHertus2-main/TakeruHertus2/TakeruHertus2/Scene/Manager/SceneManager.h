#pragma once
#include "../Base/SceneBase.h"

/// <summary>
/// �V�[���}�l�[�W���[
/// </summary>
class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	void Init();
	void Update();
	void Draw();
	void Final();

	/// <summary>
	/// �p����Ŏ擾����C���X�^���X
	/// </summary>
	/// <returns></returns>
	static SceneManager& GetInstance() { static SceneManager instance; return instance; }

	/// <summary>
	/// �p����ň����V�[���J��
	/// </summary>
	/// <param name="_newScene"></param>
	void ChangeScene(SceneType _newScene);

private:
	std::shared_ptr<SceneBase> m_currentScene;
	std::shared_ptr<SceneBase> m_titleScene;
	std::shared_ptr<SceneBase> m_gameScene;
	std::shared_ptr<SceneBase> m_gameOverScene;
	std::shared_ptr<SceneBase> m_clearScene;
	std::shared_ptr<SceneBase> m_loadScene;
	std::shared_ptr<SceneBase> m_debugScene;
	std::shared_ptr<SceneBase> m_debugTitleUIEditScene;

};

