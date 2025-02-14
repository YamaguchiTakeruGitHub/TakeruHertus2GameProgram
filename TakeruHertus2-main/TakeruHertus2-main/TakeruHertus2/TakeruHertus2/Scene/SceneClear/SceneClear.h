#pragma once
#include "../Base/SceneBase.h"

class SceneClear : public SceneBase
{
private:
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
};

