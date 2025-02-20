#include "EnemyFox.h"
#include "../../../../CSVLib/CsvData_Reading_And_Writing_Equipment.h"

EnemyFox::EnemyFox()
	: m_attackDistance	(0.0f)
	, m_chaseDistance	(0.0f)
	, m_targetPostion	(VGet(0.0f,0.0f,0.0f))
	, filename			("")
	, Data				()
{
	/*�R���|�[�l���g�̐���*/
	AddComponent<ComponentTransform>();
	m_transform = GetComponent<ComponentTransform>();

	AddComponent<ComponentRightBody>();
	m_rightbody = GetComponent<ComponentRightBody>();

	AddComponent<ComponentCapsule>(m_transform);
	m_capsule = GetComponent<ComponentCapsule>();

	AddComponent<ComponentModel>();
	m_model = GetComponent<ComponentModel>();

}

EnemyFox::~EnemyFox()
{
}

void EnemyFox::Init()
{
	/*CSVLib�̏�����*/
	filename = "../Data/GameData/EnemyData.csv";
	Data = CSVLib::ReadCSV(filename);

	/*��Ԃ̏�����*/
	m_attackDistance = CSVLib::GetCell_float(Data, 1, 5);//�U�����苗��
	m_chaseDistance	 = CSVLib::GetCell_float(Data, 1, 4); //�ǐՔ��苗��

	m_targetPostion	 = VGet(0, 0, 0);	 //�_���Ώۂ̍��W
	m_state			 = EnemyState::Idel; //�ŏ��̏��

	/*�R���|�[�l���g�̏�����*/
	Entity::InitComponent();

	/*Transform�̏�����*/
	m_transform->position	 = VGet(0, 100, 0);						//�����|�W�V����
	m_transform->scale		 = VGet(CSVLib::GetCell_float(Data, 1, 3),	//�傫���QX
								CSVLib::GetCell_float(Data, 1, 3),	//�傫���QY
								CSVLib::GetCell_float(Data, 1, 3));	//�傫���QZ

	/*�J�v�Z���̏�����*/
	m_capsule->radius		 = CSVLib::GetCell_float(Data, 1, 6);//���a
	m_capsule->height		 = CSVLib::GetCell_float(Data, 1, 7);//�T�C�Y


	/*���f���̏�����*/
	m_model->LoadModel("../ Data/Asset/3D/Enemy/Enemy_Fox/Enemy_fox.mv1");
}

void EnemyFox::Update()
{
	/*�R���|�[�l���g�̍X�V*/
	Entity::UpdateComponent();

	/*��*/
	if (m_transform->position.y - m_capsule->radius > 0.0f)
	{
		m_transform->position.y--;
	}
	else
	{
		m_transform->position.y = 0.0f + m_capsule->radius;
	}

	/*�t���[���Ŏ擾*/
	//m_capsule->startPosition = MV1GetFramePosition(m_model->m_modelHandle, 20);
	//m_capsule->endPosition = MV1GetFramePosition(m_model->m_modelHandle, 4);

	/*�J�v�Z���̍X�V*/

	/*�A���O���̍X�V*/
	m_transform->angle		 = std::atan2(-m_rightbody->direction.x, -m_rightbody->direction.z);//�A�[�N�^���W�F���g�A���[�N���b�h�����Ō����ɕϊ�

	/*��Ԃ̍X�V*/
	UpdateState();

	/*�傫���A�����A���W�̍X�V*/
	MV1SetScale			(m_model->m_modelHandle, m_transform->scale);
	MV1SetRotationXYZ	(m_model->m_modelHandle, VGet(0, m_transform->angle, 0));
	MV1SetPosition		(m_model->m_modelHandle, m_transform->position);
}

void EnemyFox::Draw()
{
	/*�R���|�[�l���g�̕`��*/
	Entity::DrawComponent();
}

void EnemyFox::Final()
{
	/*�R���|�[�l���g�̉��*/
	Entity::FinalComponent();
}

void EnemyFox::UpdateMove(VECTOR& _targetPos)
{
	VECTOR lengs = VSub(_targetPos, m_transform->position);
	float lengsSize = VSize(lengs);

	m_rightbody->direction = VNorm(lengs);
	m_transform->position = VAdd(m_transform->position, VScale(m_rightbody->direction, 1.0f));
}

void EnemyFox::UpdateState()
{
	float distance = VSize(VSub(m_targetPostion, m_transform->position));

	DrawFormatString(0, 60, 0xffffff, "distance:%f", distance);

	switch (m_state)
	{
	case EnemyFox::EnemyState::Idel:
		if (distance <= m_chaseDistance)
		{
			m_state = EnemyState::Chase;
		}
		break;

	case EnemyFox::EnemyState::Chase:
		UpdateMove(m_targetPostion);
		
		if (distance <= m_attackDistance)
		{
			m_state = EnemyState::Attack;
		}

		if (distance >= m_chaseDistance)
		{
			m_state = EnemyState::Idel;
		}
		break;

	case EnemyFox::EnemyState::Attack:

		if (distance >= m_attackDistance)
		{
			m_state = EnemyState::Chase;
		}

		break;
	case EnemyFox::EnemyState::Retreat:
		break;
	case EnemyFox::EnemyState::Deth:
		break;
	default:
		break;
	}
}