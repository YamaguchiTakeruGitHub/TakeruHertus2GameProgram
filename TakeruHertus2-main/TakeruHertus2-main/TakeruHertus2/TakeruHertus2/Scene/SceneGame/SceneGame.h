#pragma once
#include "../Base/SceneBase.h"
#include "SceneGameCommon.h"

class SceneGame : public SceneBase
{
private:
    /*�L�����N�^�[*/
	std::shared_ptr<Player> m_player;       //�v���C���[
    std::shared_ptr<EnemyFox> m_enemyFox;   //�ς̓G
    /*�J����*/
	std::shared_ptr<Camera> m_camera;       //�J����
	/*�}�b�v*/
	std::shared_ptr<TutorialMap> m_tutorialMap;//�`���[�g���A���}�b�v
	/*�t�H���g*/
	std::shared_ptr<Font> m_font;//�t�H���g

	/*�ϐ��錾*/
	bool m_isLoading;//���[�h�����ǂ���
	bool m_isOpenMenu;//���j���[���J���Ă��邩�ǂ���

	void PlayerControlCamera();

	/*�e�X�g�p�ϐ�*/
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

	bool IsTestCheckHitboxCollision(VECTOR _spherePos, float _sphereRadius, VECTOR _boxPos, VECTOR _boxSize);
	VECTOR IsTestCheckBoxResolveCollision(VECTOR _spherePos, float _sphereRadius, VECTOR _boxPos, VECTOR _boxSize);

	bool CheckCapsuleCollision();
	void ResolveCapusleCollision();

};

