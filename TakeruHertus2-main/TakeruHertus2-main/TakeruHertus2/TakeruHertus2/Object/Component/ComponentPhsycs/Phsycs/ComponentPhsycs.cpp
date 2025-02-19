#include "ComponentPhsycs.h"


ComponentPhsycs::ComponentPhsycs(std::shared_ptr<ComponentTransform> _transform, std::shared_ptr<ComponentRightBody> _rightBody)
	
{
}

void ComponentPhsycs::Init()
{
}

void ComponentPhsycs::Update()
{
}

void ComponentPhsycs::Draw()
{
}

void ComponentPhsycs::Final()
{
}

void ComponentPhsycs::CheckWallAndFloor()
{
	/*���ƒn�ʂ̃|���S���̐���������*/
	m_wallNum = 0;
	m_floorNum = 0;

	//���o���ꂽ�|���S���̐������J��Ԃ�
	for (int i = 0; i < m_hitDim.HitNum; i++)
	{
		//�|���S���̖@����Y�������ǃ|���S���̃{�[�_�[�ɒB���Ă��邩�ǂ����ŕǃ|���S�������|���S�����𔻒f����
		if (m_hitDim.Dim[i].Normal.y < CollInfo::kWallPolyBorder && m_hitDim.Dim[i].Normal.y > -CollInfo::kWallPolyBorder)
		{
			//�ǃ|���S���Ɣ��f���ꂽ�ꍇ�f���A�v���C���[��Y���W��荂���|���S���̂ݓ����蔻����s��
			if (m_hitDim.Dim[i].Position[0].y > m_transform->position.y + CollInfo::kWallPolyHeight ||
				m_hitDim.Dim[i].Position[1].y > m_transform->position.y + CollInfo::kWallPolyHeight ||
				m_hitDim.Dim[i].Position[2].y > m_transform->position.y + CollInfo::kWallPolyHeight)
			{
				//�|���S���̐������E���ɒB���Ă��Ȃ�������|���S����z��ɒǉ�
				if (m_wallNum < CollInfo::kMaxColHitPolyNum)
				{
					//�|���S���̍\���̂̃A�h���X��ǃ|���S���|�C���^�z��ɕۑ�����
					m_FloorPoly[m_floorNum] = std::make_shared<MV1_COLL_RESULT_POLY>(m_hitDim.Dim[i]);
					//�ǃ|���S���̐������Z����
					m_floorNum++;
				}
			}
		}
		else
		{
			//�|���S���̐������񐔂ɒB���Ă��Ȃ�������|���S����z��ɒǉ�
			if (m_floorNum < CollInfo::kMaxColHitPolyNum)
			{
				//�|���S���̍\���̂̃A�h���X�����|���S���|�C���^�z��ɕۑ�����
				m_FloorPoly[m_floorNum] = std::make_shared<tagMV1_COLL_RESULT_POLY>(m_hitDim.Dim[i]);
				//���|���S���̐������Z
				m_floorNum++;
			}
		}

	}

}

void ComponentPhsycs::FixPositionWithWall()
{
	if (m_wallNum == 0) return;

	m_isHitFlag = false;
	if (m_isMoveflag)
	{
		for (int i = 0; i < m_wallNum; i++)
		{
			m_poly = m_WallPoly[i];

			if(!HitCheck_Capsule_Triangle(m_transform->position, 
				VAdd(m_transform->position, VGet(0.0f, m_capsule->radius, 0.0f)),
				m_capsule->radius, m_poly->Position[0], m_poly->Position[1], m_poly->Position[2]))
			{
				continue;
			}

			m_isHitFlag = true;

			VECTOR slideVec;

			slideVec = VCross(m_rightbody->velocity, m_poly->Normal);

			slideVec = VCross(m_poly->Normal, slideVec);

			m_transform->position = VAdd(m_transform->position, slideVec);

			bool isHitWallPolygon = false;

			for (int j = 0; j < m_wallNum; j++)
			{
				m_poly = m_WallPoly[j];
				if (HitCheck_Capsule_Triangle(m_transform->position,
					VAdd(m_transform->position, VGet(0.0f, m_capsule->radius, 0.0f)),
					m_capsule->radius,
					m_poly->Position[0], m_poly->Position[1], m_poly->Position[2]))
				{
					isHitWallPolygon = true;
					break;
				}
			}

			if (!isHitWallPolygon)
			{
				m_isHitFlag = false;
				break;
			}
		}
	}
	else
	{
		for (int i = 0; i < m_wallNum; i++)
		{
			m_poly = m_WallPoly[i];

			if (HitCheck_Capsule_Triangle(m_transform->position,
				VAdd(m_transform->position, VGet(0.0f, m_capsule->radius, 0.0f)),
				m_capsule->radius,
				m_poly->Position[0], m_poly->Position[1], m_poly->Position[2]))
			{
				m_isHitFlag = true;
				break;
			}

		}
	}

	if (m_isHitFlag)
	{
		FixPositionWithWallIInternal();
	}

}

void ComponentPhsycs::FixPositionWithWallIInternal()
{
	for (int i = 0; i < CollInfo::kMaxColHitTryNum; i++)
	{
		bool isHitWall = false;

		for (int j = 0; j < m_wallNum; j++)
		{
			m_poly = m_WallPoly[j];

			if (!HitCheck_Capsule_Triangle(m_transform->position,
				VAdd(m_transform->position, VGet(0.0f, m_capsule->radius, 0.0f)),
				m_capsule->radius,
				m_poly->Position[0], m_poly->Position[1], m_poly->Position[2]))
			{
				continue;
			}

			m_transform->position = VAdd(m_transform->position, VScale(m_poly->Normal, CollInfo::kColHitSlideLength));

			for (int k = 0; k < m_wallNum; k++)
			{
				m_poly = m_WallPoly[k];
				if (HitCheck_Capsule_Triangle(m_transform->position,
					VAdd(m_transform->position, VGet(0.0f, m_capsule->radius, 0.0f)),
					m_capsule->radius,
					m_poly->Position[0], m_poly->Position[1], m_poly->Position[2]))
				{
					isHitWall = true;
					break;
				}
			}

			if (!isHitWall) break;
		}

		if (!isHitWall) break;
	}

}
