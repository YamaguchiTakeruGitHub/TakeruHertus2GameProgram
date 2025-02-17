#pragma once
#include "../../Base/Component.h"
#include "../../ComponentTransform/ComponentTransform.h"
#include "../../ComponentPhsycs/RightBody/ComponentRightBody.h"
#include "../../ComponentPhsycs/Capsule/ComponentCapsule.h"
#include "../../ComponentPhsycs/Sphere/ComponentSphere.h"
#include "../PhsycsShapeType.h"//形状のタイプ

class ComponentPhsycs : public Component
{
private:
	std::shared_ptr<ComponentTransform> m_transform;
	std::shared_ptr<ComponentRightBody> m_rightbody;
	/*いったんかりおき0*/
	std::shared_ptr<ComponentCapsule> m_capsule;
	std::shared_ptr<ComponentSphere> m_sphere;

public:
	ComponentPhsycs(std::shared_ptr<ComponentTransform> _transform, std::shared_ptr<ComponentRightBody> _rightBody, std::string _shapeType);
	
	void Init() override;
	void Update() override;
	void Draw() override;
	void Final() override;

};

