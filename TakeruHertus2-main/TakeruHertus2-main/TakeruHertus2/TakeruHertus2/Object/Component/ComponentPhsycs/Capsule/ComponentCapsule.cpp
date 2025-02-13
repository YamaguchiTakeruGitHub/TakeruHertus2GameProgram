#include "ComponentCapsule.h"

ComponentCapsule::ComponentCapsule(std::shared_ptr<ComponentTransform> _transform)
	: m_transform(_transform)
{
}

void ComponentCapsule::Draw()
{
#ifdef _DEBUG
	DrawCapsule3D(startPosition, endPosition, radius, 5, 0xff0000, 0xff0000, false);
#endif // _DEBUG

}
