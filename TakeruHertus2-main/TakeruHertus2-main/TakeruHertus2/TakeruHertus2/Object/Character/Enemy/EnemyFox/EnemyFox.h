#pragma once
#include "../Base/EnemyBase.h"


class EnemyFox : public EnemyBase
{
private:
	/*�R���|�[�l���g�̐錾*/
	std::shared_ptr<ComponentTransform> m_transform;
	std::shared_ptr<ComponentRightBody> m_rightbody;
	std::shared_ptr<ComponentCapsule> m_capsule;
	std::shared_ptr<ComponentModel> m_model;

	/*�֐����ϐ��錾*/

	/// <summary>
	/// �G�̏��
	/// </summary>
	enum class EnemyState
	{
		Idel,	//�Ƃǂ܂�
		Chase,	//�ǐ�
		Attack,	//�U��
		Retreat,//�A��
		Deth,	//���S���Ȃ�
	}m_state;//�C���X�^���X�ȈՐ錾

	//�˂炤���W
	VECTOR m_targetPostion;

	//�ǐՔ��苗��
	float m_chaseDistance;

	//�U�����苗��
	float m_attackDistance;

	//�t�@�C���̃p�X
	std::string filename;

	//�t�@�C���̃f�[�^
	std::vector<std::vector<std::string>> Data;

	//�ړ��̍X�V
	void UpdateMove(VECTOR& _targetPos);
	
	//��Ԃ̍X�V
	void UpdateState();
	
public:
	EnemyFox();
	~EnemyFox() override;

	void Init();
	void Update();
	void Draw();
	void Final();

	//======================================================================
	// �Z�b�^�[�Q�b�^�[
	//======================================================================
	//���W
	void SetPosition(const VECTOR& _pos) { m_transform->position = _pos; }
	VECTOR GetPosition() const { return m_transform->position; }

	//�_�����߂Ă���^�[�Q�b�g
	void SetTargetPosition(const VECTOR& _targetPos) { m_targetPostion = _targetPos; }
	VECTOR GetTargetPosition() const { return m_targetPostion; }

	//�J�v�Z���̊J�n�n�_
	void SetStartPos(const VECTOR& _startPos) { m_capsule->startPosition = _startPos; }
	VECTOR GetStartPos() const { return m_capsule->startPosition; }

	//�J�v�Z���̏I���n�_
	void SetEndPos(const VECTOR& _endPos) { m_capsule->endPosition = _endPos; }
	VECTOR GetEndPos() const { return m_capsule->endPosition; }

	//�J�v�Z���̔��a
	void SetRadius(const float& _radius) { m_capsule->radius = _radius; }
	float GetRadius() const { return m_capsule->radius; }

};

