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
	m_transform->position = VGet(0, 0, 0);

	m_model->LoadModel("");

	m_capsule->startPosition = VGet(0, 0, 0);
	m_capsule->endPosition = VGet(0, 0, 0);
	m_capsule->radius = 0.0f;
	m_capsule->size = 5.0f;
}

void Player::Update()
{
	Entity::UpdateComponent();

#ifdef _DEBUG
	if (CheckHitKey(KEY_INPUT_A)) m_transform->position.x--;
	if (CheckHitKey(KEY_INPUT_D)) m_transform->position.x++;
	if (CheckHitKey(KEY_INPUT_W)) m_transform->position.y--;
	if (CheckHitKey(KEY_INPUT_S)) m_transform->position.y++;

#endif // _DEBUG


	MV1SetPosition(m_model->m_modelHandle, m_transform->position);
}

void Player::Draw()
{
	Entity::DrawComponent();
	DrawCircle(m_transform->position.x, m_transform->position.y, 50.0f, 0xffffff, true);
}

void Player::Final()
{
	Entity::FinalComponent();
}
