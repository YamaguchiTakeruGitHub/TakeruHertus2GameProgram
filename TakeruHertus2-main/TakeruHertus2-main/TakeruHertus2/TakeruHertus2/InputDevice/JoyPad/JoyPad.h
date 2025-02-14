#pragma once
#include <DxLib.h>


/// <summary>
/// �p�b�h�̊e�{�^����X���C�_�[
/// </summary>
enum PadButton
{
	//�{�^��
	A = 0,
	B = 1,
	X = 2,
	Y = 3,
	LB = 4,
	RB = 5,
	BACK = 6,
	START = 7,
	STICKBL = 8,
	STICKBR = 9,

	/*�\���L�[*/
	CROSSKEY = 0,
	DUP = 0,			//��
	DRIGHT = 9000,			//�E
	DDOWN = 18000,			//��
	DLEFT = 27000,			//��
	DNONE = true,			//�������ĂȂ�
};


class JoyPad
{
public:
	JoyPad();
	~JoyPad();

	void Init();
	void Update();


	/// <summary>
	/// �W���C�X�e�b�N�E�iX���j�̃Q�b�^�[
	/// </summary>
	/// <returns>pad.Rx</returns>
	float GetRightStickX() const { return pad.Rx / 32767.0f; }

	/// <summary>
	/// �W���C�X�e�b�N�E�iY���j�̃Q�b�^�[
	/// </summary>
	/// <returns>pad.Ry</returns>
	float GetRightStickY() const { return pad.Ry / 32767.0f; }

	/// <summary>
	/// �W���C�X�e�b�N���iX���j�̃Q�b�^�[
	/// </summary>
	/// <returns>pad.X</returns>
	float GetLeftStickX() const { return pad.X / -32767.0f; }

	/// <summary>
	/// �W���C�X�e�b�N���iY���j�̃Q�b�^�[
	/// </summary>
	/// <returns>pad.Y</returns>
	float GetLeftStickY() const { return pad.Y / -32767.0f; }

private:
	DINPUT_JOYSTATE pad;

	int Pad1;
	int count;


public:

	bool isAHold;
	bool isBHold;
	bool isXHold;
	bool isYHold;
	bool isLBHold;
	bool isRBHold;
	bool isBACKHold;
	bool isSTARTHold;
	bool isSTICKBLHold;
	bool isSTICKBRHold;

	bool isDUPHold;
	bool isDRIGHTHold;
	bool isDDOWNHold;
	bool isDLEFTHold;

	/*�ʃN���X�Ŕ��肷��p�̃t���O(start)*/
	bool isA;
	bool isB;
	bool isX;
	bool isY;
	bool isLB;
	bool isRB;
	bool isBACK;
	bool isSTART;
	bool isSTICKBL;
	bool isSTICKBR;

	bool isDUP;
	bool isDRIGHT;
	bool isDDOWN;
	bool isDLEFT;

	/*�ʃN���X�Ŕ��肷��p�̃t���O(end)*/


private:

	/*�������ݏu�Ԃ̍ۂ̃t���O(start)*/
	bool pisA;
	bool pisB;
	bool pisX;
	bool pisY;
	bool pisLB;
	bool pisRB;
	bool pisBACK;
	bool pisSTART;
	bool pisSTICKL;
	bool pisSTICKR;

	bool pisDUP;
	bool pisDRIGHT;
	bool pisDDOWN;
	bool pisDLEFT;
	/*�������ݏu�Ԃ̍ۂ̃t���O(end)*/

};

