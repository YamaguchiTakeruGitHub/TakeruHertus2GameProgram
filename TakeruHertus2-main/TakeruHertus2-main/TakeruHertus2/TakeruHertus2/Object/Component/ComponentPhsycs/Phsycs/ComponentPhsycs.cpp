#include "ComponentPhsycs.h"

ComponentPhsycs::ComponentPhsycs(std::shared_ptr<ComponentTransform> _transform, std::shared_ptr<ComponentRightBody> _rightBody, std::string _shapeType)
	: m_transform(_transform)
	, m_rightbody(_rightBody)
{
}

void ComponentPhsycs::Init()
{
}

void ComponentPhsycs::Update()
{
}

void ComponentPhsycs::Draw()
{
}

void ComponentPhsycs::Final()
{
}
