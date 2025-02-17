#pragma once
#include "../../Entity/Entity.h"

class Player : public Entity
{
private:
	std::shared_ptr<ComponentTransform> m_transform;
	std::shared_ptr<ComponentRightBody> m_rightbody;
	std::shared_ptr<ComponentMovement> m_movement;
	std::shared_ptr<ComponentModel> m_model;
	std::shared_ptr<ComponentCapsule> m_capsule;
	std::shared_ptr<ComponentAnimation> m_animation;

	void UpdateAnimation();

public:
	Player();
	~Player();

	void Init();
	void Update();
	void Draw();
	void Final();

	//======================================================================
	// セッターゲッター
	//======================================================================
	void SetPosition(const VECTOR& _pos) { m_transform->position = _pos; }
	VECTOR GetPosition() const { return m_transform->position; }

	//カプセルの開始地点
	void SetStartPos(const VECTOR& _startPos) { m_capsule->startPosition = _startPos; }
	VECTOR GetStartPos() const { return m_capsule->startPosition; }

	//カプセルの終了地点
	void SetEndPos(const VECTOR& _endPos) { m_capsule->endPosition = _endPos; }
	VECTOR GetEndPos() const { return m_capsule->endPosition; }

	//カプセルの半径
	void SetRadius(const float& _radius) { m_capsule->radius = _radius; }
	float GetRadius() const { return m_capsule->radius; }

	void SetConversionHorizontalAngle(const float _cHAngle) { m_movement->SetConversionCameraHAngle(_cHAngle); }
	void SetConversionCosParam(const float _cCosParam) { m_movement->SetConversionCosParam(_cCosParam); }
	void SetConversionSinParam(const float _cSinParam) { m_movement->SetConversionSinParam(_cSinParam); }
};

