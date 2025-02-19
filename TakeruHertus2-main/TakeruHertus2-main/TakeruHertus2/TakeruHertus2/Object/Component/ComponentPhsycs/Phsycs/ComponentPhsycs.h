#pragma once
#include "../../Base/Component.h"
#include "../../ComponentTransform/ComponentTransform.h"
#include "../../ComponentPhsycs/RightBody/ComponentRightBody.h"
#include "../../ComponentPhsycs/Capsule/ComponentCapsule.h"
#include "../../ComponentPhsycs/Sphere/ComponentSphere.h"
#include "../PhsycsShapeType.h"//形状のタイプ

namespace CollInfo
{
	//最大当たり判定ポリゴン数
	constexpr int kMaxColHitPolyNum = 2000;
	//壁押し出し処理の最大試行回数
	constexpr int kMaxColHitTryNum = 16;
	//壁押し出し時にスライドさせる距離
	constexpr float kColHitSlideLength = 1.0f;

	//最大当たり判定ポリゴン数
	constexpr int kMaxColHitPolyNum = 2000;
	//壁押し出し処理の最大試行回数
	constexpr int kMaxColHitTryNum = 16;
	//壁押し出し時にスライドさせる距離
	constexpr float kColHitSlideLength = 1.0f;
	//移動したかを判断するための変数
	constexpr float kMove = 0.01f;
	//壁ポリゴンか床ポリゴンかを判断するための変数
	constexpr float kWallPolyBorder = 0.4f;
	//壁ポリゴンと判断するための高さ変数
	constexpr float kWallPolyHeight = 5.0f;

	//死んでからの時間
	constexpr int kEnableTimeCount = 10;

	//頭の高さを設定
	constexpr float kHeadHeight = 40.0f;

}

class ComponentPhsycs : public Component
{
private:
	std::shared_ptr<ComponentTransform> m_transform;
	std::shared_ptr<ComponentRightBody> m_rightbody;
	std::shared_ptr<ComponentCapsule> m_capsule;
	
	MV1_COLL_RESULT_POLY_DIM m_hitDim{};//阿多r判定結果と構造体
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

