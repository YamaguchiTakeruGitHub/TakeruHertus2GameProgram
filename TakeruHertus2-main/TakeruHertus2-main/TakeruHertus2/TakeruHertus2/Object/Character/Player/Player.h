#pragma once
#include "../../Entity/Entity.h"

/// <summary>
/// プレイヤー
/// </summary>
class Player : public Entity
{
private:
	std::shared_ptr<ComponentTransform> m_transform;
	std::shared_ptr<ComponentRightBody> m_rightbody;
	std::shared_ptr<ComponentMovement> m_movement;
	std::shared_ptr<ComponentModel> m_model;
	std::shared_ptr<ComponentCapsule> m_capsule;
	std::shared_ptr<ComponentAnimation> m_animation;

	/*変数＆関数宣言*/
	std::string filename;//ファイルのパス
	std::vector<std::vector<std::string>> Data;//ファイルのデータ

	/// <summary>
	/// アニメーションの更新
	/// </summary>
	void UpdateAnimation();

public:
	Player();
	~Player();

	void Init();
	void Update();
	void Draw();
	void Final();

	//======================================================================
	// セッターゲッター
	//======================================================================
	//ポジション
	void SetPosition(const VECTOR& _pos) { m_transform->position = _pos; }
	VECTOR GetPosition() const { return m_transform->position; }

	//ヴェロシティ
	void SetVelocity(const VECTOR& _velocity) { m_rightbody->velocity = _velocity; }
	VECTOR GetVelocity() const { return m_rightbody->velocity; }

	//カプセルの高さ
	float GetCapsuleHeight() const { return m_capsule->height; }

	//カプセルの半径
	void SetRadius(const float& _radius) { m_capsule->radius = _radius; }
	float GetRadius() const { return m_capsule->radius; }



	/*Movement系*/
	
	//移動中か
	void SetIsMove(const bool& _isMove) { m_movement->SetIsMove(_isMove); }
	bool GetIsMove() const { return m_movement->GetIsMove(); }

	//ジャンプ中か
	void SetIsJump(const bool& _isJump) { m_movement->SetIsJump(_isJump); }
	bool GetIsJump() const { return m_movement->GetIsJump(); }

	//ジャンプ力
	float GetJumpPower() const { return m_movement->GetJumpPower(); }

	//地面についてるか
	void SetIsGround(const bool& _isGround) { m_movement->SetIsGround(_isGround); }
	bool GetIsGround() const { return m_movement->GetIsGround(); }

	/*カメラの向きを考慮した座標の変換用セット関数*/
	void SetConversionHorizontalAngle(const float _cHAngle) { m_movement->SetConversionCameraHAngle(_cHAngle); }
	void SetConversionCosParam(const float _cCosParam) { m_movement->SetConversionCosParam(_cCosParam); }
	void SetConversionSinParam(const float _cSinParam) { m_movement->SetConversionSinParam(_cSinParam); }
};

