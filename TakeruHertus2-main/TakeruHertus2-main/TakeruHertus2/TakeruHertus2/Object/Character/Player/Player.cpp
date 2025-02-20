#include "Player.h"
#include "../../GameTag.h"
#include "../../../CSVLib/CsvData_Reading_And_Writing_Equipment.h"

/// <summary>
/// �v���C���[�̃p�����[�^�[
/// </summary>
namespace PLAYER_PARAMETER
{
	static constexpr float POS_X = 100.0f;//X���W
	static constexpr float POS_Y = 100.0f;//Y���W
	static constexpr float POS_Z = 0.0f;  //Z���W
}

Player::Player()
	: filename	("")//�t�@�C���̖��O
	, Data		()	//�t�@�C���̃f�[�^
{
	/*�R���|�[�l���g�𐶐�*/
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
	/*CSVLib������*/
	filename = "../Data/GameData/PlayerData.csv";//�t�@�C���̃p�X
	Data = CSVLib::ReadCSV(filename);			 //�t�@�C���̓ǂݍ���

	/*�R���|�[�l���g�̏�����*/
	Entity::InitComponent();

	/*Transform�̏�����*/
	m_transform->position = VGet(PLAYER_PARAMETER::POS_X,	//�|�W�V�����̏����ʒu_X
								 PLAYER_PARAMETER::POS_Y,	//�|�W�V�����̏����ʒu_Y
								 PLAYER_PARAMETER::POS_Z);	//�|�W�V�����̏����ʒu_Z

	m_transform->scale = VGet(CSVLib::GetCell_float(Data, 3, 2),	//���f���̃T�C�YX
							  CSVLib::GetCell_float(Data, 3, 2),	//���f���̃T�C�YY
						      CSVLib::GetCell_float(Data, 3, 2));	//���f���̃T�C�YZ

	/*���f���̏�����*/
	m_model->LoadModel("../ Data/Asset/3D/Player/Player.mv1");

	/*�J�v�Z���̏�����*/
	m_capsule->radius = CSVLib::GetCell_float(Data,1, 2);	//�J�v�Z���̔��a
	m_capsule->height = CSVLib::GetCell_float(Data, 2, 2);	//�J�v�Z���̃T�C�Y

}

void Player::Update()
{
	/*�A�j���[�V�����̍X�V*/
	UpdateAnimation();

	/*�R���|�[�l���g�̍X�V*/
	Entity::UpdateComponent();

	/*���n�_�̉��ݒu�i�}�b�v�̈ڐA������������ړ��j*/
	//if (m_transform->position.y - m_capsule->radius >= 0.0f)
	//{
	//	m_movement->SetIsGround(false);//�n�ʂɂ��Ă��Ȃ�
	//}
	//else
	//{
	//	m_movement->SetIsGround(true);//�n�ʂɂ���
	//}

	/*�s���̍X�V(�R���X�g���N�^�Ăяo�����Ƀ^�O��ݒ�ł���悤�ɂ�����)*/
	m_movement->SetTag(TagCharacterObject::PLAYER);

	/*���f���̃A���O���Ƒ傫���ƍ��W���X�V*/
	MV1SetRotationXYZ(m_model->m_modelHandle, VGet(0.0f, m_transform->angle * DX_PI_F / 180.0f, 0.0f));//�p�x�����W�A���ɕϊ����ăZ�b�g����
	MV1SetScale(m_model->m_modelHandle, m_transform->scale);
	MV1SetPosition(m_model->m_modelHandle, m_transform->position);
}

void Player::Draw()
{
	/*�R���|�[�l���g�̕`��*/
	Entity::DrawComponent();
}

void Player::Final()
{
	/*�R���|�[�l���g�̉��*/
	Entity::FinalComponent();
}

void Player::UpdateAnimation()
{
	/*���s���ł����*/
	if (m_movement->GetIsMove() == true)
	{
		m_animation->PlayAnim(8);//Move�A�j���[�V����
	}
	else
	{
		m_animation->PlayAnim(4);//Idel�A�j���[�V����
	}
}