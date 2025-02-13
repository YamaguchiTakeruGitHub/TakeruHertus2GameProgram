#include "SceneManager.h"
#include "../SceneTitle/SceneTitle.h"
#include "../SceneGame/SceneGame.h"
#include "../SceneGameOver/SceneGameOver.h"
#include "../SceneClear/SceneClear.h"
#include "../SceneLoad/SceneLoad.h"
#include "../SceneDebug/SceneDebug.h"

SceneManager::SceneManager()
{
	/*シーンのインスタンス化*/
	m_titleScene = std::make_shared<SceneTitle>();
	m_gameScene = std::make_shared<SceneGame>();
	m_gameOverScene = std::make_shared<SceneGameOver>();
	m_clearScene = std::make_shared<SceneClear>();
	m_loadScene = std::make_shared<SceneLoad>();
	m_debugScene = std::make_shared<SceneDebug>();

	/*最初に実行するシーンを現在のシーンに格納*/
#ifdef _DEBUG
	m_currentScene = m_debugScene;
#else
	m_currentScene = m_titleScene;
#endif // _DEBUG
}

SceneManager::~SceneManager()
{
	m_currentScene->Final();
}

void SceneManager::ChangeScene(SceneType _newScene)
{
	/*現在のシーンを解放してから現在のシーンに新しいシーンを格納*/
	m_currentScene->Final();
	switch (_newScene)
	{
	case SceneType::Title:
		m_currentScene = m_titleScene;
		break;
	case SceneType::Game:
		m_currentScene = m_gameScene;
		break;
	case SceneType::GameOver:
		m_currentScene = m_gameOverScene;
		break;
	case SceneType::Clear:
		m_currentScene = m_clearScene;
		break;
	case SceneType::Loading:
		m_currentScene = m_loadScene;
		break;
	case SceneType::Debug:
		m_currentScene = m_debugScene;
		break;
	}

	m_currentScene->Init();//初期化
}

void SceneManager::Init()
{
	m_currentScene->Init();
}

void SceneManager::Update()
{
	m_currentScene->Update();
}

void SceneManager::Draw()
{
	m_currentScene->Draw();
}

void SceneManager::Final()
{
	m_currentScene->Final();
}

