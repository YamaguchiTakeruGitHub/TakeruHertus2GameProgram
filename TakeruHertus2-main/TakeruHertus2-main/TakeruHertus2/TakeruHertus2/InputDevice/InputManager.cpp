#include "InputManager.h"

InputManager::InputManager()
{
	m_joyPad = std::make_shared<JoyPad>();
}

InputManager::~InputManager()
{
}

void InputManager::Init()
{
	m_joyPad->Init();
}

void InputManager::Update()
{
	m_joyPad->Update();
}
