#include "ComponentMovement.h"


void ComponentMovement::UpdatePlayerJump()
{
	//�n�ʂɒ��n���Ă���A�W�����v�{�^����������Ă�����
	if (m_isGround == true && m_Idm->m_joyPad->isA == true)
	{
		m_jumpHoldTime = 0.0f;
		m_isJump = true;
	}

	//�W�����v�����{�^���������ꑱ���Ă��邩
	if (m_isJump == true && m_Idm->m_joyPad->isAHold == true)
	{
		m_jumpHoldTime += GAMECONSTANT::k_DELTA_TIME;
		m_jumpHoldTime = min(m_jumpHoldTime, MOVEMENT::k_MAXJUMPTIME);
	}

	//���������Ԃ��V��܂ŗ�����W�����v���~�߂�
	if (m_isJump == true && (!m_Idm->m_joyPad->isAHold || m_jumpHoldTime >= MOVEMENT::k_MAXJUMPTIME))
	{
		m_jumpPower = MOVEMENT::k_MINJUMPFORCE + (MOVEMENT::k_MAXJUMPFORCE - MOVEMENT::k_MINJUMPFORCE) * (m_jumpHoldTime / MOVEMENT::k_MAXJUMPTIME);
		m_jumpVelocityY = m_jumpPower;
		m_isJump = false;
		m_isGround = false;
	}
	
	//�n�ʂɂ��Ă��Ȃ��ꍇ�d�͗���������
	if (!m_isGround)
	{
		m_jumpVelocityY += MOVEMENT::k_GRAVITY * GAMECONSTANT::k_DELTA_TIME;
		m_transform->position.y += m_jumpVelocityY * GAMECONSTANT::k_DELTA_TIME;
	}
}

void ComponentMovement::UpdatePlayerMovement()
{
	/*���X�e�b�N�̏���*/
	float leftSticX = m_Idm->m_joyPad->GetLeftStickX();
	float leftSticY = m_Idm->m_joyPad->GetLeftStickY();

	/*��ɐ��䂷��ϐ�*/
	//�P�ɂȂ�Ȃ��悤�ɖ��t���[���O�ɂ���
	m_rightbody->direction = VGet(0.0f, 0.0f, 0.0f);

	//��Ɉړ����ɂȂ�Ȃ��悤�ɖ��t���[�����낷
	m_isMove = false;

	/*�X�e�b�N�����������Ă���ꍇ*/
	if (leftSticX != 0.0f || leftSticY != 0.0f)
	{
		m_isMove = true;

		auto targetAngleRad = atan2(-leftSticX, leftSticY);
		auto targetangleDeg = targetAngleRad * 180.0f / DX_PI_F;

		auto targetAngle = targetangleDeg - m_conversionCameraHAngle;
		auto angleDifference = targetAngle - m_transform->angle;

		if (angleDifference > 180.0f)
		{
			angleDifference -= 360.0f;
		}
		else
			if (angleDifference < -180.0f)
			{
				angleDifference += 360.0f;
			}

		m_transform->angle += angleDifference * MOVEMENT::kANGLE_ROTATION_SPEED;
		m_rightbody->direction.x = sin(targetAngleRad);
		m_rightbody->direction.z = cos(targetAngleRad);
	}

	if (VSquareSize(m_rightbody->direction) > 0)
	{
		m_rightbody->direction = VNorm(m_rightbody->direction);
	}

	if (m_isMove == true)
	{
		m_rightbody->velocity = VGet(m_rightbody->direction.x * MOVEMENT::k_MOVESPEED,
									0.0f,
									m_rightbody->direction.z * MOVEMENT::k_MOVESPEED);

		m_conversionSinParam = sin(m_conversionCameraHAngle / 180.0f * DX_PI_F);
		m_conversionCosParam = cos(m_conversionCameraHAngle / 180.0f * DX_PI_F);

		VECTOR tempMoveVector;
		tempMoveVector.x = m_rightbody->velocity.x * m_conversionCosParam - m_rightbody->velocity.z * m_conversionSinParam;
		tempMoveVector.y = 0.0f;
		tempMoveVector.z = m_rightbody->velocity.x * m_conversionSinParam - m_rightbody->velocity.z * m_conversionCosParam;
		
		m_transform->position = VAdd(m_transform->position, tempMoveVector);
	}


}

ComponentMovement::ComponentMovement(std::shared_ptr<ComponentTransform> _transform, std::shared_ptr<ComponentRightBody> _rightbody, std::string _tag)
	/*�R���|�[�l���g�̎Q�Ƃ̏�����*/
	: m_transform				(_transform)
	, m_rightbody				(_rightbody)

	/*�v���C���[�̍s��*/
	, m_isJump					(false)		//�W�����v���Ă��邩�ǂ���
	, m_isGround				(false)		//�n�ʂɂ��邩�ǂ���
	, m_isMove					(false)		//�ړ������ǂ���
	, m_jumpPower				(0.0f)		//�W�����v��
	, m_jumpVelocityY			(0.0f)		//�W�����v�̕����Ƒ��x�F�x
	, m_jumpHoldTime			(0.0f)		//�������ݎ���
	
	, m_conversionCameraHAngle	(0.0f)		//�����̕ϊ��A���O��
	, m_conversionCosParam		(0.0f)		//�R�T�C���p�����[�^
	, m_conversionSinParam		(0.0f)		//�T�C���p�����[�^
	, m_targetAngle				(0.0f)		//�U�������̃A���O��
	, m_saAngle					(0.0f)		//�T�[�t�F�X�A���O��
{
	m_Idm = std::make_shared<InputManager>();
}

void ComponentMovement::Init()
{
	/*���̓f�o�C�X�̏�����*/
	m_Idm->Init();

	/*�v���C���[�̍s��*/
	m_isJump				 = false;	//�W�����v���Ă��邩�ǂ���
	m_isGround				 = false;	//�n�ʂɂ��邩�ǂ���
	m_jumpPower				 = 0.0f;	//�W�����v��
	m_jumpVelocityY			 = 0.0f;	//�W�����v�̕����Ƒ��x�F�x
	m_jumpHoldTime			 = 0.0f;	//�������ݎ���

	/*�J�����̌������l��������肩��*/
	m_conversionCameraHAngle = 0.0f;	//�����̕ϊ��A���O��
	m_conversionCosParam	 = 0.0f;	//�R�T�C���p�����[�^
	m_conversionSinParam	 = 0.0f;	//�T�C���p�����[�^
	m_targetAngle			 = 0.0f;	//�U�������̃A���O��
	m_saAngle				 = 0.0f;	//�T�[�t�F�X�A���O��
}

void ComponentMovement::Update()
{
	/*���̓f�o�C�X�̍X�V*/
	m_Idm->Update();

		UpdatePlayerMovement();//�s������
		UpdatePlayerJump();//�W�����v����
	if (m_tag == TagCharacterObject::PLAYER)
	{
	}
}

void ComponentMovement::Draw()
{
}

void ComponentMovement::Final()
{
}
