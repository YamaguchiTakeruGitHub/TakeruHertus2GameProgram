#pragma once
#include "../../Base/Component.h"
#include "../../ComponentTransform/ComponentTransform.h"
#include "../../../../InputDevice/InputManager.h"

/// <summary>
/// �J�����̃p�����[�^�[
/// </summary>
namespace CAMERACONTROLPARAMETER
{
	static constexpr float ANGLE_SPEED			 = 0.8f;	//���񑬓x
	static constexpr float PLAYER_TARGET_HEIGHT  = 100.0f;	//�v���C���[��Y���W����ǂꂾ�������ʒu�𒍎��_�Ƃ��邩
	static constexpr float PLAYER_DISTANCE		 = 100.0f;  //�v���C���[�Ƃ̋���
}

/// <summary>
/// �����_�A�J�������x�A�����_����J�����܂ł̋������Ǘ�
/// </summary>
class ComponentCameraControl : public Component
{
private:
	std::shared_ptr<ComponentTransform> m_transform;//�ʒu�Ȃǂ������R���|�[�l���g
	std::shared_ptr<InputManager> m_Idm;			//���̓f�o�C�X

	VECTOR m_target;		//�J�����̒����_
	float m_sinParam;		//sin�p�����[�^
	float m_cosParam;		//cos�p�����[�^
	float m_horizontalAngle;//�����A���O��
	float m_verticalAngle;	//�����A���O��

public:
	ComponentCameraControl(std::shared_ptr<ComponentTransform> _transform);

	void Init();
	void Update();
	void Draw();
	void Final();

	/*===============================================================*/
	//�Z�b�^�[�ƃQ�b�^�[
	/*===============================================================*/

	//�|�W�V����
	void SetPosition(const VECTOR& _pos) { m_transform->position = _pos; }
	VECTOR GetPositin() const { return m_transform->position; }

	/*�����_�̃f�[�^*/
	void SetTarget(const VECTOR& _target) { m_target = _target; }
	VECTOR GetTarget() const { return m_target; }

	/*Sin�p�����[�^�̃f�[�^*/
	void SetSinParam(const float& _sinParam) { m_sinParam = _sinParam; }
	float GetSinParam() const { return m_sinParam; }

	/*Cos�p�����[�^�̃f�[�^*/
	void SetCosParam(const float& _cosParam) { m_cosParam = _cosParam; }
	float GetCosParam() const { return m_cosParam; }

	/*�����A���O���̃f�[�^*/
	void SetHAngle(const float& _hAngle) { m_horizontalAngle = _hAngle; }
	float GetHAngle() const { return m_horizontalAngle; }

	/*�����A���O���̃f�[�^*/
	void SetVAngle(const float& _vAngle) { m_verticalAngle = _vAngle; }
	float GetVAngle() const { return m_verticalAngle; }


};

