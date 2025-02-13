#pragma once
#include "../../Entity/Entity.h"

namespace SCENESYSTEMTITLE
{
	static constexpr int OBJECTNUM = 10000;//ロード画面の確認をするためにあえて負荷をかける
	//static constexpr int OBJECTNUM =4;
}

class SceneSystemTitle : public Entity
{
private:
	std::vector<std::shared_ptr<ComponentTransform>> m_transform;
	std::vector<std::shared_ptr<ComponentGraph>> m_graph;

public:
	SceneSystemTitle();
	~SceneSystemTitle();

	void Init();
	void Update();
	void Draw();
	void Final();

};

