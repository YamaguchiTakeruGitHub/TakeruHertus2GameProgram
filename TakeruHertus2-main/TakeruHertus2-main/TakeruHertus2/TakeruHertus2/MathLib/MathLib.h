#pragma once
#include <DxLib.h>

class MathLib
{
private:
public:

	/*���w�֐�*/

	//�l�������I��_minVal�`_maxVal�̊Ԃ͈͓̔��ɂ��邱��
	float Clamp(float _minVal, float _maxVal, float _val);
	
	//VECTOR��float�̊|���Z
	VECTOR Vector_X_float(VECTOR _vval, float _fval);


	/*���Ɛ�*/
	bool CheckLineIntersection(VECTOR _posStart1, VECTOR _posEnd1, VECTOR _posStart2, VECTOR _posEnd2);//�����蔻��
	
	
};

