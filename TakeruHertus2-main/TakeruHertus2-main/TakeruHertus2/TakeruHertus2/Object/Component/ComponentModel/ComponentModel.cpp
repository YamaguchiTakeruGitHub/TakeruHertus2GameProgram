#include "ComponentModel.h"

ComponentModel::~ComponentModel()
{
	//���f���n���h���ɉ�����������Ă����
	if (m_modelHandle != -1)
	{
		//���f�������
		MV1DeleteModel(m_modelHandle);
	}
}

void ComponentModel::LoadModel(const char* _filePath)
{
	SetUseASyncLoadFlag(true);//�񓯊��ǂݍ��ݗL��
	//���f���̃��[�h
	m_modelHandle = MV1LoadModel(_filePath);
	SetUseASyncLoadFlag(false);//�ȍ~�񓯊��ǂݍ��ݔ��肵�Ă͂����Ȃ����߉���

	//�������f���ɉ�������Ȃ�������
	if (m_modelHandle == -1)
	{
#ifdef _DEBUG
		DrawFormatString(0, 40, 0xff0000, "���f����ǂݍ��߂܂���ł���");
#endif // _DEBUG
	}

}

void ComponentModel::Init()
{
}

void ComponentModel::Update()
{
}

void ComponentModel::Draw()
{
	//���f���ɉ�����������Ă����
	if (m_modelHandle != -1)
	{
		//���f����`�悷��
		MV1DrawModel(m_modelHandle);
	}
}

void ComponentModel::Final()
{
	//���f���ɉ�����������Ă����
	if (m_modelHandle != -1)
	{
		//���f�����������
		MV1DeleteModel(m_modelHandle);
	}
}
