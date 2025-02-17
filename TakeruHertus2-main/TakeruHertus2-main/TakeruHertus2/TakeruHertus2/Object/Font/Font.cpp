#include "Font.h"
#include "../GameTag.h"

Font::Font()
{
	for (int i = 0; i < FONT::FontNum; i++)
	{
		AddComponent<ComponentTransform>();
		m_transform.push_back(GetComponent<ComponentTransform>());

		AddComponent<ComponentFont>(m_transform[i]);
		m_font.push_back(GetComponent<ComponentFont>());
	}
}

Font::~Font()
{
}

void Font::Init()
{
	Entity::InitComponent();

	m_transform[0]->position = VGet(0, 0, 0);
	m_font[0]->SetFontLetter("テストフォント");
	m_font[0]->SetFontSize(60);
	m_font[0]->SetTag("testletter!");
	m_font[0]->LoadFont("../../Data/Asset/font/Kinkakuji-Normal.otf");
}

void Font::Update()
{
	Entity::UpdateComponent();
}

void Font::Draw()
{
	Entity::DrawComponent();
}

void Font::Final()
{
	Entity::FinalComponent();
}
