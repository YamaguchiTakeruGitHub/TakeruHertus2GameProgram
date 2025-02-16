#include "Camera.h"
#include "../GameTag.h"

Camera::Camera()
{
	AddComponent<ComponentTransform>();
	m_transform = GetComponent<ComponentTransform>();

	AddComponent<ComponentCameraControl>(m_transform);
	m_cameraControl = GetComponent<ComponentCameraControl>();

}

void Camera::Init()
{
	Entity::InitComponent();
	
	SetCameraNearFar(2.0f, 6000.0f);
}

void Camera::Update()
{
	Effekseer_Sync3DSetting();
	if (m_tag == TagCameraObject::CONTROL)
	{
		m_cameraControl->SetTarget(m_target);
		m_cameraControl->Update();
	}

	SetCameraPositionAndTarget_UpVecY(m_transform->position, m_target);
}

void Camera::Draw()
{
	Entity::DrawComponent();
}

void Camera::Final()
{
	Entity::FinalComponent();
}
