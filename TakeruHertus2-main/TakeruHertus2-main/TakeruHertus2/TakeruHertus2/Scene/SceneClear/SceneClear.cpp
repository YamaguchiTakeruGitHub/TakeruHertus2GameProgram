#include "SceneClear.h"

SceneClear::SceneClear()
	: graphHandle(-1)
	, pixelShaderHandle(-1)
	, vertexShaderHandle(-1)
	, vert{0.0f}
	
{
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

	
}

void SceneClear::Update()
{
	m_Idm->Update();

	vert[1].pos.x++;
	vert[5].pos.x++;

	vert[3].pos.x++;



}

void SceneClear::Draw()
{
	SetUseTextureToShader(0, graphHandle);
	SetUseVertexShader(vertexShaderHandle);
	SetUsePixelShader(pixelShaderHandle);
	
	DrawPolygon3DToShader(vert, 2);

	SetUseVertexShader(-1);
	SetUsePixelShader(-1);

#ifdef _DEBUG
	DrawString(0, 0, "ClearScene", 0xffffff);
#endif // _DEBUG

}

void SceneClear::Final()
{
	DeleteShader(vertexShaderHandle);
	DeleteShader(pixelShaderHandle);
}
