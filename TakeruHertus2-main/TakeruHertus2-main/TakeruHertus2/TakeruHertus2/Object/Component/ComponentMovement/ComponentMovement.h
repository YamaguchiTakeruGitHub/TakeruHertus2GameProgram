#pragma once
#include "../Base/Component.h"
#include "../ComponentTransform/ComponentTransform.h"
#include "../ComponentPhsycs/RightBody/ComponentRightBody.h"
#include "../../../InputDevice/InputManager.h"

/*�萔��^�O*/
#include "../../GameTag.h"//�^�O
#include "../../../Application/GameConstant.h"//Game�S�ʂň����萔


//�ړ��̒萔
namespace MOVEMENT
{
	static constexpr float k_MAXJUMPTIME = 10.0f;		//�W�����v��(�f�t�H8
	static constexpr float k_MINJUMPFORCE = 2.0f;		//�Ⴓ�i�f�t�H3
	static constexpr float k_MAXJUMPFORCE = 5.0f;		//����(�f�t�H10
	static constexpr float k_GRAVITY = -0.2f;			//�d�́i������ʂɂ����j(�f�t�H-0.3
	
	static constexpr float k_MOVESPEED = 2.0f;			//�ړ����x

	static constexpr float kANGLE_ROTATION_SPEED = 0.15f;//�U��������x
}

/// <summary>
/// �s�������F�����w��Fm_transform, m_rightbody
/// </summary>
class ComponentMovement : public Component
{
private:/*�C���X�^���X��֐���`���^�O��`*/
	/*�R���|�[�l���g*/
	std::shared_ptr<ComponentTransform> m_transform;
	std::shared_ptr<ComponentRightBody> m_rightbody;

	/*���̓f�o�C�X*/
	std::shared_ptr<InputManager> m_Idm;

	/*�v���C���[�̍s������*/
	void UpdatePlayerMovement();//�v���C���[�̍s������

	void UpdatePlayerJump();//�W�����v�X�V����

private:/*�ϐ���`*/
	/*�^�O*/
	std::string m_tag;

	/*�v���C���[�̍s���n�ϐ�*/
	bool m_isJump;					//�W�����v���Ă��邩�ǂ���
	bool m_isGround;				//�n�ʂɂ��邩�ǂ���
	bool m_isMove;					//�ړ������ǂ���

	float m_jumpPower;				//�W�����v��
	float m_jumpVelocityY;			//�W�����v�̕����Ƒ��x�F�x
	float m_jumpHoldTime;			//�������ݎ���

	/*�J�����̌������l��������肩��*/
	float m_conversionCameraHAngle;	//�����̕ϊ��A���O��
	float m_conversionCosParam;		//�R�T�C���p�����[�^
	float m_conversionSinParam;		//�T�C���p�����[�^
	float m_targetAngle;			//�U�������̃A���O��
	float m_saAngle;				//�T�[�t�F�X�A���O��


public:
	ComponentMovement(std::shared_ptr<ComponentTransform> _transform, std::shared_ptr<ComponentRightBody> _rightbody, std::string _tag);

	void Init() override;
	void Update() override;
	void Draw() override;
	void Final() override;

	void SetConversionCameraHAngle(const float& _ccHAngle) { m_conversionCameraHAngle = _ccHAngle; }
	float GetConversionCameraHAngle() { return m_conversionCameraHAngle; }

	void SetConversionCosParam(const float& _cCosParam) { m_conversionCosParam = _cCosParam; }
	float GetConversionCosParam() { return m_conversionCosParam; }

	void SetConversionSinParam(const float& _cSinParam) { m_conversionSinParam = _cSinParam; }
	float GetConversionSinParam() { return m_conversionSinParam; }

	void SetIsGround(const bool& _isGround) { m_isGround = _isGround; }

	/*�����Ă��邩�ǂ����t���O*/
	void SetIsMove(const bool& _isMove) { m_isMove = _isMove; }
	bool GetIsMove() const { return m_isMove; }

	/*�A���O��*/
	void SetAngle(const float& _angle) { m_transform->angle = _angle; }
	float GetAngle() const { return m_transform->angle; }

};

