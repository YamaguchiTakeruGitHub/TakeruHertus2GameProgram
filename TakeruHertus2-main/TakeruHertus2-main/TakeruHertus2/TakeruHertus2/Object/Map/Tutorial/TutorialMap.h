#pragma once
#include "../../Entity/Entity.h"

class TutorialMap : public Entity
{
private:

public:
	TutorialMap();
	~TutorialMap();

	void Init();
	void Update();
	void Draw();
	void Final();

	void DrawGrid(float areaSize, int numLines, float lineHeight);
   
	void DrawBox(VECTOR _boxPos, VECTOR _boxSize);
};

