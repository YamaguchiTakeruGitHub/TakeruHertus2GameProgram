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
	
	VECTOR sp1, ep1;
	VECTOR sp2, ep2;
	VECTOR moveDirection;

	// �_P�����AB�ɓ��e�����_�����߂�
	VECTOR ProjectPointOntoLine(VECTOR P, VECTOR A, VECTOR B);

public:
	SceneClear();
	~SceneClear()override;

	void Init() override;
	void Update() override;
	void Draw() override;
	void Final() override;
};

