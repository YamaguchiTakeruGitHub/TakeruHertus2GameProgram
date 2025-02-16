#pragma once
#include "../Base/SceneBase.h"
#include "SceneGameCommon.h"

class SceneGame : public SceneBase
{
private:
	std::shared_ptr<Player> m_player;//プレイヤー
	std::shared_ptr<Camera> m_camera;//カメラ

	/*変数宣言*/
	bool m_isLoading;//ロード中かどうか
	bool m_isOpenMenu;//メニューを開いているかどうか

public:
	SceneGame();
	~SceneGame()override;

	void Init() override;
	void Update() override;
	void Draw() override;
	void Final() override;


    void DrawGrid(float areaSize, int numLines)
    {
        VECTOR pos1, pos2;

        SetUseZBufferFlag(TRUE);

        pos1 = VGet(-areaSize / 2.0f, 0.0f, -areaSize / 2.0f);
        pos2 = VGet(-areaSize / 2.0f, 0.0f, areaSize / 2.0f);
        for (int i = 0; i <= numLines; i++) {
            DrawLine3D(pos1, pos2, GetColor(255, 255, 255));
            pos1.x += areaSize / numLines;
            pos2.x += areaSize / numLines;
        }

        pos1 = VGet(-areaSize / 2.0f, 0.0f, -areaSize / 2.0f);
        pos2 = VGet(areaSize / 2.0f, 0.0f, -areaSize / 2.0f);
        for (int i = 0; i < numLines; i++) {
            DrawLine3D(pos1, pos2, GetColor(255, 255, 255));
            pos1.z += areaSize / numLines;
            pos2.z += areaSize / numLines;
        }

        SetUseZBufferFlag(FALSE);
    }

};

