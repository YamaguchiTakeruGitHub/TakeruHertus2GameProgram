#include "Application/Application.h"
#include "Scene/Manager/SceneManager.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	//�Q�Ƃł̃C���X�^���X�����s��
	SceneManager& sceneManager = SceneManager::GetInstance();

	//�Q�ƂŐ��������ϐ����A�v���P�[�V�����ɓn��
	Application app(sceneManager);//�����̎��s

	if (!app.Init_App())//�A�v���P�[�V�����̏���
	{
		return -1;
	}

	app.Run_App();//�A�v���P�[�V�����̎��s
	app.close_App();//�A�v���P�[�V�����̉��

	return 0;
}

/*MEMO*/

//2025.2.10 ������邱�Ƃ̓R���t�B�O���쐬���ă{�^���̌���ƃL�����Z���̃g�����X�Ɖ��ʒ����Ƃ�
			//�F�X���
