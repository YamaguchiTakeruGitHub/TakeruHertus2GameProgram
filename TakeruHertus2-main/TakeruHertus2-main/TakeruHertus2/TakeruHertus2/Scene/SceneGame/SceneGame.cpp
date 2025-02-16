#include "SceneGame.h"
#include "../../Object/GameTag.h"

SceneGame::SceneGame()
	: m_isLoading(false)//���[�h�����ǂ���
{
	m_player = std::make_shared<Player>();//�v���C���[
	m_camera = std::make_shared<Camera>();//�J����
}

SceneGame::~SceneGame()
{
}

void SceneGame::Init()
{
	m_player->Init();
	m_camera->Init();

	m_isLoading = true;//�K���e�N���X�̌�ɂ���
}

void SceneGame::Update()
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
		/*m_player->SetConversionHorizontalAngle(m_camera->GetHAngle());
		m_player->SetConversionCosParam(m_camera->GetCosParam());
		m_player->SetConversionSinParam(m_camera->GetSinParam());*/
		m_player->Update(m_camera->GetHAngle(), m_camera->GetSinParam(), m_camera->GetCosParam());

		m_camera->SetTag(TagCameraObject::CONTROL);
		m_camera->SetTarget(m_player->GetPosition());
		m_camera->Update();
	}
}

void SceneGame::Draw()
{
	if (m_isLoading)
	{
		DrawString(0, 0, "NowLoading...", 0xffffff);

		// ���[�h�̐i�s�󋵂��v�Z
		int totalLoadTasks = GetASyncLoadNum(); // �����[�h�^�X�N�����擾����֐��i����j
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
		DrawGrid(100, 100);

		m_player->Draw();
		m_camera->Draw();
	}
}

void SceneGame::Final()
{
	m_player->Final();
	m_camera->Final();
}
