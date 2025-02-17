#pragma once
#include "../Base/Component.h"
#include "../ComponentTransform/ComponentTransform.h"

class ComponentFont : public Component
{
private:
	std::shared_ptr<ComponentTransform> m_transform;
	float m_size;			//�t�H���g�̃T�C�Y
	int m_fontHandle;		//�t�H���g�̃n���h��
	const char* m_Tag;		//�^�O
	const char* m_letter;	//�`�悷�镶

public:
	ComponentFont(std::shared_ptr<ComponentTransform> _transform);
	~ComponentFont();

	void LoadFont(const char* _path);

	void Init() override;
	void Update() override;
	void Draw() override;
	void Final() override;

	//======================================================================
	// �Z�b�^�[�Q�b�^�[
	//======================================================================
	void SetFontSize(const float& _size) { m_size = _size; }
	float GetFontSize() const { return m_size; }

	void SetTag(const char* _tag) { m_Tag = _tag; }
	const char* GetTag() const { return m_Tag; }

	void SetFontLetter(const char* _letter) { m_letter = _letter; }
	const char* GetFontLetter() const { return m_letter; }

};

