#pragma once
#include <DxLib.h>

class MathLib
{
private:
public:

	/*数学関数*/

	//値を強制的に_minVal〜_maxValの間の範囲内にすること
	float Clamp(float _minVal, float _maxVal, float _val);
	
	//VECTORとfloatの掛け算
	VECTOR Vector_X_float(VECTOR _vval, float _fval);

	/*線と線*/
	bool CheckLineIntersection(VECTOR _posStart1, VECTOR _posEnd1, VECTOR _posStart2, VECTOR _posEnd2);//当たり判定
	
};

