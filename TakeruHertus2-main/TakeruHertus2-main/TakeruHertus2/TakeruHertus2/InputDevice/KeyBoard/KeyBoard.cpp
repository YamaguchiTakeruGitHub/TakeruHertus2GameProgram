#include "KeyBoard.h"
void KeyBoard::Update()
{
	memcpy(oldKyes, keys, KEY_BOARD::KEY_BUFFER);
	GetHitKeyStateAll(keys);
}

bool KeyBoard::IsPressed(int _key)
{
	if (keys[_key] != 0)
	{
		return true;
	}
	return false;
}

bool KeyBoard::IsTriggered(int _key)
{
	if (keys[_key] != 0 && oldKyes[_key] == 0)
	{
		return true;
	}
	return false;
}