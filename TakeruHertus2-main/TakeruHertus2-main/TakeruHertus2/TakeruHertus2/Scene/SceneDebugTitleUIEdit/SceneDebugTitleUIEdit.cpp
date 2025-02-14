#include "SceneDebugTitleUIEdit.h"
#include "../../CSVLib/CsvData_Reading_And_Writing_Equipment.h"


SceneDebugTitleUIEdit::SceneDebugTitleUIEdit()
	: m_isMenu(false)
	, m_isAttachGraph()
	, m_resourceNum{-1,-1,-1,-1-1,-1,-1}
	, m_resourcePos()
	, m_resourceGraphPos()
{
	m_systemTitle = std::make_shared<SceneSystemTitle>();
	m_Idm = std::make_shared<InputManager>();
}

SceneDebugTitleUIEdit::~SceneDebugTitleUIEdit()
{
}

void SceneDebugTitleUIEdit::Init()
{
	m_systemTitle->Init();
	m_isMenu = false;

	for (int i = 0; i < TITLEUINUMBER::RESOURCENUM; i++)
	{
		m_isAttachGraph[i] = false;
	}

	m_resourceNum[0] = LoadGraph("../Data/Asset/2D/SceneTitle/add_0.png");
	m_resourceNum[1] = LoadGraph("../Data/Asset/2D/SceneTitle/add_1.png");
	m_resourceNum[2] = LoadGraph("../Data/Asset/2D/SceneTitle/add_2.png");
	m_resourceNum[3] = LoadGraph("../Data/Asset/2D/SceneTitle/add_3.png");
	m_resourceNum[4] = LoadGraph("../Data/Asset/2D/SceneTitle/add_4.png");
	m_resourceNum[5] = LoadGraph("../Data/Asset/2D/SceneTitle/add_5.png");
	m_resourceNum[6] = LoadGraph("../Data/Asset/2D/SceneTitle/add_6.png");

	for (int i = 0; i < TITLEUINUMBER::RESOURCENUM; i++)
	{
		m_resourcePos[i] = VGet(0, 0, 0);
	}

	
	m_resourcePos[0] = VGet(220, 120, 0);
	m_resourcePos[1] = VGet(220, 140, 0);
	m_resourcePos[2] = VGet(220, 160, 0);
	m_resourcePos[3] = VGet(220, 180, 0);
	m_resourcePos[4] = VGet(220, 200, 0);
	m_resourcePos[5] = VGet(220, 220, 0);
	m_resourcePos[6] = VGet(220, 240, 0);

}

void SceneDebugTitleUIEdit::Update()
{
	
	GetMousePoint(&mouseX, &mouseY);
	m_systemTitle->UpdateSelectedCell(mouseX, mouseY, 20);

	if (m_isMenu == true)
	{
		if (mouseX >= m_resourcePos[0].x && mouseX <= m_resourcePos[0].x + 60 &&
			mouseY >= m_resourcePos[0].y && mouseY <= m_resourcePos[0].y + 15)
		{
			DrawString(0, 0, "Hit", 0xff0000);
		}

		/*—£‚µ‚½‚çƒƒjƒ…‚ð•Â‚¶‚é*/
		if (CheckHitKey(KEY_INPUT_SPACE) != 1)
		{
			m_isMenu = false;
		}
	}
	else
	{
		m_systemTitle->Update();

		

		/*if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{
			m_isAttachGraph[0] = true;
		}
		
		if (m_isAttachGraph[0] == false)
		{
			m_resourceGraphPos[0] = VGet(mouseX, mouseY, 0);
			m_resourceCurrentPos[0] = m_resourceGraphPos[0];
		}
		else
		{
			m_resourceGraphPos[0] = VGet(m_resourceCurrentPos[0].x, m_resourceCurrentPos[0].y, 0);

		}*/

		/*‰Ÿ‚µ‚½‚çƒƒjƒ…‚ðŠJ‚­*/
		if (CheckHitKey(KEY_INPUT_SPACE))
		{
			m_isMenu = true;
		}
	}
}

void SceneDebugTitleUIEdit::Draw()
{
	m_systemTitle->DrawGrid(GAMECONSTANT::k_WindowWidth, GAMECONSTANT::k_WindowHeigth, 20);
	m_systemTitle->DrawSelectedCell(20);
	if (m_isMenu == true)
	{
		DrawBox(200, 100, 1000, 500, 0xffffff, true);
		DrawBox(600, 150, 900, 300, 0x00ff00, false);

		DrawMenuString();
		DrawMenuHitDebug();
	}    
	else
	{
		DrawGraph(m_resourceGraphPos[0].x, m_resourceGraphPos[0].y, m_resourceNum[0], true);
	}
}

void SceneDebugTitleUIEdit::Final()
{
	m_systemTitle->Final();
}

void SceneDebugTitleUIEdit::DrawMenuString()
{
	DrawString(m_resourcePos[0].x, m_resourcePos[0].y, "Graph_1", 0x000000);
	DrawString(m_resourcePos[1].x, m_resourcePos[1].y, "Graph_2", 0x000000);
	DrawString(m_resourcePos[2].x, m_resourcePos[2].y, "Graph_3", 0x000000);
	DrawString(m_resourcePos[3].x, m_resourcePos[3].y, "Graph_4", 0x000000);
	DrawString(m_resourcePos[4].x, m_resourcePos[4].y, "Graph_5", 0x000000);
	DrawString(m_resourcePos[5].x, m_resourcePos[5].y, "Graph_6", 0x000000);
	DrawString(m_resourcePos[6].x, m_resourcePos[6].y, "Graph_7", 0x000000);
}

void SceneDebugTitleUIEdit::DrawMenuHitDebug()
{
	DrawBox(m_resourcePos[0].x, m_resourcePos[0].y, m_resourcePos[0].x + 60, m_resourcePos[0].y + 15, 0xff0000, false);
	DrawBox(m_resourcePos[1].x, m_resourcePos[1].y, m_resourcePos[1].x + 60, m_resourcePos[1].y + 15, 0xff0000, false);
	DrawBox(m_resourcePos[2].x, m_resourcePos[2].y, m_resourcePos[2].x + 60, m_resourcePos[2].y + 15, 0xff0000, false);
	DrawBox(m_resourcePos[3].x, m_resourcePos[3].y, m_resourcePos[3].x + 60, m_resourcePos[3].y + 15, 0xff0000, false);
	DrawBox(m_resourcePos[4].x, m_resourcePos[4].y, m_resourcePos[4].x + 60, m_resourcePos[4].y + 15, 0xff0000, false);
	DrawBox(m_resourcePos[5].x, m_resourcePos[5].y, m_resourcePos[5].x + 60, m_resourcePos[5].y + 15, 0xff0000, false);
	DrawBox(m_resourcePos[6].x, m_resourcePos[6].y, m_resourcePos[6].x + 60, m_resourcePos[6].y + 15, 0xff0000, false);
}