#pragma once
#include "../Base/SceneBase.h"
#include "../../InputDevice/InputManager.h"
#include "../../UI/UIManager.h"

/// <summary>
/// �f�o�b�N�V�[��
/// </summary>
class SceneDebug : public SceneBase
{
private:

	std::shared_ptr<UIManager> m_UI;//UI�̃V�X�e��������
	
	/*�I���̃|�W�V����*/
	struct Position
	{
		VECTOR Title;
		VECTOR Game;
		VECTOR GameOver;
		VECTOR Clear;
		VECTOR Load;
		VECTOR nowPoint;
	}m_pos;

	/*�I�����̗񋓌^*/
	typedef enum
	{
		eSelect_Title,		//�^�C�g���V�[��	
		eSelect_Game,		//�Q�[���V�[��
		eSelect_GameOver,	//�Q�[���I�[�o�[�V�[��
		eSelect_Clear,		//�N���A�V�[��
		eSelect_Load,		//���[�h�V�[��

		eSelect_Num,		//�I�����̐�����
	}eSelect;

	int m_nowSelect;//���ݑI�����Ă��鍀�ڂ̊i�[

	/// <summary>
	/// ���݂̑I��
	/// </summary>
	void SelectNow();

	/// <summary>
	/// �I���������ڂ̎��s
	/// </summary>
	void SelectPushEntryScene();


public:
	SceneDebug();
	~SceneDebug()override;

	void Init() override;
	void Update() override;
	void Draw() override;
	void Final() override;

};

