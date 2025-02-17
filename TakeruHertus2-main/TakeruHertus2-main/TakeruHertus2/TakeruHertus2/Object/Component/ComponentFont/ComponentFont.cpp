#include "ComponentFont.h"
#include "../../../Object/GameTag.h"

ComponentFont::ComponentFont(std::shared_ptr<ComponentTransform> _transform)
	: m_transform(_transform)
{
}

ComponentFont::~ComponentFont()
{
}

void ComponentFont::LoadFont(const char* _path)
{
	m_fontHandle = LoadFontDataToHandle(_path, 5);
}

void ComponentFont::Init()
{
}

void ComponentFont::Update()
{
}

void ComponentFont::Draw()
{
	if (m_Tag == TagFontObject::TestLetter)
	{
		DrawStringToHandle(m_transform->position.x, m_transform->position.y, m_letter, m_fontHandle, 0xffffff, true);
	}
}

void ComponentFont::Final()
{
	//フォントハンドルに何かしら入っていれば
	if (m_fontHandle != -1)
	{
		DeleteFontToHandle(m_fontHandle);//ハンドルを削除する
	}
}
