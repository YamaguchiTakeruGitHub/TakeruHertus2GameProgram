#include "SceneTitle.h"
#include "../../Application/GameConstant.h"

SceneTitle::SceneTitle()
	: m_isLoading(false)
{
	m_systemTitle = std::make_shared<SceneSystemTitle>();
}

SceneTitle::~SceneTitle()
{
}

void SceneTitle::Init()
{
	m_systemTitle->Init();
	m_isLoading = true;
}

void SceneTitle::Update()
{
	if (m_isLoading)
	{
		if (GetASyncLoadNum() == 0)
		{
			m_isLoading = false;
		}
	}
	else
	{
		m_systemTitle->Update();
	}
}

void SceneTitle::Draw()
{
	if (m_isLoading)
	{
		DrawString(0, 0, "NowLoading...", 0xffffff);

		// ���[�h�̐i�s�󋵂��v�Z
		int totalLoadTasks = SCENESYSTEMTITLE::OBJECTNUM; // �����[�h�^�X�N�����擾����֐��i����j
		int remainingLoadTasks = GetASyncLoadNum(); // �c��̃��[�h�^�X�N�����擾
		float progress = 1.0f - (static_cast<float>(remainingLoadTasks) / totalLoadTasks);

		// �o�[�̕`��
		int barWidth = 200; // �o�[�̕�
		int barHeight = 20; // �o�[�̍���
		int barX = 100; // �o�[��X���W
		int barY = 50; // �o�[��Y���W
		DrawBox(barX, barY, barX + static_cast<int>(barWidth * progress), barY + barHeight, 0x00ff00, TRUE); // �v���O���X�o�[
		DrawBox(barX, barY, barX + barWidth, barY + barHeight, 0xffffff, false);

		if (GetASyncLoadNum() == 0)
		{
			m_isLoading = false;
		}
	}
	else
	{
		m_systemTitle->Draw();
	}
}

void SceneTitle::Final()
{
	m_systemTitle->Final();
}
