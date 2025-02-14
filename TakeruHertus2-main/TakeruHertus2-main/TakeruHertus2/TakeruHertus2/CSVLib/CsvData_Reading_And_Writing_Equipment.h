#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cassert>//�f�o�b�N�p

/*===========================================*/
// �O���f�[�^�̓ǂݍ��ݏ������݂��y�ɂ��郉�C�u����
// �Q�l���F�[������w��C++
/*===========================================*/
namespace CSVLib
{
	/// <summary>
	/// CSV�t�@�C���Ƀf�[�^����������
	/// </summary>
	/// <param name="_fileName">�t�@�C���̃p�X</param>
	/// <param name="_data">�Q�����z��</param>
	void WriteCSV(const std::string& _fileName, const std::vector<std::vector<std::string>>& _data);

	/// <summary>
	/// CSV�t�@�C����ǂݍ���
	/// </summary>
	/// <param name="_filename">�ǂݍ��ރt�@�C���̖��O</param>
	/// <returns>�f�[�^</returns>
	std::vector<std::vector<std::string>> ReadCSV(const std::string& _fileName);

	/// <summary>
	/// �w�肵���Z�������̂܂܃f�[�^�Ƃ��Ď擾����
	/// </summary>
	/// <param name="_data">2�����z��</param>
	/// <param name="_row">��(�c)</param>
	/// <param name="_col">�s(��)</param>
	/// <returns>�w�肳�ꂽ�Z���̃f�[�^</returns>
	std::string GetCell(const std::vector<std::vector<std::string>>& _data, int _row, int _col);

	/// <summary>
	/// �w�肵���Z���𕶎���(const char*�^)�Ƃ��Ď擾
	/// </summary>
	/// <param name="_data">2�����z��</param>
	/// <param name="_row">��(�c)</param>
	/// <param name="_col">�s(��)</param>
	/// <returns></returns>
	const char* GetCell_ConstChar(const std::vector<std::vector<std::string>>& _data, int _row, int _col);

	/// <summary>
	/// �w�肵���Z���𕶎���(String�^)�Ƃ��Ď擾
	/// </summary>
	/// <param name="_data">2�����z��</param>
	/// <param name="_row">��(�c)</param>
	/// <param name="_col">�s(��)</param>
	/// <returns>�w�肳�ꂽ�Z���̃f�[�^(string)</returns>
	std::string GetCell_String(const std::vector<std::vector<std::string>>& _data, int _row, int _col);

	/// <summary>
	/// �w�肵���Z���𐮐��Ƃ��Ď擾
	/// </summary>
	/// <param name="_data">2�����z��(�c)</param>
	/// <param name="_row">��(�c)</param>
	/// <param name="_col">�s(��)</param>
	/// <returns>�w�肳�ꂽ�Z���̃f�[�^(int)</returns>
	int GetCell_Int(const std::vector<std::vector<std::string>>& _data, int _row, int _col);


	/// <summary>
	/// �w�肵���Z���𕂓������_�Ƃ��Ď擾
	/// </summary>
	/// <param name="_data">2�����z��(�c)</param>
	/// <param name="_row">��(�c)</param>
	/// <param name="_col">�s(��)</param>
	/// <returns>�w�肳�ꂽ�Z���̃f�[�^(float)</returns>
	float GetCell_float(const std::vector<std::vector<std::string>>& _data, int _row, int _col);

	/// <summary>
	///  CSV�f�[�^�̓���̃Z���𐔒l�ɕϊ����čX�V����
	/// </summary>
	/// <param name="_data">2�����z��(�c)</param>
	/// <param name="_row">��(�c)</param>
	/// <param name="_col">�s(��)</param>
	/// <param name="_value">�ϊ����鐔�l</param>
	void UpdateCell_Value_Trans_String(std::vector<std::vector<std::string>>& _data, int _row, int _col, float _value);




	//===========================================================
	// �����[�U�[��`�֐���
	// �ȉ��ɂ͎g�p�҂������₷�����邽�߂ɍ쐬����X�y�[�X�Ƃ���
	//===========================================================
	namespace User_Subscription
	{
		/// <summary>
		/// ID����������Number�ɂ̒l���擾����(���[�U�[��`�̃T���v��)
		/// </summary>
		/// <param name="_data">2�����z��(�c)</param>
		/// <param name="_targetID">�w���ID</param>
		/// <returns></returns>
		std::string GetNumberByID(const std::vector<std::vector<std::string>>& _data, const std::string& _targetID);
	}
}