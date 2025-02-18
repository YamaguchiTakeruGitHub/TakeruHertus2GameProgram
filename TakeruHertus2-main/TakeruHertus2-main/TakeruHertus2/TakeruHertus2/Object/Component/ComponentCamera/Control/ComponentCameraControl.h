#pragma once
#include "../../Base/Component.h"
#include "../../ComponentTransform/ComponentTransform.h"
#include "../../../../InputDevice/InputManager.h"

/// <summary>
/// カメラのパラメーター
/// </summary>
namespace CAMERACONTROLPARAMETER
{
	static constexpr float ANGLE_SPEED			 = 0.8f;	//旋回速度
	static constexpr float PLAYER_TARGET_HEIGHT  = 100.0f;	//プレイヤーのY座標からどれだけ高い位置を注視点とするか
	static constexpr float PLAYER_DISTANCE		 = 100.0f;  //プレイヤーとの距離
}

/// <summary>
/// 注視点、カメラ速度、注視点からカメラまでの距離を管理
/// </summary>
class ComponentCameraControl : public Component
{
private:
	std::shared_ptr<ComponentTransform> m_transform;//位置などを扱うコンポーネント
	std::shared_ptr<InputManager> m_Idm;			//入力デバイス

	VECTOR m_target;		//カメラの注視点
	float m_sinParam;		//sinパラメータ
	float m_cosParam;		//cosパラメータ
	float m_horizontalAngle;//水平アングル
	float m_verticalAngle;	//垂直アングル

public:
	ComponentCameraControl(std::shared_ptr<ComponentTransform> _transform);

	void Init();
	void Update();
	void Draw();
	void Final();

	/*===============================================================*/
	//セッターとゲッター
	/*===============================================================*/

	//ポジション
	void SetPosition(const VECTOR& _pos) { m_transform->position = _pos; }
	VECTOR GetPositin() const { return m_transform->position; }

	/*注視点のデータ*/
	void SetTarget(const VECTOR& _target) { m_target = _target; }
	VECTOR GetTarget() const { return m_target; }

	/*Sinパラメータのデータ*/
	void SetSinParam(const float& _sinParam) { m_sinParam = _sinParam; }
	float GetSinParam() const { return m_sinParam; }

	/*Cosパラメータのデータ*/
	void SetCosParam(const float& _cosParam) { m_cosParam = _cosParam; }
	float GetCosParam() const { return m_cosParam; }

	/*水平アングルのデータ*/
	void SetHAngle(const float& _hAngle) { m_horizontalAngle = _hAngle; }
	float GetHAngle() const { return m_horizontalAngle; }

	/*垂直アングルのデータ*/
	void SetVAngle(const float& _vAngle) { m_verticalAngle = _vAngle; }
	float GetVAngle() const { return m_verticalAngle; }


};

