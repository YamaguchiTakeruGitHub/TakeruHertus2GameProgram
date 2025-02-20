#pragma once
#include "../../Base/Component.h"
#include "../../ComponentTransform/ComponentTransform.h"

/// <summary>
/// �J�v�Z���̍\���́i���������W�Ƃ����ꍇ�̏����ɑΉ��j
/// </summary>
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

	float radius;			//���a
	float height;			//�|�W�V��������̍���
};

