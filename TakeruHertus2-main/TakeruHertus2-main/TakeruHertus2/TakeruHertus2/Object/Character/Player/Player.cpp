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

	AddComponent<ComponentAnimation>(m_model);
	m_animation = GetComponent<ComponentAnimation>();

}

Player::~Player()
{
}

void Player::Init()
{
	Entity::InitComponent();
	m_transform->position = VGet(100, 100, 0);
	m_transform->scale = VGet(0.2f, 0.2f, 0.2f);

	m_model->LoadModel("../Data/Asset/3D/Player/Player.mv1");

	m_capsule->startPosition = VAdd(m_transform->position, VGet(0, m_capsule->size, 0));
	m_capsule->endPosition = VSub(m_transform->position, VGet(0, m_capsule->size, 0));
	m_capsule->radius = 20.0f;
	m_capsule->size = 15.0f;

}

void Player::Update()
{
	UpdateAnimation();//アニメーションの更新

	Entity::UpdateComponent();

	if (m_transform->position.y - m_capsule->size - m_capsule->radius >= 0.0f)
	{
		m_movement->SetIsGround(false);
	}
	else
	{
		m_movement->SetIsGround(true);
	}

	m_capsule->startPosition = VAdd(m_transform->position, VGet(0, m_capsule->size, 0));
	m_capsule->endPosition = VSub(m_transform->position, VGet(0, m_capsule->size, 0));


	MV1SetRotationXYZ(m_model->m_modelHandle, VGet(0.0f, m_transform->angle * DX_PI_F / 180.0f, 0.0f));//角度をラジアンに変換してセットする
	MV1SetScale(m_model->m_modelHandle, m_transform->scale);
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

void Player::UpdateAnimation()
{
	if (m_movement->GetIsMove() == true)
	{
		m_animation->PlayAnim(8);
		//m_animation->PlayBlendAnim(8);
	}
	else
	{
		m_animation->PlayAnim(4);
		//m_animation->PlayBlendAnim(4);
	}

}