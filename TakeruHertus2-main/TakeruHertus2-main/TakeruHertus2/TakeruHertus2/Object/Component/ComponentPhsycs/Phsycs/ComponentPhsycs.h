#pragma once
#include "../../Base/Component.h"
#include "../../ComponentTransform/ComponentTransform.h"
#include "../../ComponentPhsycs/RightBody/ComponentRightBody.h"
#include "../../ComponentPhsycs/Capsule/ComponentCapsule.h"
#include "../../ComponentPhsycs/Sphere/ComponentSphere.h"
#include "../PhsycsShapeType.h"//�`��̃^�C�v

namespace CollInfo
{
	//�ő哖���蔻��|���S����
	constexpr int kMaxColHitPolyNum = 2000;
	//�ǉ����o�������̍ő厎�s��
	constexpr int kMaxColHitTryNum = 16;
	//�ǉ����o�����ɃX���C�h�����鋗��
	constexpr float kColHitSlideLength = 1.0f;

	//�ő哖���蔻��|���S����
	constexpr int kMaxColHitPolyNum = 2000;
	//�ǉ����o�������̍ő厎�s��
	constexpr int kMaxColHitTryNum = 16;
	//�ǉ����o�����ɃX���C�h�����鋗��
	constexpr float kColHitSlideLength = 1.0f;
	//�ړ��������𔻒f���邽�߂̕ϐ�
	constexpr float kMove = 0.01f;
	//�ǃ|���S�������|���S�����𔻒f���邽�߂̕ϐ�
	constexpr float kWallPolyBorder = 0.4f;
	//�ǃ|���S���Ɣ��f���邽�߂̍����ϐ�
	constexpr float kWallPolyHeight = 5.0f;

	//����ł���̎���
	constexpr int kEnableTimeCount = 10;

	//���̍�����ݒ�
	constexpr float kHeadHeight = 40.0f;

}

class ComponentPhsycs : public Component
{
private:
	std::shared_ptr<ComponentTransform> m_transform;
	std::shared_ptr<ComponentRightBody> m_rightbody;
	std::shared_ptr<ComponentCapsule> m_capsule;
	
	MV1_COLL_RESULT_POLY_DIM m_hitDim{};//����r���茋�ʂƍ\����
	std::shared_ptr<MV1_COLL_RESULT_POLY> m_WallPoly[CollInfo::kMaxColHitPolyNum]{};
	std::shared_ptr<MV1_COLL_RESULT_POLY> m_FloorPoly[CollInfo::kMaxColHitPolyNum]{};
	std::shared_ptr<MV1_COLL_RESULT_POLY> m_poly = nullptr;


	int m_wallNum = 0;
	int m_floorNum = 0;

	bool m_isHitFlag;
	bool m_isMoveflag;

	void CheckWallAndFloor();
	void FixPositionWithWall();
	void FixPositionWithWallIInternal();

public:
	ComponentPhsycs(std::shared_ptr<ComponentTransform> _transform, std::shared_ptr<ComponentRightBody> _rightBody);
	
	void Init() override;
	void Update() override;
	void Draw() override;
	void Final() override;

};

