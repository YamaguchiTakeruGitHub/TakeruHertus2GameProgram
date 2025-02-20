#pragma once
#include "../../Entity/Entity.h"

/// <summary>
/// �v���C���[
/// </summary>
class Player : public Entity
{
private:
	std::shared_ptr<ComponentTransform> m_transform;
	std::shared_ptr<ComponentRightBody> m_rightbody;
	std::shared_ptr<ComponentMovement> m_movement;
	std::shared_ptr<ComponentModel> m_model;
	std::shared_ptr<ComponentCapsule> m_capsule;
	std::shared_ptr<ComponentAnimation> m_animation;

	/*�ϐ����֐��錾*/
	std::string filename;//�t�@�C���̃p�X
	std::vector<std::vector<std::string>> Data;//�t�@�C���̃f�[�^

	/// <summary>
	/// �A�j���[�V�����̍X�V
	/// </summary>
	void UpdateAnimation();

public:
	Player();
	~Player();

	void Init();
	void Update();
	void Draw();
	void Final();

	//======================================================================
	// �Z�b�^�[�Q�b�^�[
	//======================================================================
	//�|�W�V����
	void SetPosition(const VECTOR& _pos) { m_transform->position = _pos; }
	VECTOR GetPosition() const { return m_transform->position; }

	//���F���V�e�B
	void SetVelocity(const VECTOR& _velocity) { m_rightbody->velocity = _velocity; }
	VECTOR GetVelocity() const { return m_rightbody->velocity; }

	//�J�v�Z���̍���
	float GetCapsuleHeight() const { return m_capsule->height; }

	//�J�v�Z���̔��a
	void SetRadius(const float& _radius) { m_capsule->radius = _radius; }
	float GetRadius() const { return m_capsule->radius; }



	/*Movement�n*/
	
	//�ړ�����
	void SetIsMove(const bool& _isMove) { m_movement->SetIsMove(_isMove); }
	bool GetIsMove() const { return m_movement->GetIsMove(); }

	//�W�����v����
	void SetIsJump(const bool& _isJump) { m_movement->SetIsJump(_isJump); }
	bool GetIsJump() const { return m_movement->GetIsJump(); }

	//�W�����v��
	float GetJumpPower() const { return m_movement->GetJumpPower(); }

	//�n�ʂɂ��Ă邩
	void SetIsGround(const bool& _isGround) { m_movement->SetIsGround(_isGround); }
	bool GetIsGround() const { return m_movement->GetIsGround(); }

	/*�J�����̌������l���������W�̕ϊ��p�Z�b�g�֐�*/
	void SetConversionHorizontalAngle(const float _cHAngle) { m_movement->SetConversionCameraHAngle(_cHAngle); }
	void SetConversionCosParam(const float _cCosParam) { m_movement->SetConversionCosParam(_cCosParam); }
	void SetConversionSinParam(const float _cSinParam) { m_movement->SetConversionSinParam(_cSinParam); }
};

