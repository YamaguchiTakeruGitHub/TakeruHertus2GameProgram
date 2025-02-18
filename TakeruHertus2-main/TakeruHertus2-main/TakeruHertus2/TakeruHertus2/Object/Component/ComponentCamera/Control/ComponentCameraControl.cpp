#include "ComponentCameraControl.h"


ComponentCameraControl::ComponentCameraControl(std::shared_ptr<ComponentTransform> _transform)	
	: m_transform		(_transform) //�Q��
	, m_horizontalAngle	(0.0f)		 //�����A���O��
	, m_verticalAngle	(0.0f)		 //�����A���O��
	, m_cosParam		(0.0f)		 //�R�T�C���p�����[�^
	, m_sinParam		(0.0f)		 //�T�C���p�����[�^
{
	m_Idm = std::make_shared<InputManager>();//���̓f�o�C�X�̃C���X�^���X��
}

void ComponentCameraControl::Init()
{
	m_Idm->Init();
	/*Transform�̏�����*/
	m_transform->position = VGet(0.0f, 50.0f, 50.0f);

	/*�����o�ϐ��̏�����*/
	m_target			  = VGet(0, 0, 0);//�����_

	m_horizontalAngle	  = 0.0f;		  //�����A���O��
	m_verticalAngle		  = 0.0f;		  //�����A���O��
	
	m_cosParam			  = std::cos(m_horizontalAngle / 180.0f * DX_PI_F);//�R�T�C���p�����[�^
	m_sinParam			  = std::sin(m_horizontalAngle / 180.0f * DX_PI_F);//�T�C���p�����[�^�[
}

void ComponentCameraControl::Update()
{
	m_Idm->Update();

	/*�E�X�e�B�b�N�̎擾*/
	auto rightStickX = m_Idm->m_joyPad->GetRightStickX();
	auto rightStickY = m_Idm->m_joyPad->GetRightStickY();

	/*���O�ɕϊ�*/
	bool Left = rightStickX != 0 && rightStickX <= 0.030519f && rightStickX >= 0.0f;
	bool Right = rightStickX != 0 && rightStickX >= -0.030519f && rightStickX <= 0.0f;
	bool Up = rightStickY != 0 && rightStickY <= 0.030519f && rightStickY >= 0.0f;
	bool Down = rightStickY != 0 && rightStickY >= -0.030519 && rightStickY <= 0.0f;

	/*�J�����̑���*/
	if (rightStickX != 0 && rightStickX >= -0.030519f && rightStickX <= 0.0f)
	{
		m_horizontalAngle += CAMERACONTROLPARAMETER::ANGLE_SPEED;
		if (m_horizontalAngle >= 180.0f) m_horizontalAngle -= 360.0f;
	}
	if (rightStickX != 0 && rightStickX <= 0.030519f && rightStickX >= 0.0f)
	{
		m_horizontalAngle -= CAMERACONTROLPARAMETER::ANGLE_SPEED;
		if (m_horizontalAngle <= -180.0f) m_horizontalAngle += 360.0f;
	}
	if (rightStickY != 0 && rightStickY <= 0.030519f && rightStickY >= 0.0f)
	{
		m_verticalAngle += CAMERACONTROLPARAMETER::ANGLE_SPEED;
		if (m_verticalAngle >= 70.0f) m_verticalAngle = 70.0f;
	}
	if (rightStickY != 0 && rightStickY >= -0.030519f && rightStickY <= 0.0f)
	{
		m_verticalAngle -= CAMERACONTROLPARAMETER::ANGLE_SPEED;
		if (m_verticalAngle <= -20.0f) m_verticalAngle = -20.0f;
	}

	/*�T�C���R�T�C���p�����[�^�[*/
	m_sinParam = sin(m_verticalAngle / 180.0f * DX_PI_F);
	m_cosParam = cos(m_verticalAngle / 180.0f * DX_PI_F);

	VECTOR tempPosition1, tempPosition2;
	tempPosition1.x = 0.0f;
	tempPosition1.y = m_sinParam * CAMERACONTROLPARAMETER::PLAYER_DISTANCE;
	tempPosition1.z = -m_cosParam * CAMERACONTROLPARAMETER::PLAYER_DISTANCE;

	m_sinParam = sin(m_horizontalAngle / 180.0f * DX_PI_F);
	m_cosParam = cos(m_horizontalAngle / 180.0f * DX_PI_F);

	tempPosition2.x = m_cosParam * tempPosition1.x - m_sinParam * tempPosition1.z;
	tempPosition2.y = tempPosition1.y;
	tempPosition2.z = m_sinParam * tempPosition1.x + m_cosParam * tempPosition1.z;

	m_transform->position = VAdd(tempPosition2, m_target);
}

void ComponentCameraControl::Draw()
{
}

void ComponentCameraControl::Final()
{
}
