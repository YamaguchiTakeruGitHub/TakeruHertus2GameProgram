#pragma once
#include <DxLib.h>

class MathLib
{
private:
public:

	/*”ŠwŠÖ”*/

	//’l‚ğ‹­§“I‚É_minVal`_maxVal‚ÌŠÔ‚Ì”ÍˆÍ“à‚É‚·‚é‚±‚Æ
	float Clamp(float _minVal, float _maxVal, float _val);
	
	//VECTOR‚Æfloat‚ÌŠ|‚¯Z
	VECTOR Vector_X_float(VECTOR _vval, float _fval);


	/*ü‚Æü*/
	bool CheckLineIntersection(VECTOR _posStart1, VECTOR _posEnd1, VECTOR _posStart2, VECTOR _posEnd2);//“–‚½‚è”»’è
	
	
};

