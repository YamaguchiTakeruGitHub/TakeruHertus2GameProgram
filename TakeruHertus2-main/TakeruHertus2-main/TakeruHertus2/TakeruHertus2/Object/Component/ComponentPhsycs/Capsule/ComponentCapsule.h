#pragma once
#include "../../Base/Component.h"
#include "../../ComponentTransform/ComponentTransform.h"

class ComponentCapsule : public Component
{
private:
	std::shared_ptr<ComponentTransform> m_transform;

public:
	ComponentCapsule(std::shared_ptr<ComponentTransform> _transform);
	void Init() override {};
	void Update() override {};
	void Draw() override;
	void Final() override {};

	VECTOR startPosition;	//�J�v�Z���̓�
	VECTOR endPosition;		//�J�v�Z���̑���
	float radius;			//���a
	float size;				//�|�W�V��������̃T�C�Y
};

