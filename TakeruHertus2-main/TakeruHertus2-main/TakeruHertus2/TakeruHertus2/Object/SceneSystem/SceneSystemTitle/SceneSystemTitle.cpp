#include "SceneSystemTitle.h"

SceneSystemTitle::SceneSystemTitle()
{
	for (int i = 0; i < SCENESYSTEMTITLE::OBJECTNUM; i++)
	{
		AddComponent<ComponentTransform>();
		m_transform.push_back(GetComponent<ComponentTransform>());//末尾に要素を追加

		AddComponent<ComponentGraph>(m_transform[i]);//末尾を参照
		m_graph.push_back(GetComponent<ComponentGraph>());//末尾に要素を追加
	}
}

SceneSystemTitle::~SceneSystemTitle()
{

}

void SceneSystemTitle::Init()
{
	Entity::InitComponent();
	
	/*背景*/
	m_transform[0]->position = VGet(0, 0, 0);
	m_graph[0]->LoadGraph("../Data/Asset/2D/SceneTitle/backGround.png");
	
	/*NewGame*/
	m_transform[1]->position = VGet(0, 535, 0);
	m_graph[1]->LoadGraph("../Data/Asset/2D/SceneTitle/NewGame.png");
	
	/*LoadGame*/
	m_transform[2]->position = VGet(0, 590, 0);
	m_graph[2]->LoadGraph("../Data/Asset/2D/SceneTitle/LoadGame.png");

	/*Back*/
	m_transform[3]->position = VGet(0, 650, 0);
	m_graph[3]->LoadGraph("../Data/Asset/2D/SceneTitle/back.png");

	/*ロードのテスト用に負荷をかけています*/
	for (int i = 4; i < SCENESYSTEMTITLE::OBJECTNUM; i++)
	{
		m_transform[i]->position = VGet(i * 10, 0, 0);
		m_graph[i]->LoadGraph("../Data/Asset/2D/SceneTitle/add_0.png");
	}
}

void SceneSystemTitle::Update()
{
	for (int i = 0; i < SCENESYSTEMTITLE::OBJECTNUM; i++)
	{
		m_transform[i]->Update();
		m_graph[i]->Update();
	}
}

void SceneSystemTitle::Draw()
{
	for (int i = 0; i < SCENESYSTEMTITLE::OBJECTNUM; i++)
	{
		m_transform[i]->Draw();
		m_graph[i]->Draw();
	}
}

void SceneSystemTitle::Final()
{
	for (int i = 0; i < SCENESYSTEMTITLE::OBJECTNUM; i++)
	{
		m_transform[i]->Final();
		m_graph[i]->Final();
	}
}
