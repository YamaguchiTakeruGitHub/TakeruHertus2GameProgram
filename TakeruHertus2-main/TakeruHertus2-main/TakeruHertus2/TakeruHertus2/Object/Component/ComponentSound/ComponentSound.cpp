#include "ComponentSound.h"

ComponentSound::~ComponentSound()
{
	if (m_soundHandle != -1)
	{
		DeleteSoundMem(m_soundHandle);
	}
}

void ComponentSound::LoadSound(const char* _filePath)
{
	m_soundHandle = LoadSoundMem(_filePath);

	if (m_soundHandle == -1)
	{
#ifdef _DEBUG
		DrawString(0, 0, "�T�E���h���ǂݍ��߂܂���ł���", 0xff0000);
#endif // _DEBUG
	}
}

void ComponentSound::Play_Sound(int _playType)
{
	PlaySoundMem(m_soundHandle, _playType, false);
	m_isPlaySound = true;
}

void ComponentSound::Stop_Sound()
{
	StopSoundMem(m_soundHandle);
	m_isPlaySound = false;
}

void ComponentSound::Init()
{
	m_isPlaySound = false;
}

void ComponentSound::Update()
{
}

void ComponentSound::Draw()
{
#ifdef _DEBUG
	if (m_isPlaySound == true) DrawFormatString(0, 0, 0xfffff, "�����Đ���");
	if (m_isPlaySound == false) DrawFormatString(0, 0, 0xfffff, "������~��");

#endif // _DEBUG
}

void ComponentSound::Final()
{
	if (m_soundHandle != -1)
	{
		DeleteSoundMem(m_soundHandle);
	}
}

