#pragma once
#include "../Entity/Entity.h"

class Camera : public Entity
{
private:
	std::shared_ptr<ComponentTransform> m_transform;		//�ړ��Ȃǂ̃R���|�[�l���g
	std::shared_ptr<ComponentCameraControl> m_cameraControl;//�J�����̃R���g���[��

	VECTOR m_target;
	std::string m_tag;

public:
	Camera();

	void Init();
	void Update();
	void Draw(); 
	void Final();

	/*===============================================================*/
	//�Z�b�^�[�ƃQ�b�^�[
	/*===============================================================*/

	void SetTag(std::string _tag) { m_tag = _tag; }
	std::string GetTag() const { return m_tag; }

	void SetPosition(const VECTOR& _pos) { m_transform->position; }
	VECTOR GetPosition() const { return m_transform->position; }

	void SetTarget(const VECTOR& _target) { m_target = _target; }
	VECTOR GetTarget() const { return m_target; }

	void SetHAngle(const float& _hAngle) { m_cameraControl->SetHAngle(_hAngle); }
	float GetHAngle() const { return m_cameraControl->GetHAngle(); }

	void SetCosParam(const float& _cosParam) { m_cameraControl->SetCosParam(_cosParam); }
	float GetCosParam() const { return m_cameraControl->GetCosParam(); }

	void SetSinParam(const float& _sinParam) { m_cameraControl->SetSinParam(_sinParam); }
	float GetSinParam() const { return m_cameraControl->GetSinParam(); }


};

