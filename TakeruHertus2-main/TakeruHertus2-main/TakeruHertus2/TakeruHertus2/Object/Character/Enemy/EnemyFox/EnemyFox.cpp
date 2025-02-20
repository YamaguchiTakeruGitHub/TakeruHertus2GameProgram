#include "EnemyFox.h"
#include "../../../../CSVLib/CsvData_Reading_And_Writing_Equipment.h"

EnemyFox::EnemyFox()
	: m_attackDistance	(0.0f)
	, m_chaseDistance	(0.0f)
	, m_targetPostion	(VGet(0.0f,0.0f,0.0f))
	, filename			("")
	, Data				()
{
	/*コンポーネントの生成*/
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
	/*CSVLibの初期化*/
	filename = "../Data/GameData/EnemyData.csv";
	Data = CSVLib::ReadCSV(filename);

	/*状態の初期化*/
	m_attackDistance = CSVLib::GetCell_float(Data, 1, 5);//攻撃判定距離
	m_chaseDistance	 = CSVLib::GetCell_float(Data, 1, 4); //追跡判定距離

	m_targetPostion	 = VGet(0, 0, 0);	 //狙う対象の座標
	m_state			 = EnemyState::Idel; //最初の状態

	/*コンポーネントの初期化*/
	Entity::InitComponent();

	/*Transformの初期化*/
	m_transform->position	 = VGet(0, 100, 0);						//初期ポジション
	m_transform->scale		 = VGet(CSVLib::GetCell_float(Data, 1, 3),	//大きさ＿X
								CSVLib::GetCell_float(Data, 1, 3),	//大きさ＿Y
								CSVLib::GetCell_float(Data, 1, 3));	//大きさ＿Z

	/*カプセルの初期化*/
	m_capsule->radius		 = CSVLib::GetCell_float(Data, 1, 6);//半径
	m_capsule->height		 = CSVLib::GetCell_float(Data, 1, 7);//サイズ


	/*モデルの初期化*/
	m_model->LoadModel("../ Data/Asset/3D/Enemy/Enemy_Fox/Enemy_fox.mv1");
}

void EnemyFox::Update()
{
	/*コンポーネントの更新*/
	Entity::UpdateComponent();

	/*仮*/
	if (m_transform->position.y - m_capsule->radius > 0.0f)
	{
		m_transform->position.y--;
	}
	else
	{
		m_transform->position.y = 0.0f + m_capsule->radius;
	}

	/*フレームで取得*/
	//m_capsule->startPosition = MV1GetFramePosition(m_model->m_modelHandle, 20);
	//m_capsule->endPosition = MV1GetFramePosition(m_model->m_modelHandle, 4);

	/*カプセルの更新*/

	/*アングルの更新*/
	m_transform->angle		 = std::atan2(-m_rightbody->direction.x, -m_rightbody->direction.z);//アークタンジェント、ユークリッド距離で向きに変換

	/*状態の更新*/
	UpdateState();

	/*大きさ、向き、座標の更新*/
	MV1SetScale			(m_model->m_modelHandle, m_transform->scale);
	MV1SetRotationXYZ	(m_model->m_modelHandle, VGet(0, m_transform->angle, 0));
	MV1SetPosition		(m_model->m_modelHandle, m_transform->position);
}

void EnemyFox::Draw()
{
	/*コンポーネントの描画*/
	Entity::DrawComponent();
}

void EnemyFox::Final()
{
	/*コンポーネントの解放*/
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