#include "Player.h"
#include "../../GameTag.h"

Player::Player()
{
	AddComponent<ComponentTransform>();
	m_transform = GetComponent<ComponentTransform>();

	AddComponent<ComponentRightBody>();
	m_rightbody = GetComponent<ComponentRightBody>();

	AddComponent<ComponentMovement>(m_transform, m_rightbody, TagCharacterObject::PLAYER);
	m_movement = GetComponent<ComponentMovement>();

	AddComponent<ComponentModel>();
	m_model = GetComponent<ComponentModel>();

	AddComponent<ComponentCapsule>(m_transform);
	m_capsule = GetComponent<ComponentCapsule>();
}

Player::~Player()
{
}

void Player::Init()
{
	Entity::InitComponent();
	m_transform->position = VGet(0, 100, 0);

	m_model->LoadModel("");

	m_capsule->startPosition = VAdd(m_transform->position, VGet(0, m_capsule->size, 0));
	m_capsule->endPosition = VSub(m_transform->position, VGet(0, m_capsule->size, 0));
	m_capsule->radius = 20.0f;
	m_capsule->size = 15.0f;
}

void Player::Update(float _cHAngle, float _sinParam, float _cosParam)
{
	Entity::UpdateComponent();

	if (m_transform->position.y - m_capsule->size - m_capsule->radius >= 0.0f)
	{
		m_movement->SetIsGround(false);
	}
	else
	{
		m_movement->SetIsGround(true);
	}

	m_movement->SetConversionCameraHAngle(_cHAngle);
	m_movement->SetConversionCosParam(_sinParam);
	m_movement->SetConversionSinParam(_cosParam);

	m_capsule->startPosition = VAdd(m_transform->position, VGet(0, m_capsule->size, 0));
	m_capsule->endPosition = VSub(m_transform->position, VGet(0, m_capsule->size, 0));
	MV1SetPosition(m_model->m_modelHandle, m_transform->position);
}

void Player::Draw()
{
	Entity::DrawComponent();
}

void Player::Final()
{
	Entity::FinalComponent();
}
