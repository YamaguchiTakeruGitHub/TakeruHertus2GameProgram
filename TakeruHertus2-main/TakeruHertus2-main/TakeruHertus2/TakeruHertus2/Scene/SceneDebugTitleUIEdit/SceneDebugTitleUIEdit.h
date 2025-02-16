#pragma once
#include "../Base/SceneBase.h"
#include "../../Object/SceneSystem/SceneSystemTitle/SceneSystemTitle.h"
#include "../../InputDevice/InputManager.h"

namespace TITLEUINUMBER
{
	static constexpr int RESOURCENUM = 7;//�^�C�g���ň������\�[�X�̐�
}

class SceneDebugTitleUIEdit : public SceneBase
{
private:
	std::shared_ptr<InputManager> m_Idm;
	std::shared_ptr<SceneSystemTitle> m_systemTitle;

	int mouseX, mouseY;//�}�E�X
	
	/*�ϐ��錾*/
	bool m_isMenu;//���j�����J����Ă��邩
	bool m_isAttachGraph[TITLEUINUMBER::RESOURCENUM];
	bool m_isMenuHitString[TITLEUINUMBER::RESOURCENUM];
	bool m_isAttachGraphNumber[TITLEUINUMBER::RESOURCENUM];

	int m_resourceNum[TITLEUINUMBER::RESOURCENUM];		//�g�p���郊�\�[�X�̐�
	int m_resourceHitColor[TITLEUINUMBER::RESOURCENUM];//���j���[��ʂ̕����̐F


	VECTOR m_resourcePos[TITLEUINUMBER::RESOURCENUM];	//���\�[�X�̍��W
	VECTOR m_resourceGraphPos[TITLEUINUMBER::RESOURCENUM];	//���\�[�X�̍��W

	VECTOR m_resourceCurrentPos[TITLEUINUMBER::RESOURCENUM];

	void UpdateMenuHitSelect();
	void UpdateMenuAttachSelect(int _attachNum);

	void DrawMenuString();
	void DrawMenuHitDebug();

public:
	SceneDebugTitleUIEdit();
	~SceneDebugTitleUIEdit()override;

	void Init() override;
	void Update() override;
	void Draw() override;
	void Final() override;
};

