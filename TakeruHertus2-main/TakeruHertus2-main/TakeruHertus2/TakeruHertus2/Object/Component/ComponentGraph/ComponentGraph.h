#pragma once
#include "../Base/Component.h"
#include "../ComponentTransform/ComponentTransform.h"

class ComponentGraph : public Component
{
private:
	std::shared_ptr<ComponentTransform> m_transform;

public:
	ComponentGraph(std::shared_ptr<ComponentTransform> _transform);

	~ComponentGraph() override;

	void LoadGraph(const char* _filePath);

	int GetGraph() const { return m_graphHandle; }

	void Init() override;
	void Update() override;
	void Draw() override;
	void Final() override;

	int m_graphHandle;
};

