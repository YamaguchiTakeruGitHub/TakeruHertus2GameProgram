#include "JoyPad.h"


JoyPad::JoyPad()
	: pad()
	, Pad1(GetJoypadInputState(DX_INPUT_PAD1))
	, count(0)
	, isA(false)
	, isB(false)
	, isX(false)
	, isY(false)
	, isLB(false)
	, isRB(false)
	, isBACK(false)
	, isSTART(false)
	, isSTICKBL(false)
	, isSTICKBR(false)
	, isDUP(false)
	, isDRIGHT(false)
	, isDDOWN(false)
	, isDLEFT(false)

	, isAHold(false)
	, isBHold(false)
	, isXHold(false)
	, isYHold(false)
	, isLBHold(false)
	, isRBHold(false)
	, isBACKHold(false)
	, isSTARTHold(false)
	, isSTICKBLHold(false)
	, isSTICKBRHold(false)

	, isDUPHold(false)
	, isDRIGHTHold(false)
	, isDDOWNHold(false)
	, isDLEFTHold(false)

	, pisA(false)
	, pisB(false)
	, pisX(false)
	, pisY(false)
	, pisLB(false)
	, pisRB(false)
	, pisBACK(false)
	, pisSTART(false)
	, pisSTICKL(false)
	, pisSTICKR(false)

	, pisDUP(false)
	, pisDRIGHT(false)
	, pisDDOWN(false)
	, pisDLEFT(false)
{
}

JoyPad::~JoyPad()
{
}

void JoyPad::Init()
{


	Pad1 = GetJoypadInputState(DX_INPUT_PAD1);
	count = 0;

	isA = false;
	isB = false;
	isX = false;
	isY = false;
	isLB = false;
	isRB = false;
	isBACK = false;
	isSTART = false;
	isSTICKBL = false;
	isSTICKBR = false;

	isDUP = false;
	isDRIGHT = false;
	isDDOWN = false;
	isDLEFT = false;

	isAHold = false;
	isBHold = false;
	isXHold = false;
	isYHold = false;
	isLBHold = false;
	isRBHold = false;
	isBACKHold = false;
	isSTARTHold = false;
	isSTICKBLHold = false;
	isSTICKBRHold = false;

	isDUPHold = false;
	isDRIGHTHold = false;
	isDDOWNHold = false;
	isDLEFTHold = false;

	pisA = false;
	pisB = false;
	pisX = false;
	pisY = false;
	pisLB = false;
	pisRB = false;
	pisBACK = false;
	pisSTART = false;
	pisSTICKL = false;
	pisSTICKR = false;

	pisDUP = false;
	pisDRIGHT = false;
	pisDDOWN = false;
	pisDLEFT = false;

}

void JoyPad::Update()
{
	GetJoypadDirectInputState(DX_INPUT_PAD1, &pad);

	isA = false;
	isB = false;
	isX = false;
	isY = false;
	isLB = false;
	isRB = false;
	isBACK = false;
	isSTART = false;
	isSTICKBL = false;
	isSTICKBR = false;

	isDUP = false;
	isDRIGHT = false;
	isDDOWN = false;
	isDLEFT = false;

	isAHold = false;
	isBHold = false;
	isXHold = false;
	isYHold = false;
	isLBHold = false;
	isRBHold = false;
	isBACKHold = false;
	isSTARTHold = false;
	isSTICKBLHold = false;
	isSTICKBRHold = false;

	isDUPHold = false;
	isDRIGHTHold = false;
	isDDOWNHold = false;
	isDLEFTHold = false;

	/*�z�[���h�{�^���istart�j*/

	//A�{�^��
	if (pad.Buttons[PadButton::A])
	{

		isAHold = true;//�ʃN���X�Ŕ��肷��p�̃t���O

	}
	//B�{�^��
	if (pad.Buttons[PadButton::B])
	{
		isBHold = true;//�ʃN���X�Ŕ��肷��p�̃t���O
	}

	//Y�{�^��
	if (pad.Buttons[PadButton::Y])
	{
		isYHold = true;//�ʃN���X�Ŕ��肷��p�̃t���O
	}
	//X�{�^��
	if (pad.Buttons[PadButton::X])
	{

		isXHold = true;//�ʃN���X�Ŕ��肷��p�̃t���O
	}
	//LB�{�^��
	if (pad.Buttons[PadButton::LB])
	{

		isLBHold = true;//�ʃN���X�Ŕ��肷��p�̃t���O
	}
	//RB�{�^��
	if (pad.Buttons[PadButton::RB])
	{
		isRBHold = true;//�ʃN���X�Ŕ��肷��p�̃t���O
	}
	/*�z�[���h�{�^���istart�j*/



	//A�{�^��
	if (pad.Buttons[PadButton::A] && !pisA)
	{
		pisA = true;
		isA = true;//�ʃN���X�Ŕ��肷��p�̃t���O

	}
	//B�{�^��
	if (pad.Buttons[PadButton::B])
	{
		pisB = true;
		isB = true;//�ʃN���X�Ŕ��肷��p�̃t���O
	}



	//Y�{�^��
	if (pad.Buttons[PadButton::Y])
	{
		pisY = true;
		isY = true;//�ʃN���X�Ŕ��肷��p�̃t���O
	}
	//X�{�^��
	if (pad.Buttons[PadButton::X])
	{
		pisX = true;
		isX = true;//�ʃN���X�Ŕ��肷��p�̃t���O
	}
	//LB�{�^��
	if (pad.Buttons[PadButton::LB])
	{
		pisLB = true;
		isLB = true;//�ʃN���X�Ŕ��肷��p�̃t���O
	}
	//RB�{�^��
	if (pad.Buttons[PadButton::RB])
	{
		pisRB = true;
		isRB = true;//�ʃN���X�Ŕ��肷��p�̃t���O
	}
	//BACK�{�^��
	if (pad.Buttons[PadButton::BACK])
	{
		pisBACK = true;
		isBACK = true;//�ʃN���X�Ŕ��肷��p�̃t���O
	}
	//START�{�^��
	if (pad.Buttons[PadButton::START])
	{
		pisSTART = true;
		isSTART = true;//�ʃN���X�Ŕ��肷��p�̃t���O
	}
	//STICKL�{�^��
	if (pad.Buttons[PadButton::STICKBL])
	{
		pisSTICKL = true;
		isSTICKBL = true;//�ʃN���X�Ŕ��肷��p�̃t���O
	}
	//STICKR�{�^��
	if (pad.Buttons[PadButton::STICKBR])
	{
		pisSTICKR = true;
		isSTICKBR = true;//�ʃN���X�Ŕ��肷��p�̃t���O
	}

	//����̃{�^����������Ă��Ȃ����̓t���O�����낷
	if (!pad.Buttons[PadButton::A]
		&& !pad.Buttons[PadButton::B]
		&& !pad.Buttons[PadButton::Y]
		&& !pad.Buttons[PadButton::X]
		&& !pad.Buttons[PadButton::LB]
		&& !pad.Buttons[PadButton::RB]
		&& !pad.Buttons[PadButton::BACK]
		&& !pad.Buttons[PadButton::START]
		&& !pad.Buttons[PadButton::STICKBL]
		&& !pad.Buttons[PadButton::STICKBR])
	{
		pisA = false;
		pisA = false;
		pisB = false;
		pisX = false;
		pisY = false;
		pisLB = false;
		pisRB = false;
		pisBACK = false;
		pisSTART = false;
		pisSTICKL = false;
		pisSTICKR = false;

		pisDUP = false;
		pisDRIGHT = false;
		pisDDOWN = false;
		pisDLEFT = false;
	}
	/*�{�^���iend�j*/

	/*�\���L�[�istart�j*/
	switch (pad.POV[PadButton::CROSSKEY])
	{
	case PadButton::DUP://��
		count++;
		isDUP = true;//�ʃN���X�Ŕ��肷��p�̃t���O
		break;

	case PadButton::DRIGHT://�E
		count = 0;
		isDRIGHT = true;//�ʃN���X�Ŕ��肷��p�̃t���O
		break;

	case PadButton::DDOWN://��
		count--;
		isDDOWN = true;//�ʃN���X�Ŕ��肷��p�̃t���O
		break;

	case PadButton::DLEFT://��
		count = 1000;
		isDLEFT = true;//�ʃN���X�Ŕ��肷��p�̃t���O
		break;

	default:
		break;
	}
	/*�\���L�[�iend�j*/
}