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
	void Update();
	void Draw();
	void Final();

};

