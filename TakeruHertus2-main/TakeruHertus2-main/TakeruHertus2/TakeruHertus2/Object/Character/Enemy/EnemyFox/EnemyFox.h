#pragma once
#include "../Base/EnemyBase.h"

class EnemyFox : public EnemyBase
{
private:
	std::shared_ptr<ComponentTransform> m_transform;
	std::shared_ptr<ComponentRightBody> m_rightbody;
	std::shared_ptr<ComponentCapsule> m_capsule;
	std::shared_ptr<ComponentModel> m_model;

	void UpdateMove(VECTOR& _targetPos);

	void UpdateState();
	
	enum class EnemyState
	{
		Idel,
		Chase,
		Attack,
		Retreat,
		Deth,
	}m_state;

	VECTOR m_targetPostion;

	float m_chaseDistance;
	float m_attackDistance;

	std::string filename;
	std::vector<std::vector<std::string>> Data;

public:
	EnemyFox();
	~EnemyFox() override;

	void Init();
	void Update();
	void Draw();
	void Final();

	//======================================================================
	// セッターゲッター
	//======================================================================
	void SetPosition(const VECTOR& _pos) { m_transform->position = _pos; }
	VECTOR GetPosition() const { return m_transform->position; }

	//狙いを定めているターゲット
	void SetTargetPosition(const VECTOR& _targetPos) { m_targetPostion = _targetPos; }
	VECTOR GetTargetPosition() const { return m_targetPostion; }

	//カプセルの開始地点
	void SetStartPos(const VECTOR& _startPos) { m_capsule->startPosition = _startPos; }
	VECTOR GetStartPos() const { return m_capsule->startPosition; }

	//カプセルの終了地点
	void SetEndPos(const VECTOR& _endPos) { m_capsule->endPosition = _endPos; }
	VECTOR GetEndPos() const { return m_capsule->endPosition; }

	//カプセルの半径
	void SetRadius(const float& _radius) { m_capsule->radius = _radius; }
	float GetRadius() const { return m_capsule->radius; }

};

