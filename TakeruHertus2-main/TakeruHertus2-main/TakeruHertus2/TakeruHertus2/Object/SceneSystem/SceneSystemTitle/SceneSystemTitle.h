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

	int m_selectedCellX;
	int m_selectedCellY;

public:
	SceneSystemTitle();
	~SceneSystemTitle();

	void Init();
	void Update();
	void Draw();
	void Final();

	void DrawGrid(int width, int height, int cellSize);
	void UpdateSelectedCell(int _mouseX, int _mouseY, int _cellSize);
	void DrawSelectedCell(int _cellSize);

};

