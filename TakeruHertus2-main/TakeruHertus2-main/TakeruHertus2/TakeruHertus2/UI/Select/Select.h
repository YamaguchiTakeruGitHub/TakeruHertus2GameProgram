#pragma once
class Select
{
public:
	Select();
	~Select();

	void Init();

	/// <summary>
	/// ���ڂ���Ɉړ�
	/// </summary>
	/// <param name="_nowSelect">���݂̑I��</param>
	/// <param name="_enum">���ڂ̐�</param>
	/// <param name="isUpButton">��{�^���̃t���O</param>
	void UpSelect(int& _nowSelect, int _enum, bool isUpButton);

	/// <summary>
	///	���ڂ����Ɉړ�
	/// </summary>
	/// <param name="_nowSelect">���݂̑I��</param>
	/// <param name="_enum">���ڂ̐�</param>
	/// <param name="isDownButton">���{�^���̃t���O</param>
	void DownSelect(int& _nowSelect, int _enum, bool isDownButton);

	/// <summary>
	///	���ڂ����Ɉړ�
	/// </summary>
	/// <param name="_nowSelect">���݂̑I��</param>
	/// <param name="_enum">���ڂ̐�</param>
	/// <param name="isDownButton">���{�^���̃t���O</param>
	void LeftSelect(int& _nowSelect, int _enum, bool isLeftButton);

	/// <summary>
	///	���ڂ��E�Ɉړ�
	/// </summary>
	/// <param name="_nowSelect">���݂̑I��</param>
	/// <param name="_enum">���ڂ̐�</param>
	/// <param name="isDownButton">�E�{�^���̃t���O</param>
	void RightSelect(int& _nowSelect, int _enum, bool isRightButton);



private:

	bool m_isUpButtonPressed;
	bool m_isDownButtonPressed;

	int m_pushNow;
};

