#include "stdafx.h"
#include "..\Public\AttackObject_CommandGrab.h"

#include "RenderInstance.h"
#include "GameInstance.h"

#include "Character.h"
#include "Main_Camera.h"

CAttackObject_CommandGrab::CAttackObject_CommandGrab(ID3D11Device* pDevice, ID3D11DeviceContext* pContext)
	: CAttackObject{ pDevice, pContext }
{

}

CAttackObject_CommandGrab::CAttackObject_CommandGrab(const CAttackObject_CommandGrab& Prototype)
	: CAttackObject{ Prototype }
{

}

HRESULT CAttackObject_CommandGrab::Initialize_Prototype()
{
	return S_OK;
}

HRESULT CAttackObject_CommandGrab::Initialize(void* pArg)
{

	if (nullptr == pArg)
		return E_FAIL;

	ATTACK_COMMANDGRAB_DESC* pDesc = static_cast<ATTACK_COMMANDGRAB_DESC*>(pArg);
	
	m_bGrabbedEnd = false;

	if (FAILED(__super::Initialize(pArg)))
		return E_FAIL;

	
	//������ ĳ���Ϳ� �Ÿ���
	m_fDistance = pDesc->fDistance;

	//������ ĳ������ �ִϸ��̼� ����
	m_iGrabAnimationIndex = pDesc->iGrabAnimationIndex;
	m_fGrabAnimationPosition = pDesc->fGrabAnimationPosition;
	
	//����Ҵ� ����
	m_bForcedHit = pDesc->bForcedHit;

	//������ ĳ������ �߷� ���� ����
	m_bGrabedGravity = pDesc->bGrabedGravity;

	


	return S_OK;
}

void CAttackObject_CommandGrab::Camera_Update(_float fTimeDelta)
{

}

void CAttackObject_CommandGrab::Update(_float fTimeDelta)
{
	if (Check_UpdateStop(fTimeDelta))
		return;



	m_fAccLifeTime += fTimeDelta;

	if (m_fAccLifeTime > m_fLifeTime)
	{
		if (m_bEnableDestory)
		{
			CGameInstance::Get_Instance()->Destroy_Reserve(m_pColliderCom);
			m_bEnableDestory = false;
			Destory();
		}
	}
	else
		m_pColliderCom->Update(m_pOwnerTransform->Get_State(CTransform::STATE_POSITION));

}

void CAttackObject_CommandGrab::Late_Update(_float fTimeDelta)
{

	
		
	m_pRenderInstance->Add_RenderObject(CRenderer::RG_UI, this);
}

HRESULT CAttackObject_CommandGrab::Render(_float fTimeDelta)
{
//
#ifdef _DEBUG
	m_pColliderCom->Render(fTimeDelta);
#endif // DEBUG


	return S_OK;
}




void CAttackObject_CommandGrab::OnCollisionEnter(CCollider* other, _float fTimeDelta)
{



	//��Ⱑ �������� ����
	if (m_pOwner->Get_iAnimationIndex() != m_iGrabAnimationIndex || m_pOwner->Get_bStun())
		return;

	//��� vs ��� 
	else if (other->m_ColliderGroup == CCollider_Manager::COLLIDERGROUP::CG_1P_BODY || other->m_ColliderGroup == CCollider_Manager::COLLIDERGROUP::CG_2P_BODY)
	{
		CCharacter* pCharacter = static_cast<CCharacter*>(other->GetMineGameObject());


		//��� ĳ���� ����/�ٿ� ���¿� ������ ����� ���� ���� ���� �Ǻ�
		//�ִϸ��̼�,����Ÿ��,���� �ð�,������,���ݹ���,�з����� ������ �� ����
		AttackColliderResult eResult =
			pCharacter->Set_Hit4(m_ihitCharacter_Motion, m_eAttackGrade, m_eAttackType, m_fhitCharacter_StunTime, m_iDamage, m_fAnimationLockTime, m_iOnwerDirection, m_fhitCharacter_Impus);
		

		//���� ������
		if (eResult == RESULT_HIT || m_bForcedHit)
		{
			if (m_isfxSoundIndex != 60000)
			{
				m_pGameInstance->Play_Sound((CSound_Manager::SOUND_KEY_NAME)m_isfxSoundIndex, false, m_fsfxVolume);
			}

			
			//�ǰݵ� �� ���� ����
			pCharacter->Set_GroundSmash(m_bGroundSmash);

			if(m_bOnwerHitNoneStop == false)
				m_pOwner->Set_AnimationStop(m_fAnimationLockTime);

			pCharacter->Set_AnimationStop(m_fAnimationLockTime);

			if (m_fForcedGravityTime != 100)
				pCharacter->Set_fGravityTime(m_fForcedGravityTime);


			//������ȸ��
			m_pOwner->Gain_AttackStep(m_iGainAttackStep);
			m_pOwner->Gain_HitCount(m_iGainHitCount);
			m_pOwner->Gain_KiAmount(m_iGainKiAmount);

			//���� ���� �ǵ��
			m_pOwner->Set_AttackBackEvent(true);	



			

			//ī�޶� ���Ⱚ�� ������ ����
			if (m_iVirtualCameraindex != 200 || m_fCameraShakeDuration != 0)
			{
				CMain_Camera* main_Camera = static_cast<CMain_Camera*>(m_pGameInstance->Get_GameObject(LEVEL_GAMEPLAY, TEXT("Layer_Main_Camera")));

				//���� ��ȣ
				if (m_iVirtualCameraindex != 200)
				{
					main_Camera->Play((CMain_Camera::VIRTUAL_CAMERA)m_iVirtualCameraindex, m_ianimationIndex, m_pOwner);

				}

				//ȭ�� ��������,�ð�
				if (m_fCameraShakeDuration != 0)
				{
					main_Camera->StartCameraShake(m_fCameraShakeDuration, m_fCameraShakeMagnitude);
				}
			}

			

			//�ǰݵ� ĳ���� ���� ����
			pCharacter->Set_bGrabbed(!m_bGrabbedEnd);
			pCharacter->Set_bGrabbedGravity(m_bGrabedGravity);

			if (m_fForcedGravityTime != 100)   //������ �⺻ ��. 0�� �� ���� �־ 100���� ��
			{
				pCharacter->Set_ForcveGravityTime(m_fForcedGravityTime);
			}

			//������ ĳ������ ��ġ ����
			if(m_fDistance.x != 100)
			{
				_vector vPos = static_cast<CTransform*>(m_pOwner->Get_Component(TEXT("Com_Transform")))->Get_State(CTransform::STATE_POSITION);
				vPos += _vector{ m_fDistance.x, m_fDistance.y , 0.f, 0.f };
				static_cast<CTransform*>(pCharacter->Get_Component(TEXT("Com_Transform")))->Set_State(CTransform::STATE_POSITION, vPos);
			}
			if (m_strHitEffectName.size() != 0)
			{
				pCharacter->Character_Make_Effect(m_strHitEffectName, m_fHitEffectOffset, m_bHitEffectFlip);
			}

			//�������� �ִϸ��̼� ����
			if (m_bOwnerNextAnimation)
			{
				m_pOwner->Set_Animation(m_iOnwerNextAnimationIndex, false);
				m_pOwner->Set_CurrentAnimationPositionJump(m_fGrabAnimationPosition);

			}
			if (m_iCallAttackBackIndex != 60000)
			{
				m_pOwner->AttackEvent(m_iCallAttackBackIndex);
			}


		}
		else if (eResult == RESULT_GUARD) //������ص� �浹�� ������ ĳ���� ���� ����
		{
			m_pOwner->Set_AnimationStop(0.08f);
			pCharacter->Set_AnimationStop(0.08f);

			pCharacter->Character_Make_Effect(TEXT("Guard02"));
		}

		else if (eResult == RESULT_DRAW)
		{
			m_pOwner->Set_AnimationStop(0.3f);
			pCharacter->Set_AnimationStop(0.3f);
		}

		else if (eResult == RESULT_MISS)
		{

		}

		
	}




	



	
}

void CAttackObject_CommandGrab::OnCollisionStay(CCollider* other, _float fTimeDelta)
{
	_bool Debug = true;

}

void CAttackObject_CommandGrab::OnCollisionExit(CCollider* other)
{
	_bool Debug = true;

}

void CAttackObject_CommandGrab::CollisingAttack()
{
}

void CAttackObject_CommandGrab::CollisingPlayer()
{
}







CAttackObject_CommandGrab* CAttackObject_CommandGrab::Create(ID3D11Device* pDevice, ID3D11DeviceContext* pContext)
{
	CAttackObject_CommandGrab* pInstance = new CAttackObject_CommandGrab(pDevice, pContext);

	if (FAILED(pInstance->Initialize_Prototype()))
	{
		MSG_BOX(TEXT("Failed to Created : CAttackObject_CommandGrab"));
		Safe_Release(pInstance);
	}

	return pInstance;
}

CGameObject* CAttackObject_CommandGrab::Clone(void* pArg)
{
	CAttackObject_CommandGrab* pInstance = new CAttackObject_CommandGrab(*this);

	if (FAILED(pInstance->Initialize(pArg)))
	{
		MSG_BOX(TEXT("Failed to Cloned : CAttackObject_CommandGrab"));
		Safe_Release(pInstance);
	}

	return pInstance;
}

void CAttackObject_CommandGrab::Free()
{
	__super::Free();
	Safe_Release(m_pColliderCom);

}
