#include "SceneClear.h"

VECTOR SceneClear::ProjectPointOntoLine(VECTOR P, VECTOR A, VECTOR B)
{
	VECTOR AP = VSub(P, A);
	VECTOR AB = VSub(B, A);
	VECTOR AB_normalized = VNorm(AB);

	float projectionLength = VDot(AP, AB_normalized);
	return VAdd(A, m_mathLib->Vector_X_float(AB_normalized, projectionLength));
}


SceneClear::SceneClear()
	: graphHandle(-1)
	, pixelShaderHandle(-1)
	, vertexShaderHandle(-1)
	, vert{0.0f}
	, sp1(VGet(0,0,0))
	, ep1(VGet(0, 0, 0))
	, sp2(VGet(0, 0, 0))
	, ep2(VGet(0, 0, 0))
	, moveDirection(VGet(0,0,0))
	
{
	m_mathLib = std::make_shared<MathLib>();
}

SceneClear::~SceneClear()
{
}

void SceneClear::Init()
{
	m_Idm->Init();

	
	graphHandle = LoadGraph("../Data/Asset/2D/Texture0.bmp");
	vertexShaderHandle = LoadVertexShader("../../VertexShader_1.vso");
	pixelShaderHandle = LoadPixelShader("../../PixelShader_1.pso");
	
	vert[0].pos = VGet(100.0f, 356.0f, 0.0f);
	vert[1].pos = VGet(356.0f, 356.0f, 0.0f);
	vert[2].pos = VGet(100.0f, 100.0f, 0.0f);
	vert[3].pos = VGet(356.0f, 100.0f, 0.0f);

	vert[0].dif = GetColorU8(255, 255, 255, 255);
	vert[1].dif = GetColorU8(255, 255, 255, 255);
	vert[2].dif = GetColorU8(255, 255, 255, 255);
	vert[3].dif = GetColorU8(255, 255, 255, 255);

	vert[0].u = 0.0f; vert[0].v = 0.0f;
	vert[1].u = 1.0f; vert[1].v = 0.0f;
	vert[2].u = 0.0f; vert[3].v = 1.0f;
	vert[3].u = 1.0f; vert[2].v = 1.0f;
	vert[4] = vert[2];
	vert[5] = vert[1];

	sp1 = VGet(500, 100, 0);
	ep1 = VGet(300, 300, 0);

	sp2 = VGet(100, 300, 0);
	ep2 = VGet(300, 100, 0);

	moveDirection = VGet(0, 0, 0);
}

void SceneClear::Update()
{
	m_Idm->Update();

	/*vert[1].pos.x++;
	vert[5].pos.x++;

	vert[3].pos.x++;*/
	
	//HitTest();

	if (CheckHitKey(KEY_INPUT_UP)) sp2.y += 2;
	if (CheckHitKey(KEY_INPUT_DOWN)) sp2.y -= 2;
	if (CheckHitKey(KEY_INPUT_LEFT)) sp2.x -= 2;
	if (CheckHitKey(KEY_INPUT_RIGHT)) sp2.x += 2;

	float ssc = Segment_Point_MinLength(sp1, ep1, sp2);

	DrawSphere3D(sp2, 10.0f, 5, 0xffffff, 0xffffff, true);

	if (ssc <= 0.0f)
	{
		DrawLine3D(sp1, ep1, 0xffffff);
	}
	else
	{
		DrawLine3D(sp1, ep1, 0xff0000);
	}
	
	
	VECTOR closestPoint = ProjectPointOntoLine(sp2, sp1, ep1);
	
	// Å‹ß“_‚ð•`‰æ
	DrawSphere3D(closestPoint, 10.0f, 5, 0x00ff00, 0x00ff00, true);

	VECTOR ppSub = VSub(sp2, closestPoint);
	float ppSubSize = VSize(ppSub);
	float rad = 20.0f;

	if (VSize(closestPoint) <= VSize(sp1) && VSize(closestPoint) >= VSize(sp2) || 
		VSize(closestPoint) <= VSize(sp1) && VSize(closestPoint) <= VSize(sp2))
	{
		if (ppSubSize <= rad)
		{
			VECTOR pushback = VScale(VNorm(ppSub), rad - ppSubSize);
			sp2 = VAdd(sp2, pushback);
		}
	}
}

void SceneClear::Draw()
{
	//SetUseTextureToShader(0, graphHandle);
	//SetUseVertexShader(vertexShaderHandle);
	//SetUsePixelShader(pixelShaderHandle);
	//
	//DrawPolygon3DToShader(vert, 2);

	//SetUseVertexShader(-1);
	//SetUsePixelShader(-1);

#ifdef _DEBUG
	DrawString(0, 0, "ClearScene", 0xffffff);

#endif // _DEBUG

}

void SceneClear::Final()
{
	DeleteShader(vertexShaderHandle);
	DeleteShader(pixelShaderHandle);
}

void SceneClear::HitTest()
{
	moveDirection = VGet(0, 0, 0);

	if (CheckHitKey(KEY_INPUT_UP)) moveDirection.y += 2;
	if (CheckHitKey(KEY_INPUT_DOWN)) moveDirection.y -= 2;
	if (CheckHitKey(KEY_INPUT_LEFT)) moveDirection.x -= 2;
	if (CheckHitKey(KEY_INPUT_RIGHT)) moveDirection.x += 2;

	sp1 = VAdd(sp1, moveDirection);
	//ep1 = VAdd(ep1, moveDirection);


	bool isIntersect = m_mathLib->CheckLineIntersection(sp1, ep1, sp2, ep2);

	DrawLine3D(sp1, ep1, 0xffffff);
	DrawLine3D(sp2, ep2, 0xffffff);


	if (isIntersect)
	{
		VECTOR projectedsp1 = ProjectPointOntoLine(sp1, sp2, ep2);
		VECTOR projectedep1 = ProjectPointOntoLine(ep1, sp2, ep2);

		sp1 = projectedsp1;
		//ep1 = projectedep1;

		DrawLine3D(sp1, ep1, 0xff0000);
		DrawLine3D(sp2, ep2, 0xff0000);
	}
}