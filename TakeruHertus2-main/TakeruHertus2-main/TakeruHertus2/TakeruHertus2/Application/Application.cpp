#include "Application.h"

Application::Application(SceneManager& _sceneManager)
	: m_sceneManager(_sceneManager)
{
}

Application::~Application()
{
	m_sceneManager.Final();//�Ăяo����邲�Ƃɉ��
}

bool Application::Init_App()
{
	SetWindowText("Test");//�E�B���h�E�ɕ\������閼�O

	ChangeWindowMode(true);//�S���:false �E�B���h�E���:true

	SetGraphMode(1280, 740, 16);//�\�������ʂ̑傫���ƃJ���[�o�b�t�@

	SetUseDirect3DVersion(DX_DIRECT3D_11);//Direct3D�̃o�[�W�������Z�b�g����

	/*DxLib�̏�����*/
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	/*�G�ӂ��������̏�����*/
	if (Effekseer_Init(8000) == -1)
	{
		DxLib_End();
		return -1;
	}

	//����ʕ`����Z�b�g
	SetDrawScreen(DX_SCREEN_BACK);

	//�O���t�B�b�N���[�h�ɕύX���邩�ǂ���
	SetChangeScreenModeGraphicsSystemResetFlag(false);

	//�O���t�B�b�N�f�o�C�X���Ȃ��Ȃ�����R�[���o�b�N����
	Effekseer_SetGraphicsDeviceLostCallbackFunctions();

	/*3D������*/
	SetUseZBuffer3D(true);	//Z�o�b�t�@��������
	SetWriteZBuffer3D(true);//Z�o�b�t�@�ɏ������ނ�
	SetUseBackCulling(true);//�RD���f�����ʂ̕`���������

	/*�e������*/
	m_sceneManager.Init();

	return true;
}

void Application::Run_App()
{
	while (ProcessMessage() != -1)
	{
		//�t���[���������i�[
		LONGLONG start = GetNowHiPerformanceCount();
		//��ʂ�|��
		ClearDrawScreen();

		/*�e�X�V*/
		m_sceneManager.Update();
		m_sceneManager.Draw();

		//����ʂƕ\��ʂ̌���
		ScreenFlip();

		//�X�y�[�X�L�[���͂ɂ��Q�[���̋����I��
		if (CheckHitKey(KEY_INPUT_ESCAPE)) break;
		//FPS��60�ŌŒ�
		while (GetNowHiPerformanceCount() - start < 16667) {}
	}
}

void Application::close_App()
{
	/*�e���*/
	m_sceneManager.Final(); //�V�[���}�l�[�W���[�̉��
	Effkseer_End();			//�G�ӂ��������̉��
	DxLib_End();			//DxLib�̉��
}
