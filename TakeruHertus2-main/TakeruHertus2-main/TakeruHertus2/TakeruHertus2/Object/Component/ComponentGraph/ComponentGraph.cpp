#include "ComponentGraph.h"

ComponentGraph::ComponentGraph(std::shared_ptr<ComponentTransform> _transform)
	: m_transform(_transform)
{
}

ComponentGraph::~ComponentGraph()
{
	if (m_graphHandle != -1)
	{
		DeleteGraph(m_graphHandle);
	}
}

void ComponentGraph::LoadGraph(const char* _filePath)
{
	SetUseASyncLoadFlag(true);//�񓯊��ǂݍ���
	m_graphHandle = DxLib::LoadGraph(_filePath);
	SetUseASyncLoadFlag(false);//����

	if (m_graphHandle != -1)
	{
#ifdef _DEBUG
		DrawString(0, 0, "�O���t��ǂݍ��߂܂���ł����B", 0xffffff);
#endif // _DEBUG
	}
}

void ComponentGraph::Init()
{
}

void ComponentGraph::Update()
{
}

void ComponentGraph::Draw()
{
	if (m_graphHandle != -1)
	{
		DrawGraph(m_transform->position.x, m_transform->position.y, m_graphHandle, true);
	}
	else
	{
		DrawString(0, 0, "�O���t���ǂݍ��߂��`�掸�s�B", 0xffffff);
	}
}

void ComponentGraph::Final()
{
	DeleteGraph(m_graphHandle);
}
