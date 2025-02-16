#include "SceneGame.h"
#include "../../Object/GameTag.h"

SceneGame::SceneGame()
	: m_isLoading(false)//ロード中かどうか
{
	m_player = std::make_shared<Player>();//プレイヤー
	m_camera = std::make_shared<Camera>();//カメラ
}

SceneGame::~SceneGame()
{
}

void SceneGame::Init()
{
	m_player->Init();
	m_camera->Init();

	m_isLoading = true;//必ず各クラスの後につける
}

void SceneGame::Update()
{
	if (m_isLoading)
	{
		if (GetASyncLoadNum() == 0)
		{
			m_isLoading = false;
		}
	}
	else
	{
		/*m_player->SetConversionHorizontalAngle(m_camera->GetHAngle());
		m_player->SetConversionCosParam(m_camera->GetCosParam());
		m_player->SetConversionSinParam(m_camera->GetSinParam());*/
		m_player->Update(m_camera->GetHAngle(), m_camera->GetSinParam(), m_camera->GetCosParam());

		m_camera->SetTag(TagCameraObject::CONTROL);
		m_camera->SetTarget(m_player->GetPosition());
		m_camera->Update();
	}
}

void SceneGame::Draw()
{
	if (m_isLoading)
	{
		DrawString(0, 0, "NowLoading...", 0xffffff);

		// ロードの進行状況を計算
		int totalLoadTasks = GetASyncLoadNum(); // 総ロードタスク数を取得する関数（仮定）
		int remainingLoadTasks = GetASyncLoadNum(); // 残りのロードタスク数を取得
		float progress = 1.0f - (static_cast<float>(remainingLoadTasks) / totalLoadTasks);

		// バーの描画
		int barWidth = 200; // バーの幅
		int barHeight = 20; // バーの高さ
		int barX = 100; // バーのX座標
		int barY = 50; // バーのY座標
		DrawBox(barX, barY, barX + static_cast<int>(barWidth * progress), barY + barHeight, 0x00ff00, TRUE); // プログレスバー
		DrawBox(barX, barY, barX + barWidth, barY + barHeight, 0xffffff, false);


		if (GetASyncLoadNum() == 0)
		{
			m_isLoading = false;
		}
	}
	else
	{
		DrawGrid(100, 100);

		m_player->Draw();
		m_camera->Draw();
	}
}

void SceneGame::Final()
{
	m_player->Final();
	m_camera->Final();
}
