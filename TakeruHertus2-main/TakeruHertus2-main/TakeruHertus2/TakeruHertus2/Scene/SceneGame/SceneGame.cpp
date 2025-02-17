#include "SceneGame.h"
#include "../../Object/GameTag.h"

void SceneGame::PlayerControlCamera()
{
	/*�J�����̊p�x���l���������W�ɕϊ�*/
	m_player->SetConversionHorizontalAngle(m_camera->GetHAngle());
	m_player->SetConversionCosParam(m_camera->GetCosParam());
	m_player->SetConversionSinParam(m_camera->GetSinParam());
	m_player->Update();

	m_camera->SetTag(TagCameraObject::CONTROL);
	m_camera->SetTarget(m_player->GetPosition());
	m_camera->Update();
}

SceneGame::SceneGame()
	: m_isLoading(false)//���[�h�����ǂ���
{
	m_player = std::make_shared<Player>();		//�v���C���[
	m_enemyFox = std::make_shared<EnemyFox>();	//�ς̓G

	m_camera = std::make_shared<Camera>();//�J����

	m_tutorialMap = std::make_shared<TutorialMap>();//�`���[�g���A���}�b�v

	m_font = std::make_shared<Font>();//�t�H���g

	/*�e�X�g�p�ϐ�*/
	boxPos = VGet(-400.0f, 0.0f, 0.0f);
	boxSize = VGet(60.0f, 60.0f, 60.0f);

}

SceneGame::~SceneGame()
{
}

void SceneGame::Init()
{
	m_player->Init();
	m_enemyFox->Init();
	m_camera->Init();

	m_font->Init();

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
		PlayerControlCamera();//�v���C���[�̍X�V�Ƒ���J�����̍X�V

		m_enemyFox->SetTargetPosition(m_player->GetPosition());
		m_enemyFox->Update();
		m_font->Update();
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
#ifdef _DEBUG
		/*�O���b�h�̃f�o�b�O�\��*/
		m_tutorialMap->DrawGrid(1000, 100, 0.0f);
		m_tutorialMap->DrawGrid(1000, 100, 100.0f);
		m_tutorialMap->DrawBox(boxPos, boxSize);


#endif // _DEBUG

		m_player->Draw();
		m_enemyFox->Draw();
		m_camera->Draw();

		m_font->Draw();

		IsTestPhsycse();
	}
}

void SceneGame::Final()
{
	m_player->Final();
	m_enemyFox->Final();
	m_camera->Final();
	m_font->Final();
}

void SceneGame::IsTestPhsycse()
{
	DrawLine3D(m_player->GetPosition(), m_enemyFox->GetPosition(), 0xff0000);
	DrawLine3D(m_player->GetStartPos(), m_player->GetEndPos(), 0xff0000);
	DrawLine3D(m_enemyFox->GetStartPos(), m_enemyFox->GetEndPos(), 0xff0000);

}

