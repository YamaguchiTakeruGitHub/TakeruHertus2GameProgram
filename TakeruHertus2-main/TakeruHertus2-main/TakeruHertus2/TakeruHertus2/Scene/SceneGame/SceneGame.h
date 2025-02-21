#pragma once
#include "../Base/SceneBase.h"
#include "SceneGameCommon.h"

/*仮なのであとで移行します*/
namespace ColInfo
{
	//最大当たり判定ポリゴン数
	constexpr int kMaxColHitPolyNum = 2000;
	//壁押し出し処理の最大試行回数
	constexpr int kMaxColHitTryNum = 16;
	//壁押し出し時にスライドさせる距離
	constexpr float kColHitSlideLength = 1.0f;
}


class SceneGame : public SceneBase
{
private:
    /*キャラクター*/
	std::shared_ptr<Player> m_player;       //プレイヤー
    std::shared_ptr<EnemyFox> m_enemyFox;   //狐の敵
    /*カメラ*/
	std::shared_ptr<Camera> m_camera;       //カメラ
	/*マップ*/
	std::shared_ptr<TutorialMap> m_tutorialMap;//チュートリアルマップ
	/*フォント*/
	std::shared_ptr<Font> m_font;//フォント

	/*変数宣言*/
	bool m_isLoading;//ロード中かどうか
	bool m_isOpenMenu;//メニューを開いているかどうか

	void PlayerControlCamera();

	/*テスト用変数*/
	VECTOR boxPos;
	VECTOR boxSize;

public:
	SceneGame();
	~SceneGame()override;

	void Init() override;
	void Update() override;
	void Draw() override;
	void Final() override;

	void IsTestPhsycse();

private:

	/*仮ライト*/
	int lightHandle;

	/*当たり判定のテスト*/
	MV1_COLL_RESULT_POLY_DIM m_hitDim{ };
	MV1_COLL_RESULT_POLY* m_wallPoly[2000]{};
	MV1_COLL_RESULT_POLY* m_floorPoly[2000]{};
	MV1_COLL_RESULT_POLY* m_poly = nullptr;
	HITRESULT_LINE m_lineRes{};

	int m_wallNum = 0;
	int m_floorNum = 0;

	void CHeckWallAndFloor(VECTOR _pos2, float _h);
	void FixPositionWithWall(VECTOR _pos1, VECTOR _pos2);

	void FixPositionWigthWallInternal(VECTOR _pos1, VECTOR _pos2);
	void FixNowPositionWithFloor(VECTOR _pos1, VECTOR _pos2);

	// 三角形の中心を求める
	VECTOR CalculateCenter(const VECTOR& p1, const VECTOR& p2, const VECTOR& p3) {
		return {
			(p1.x + p2.x + p3.x) / 3.0f,
			(p1.y + p2.y + p3.y) / 3.0f,
			(p1.z + p2.z + p3.z) / 3.0f
		};
	}

	// 三角形の法線ベクトルを求める
	VECTOR CalculateNormal(const VECTOR& p1, const VECTOR& p2, const VECTOR& p3) {
		VECTOR v1 = { p2.x - p1.x, p2.y - p1.y, p2.z - p1.z };
		VECTOR v2 = { p3.x - p1.x, p3.y - p1.y, p3.z - p1.z };
		return VNorm(VCross(v1, v2));
	}

	// 点と平面の距離を求める
	float PointPlaneDistance(const VECTOR& point, const VECTOR& normal, float d) {
		return normal.x * point.x + normal.y * point.y + normal.z * point.z + d;
	}

	// 点を三角形の内側に投影（バリセントリック座標）
	bool IsPointInTriangle(const VECTOR& p, const VECTOR& a, const VECTOR& b, const VECTOR& c) {
		VECTOR v0 = { b.x - a.x, b.y - a.y, b.z - a.z };
		VECTOR v1 = { c.x - a.x, c.y - a.y, c.z - a.z };
		VECTOR v2 = { p.x - a.x, p.y - a.y, p.z - a.z };

		float dot00 = VDot(v0, v0);
		float dot01 = VDot(v0, v1);
		float dot02 = VDot(v0, v2);
		float dot11 = VDot(v1, v1);
		float dot12 = VDot(v1, v2);

		float invDenom = 1.0f / (dot00 * dot11 - dot01 * dot01);
		float u = (dot11 * dot02 - dot01 * dot12) * invDenom;
		float v = (dot00 * dot12 - dot01 * dot02) * invDenom;

		return (u >= 0) && (v >= 0) && (u + v <= 1);
	}

	// カプセルと三角形の衝突チェック
	bool CheckCapsuleTriangleCollision(const VECTOR pos, float height, float radius,
		const VECTOR p1, const VECTOR p2, const VECTOR p3, const VECTOR normal) 
	{
		/*法線ベクトルからposまでの距離*/
		float d = -(normal.x * p1.x + normal.y * p1.y + normal.z * p1.z);

	
		// カプセルの線（中心軸）の最近接点
		VECTOR top = { pos.x , pos.y + height, pos.z };//頭
		VECTOR bottom = { pos.x, pos.y, pos.z };		//底

		// カプセル軸を平面に投影
		float distTop = PointPlaneDistance(top, normal, d);
		float distBottom = PointPlaneDistance(bottom, normal, d);

		float distSpc = 30.0f;

		// カプセルの半径内にあるか判定
		if (distTop > radius + distSpc && distBottom > radius + distSpc) return false;

		// 三角形の内側に最近接点があるか
		VECTOR closestPoint = {
			pos.x - normal.x * distBottom,
			pos.y - normal.y * distBottom,
			pos.z - normal.z * distBottom 
		};

		return IsPointInTriangle(closestPoint, p1, p2, p3);
	}

	// 押し戻しベクトルを計算する関数
	VECTOR GetPushbackVector(const VECTOR pos, float height, float radius,
		const VECTOR p1, const VECTOR p2, const VECTOR p3,
		const VECTOR normal) {
		float d = -(normal.x * p1.x + normal.y * p1.y + normal.z * p1.z);
		VECTOR bottom = { pos.x, pos.y, pos.z };
		float distBottom = PointPlaneDistance(bottom, normal, d);

		if (distBottom < radius) {
			float pushbackDist = radius - distBottom;
			return { normal.x * pushbackDist, normal.y * pushbackDist, normal.z * pushbackDist };
		}
		return { 0.0f, 0.0f, 0.0f };
	}
};

