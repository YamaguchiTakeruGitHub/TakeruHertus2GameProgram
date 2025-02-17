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
	if (CheckCapsuleCollision() == true)
	{
		DrawString(0, 20, "Hit", 0xffffff);
	}
}

bool SceneGame::IsTestCheckHitboxCollision(VECTOR _spherePos, float _sphereRadius, VECTOR _boxPos, VECTOR _boxSize)
{
	VECTOR closestPoint = _spherePos;
	closestPoint.x = max(_boxPos.x - _boxSize.x / 2, min(_spherePos.x, _boxPos.x + _boxSize.x / 2));
	closestPoint.y = max(_boxPos.y - _boxSize.y / 2, min(_spherePos.y, _boxPos.y + _boxSize.y / 2));
	closestPoint.z = max(_boxPos.z - _boxSize.z / 2, min(_spherePos.z, _boxPos.z + _boxSize.z / 2));
	
	VECTOR distance = VSub(_spherePos, closestPoint);

	float distansSquared = VDot(distance, distance);
	return distansSquared < _sphereRadius * _sphereRadius;
}

VECTOR SceneGame::IsTestCheckBoxResolveCollision(VECTOR _spherePos, float _sphereRadius, VECTOR _boxPos, VECTOR _boxSize)
{
	VECTOR boxMin = VSub(_boxPos, VGet(_boxSize.x / 2, _boxSize.y / 2, _boxSize.z / 2));
	VECTOR boxMax = VAdd(_boxPos, VGet(_boxSize.x / 2, _boxSize.y / 2, _boxSize.z / 2));

	// �{�b�N�X�̍ŋߐړ_�����߂�
	VECTOR boxClosest = VGet(
		max(boxMin.x, min(_spherePos.x, boxMax.x)),
		max(boxMin.y, min(_spherePos.y, boxMax.y)),
		max(boxMin.z, min(_spherePos.z, boxMax.z))
	);

	// ���̒��S�ƍŋߐړ_�̋���
	VECTOR diff = VSub(_spherePos, boxClosest);
	float distSq = VDot(diff, diff);  // ��拗��

	// �Փ˔���
	float radiusSq = _sphereRadius * _sphereRadius;
	if (distSq < radiusSq)
	{
		float dist = std::sqrt(distSq);
		VECTOR normal = (dist > 0.0f) ? VScale(diff, 1.0f / dist) : VGet(1.0f, 0.0f, 0.0f); // ���K��

		// �����߂�����
		float overlap = _sphereRadius - dist;
		VECTOR pushBack = VScale(normal, overlap);

		return VAdd(_spherePos, pushBack);
	}

	return _spherePos; // �ω��Ȃ�
}

bool SceneGame::CheckCapsuleCollision()
{
    // �������J�v�Z���̔��a�̘a�ȉ��ł���ΏՓ�
    return Segment_Segment_MinLength(m_player->GetStartPos(), m_player->GetEndPos(), m_enemyFox->GetStartPos(), m_enemyFox->GetEndPos()) <= (m_player->GetRadius() + m_enemyFox->GetRadius());
}

void SceneGame::ResolveCapusleCollision()
{
}
