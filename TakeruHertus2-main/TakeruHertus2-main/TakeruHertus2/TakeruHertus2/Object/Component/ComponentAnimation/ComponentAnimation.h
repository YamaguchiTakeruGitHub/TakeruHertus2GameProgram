#pragma once
#include "../Base/Component.h"
#include "../ComponentModel/ComponentModel.h"

/// <summary>
/// �A�j���[�V�����萔
/// </summary>
namespace ANIMATION
{
	static constexpr float PLAY_ANIM_BLEND_SPEED = 0.2F;//�A�j���[�V�����u�����h�̑��x
	static constexpr float PLAY_ANIM_SPEED = 1.0f;		//�ʏ�A�j���[�V�����̑��x
}

/// <summary>
/// �A�j���[�V�����̃R���|�[�l���g�F�����w��FComponentModel
/// </summary>
class ComponentAnimation : public Component
{
private:
	std::shared_ptr<ComponentModel> m_model;//�A�j���[�V�������������߂ɃR���|�[�l���g���f�����Q�Ƃ�����


	/*�u�����h�Ŏg�p����A�j���[�V�����̕ϐ�*/
	int		m_blendPlayAnim1;				// �Đ����Ă���A�j���[�V�����P�̃A�^�b�`�ԍ�( -1:�����A�j���[�V�������A�^�b�`����Ă��Ȃ� )
	float	m_blendAnimPlayCount1;			// �Đ����Ă���A�j���[�V�����P�̍Đ�����
	int		m_blendPlayAnim2;				// �Đ����Ă���A�j���[�V�����Q�̃A�^�b�`�ԍ�( -1:�����A�j���[�V�������A�^�b�`����Ă��Ȃ� )
	float	m_blendAnimPlayCount2;			// �Đ����Ă���A�j���[�V�����Q�̍Đ�����
	float	m_blendAnimBlendRate;			// �Đ����Ă���A�j���[�V�����P�ƂQ�̃u�����h��
	float   m_blendAnimTotalTime;			// �A�j���[�V�����̑��Đ�����

	//�u�����h�A�j���[�V�����̍X�V
	void UpdatePlayBlendAnim();

	/*�ʏ�̃A�j���[�V�����ϐ�*/
	float m_anim_TotalTime;
	float m_anim_NowTime;
	int m_animIndex;
	int m_newAnimIndex;

	//�ʏ�A�j���[�V�����̍X�V
	void UpdatePlayAnim();

	/*�A�j���[�V�����Đ��t���O*/
	bool m_isPlayingAnimation;


public:
	/// <summary>
	///�@�A�j���[�V�����R���|�[�l���g�i�����w��F���f���R���|�[�l���g�j
	/// </summary>
	/// <param name="_model">���f���R���|�[�l���g</param>
	ComponentAnimation(std::shared_ptr<ComponentModel> _model);
	
	/// <summary>
	/// �u�����h���ꂽ�A�j���[�V�����̍Đ�
	/// </summary>
	/// <param name="_playBlendAnim"></param>
	void PlayBlendAnim(int _playBlendAnim);

	/// <summary>
	/// �ʏ�A�j���[�V�����̍Đ�
	/// </summary>
	/// <param name="_playAnim"></param>
	void PlayAnim(int _playAnim);

	//�A�j���[�V�����̍Đ����Ԃ����Z�b�g����
	void ResetAnimationNowTime();

	void Init() override;
	void Update() override;
	void Draw() override;
	void Final() override;

	//********************************************************//
	//	�Z�b�^�[�ƃQ�b�^�[
	//********************************************************//

	/// <summary>
	/// �A�j���[�V�������Đ������̃t���O
	/// </summary>
	/// <returns></returns>
	bool GetIsAnimPlaying() const { return m_isPlayingAnimation; }

};

