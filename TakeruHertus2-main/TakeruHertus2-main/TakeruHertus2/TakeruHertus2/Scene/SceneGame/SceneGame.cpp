#include "SceneGame.h"
#include "../../Object/GameTag.h"

void SceneGame::PlayerControlCamera()
{
	/*カメラの角度を考慮した座標に変換*/
	m_player->SetConversionHorizontalAngle(m_camera->GetHAngle());
	m_player->SetConversionCosParam(m_camera->GetCosParam());
	m_player->SetConversionSinParam(m_camera->GetSinParam());
	m_player->Update();

	m_camera->SetTag(TagCameraObject::CONTROL);
	m_camera->SetTarget(m_player->GetPosition());
	m_camera->Update();
}

SceneGame::SceneGame()
	: m_isLoading(false)//ロード中かどうか
{
	m_player = std::make_shared<Player>();		//プレイヤー
	m_enemyFox = std::make_shared<EnemyFox>();	//狐の敵

	m_camera = std::make_shared<Camera>();//カメラ

	m_tutorialMap = std::make_shared<TutorialMap>();//チュートリアルマップ

	m_font = std::make_shared<Font>();//フォント

	/*テスト用変数*/
	boxPos = VGet(-400.0f, 0.0f, 0.0f);
	boxSize = VGet(60.0f, 60.0f, 60.0f);

}

SceneGame::~SceneGame()
{
}

void SceneGame::Init()
{
	m_player->Init();
	m_enemyFox->Init();
	m_camera->Init();

	m_font->Init();

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
		PlayerControlCamera();//プレイヤーの更新と操作カメラの更新

		m_enemyFox->SetTargetPosition(m_player->GetPosition());
		m_enemyFox->Update();
		m_font->Update();
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
#ifdef _DEBUG
		/*グリッドのデバッグ表示*/
		m_tutorialMap->DrawGrid(1000, 100, 0.0f);
		m_tutorialMap->DrawGrid(1000, 100, 100.0f);
		m_tutorialMap->DrawBox(boxPos, boxSize);


#endif // _DEBUG

		m_player->Draw();
		m_enemyFox->Draw();
		m_camera->Draw();

		m_font->Draw();

		IsTestPhsycse();
	}
}

void SceneGame::Final()
{
	m_player->Final();
	m_enemyFox->Final();
	m_camera->Final();
	m_font->Final();
}

void SceneGame::IsTestPhsycse()
{
	DrawLine3D(m_player->GetPosition(), m_enemyFox->GetPosition(), 0xff0000);
	DrawLine3D(m_player->GetStartPos(), m_player->GetEndPos(), 0xff0000);
	DrawLine3D(m_enemyFox->GetStartPos(), m_enemyFox->GetEndPos(), 0xff0000);

}

