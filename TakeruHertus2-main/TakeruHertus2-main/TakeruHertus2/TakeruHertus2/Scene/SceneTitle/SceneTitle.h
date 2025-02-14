#pragma once
#include "../Base/SceneBase.h"
#include "../../Object/SceneSystem/SceneSystemTitle/SceneSystemTitle.h"

class SceneTitle : public SceneBase
{
private:
	std::shared_ptr<SceneSystemTitle> m_systemTitle;
	
	/*•Ï”éŒ¾*/
	bool m_isLoading;

public:
	SceneTitle();
	~SceneTitle();

	void Init() override;
	void Update() override;
	void Draw() override;
	void Final() override;
};

