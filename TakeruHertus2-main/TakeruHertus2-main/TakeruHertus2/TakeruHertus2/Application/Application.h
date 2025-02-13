#pragma once
#include <EffekseerForDXLib.h>
#include <DxLib.h>
#include "../Scene/Manager/SceneManager.h"

class Application final
{
public:
	/// <summary>
	/// �V�[���}�l�[�W���[�ˑ�
	/// </summary>
	/// <param name="_sceneManager"></param>
	Application(SceneManager& _sceneManager);
	~Application();
	
	/// <summary>
	/// ������
	/// </summary>
	/// <returns></returns>
	bool Init_App();

	/// <summary>
	/// ���s
	/// </summary>
	void Run_App();

	/// <summary>
	/// ���
	/// </summary>
	void close_App();

private:
	//�V�[���}�l�[�W���[�̃C���X�^���X
	SceneManager& m_sceneManager;

};
