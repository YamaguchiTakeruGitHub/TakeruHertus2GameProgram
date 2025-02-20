#include "Player.h"
#include "../../GameTag.h"
#include "../../../CSVLib/CsvData_Reading_And_Writing_Equipment.h"

/// <summary>
/// プレイヤーのパラメーター
/// </summary>
namespace PLAYER_PARAMETER
{
	static constexpr float POS_X = 100.0f;//X座標
	static constexpr float POS_Y = 100.0f;//Y座標
	static constexpr float POS_Z = 0.0f;  //Z座標
}

Player::Player()
	: filename	("")//ファイルの名前
	, Data		()	//ファイルのデータ
{
	/*コンポーネントを生成*/
	AddComponent<ComponentTransform>();
	m_transform = GetComponent<ComponentTransform>();

	AddComponent<ComponentRightBody>();
	m_rightbody = GetComponent<ComponentRightBody>();

	AddComponent<ComponentMovement>(m_transform, m_rightbody, TagCharacterObject::PLAYER);
	m_movement = GetComponent<ComponentMovement>();

	AddComponent<ComponentModel>();
	m_model = GetComponent<ComponentModel>();

	AddComponent<ComponentCapsule>(m_transform);
	m_capsule = GetComponent<ComponentCapsule>();

	AddComponent<ComponentAnimation>(m_model);
	m_animation = GetComponent<ComponentAnimation>();

}

Player::~Player()
{
}

void Player::Init()
{
	/*CSVLib初期化*/
	filename = "../Data/GameData/PlayerData.csv";//ファイルのパス
	Data = CSVLib::ReadCSV(filename);			 //ファイルの読み込み

	/*コンポーネントの初期化*/
	Entity::InitComponent();

	/*Transformの初期化*/
	m_transform->position = VGet(PLAYER_PARAMETER::POS_X,	//ポジションの初期位置_X
								 PLAYER_PARAMETER::POS_Y,	//ポジションの初期位置_Y
								 PLAYER_PARAMETER::POS_Z);	//ポジションの初期位置_Z

	m_transform->scale = VGet(CSVLib::GetCell_float(Data, 3, 2),	//モデルのサイズX
							  CSVLib::GetCell_float(Data, 3, 2),	//モデルのサイズY
						      CSVLib::GetCell_float(Data, 3, 2));	//モデルのサイズZ

	/*モデルの初期化*/
	m_model->LoadModel("../ Data/Asset/3D/Player/Player.mv1");

	/*カプセルの初期化*/
	m_capsule->radius = CSVLib::GetCell_float(Data,1, 2);	//カプセルの半径
	m_capsule->height = CSVLib::GetCell_float(Data, 2, 2);	//カプセルのサイズ

}

void Player::Update()
{
	/*アニメーションの更新*/
	UpdateAnimation();

	/*コンポーネントの更新*/
	Entity::UpdateComponent();

	/*着地点の仮設置（マップの移植が完了したら移動）*/
	//if (m_transform->position.y - m_capsule->radius >= 0.0f)
	//{
	//	m_movement->SetIsGround(false);//地面についていない
	//}
	//else
	//{
	//	m_movement->SetIsGround(true);//地面についた
	//}

	/*行動の更新(コンストラクタ呼び出し時にタグを設定できるようにしたい)*/
	m_movement->SetTag(TagCharacterObject::PLAYER);

	/*モデルのアングルと大きさと座標を更新*/
	MV1SetRotationXYZ(m_model->m_modelHandle, VGet(0.0f, m_transform->angle * DX_PI_F / 180.0f, 0.0f));//角度をラジアンに変換してセットする
	MV1SetScale(m_model->m_modelHandle, m_transform->scale);
	MV1SetPosition(m_model->m_modelHandle, m_transform->position);
}

void Player::Draw()
{
	/*コンポーネントの描画*/
	Entity::DrawComponent();
}

void Player::Final()
{
	/*コンポーネントの解放*/
	Entity::FinalComponent();
}

void Player::UpdateAnimation()
{
	/*歩行中であれば*/
	if (m_movement->GetIsMove() == true)
	{
		m_animation->PlayAnim(8);//Moveアニメーション
	}
	else
	{
		m_animation->PlayAnim(4);//Idelアニメーション
	}
}