#pragma once
#include "../Base/SceneBase.h"
#include "../../MathLib/MathLib.h"

class SceneClear : public SceneBase
{
private:
	std::shared_ptr<MathLib> m_mathLib;


	int graphHandle;
	int pixelShaderHandle;
	int vertexShaderHandle;
	VERTEX3DSHADER vert[6] = { 0.0f };
	


public:
	SceneClear();
	~SceneClear()override;

	void Init() override;
	void Update() override;
	void Draw() override;
	void Final() override;

private:
	VECTOR sp1, ep1;
	VECTOR sp2, ep2;
	VECTOR moveDirection;

	// 点Pを線分ABに投影した点を求める
	VECTOR ProjectPointOntoLine(VECTOR P, VECTOR A, VECTOR B);

	void HitTest();
	// 三角形の法線ベクトルを求める
	VECTOR CalculateNormal(const VECTOR& p1, const VECTOR& p2, const VECTOR& p3) {
		VECTOR v1 = { p2.x - p1.x, p2.y - p1.y, p2.z - p1.z };
		VECTOR v2 = { p3.x - p1.x, p3.y - p1.y, p3.z - p1.z };
		return VNorm(VCross(v1, v2));
	}




};

