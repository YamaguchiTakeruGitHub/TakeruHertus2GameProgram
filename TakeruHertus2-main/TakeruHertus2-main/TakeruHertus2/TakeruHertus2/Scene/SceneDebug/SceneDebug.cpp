#include "SceneDebug.h"
#include "../Manager/SceneManager.h"

void SceneDebug::SelectNow()
{
	//���݂̃V�[���ɉ����āA�I���J�[�\����Y���Ɋe�V�[���̑I������Y�����i�[
	switch (m_nowSelect)
	{
	case eSelect_Title:
		m_pos.nowPoint.y = m_pos.Title.y;
		break;
	case eSelect_Game:
		m_pos.nowPoint.y = m_pos.Game.y;
		break;
	case eSelect_GameOver:
		m_pos.nowPoint.y = m_pos.GameOver.y;
		break;
	case eSelect_Clear:
		m_pos.nowPoint.y = m_pos.Clear.y;
		break;
	case eSelect_Load:
		m_pos.nowPoint.y = m_pos.Load.y;
		break;
	case eSelect_DebugTitleUIEdit:
		m_pos.nowPoint.y = m_pos.DebugTitleUIEdit.y;
		break;
	}
}

void SceneDebug::SelectPushEntryScene()
{
	//�I�����̃V�[�������s
	if (m_Idm->m_joyPad->isB == true)
	{
		switch (m_nowSelect)
		{
		case eSelect_Title:
			SceneManager::GetInstance().ChangeScene(SceneType::Title);
			break;
		case eSelect_Game:
			SceneManager::GetInstance().ChangeScene(SceneType::Game);
			break;
		case eSelect_GameOver:
			SceneManager::GetInstance().ChangeScene(SceneType::GameOver);
			break;
		case eSelect_Clear:
			SceneManager::GetInstance().ChangeScene(SceneType::Clear);
			break;
		case eSelect_Load:
			SceneManager::GetInstance().ChangeScene(SceneType::Loading);
			break;
		case eSelect_DebugTitleUIEdit:
			SceneManager::GetInstance().ChangeScene(SceneType::DebugTitleUIEdit);
			break;
		}
	}
}

SceneDebug::SceneDebug()
	: m_nowSelect(0)
	, m_pos()
{
	m_UI = std::make_shared<UIManager>();//�C���X�^���X��

	/*�|�W�V�����̏�����*/
	m_pos.Title = VGet(30,20,0);
	m_pos.Game = VGet(30, 40, 0);
	m_pos.GameOver = VGet(30, 60, 0);
	m_pos.Clear = VGet(30, 80, 0);
	m_pos.Load = VGet(30, 100, 0);
	m_pos.DebugTitleUIEdit = VGet(30, 120, 0);

	m_nowSelect = eSelect_Title;		//���ݑI���̃V�[��
}

SceneDebug::~SceneDebug()
{
	//������郊�\�[�X�͂Ȃ��̂ŋL������
}

void SceneDebug::Init()
{
	m_Idm->Init();						//���̓f�o�C�X�̏�����
	m_UI->Init();						//UI�̏�����

	/*�e�V�[���̍��W�̏�����*/
	m_pos.Title = VGet(30, 20, 0);	
	m_pos.Game = VGet(30, 40, 0);		
	m_pos.GameOver = VGet(30, 60, 0);
	m_pos.Clear = VGet(30, 80, 0);
	m_pos.Load = VGet(30, 100, 0);
	m_pos.DebugTitleUIEdit = VGet(30, 120, 0);


	m_nowSelect = eSelect_Title;		//���݂̑I�������^�C�g���ɐݒ�
}

void SceneDebug::Update()
{
	//���̓f�o�C�X�̂̍X�V
	m_Idm->Update();

	//��I���̍X�V
	m_UI->m_select->UpSelect(m_nowSelect, eSelect_Num, m_Idm->m_joyPad->isDUP == true);

	//���I���̍X�V
	m_UI->m_select->DownSelect(m_nowSelect, eSelect_Num, m_Idm->m_joyPad->isDDOWN == true);

	/*���݂̑I�����Ƃ��̌���*/
	SelectPushEntryScene();
	SelectNow();
}

void SceneDebug::Draw()
{
	/*�b�t�h*/
#ifdef _DEBUG
	DrawString(0, 0, "DebugScene", 0xffffff);
	DrawString(m_pos.Title.x, m_pos.Title.y, "TitleScene", 0xffffff);
	DrawString(m_pos.Game.x, m_pos.Game.y, "GameScene", 0xfffffff);
	DrawString(m_pos.GameOver.x, m_pos.GameOver.y, "GameOverScene", 0xffffff);
	DrawString(m_pos.Clear.x, m_pos.Clear.y, "ClearScene", 0xfffffff);
	DrawString(m_pos.Load.x, m_pos.Load.y, "LoadScene", 0xffffff);
	DrawString(m_pos.DebugTitleUIEdit.x, m_pos.DebugTitleUIEdit.y, "DebugTitleUIEdit", 0xffffff);

	DrawString(m_pos.nowPoint.x, m_pos.nowPoint.y, "��", 0xffffff);

#endif // _DEBUG

}

void SceneDebug::Final()
{
	/*������郊�\�[�X�͂Ȃ��̂ŋL������*/
}
