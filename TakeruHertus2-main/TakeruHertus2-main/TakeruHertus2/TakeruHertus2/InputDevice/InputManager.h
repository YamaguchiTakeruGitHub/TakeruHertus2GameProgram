#pragma once
#include "KeyBoard/KeyBoard.h"
#include "JoyPad/JoyPad.h"
#include <memory>

/*���̓f�o�C�X�̃}�l�[�W���[*/
class InputManager
{
public:
	InputManager();
	~InputManager();

	void Init();	//���̓f�o�C�X�̏�����
	void Update();	//���̓f�o�C�X�̍X�V

	std::shared_ptr<KeyBoard> m_keyboard;//�L�[�{�[�h
	std::shared_ptr<JoyPad> m_joyPad;	 //�R���g���[���[
};

