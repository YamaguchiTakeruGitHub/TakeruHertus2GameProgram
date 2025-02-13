#include "ComponentAnimation.h"

void ComponentAnimation::UpdatePlayBlendAnim()
{
	//�u�����h�����P�ȉ��̏ꍇ�͂P�ɋ߂Â���
	if (m_blendAnimBlendRate < 1.0f)
	{
		//�u�����h���[�g�ɃX�s�[�h�����Z����
		m_blendAnimBlendRate += ANIMATION::PLAY_ANIM_BLEND_SPEED;
		
		//�ȏ�ɂȂ��
		if (m_blendAnimBlendRate > 1.0f)
		{
			//�Œ�
			m_blendAnimBlendRate = 1.0f;
		}
	}

	//�Đ����Ă���u�����h�A�j���[�V�����P�̏���
	if (m_blendPlayAnim1 != -1)
	{
		//�A�j���[�V�����̑����Ԃ��擾
		m_blendAnimTotalTime = MV1GetAttachAnimTotalTime(m_model->m_modelHandle, m_blendPlayAnim1);
		//���Ԃ�i�߂�
		m_blendAnimPlayCount1 += ANIMATION::PLAY_ANIM_BLEND_SPEED;
		//�Đ����Ԃ������ԂɒB������Đ����Ԃ����[�v
		if (m_blendAnimPlayCount1 >= m_blendAnimTotalTime)
		{
			m_blendAnimPlayCount1 = fmod(m_blendAnimPlayCount1, m_blendAnimTotalTime);
		}
		//�ύX�����Đ����Ԃ����f���ɔ��f������
		MV1SetAttachAnimTime(m_model->m_modelHandle, m_blendPlayAnim1, m_blendAnimPlayCount1);
		//�A�j���[�V�����P�̃��f���ɑ΂��锽�f�����Z�b�g
		MV1SetAttachAnimBlendRate(m_model->m_modelHandle, m_blendPlayAnim1, m_blendAnimBlendRate);
	}

	// �Đ����Ă���A�j���[�V�����Q�̏���
	if (m_blendPlayAnim2 != -1)
	{
		// �A�j���[�V�����̑����Ԃ��擾
		m_blendAnimTotalTime = MV1GetAttachAnimTotalTime(m_model->m_modelHandle, m_blendPlayAnim2);

		// �Đ����Ԃ�i�߂�
		m_blendAnimPlayCount2 += ANIMATION::PLAY_ANIM_BLEND_SPEED;

		// �Đ����Ԃ������Ԃɓ��B���Ă�����Đ����Ԃ����[�v������
		if (m_blendAnimPlayCount2 > m_blendAnimTotalTime)
		{
			m_blendAnimPlayCount2 = fmod(m_blendAnimPlayCount2, m_blendAnimTotalTime);
		}

		// �ύX�����Đ����Ԃ����f���ɔ��f������
		MV1SetAttachAnimTime(m_model->m_modelHandle, m_blendPlayAnim2, m_blendAnimPlayCount2);

		// �A�j���[�V�����Q�̃��f���ɑ΂��锽�f�����Z�b�g
		MV1SetAttachAnimBlendRate(m_model->m_modelHandle, m_blendPlayAnim2, 1.0f - m_blendAnimBlendRate);
	}

}

void ComponentAnimation::UpdatePlayAnim()
{
	//�A�j���[�V�����̃C���f�b�N�X�ɂ��āAMV1Attachanim�͒��ŉ��Z�����d�g�݂������Ă��邪���߂ɁA
	//���ۂɃA�j���[�V���������s��ʂŌ���Ƃ����Ⴎ����ɂȂ�����A�������ōs�����肷��
	//�����h�����߂ɁA�A�j���[�V�������^�C�~���O�łŃ^�b�`�����˂΂Ȃ�Ȃ�
	if (m_newAnimIndex != m_animIndex)
	{
		m_animIndex = m_newAnimIndex;	//���݂̃C���f�b�N�X�ɐV�����C���f�b�N�X����
		m_anim_NowTime = 0.0f;		//�Đ����Ԃ����Z�b�g����
	}
	//�Đ����Ԃ�i�߂�
	m_anim_NowTime += ANIMATION::PLAY_ANIM_SPEED;
	//�A�j���[�V�����̍Đ����Ԃ��Z�b�g����
	MV1SetAttachAnimTime(m_model->m_modelHandle, m_animIndex, m_anim_NowTime);
	//�A�j���[�V�������̃t���O�𗧂Ă�
	m_isPlayingAnimation = true;

	//�Đ����Ԃ������Ԃ���������
	if (m_anim_NowTime >= MV1GetAttachAnimTotalTime(m_model->m_modelHandle, m_animIndex))
	{
		m_anim_NowTime = 0.0f;			//�Đ����Ԃ����Z�b�g
		m_isPlayingAnimation = false;	//�A�j���[�V�������t���O�����낷
	}
}

ComponentAnimation::ComponentAnimation(std::shared_ptr<ComponentModel> _model)
	: m_model(_model)

	/*�u�����h�A�j���[�V����*/
	, m_blendPlayAnim1(-1)		  //�A�j���[�V����1�̃C���f�b�N�X
	, m_blendAnimPlayCount1(0.0f) //�A�j���[�V����1�Đ��J�E���g
	, m_blendPlayAnim2(-1)		  //�A�j���[�V����2�̃C���f�b�N�X
	, m_blendAnimPlayCount2(0.0f) //�A�j���[�V����2�Đ��J�E���g
	, m_blendAnimBlendRate(0.0f)  //�A�j���[�V�����̃u�����h��	
	, m_blendAnimTotalTime(0.0f)  //�A�j���[�V�����̑�����

	/*�ʏ�A�j���[�V����*/
	, m_animIndex(-1)			  //�A�j���[�V�����̃C���f�b�N�X
	, m_newAnimIndex(-1)		  //�V�����A�j���[�V�����̃C���f�b�N�X
	, m_anim_TotalTime(0.0f)	  //�A�j���[�V�����̑�����
	, m_anim_NowTime(0.0f)	      //�Đ�����

	/*�t���O*/
	, m_isPlayingAnimation(false) //�A�j���[�V�����Đ����t���O
{
}

void ComponentAnimation::PlayBlendAnim(int _playBlendAnim)
{
	// �Đ����̃��[�V�����Q���L����������f�^�b�`����
	if (m_blendPlayAnim2 != -1)
	{
		m_blendPlayAnim2 = -1;
		MV1DetachAnim(m_model->m_modelHandle, m_blendPlayAnim2);

	}

	// ���܂ōĐ����̃��[�V�����P���������̂̏����Q�Ɉړ�����
	m_blendPlayAnim2 = m_blendPlayAnim1;
	m_blendAnimPlayCount2 = m_blendAnimPlayCount1;

	// �V���Ɏw��̃��[�V���������f���ɃA�^�b�`���āA�A�^�b�`�ԍ���ۑ�����
	m_blendPlayAnim1 = MV1AttachAnim(m_model->m_modelHandle, _playBlendAnim);
	m_blendAnimPlayCount1 = 0.0f;

	// �u�����h���͍Đ����̃��[�V�����Q���L���ł͂Ȃ��ꍇ�͂P�D�O��( �Đ����̃��[�V�����P���P�O�O���̏�� )�ɂ���
	m_blendAnimBlendRate = m_blendPlayAnim2 == -1 ? 1.0f : 0.0f;
}

void ComponentAnimation::PlayAnim(int _playAnim)
{
	//�A�j���[�V�������Ń^�b�`����
	m_animIndex = MV1DetachAnim(m_model->m_modelHandle, m_animIndex);
	//�V�����A�j���[�V�������A�^�b�`����
	m_newAnimIndex = MV1AttachAnim(m_model->m_modelHandle, _playAnim);
}

void ComponentAnimation::ResetAnimationNowTime()
{
	m_anim_NowTime = 0;
}

void ComponentAnimation::Init()
{
	/*�u�����h�A�j���[�V����*/
	m_blendPlayAnim1 = -1;
	m_blendAnimPlayCount1 = 0.0f;
	m_blendPlayAnim2 = -1;
	m_blendAnimPlayCount2 = 0.0f;
	m_blendAnimBlendRate = 1.0f;
	m_blendAnimTotalTime = 0.0f;

	/*�ʏ�A�j���[�V����*/
	m_animIndex = -1;
	m_newAnimIndex = -1;

	m_anim_TotalTime = 0.0f;
	m_anim_NowTime = 0.0f;

	/*�A�j���[�V�����Đ��̃t���O*/
	m_isPlayingAnimation = false;
}

void ComponentAnimation::Update()
{
	//�ʏ�A�j���[�V�����̍X�V
	UpdatePlayAnim();
	//�u�����h�A�j���[�V�����̍X�V
	UpdatePlayBlendAnim();
}

void ComponentAnimation::Draw()
{
#ifdef _DEBUG
	DrawFormatString(0, 160, 0xffffff, "animCount1:%f, animCoune2:%f", m_blendAnimPlayCount1, m_blendAnimPlayCount2);
	DrawFormatString(0, 180, 0xffffff, "animTotalTime:%f", m_blendAnimTotalTime);
	DrawFormatString(0, 200, 0xffffff, "animBlendRate:%f", m_blendAnimBlendRate);
	DrawFormatString(0, 220, 0xffffff, "attachanimNum:%d", MV1GetAnimNum(m_model->m_modelHandle));
#endif // _DEBUG

}

void ComponentAnimation::Final()
{
}
