#pragma once
#include "SceneType.h"
#include <EffekseerForDXLib.h>
#include <DxLib.h>
#include <memory>
#include "../../InputDevice/InputManager.h"

/// <summary>
/// �V�[���̃x�[�X
/// </summary>
class SceneBase
{
protected:
	//�����œ��̓f�o�C�X�̃C���X�^���X���쐬���Čp����̃N���X�ŃC���X�^���X�������Ɉ���
	std::shared_ptr<InputManager> m_Idm;

public:
	SceneBase();
	virtual ~SceneBase() {}

	virtual void Init() {}
	virtual void Update() {}
	virtual void Draw() {}
	virtual void Final() {}
};