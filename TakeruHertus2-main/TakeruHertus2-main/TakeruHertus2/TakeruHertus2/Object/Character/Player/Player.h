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

public:
	Player();
	~Player();

	void Init();
	void Update(float _cHAngle, float _sinParam, float _cosParam);
	void Draw();
	void Final();

	//======================================================================
	// セッターゲッター
	//======================================================================
	void SetPosition(const VECTOR& _pos) { m_transform->position = _pos; }
	VECTOR GetPosition() const { return m_transform->position; }

	void SetConversionHorizontalAngle(const float _cHAngle) { m_movement->SetConversionCameraHAngle(_cHAngle); }
	void SetConversionCosParam(const float _cCosParam) { m_movement->SetConversionCosParam(_cCosParam); }
	void SetConversionSinParam(const float _cSinParam) { m_movement->SetConversionSinParam(_cSinParam); }
};

