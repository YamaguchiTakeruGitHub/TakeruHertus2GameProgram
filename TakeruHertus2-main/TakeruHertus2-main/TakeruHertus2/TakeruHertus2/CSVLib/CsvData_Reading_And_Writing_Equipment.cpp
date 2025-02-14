#include "CsvData_Reading_And_Writing_Equipment.h"

#include "CsvData_Reading_And_Writing_Equipment.h"

void CSVLib::WriteCSV(const std::string& _fileName, const std::vector<std::vector<std::string>>& _data)
{
	std::ofstream file(_fileName);

	//�����t�@�C����������Ȃ��ꍇ
	if (!file) throw std::runtime_error("CSV�t�@�C�����J���܂���ł����Bfilename:" + _fileName);

	//2�����z��̃f�[�^��CSV�`���ŏ�������
	for (const auto& row : _data)
	{
		for (size_t i = 0; i < row.size(); i++)
		{
			file << row[i];//�Z���̃f�[�^�̏�������
			if (i < row.size() - 1) file << ",";//�Z���̋�؂�
		}
		file << "\n";//�s(��)�̏I���
	}

	file.close();//�t�@�C�������
	std::cout << "CSV�t�@�C���ɏ������݂܂���:" << _fileName << std::endl;
}

std::vector<std::vector<std::string>> CSVLib::ReadCSV(const std::string& _fileName)
{
	std::ifstream file(_fileName);

	//�����t�@�C����������Ȃ��ꍇ
	if (!file) throw std::runtime_error("CSV�t�@�C�����J���܂���ł����Bfilename:" + _fileName);

	std::vector<std::vector<std::string>> data;
	std::string line;

	//�P�s(��)���ǂݍ���
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::vector<std::string> row;
		std::string cell;

		//�J���}��؂�Ńf�[�^�𕪊����Ĕz��Ɋi�[
		while (std::getline(ss, cell, ','))
		{
			row.push_back(cell);
		}

		//1�s(��)���̃f�[�^��ǉ�
		data.push_back(row);
	}

	file.close();//�t�@�C�������
	return data;//2�����z��(�c)��Ԃ�
}

std::string CSVLib::GetCell(const std::vector<std::vector<std::string>>& _data, int _row, int _col)
{
	//�s(��)�Ɨ�(�c)���͈͓��ł��邱�Ƃ��m�F
	assert(_row >= 0 && _row < _data.size() && "�s(��)�͈̔͂������ł��I");
	assert(_col >= 0 && _col < _data[_row].size() && "��(�c)�͈̔͂������ł��I");
	return _data[_row][_col];//�w�肵���Z���̃f�[�^��Ԃ�
}

const char* CSVLib::GetCell_ConstChar(const std::vector<std::vector<std::string>>& _data, int _row, int _col)
{
	if (_row < 0 || _row >= static_cast<int>(_data.size())) throw std::out_of_range("�s(��)�͈̔͂������ł�:" + std::to_string(_row));

	if (_col < 0 || _col >= static_cast<int>(_data[_row].size())) throw std::out_of_range("��(�c)�͈̔͂������ł�:" + std::to_string(_col));

	return _data[_row][_col].c_str();
}

std::string CSVLib::GetCell_String(const std::vector<std::vector<std::string>>& _data, int _row, int _col)
{
	if (_row < 0 || _row >= static_cast<int>(_data.size())) throw std::out_of_range("�s(��)�͈̔͂������ł�:" + std::to_string(_row));

	if (_col < 0 || _col >= static_cast<int>(_data[_row].size())) throw std::out_of_range("��(�c)�͈̔͂������ł�:" + std::to_string(_col));

	return _data[_row][_col];
}

int CSVLib::GetCell_Int(const std::vector<std::vector<std::string>>& _data, int _row, int _col)
{
	std::string value = GetCell_String(_data, _row, _col);

	try
	{
		return std::stoi(value);//������(�c)�𐮐��ɕϊ�
	}
	catch (const std::exception& e)
	{
		throw std::runtime_error("���l�ϊ��G���[(int):" + value);
	}

}

float CSVLib::GetCell_float(const std::vector<std::vector<std::string>>& _data, int _row, int _col)
{
	std::string value = GetCell_String(_data, _row, _col);

	try
	{
		return std::stof(value);//������(�c)�𕂓������_�ɕϊ�
	}
	catch (const std::exception& e)
	{
		throw std::runtime_error("���l�ϊ��G���[(float):" + value);
	}

}

void CSVLib::UpdateCell_Value_Trans_String(std::vector<std::vector<std::string>>& _data, int _row, int _col, float _value)
{
	if (_row < 0 || _row >= static_cast<int>(_data.size())) throw std::out_of_range("�s(��)�͈̔͂������ł�:" + std::to_string(_row));
	if (_col < 0 || _col >= static_cast<int>(_data[_row].size())) throw std::out_of_range("��(�c)�͈̔͂������ł�:" + std::to_string(_col));

	_data[_row][_col] = std::to_string(_value);//���l�𕶎���t�ɂւ񂩂񂵂đ��
}

std::string CSVLib::User_Subscription::GetNumberByID(const std::vector<std::vector<std::string>>& _data, const std::string& _targetID)
{
	int idColumn = 0;		//ID�̗�(�c)�̈ʒu�i0�s(��)�ځj
	int numberColumn = 4;	//Number�̗�(�c)�̈ʒu(4�s(��)��)���[�U�[�̐ݒ�

	//�P�s(��)�ڂ��΂��Č���
	for (size_t i = 1; i < _data.size(); i++)
	{
		//�w�肵��ID�ƈ�v����s(��)����������
		if (_data[i][idColumn] == _targetID)
		{
			//Number�̒l��Ԃ�
			return _data[i][numberColumn];
		}
	}

	//��v����ID���Ȃ��ꍇ
	return "ID��������܂���B";
}
