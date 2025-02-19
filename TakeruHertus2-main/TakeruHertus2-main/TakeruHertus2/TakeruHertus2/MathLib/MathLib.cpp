#include "MathLib.h"
#include <cmath>

float MathLib::Clamp(float _minVal, float _maxVal, float _val)
{
	if (_val < _minVal) return _val = _minVal;
	else if (_val > _maxVal) return _val = _maxVal;
}

VECTOR MathLib::Vector_X_float(VECTOR _vval, float _fval)
{
	VECTOR result;
	result.x = _vval.x * _fval;
	result.y = _vval.y * _fval;
	result.z = _vval.z * _fval;
	return result;
}

bool MathLib::CheckLineIntersection(VECTOR _posStart1, VECTOR _posEnd1, VECTOR _posStart2, VECTOR _posEnd2)
{
	VECTOR p1_Line = VSub(_posStart1, _posEnd1);//1�̐���

	VECTOR p1S_To_p2S_Line = VSub(_posStart1, _posStart2);//1�̊J�n�n�_�ƂQ�̊J�n�n�_�̐���

	VECTOR p1S_To_p2E_Line = VSub(_posStart1, _posEnd2);//�P�̊J�n�n�_�ƂQ�̏I���n�_�̐���

	VECTOR p2_Line = VSub(_posStart2, _posEnd2);//2�̐���
	
	VECTOR p2S_To_p1S_Line = VSub(_posStart2, _posStart1);//2�̊J�n�n�_��1�̊J�n�n�_�̐���

	VECTOR p2S_To_p1E_Line = VSub(_posStart2, _posEnd1);//2�̊J�n�n�_��1�̏I���n�_�̐���

	//==================================================================================

	VECTOR cross1 = VCross(p1_Line, p1S_To_p2S_Line);

	VECTOR cross2 = VCross(p1_Line, p1S_To_p2E_Line);

	VECTOR cross3 = VCross(p2_Line, p2S_To_p1S_Line);

	VECTOR cross4 = VCross(p2_Line, p2S_To_p1E_Line);

	return (VDot(cross1, cross2) < 0) && (VDot(cross3, cross4) < 0);

	//return (VDot(cross1, cross2) < 0.0f) && (VDot(cross3, cross4) < 0.0f);
}
