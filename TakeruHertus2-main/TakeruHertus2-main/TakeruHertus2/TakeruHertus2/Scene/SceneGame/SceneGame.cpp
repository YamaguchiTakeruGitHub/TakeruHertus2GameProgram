#include "SceneGame.h"
#include "../../Object/GameTag.h"


/*���Ȃ̂ł��Ƃňڍs*/
namespace
{
	//�ő哖���蔻��|���S����
	constexpr int kMaxColHitPolyNum = 2000;
	//�ǉ����o�������̍ő厎�s��
	constexpr int kMaxColHitTryNum = 16;
	//�ǉ����o�����ɃX���C�h�����鋗��
	constexpr float kColHitSlideLength = 1.0f;
	//�ړ��������𔻒f���邽�߂̕ϐ�
	constexpr float kMove = 0.01f;
	//�ǃ|���S�������|���S�����𔻒f���邽�߂̕ϐ�
	constexpr float kWallPolyBorder = 0.4f;
	//�ǃ|���S���Ɣ��f���邽�߂̍����ϐ�
	constexpr float kWallPolyHeight = 5.0f;

	//����ł���̎���
	constexpr int kEnableTimeCount = 10;

	//���̍�����ݒ�
	constexpr float kHeadHeight = 40.0f;
	//
}


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
	m_tutorialMap->Init();
	m_font->Init();

	m_isLoading = true;//�K���e�N���X�̌�ɂ���

	/*�����C�g*/
	lightHandle = CreateDirLightHandle(VGet(0.0f, 200.0f, 0.0f));

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
		/*�����C�g*/
		SetLightDirectionHandle(lightHandle, VGet(0, 1, 0));
		SetLightPositionHandle(lightHandle, VGet(0, 200, 0));
	
		m_tutorialMap->Update();
		PlayerControlCamera();//�v���C���[�̍X�V�Ƒ���J�����̍X�V

		m_enemyFox->SetTargetPosition(m_player->GetPosition());
		m_enemyFox->Update();
		m_font->Update();

		/*�����蔻�菈�����Ȃ̂ł��Ƃňڍs*/
		
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

		m_tutorialMap->Draw();
#ifdef _DEBUG
		/*�O���b�h�̃f�o�b�O�\��*/
	/*	m_tutorialMap->DrawGrid(1000, 100, 0.0f);
		m_tutorialMap->DrawGrid(1000, 100, 100.0f);*/
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
	m_tutorialMap->Final();
	m_player->Final();
	m_enemyFox->Final();
	m_camera->Final();
	m_font->Final();

	DeleteLightHandle(lightHandle);
}

void SceneGame::IsTestPhsycse()
{
	
	//VECTOR pos1 = VGet(m_player->GetPosition().x, m_player->GetPosition().y + m_player->GetRadius(), m_player->GetPosition().z);
	//VECTOR pos2 = VGet(m_player->GetPosition().x, m_player->GetPosition().y + m_player->GetCapsuleHeight() - m_player->GetRadius(), m_player->GetPosition().z);

	//��
	VECTOR pos1 = VGet(m_player->GetPosition().x, m_player->GetPosition().y + m_player->GetCapsuleHeight(), m_player->GetPosition().z);
	//��
	VECTOR pos2 = m_player->GetPosition();//�J�v�Z���̉������͍��W���甼�a�����Z����̂ł����OK


	/*�@���x�N�g���e�X�g�v*/
	VECTOR tpos1 = VGet(100, 0, 100);
	VECTOR tpos2 = VGet(200, 200, 200);
	VECTOR tpos3 = VGet(200, 0, 200);
	
	VECTOR normal = CalculateNormal(tpos1, tpos2, tpos3);
	VECTOR center = CalculateCenter(tpos1, tpos2, tpos3);

	if (CheckCapsuleTriangleCollision(m_player->GetPosition(), m_player->GetCapsuleHeight(), m_player->GetRadius(), tpos1, tpos2, tpos3, normal)) {
		VECTOR pushback = GetPushbackVector(m_player->GetPosition(), m_player->GetCapsuleHeight(), m_player->GetRadius(), tpos1, tpos2, tpos3, normal);
		
		m_player->SetPosition(VAdd(m_player->GetPosition(), pushback));
	}

	float size = 30.0f;

	VECTOR normalEnd = VGet(center.x + normal.x * size, center.y + normal.y * size, center.z + normal.z * size);

	DrawTriangle3D(tpos1, tpos2, tpos3, 0xfffff, true);
	DrawLine3D(center, normalEnd, 0xff0000);
	/*�@���x�N�g���e�X�g�����*/


	m_hitDim = MV1CollCheck_Capsule(m_tutorialMap->GetModelHandle(), -1, pos1, pos2, m_player->GetRadius());//��A���A���a

	CHeckWallAndFloor(pos2, m_player->GetRadius());
	FixPositionWithWall(pos1,pos2);
	FixNowPositionWithFloor(pos1, pos2);
	
	MV1CollResultPolyDimTerminate(m_hitDim);

	DrawFormatString(20, 20, 0xffffff, "x:%f,y:%f,z:%f", pos2.x, pos2.y, pos2.z);
}

void SceneGame::CHeckWallAndFloor(VECTOR _po1, float _radius)
{
	m_wallNum = 0;
	m_floorNum = 0;
	
	m_player->SetIsGround(false);

	//�ڐG����
	for (int i = 0; i < m_hitDim.HitNum; i++)
	{
		if (m_hitDim.Dim[i].Normal.y < 0.4f && m_hitDim.Dim[i].Normal.y > -0.4f)
		{
			if (m_hitDim.Dim[i].Position[0].y > _po1.y ||
				m_hitDim.Dim[i].Position[1].y > _po1.y ||
				m_hitDim.Dim[i].Position[2].y > _po1.y)
			{
				if (m_wallNum < 2000)
				{
					m_wallPoly[m_wallNum] = &m_hitDim.Dim[i];
					m_wallNum++;
					m_player->SetIsJump(false);
				}
			}
		}
		else
		{
			if (m_floorNum < 2000)
			{
				m_floorPoly[m_floorNum] = &m_hitDim.Dim[i];

				m_floorNum++;
				m_player->SetIsGround(true);
			}
		}

	}
}

void SceneGame::FixPositionWithWall(VECTOR _pos1, VECTOR _pos2)
{
	if (m_wallNum == 0) return;

	bool isHit = false;

	/*��*/
	for (int i = 0; i < m_wallNum; i++)
	{
		m_poly = m_wallPoly[i];

		if (!HitCheck_Capsule_Triangle(_pos1, _pos2, m_player->GetRadius(),
			m_poly->Position[0], m_poly->Position[1], m_poly->Position[2]))
		{
			continue;
		}

		isHit = true;

		DrawString(200, 200, "hitPolygon", 0xffffff);

		VECTOR SlideVec;
		SlideVec = VCross(m_player->GetVelocity(), m_poly->Normal);

		SlideVec = VCross(m_poly->Normal, SlideVec);

		m_player->SetPosition(VAdd(m_player->GetPosition(), SlideVec));

		bool isHitWallPolygon = false;
		for (int j = 0; j < m_wallNum; j++)
		{
			m_poly - m_wallPoly[j];

			if (!HitCheck_Capsule_Triangle(_pos1, _pos2, m_player->GetRadius(),
				m_poly->Position[0], m_poly->Position[1], m_poly->Position[2]))
			{
				isHitWallPolygon = true;
				break;
			}

		}

		if (!isHitWallPolygon)
		{
			isHit = false;
			break;
		}

	}

	for (int i = 0; i < m_wallNum; i++)
	{
		m_poly = m_wallPoly[i];

		if (HitCheck_Capsule_Triangle(_pos1, _pos2, m_player->GetRadius(),
			m_poly->Position[0], m_poly->Position[1], m_poly->Position[2]))
		{
			isHit = true;
			break;
		}

	}

	if (isHit == true)
	{
		FixPositionWigthWallInternal(_pos1, _pos2);
	}
}

void SceneGame::FixPositionWigthWallInternal(VECTOR _pos1, VECTOR _pos2)
{
	for (int i = 0; i < 16; i++)
	{
		bool isHitWall = false;
		for (int j = 0; j < m_wallNum; j++)
		{
			m_poly = m_wallPoly[j];
			if (HitCheck_Capsule_Triangle(_pos1, _pos2, m_player->GetRadius(),
				m_poly->Position[0], m_poly->Position[1], m_poly->Position[2]))
			{
				continue;
			}

			m_player->SetPosition(VAdd(m_player->GetPosition(), VScale(m_poly->Normal, 0.008f)));

			for (int k = 0; k < m_wallNum; k++)
			{
				m_poly = m_wallPoly[k];
				if (HitCheck_Capsule_Triangle(_pos1, _pos2, m_player->GetRadius(),
					m_poly->Position[0], m_poly->Position[1], m_poly->Position[2]))
				{
					isHitWall = true;
					break;
				}
			}

			if (!isHitWall) break;
		}

		if (!isHitWall) break;

	}
}

void SceneGame::FixNowPositionWithFloor(VECTOR _pos1, VECTOR _pos2)
{
	if (m_floorNum == 0) return;
	bool isHit = false;

	if (m_player->GetIsJump() == true && m_player->GetJumpPower() >= 0.0f)
	{

		float PolyMinPosY = 0.0f;

		for (int i = 0; i < m_floorNum; i++)
		{
			m_poly = m_floorPoly[i];

			m_lineRes = HitCheck_Line_Triangle(_pos1, _pos2, m_poly->Position[0], m_poly->Position[1], m_poly->Position[2]);

			if (!m_lineRes.HitFlag) continue;

			if (PolyMinPosY < m_lineRes.Position.y)
			{
				isHit = true;
				PolyMinPosY = m_lineRes.Position.y;
			}

		}

		if (isHit)
		{
			m_player->SetPosition(VGet(m_player->GetPosition().x, PolyMinPosY/* - _pos2.y*/, m_player->GetPosition().z));
		}
	
	}
	else
	{
		float PolyMaxPosY = 0.0f;

		isHit = false;
		for (int i = 0; i < m_floorNum; i++)
		{
			m_poly = m_floorPoly[i];

			m_lineRes = HitCheck_Line_Triangle(VAdd(_pos1, _pos2), m_player->GetPosition(),
				m_poly->Position[0], m_poly->Position[1], m_poly->Position[2]);

			if (!m_lineRes.HitFlag) continue;

			if (isHit && PolyMaxPosY > m_lineRes.Position.y) continue;

			isHit = true;
			PolyMaxPosY = m_lineRes.Position.y;

		}

		if (isHit)
		{
			m_player->SetPosition(VGet(m_player->GetPosition().x, PolyMaxPosY + m_player->GetRadius(), m_player->GetPosition().z));
		
		}
	}


}



//memo
//��������̓J�v�Z���̐��ɓ���������␳�����悤�ɂȂ��Ă��邩��A�J�v�Z���̔��a���l�������ڐG�ɂ��Ă�����