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

	VECTOR startPosition;	//カプセルの頭
	VECTOR endPosition;		//カプセルの足元
	float radius;			//半径
	float size;				//ポジションからのサイズ
};

