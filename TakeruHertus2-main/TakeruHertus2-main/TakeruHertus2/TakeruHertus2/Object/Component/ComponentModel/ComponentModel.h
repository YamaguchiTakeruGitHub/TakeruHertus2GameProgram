#pragma once
#include "../Base/Component.h"

/// <summary>
/// 3D���f���������R���|�[�l���g
/// </summary>
class ComponentModel : public Component
{
private:

public:
	/// <summary>
	/// �Ăяo�����Ƀ��f���̉�����s��
	/// </summary>
	~ComponentModel() override;

	/// <summary>
	/// ���f���̃��[�h���s��
	/// </summary>
	/// <param name="_filePath">3D���f���̃p�X</param>
	void LoadModel(const char* _filePath);

	/// <summary>
	/// ���f���𑼃N���X�Ŏ擾����
	/// </summary>
	/// <returns>���f���n���h��</returns>
	int GetModel() const { return m_modelHandle; }

	void Init() override;
	void Update() override;
	void Draw() override;
	void Final() override;

	int m_modelHandle;//���f���̃n���h��

};

