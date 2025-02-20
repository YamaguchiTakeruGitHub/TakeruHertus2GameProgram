#pragma once
#include "../Entity/Entity.h"

namespace FONT
{
	static constexpr int FontNum = 1;
}

class Font : public Entity
{
private:
	std::vector<std::shared_ptr<ComponentFont>> m_font;
	std::vector<std::shared_ptr<ComponentTransform>> m_transform;

public:
	Font();
	~Font();

	void Init();
	void Update();
	void Draw();
	void Final();


};

