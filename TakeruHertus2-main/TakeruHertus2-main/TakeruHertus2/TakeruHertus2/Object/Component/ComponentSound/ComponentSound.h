#pragma once
#include "../Base/Component.h"

class ComponentSound : public Component
{
private:
	int m_soundHandle;//�T�E���h�̃n���h��

	bool m_isPlaySound;

public:
	/// <summary>
	/// �Ăяo�����ɃT�E���h�̉�����s��
	/// </summary>
	~ComponentSound() override;

	/// <summary>
	/// �T�E���h�̃��[�h���s��
	/// </summary>
	/// <param name="_filePath">�T�E���h�̃p�X</param>
	void LoadSound(const char* _filePath);

	/// <summary>
	/// �T�E���h�𑼃N���X�Ŏ擾����
	/// </summary>
	/// <returns>�T�E���h�n���h��</returns>
	int GetSound() const { return m_soundHandle; }

	void Play_Sound(int _playType);
	void Stop_Sound();
	
	void Init() override;
	void Update() override;
	void Draw() override;
	void Final() override;



};

