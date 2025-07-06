#include "stdafx.h"
#include "..\Public\Character.h"

#include "RenderInstance.h"
#include "GameInstance.h"
#include "iostream"
#include "AttackObject.h"
#include "UI_Manager.h"
#include "Effect_Manager.h"

#include "AttackObject.h"
#include "BattleInterface.h"
#include "Main_Camera.h"

#include "Animation.h"
#include <cmath>
#include "SpaceMeteoBreak.h"
#include "Effect_Layer.h"
#include "Map_Manager.h"

#include "QTE_Manager.h"
#include "Particle_Manager.h"

#include "Level_GamePlay.h"
const _float CCharacter::fGroundHeight = 0.f; //0
const _float CCharacter::fJumpPower = 3.f; //0


vector<CInput> CCharacter::Command_236Attack =
{
	{MOVEKEY_DOWN, ATTACK_NONE},
	{MOVEKEY_DOWN_RIGHT, ATTACK_NONE},
	{MOVEKEY_RIGHT, ATTACK_NONE},
	{MOVEKEY_NEUTRAL, ATTACK_LIGHT}
};
vector<CInput> CCharacter::Command_236Attack_Extra =
{
	{MOVEKEY_DOWN, ATTACK_NONE},
	{MOVEKEY_DOWN_RIGHT, ATTACK_NONE},
	{MOVEKEY_RIGHT, ATTACK_NONE},
	{MOVEKEY_RIGHT, ATTACK_LIGHT}
};

vector<CInput> CCharacter::Command_236Attack_Heavy =
{
	{MOVEKEY_DOWN, ATTACK_NONE},
	{MOVEKEY_DOWN_RIGHT, ATTACK_NONE},
	{MOVEKEY_RIGHT, ATTACK_NONE},
	{MOVEKEY_NEUTRAL, ATTACK_HEAVY}
};
vector<CInput> CCharacter::Command_236Attack_Heavy_Extra =
{
	{MOVEKEY_DOWN, ATTACK_NONE},
	{MOVEKEY_DOWN_RIGHT, ATTACK_NONE},
	{MOVEKEY_RIGHT, ATTACK_NONE},
	{MOVEKEY_RIGHT, ATTACK_HEAVY}
};


vector<CInput> CCharacter::Command_214Attack =
{
	{MOVEKEY_DOWN, ATTACK_NONE},
	{MOVEKEY_DOWN_LEFT, ATTACK_NONE},
	{MOVEKEY_LEFT, ATTACK_NONE},
	{MOVEKEY_NEUTRAL, ATTACK_LIGHT}
};
vector<CInput> CCharacter::Command_214Attack_Extra =
{
	{MOVEKEY_DOWN, ATTACK_NONE},
	{MOVEKEY_DOWN_LEFT, ATTACK_NONE},
	{MOVEKEY_LEFT, ATTACK_NONE},
	{MOVEKEY_LEFT, ATTACK_LIGHT}
};

vector<CInput> CCharacter::Command_236Special =
{
	{MOVEKEY_DOWN, ATTACK_NONE},
	{MOVEKEY_DOWN_RIGHT, ATTACK_NONE},
	{MOVEKEY_RIGHT, ATTACK_NONE},
	{MOVEKEY_RIGHT, ATTACK_SPECIAL}
};

vector<CInput> CCharacter::Command_236Special_Side =
{
	{MOVEKEY_DOWN, ATTACK_NONE},
	{MOVEKEY_DOWN_RIGHT, ATTACK_NONE},
	{MOVEKEY_RIGHT, ATTACK_NONE},
	{MOVEKEY_DOWN, ATTACK_SPECIAL}
};

vector<CInput> CCharacter::Command_236Special_Side_Extra =
{
	{MOVEKEY_DOWN, ATTACK_NONE},
	{MOVEKEY_DOWN_RIGHT, ATTACK_NONE},
	{MOVEKEY_RIGHT, ATTACK_NONE},
	{MOVEKEY_DOWN, ATTACK_NONE},
	{MOVEKEY_DOWN, ATTACK_SPECIAL}
};

vector<CInput> CCharacter::Command_214Special =
{
	{MOVEKEY_DOWN, ATTACK_NONE},
	{MOVEKEY_DOWN_LEFT, ATTACK_NONE},
	{MOVEKEY_LEFT, ATTACK_NONE},
	{MOVEKEY_NEUTRAL, ATTACK_SPECIAL}
};

vector<CInput> CCharacter::Command_214Special_Extra =
{
	{MOVEKEY_DOWN, ATTACK_NONE},
	{MOVEKEY_DOWN_LEFT, ATTACK_NONE},
	{MOVEKEY_LEFT, ATTACK_NONE},
	{MOVEKEY_LEFT, ATTACK_SPECIAL}
};




vector<CInput> CCharacter::Command_214FinalAttack =
{
	{MOVEKEY_DOWN, ATTACK_NONE},
	{MOVEKEY_DOWN_LEFT, ATTACK_NONE},
	{MOVEKEY_LEFT, ATTACK_NONE},
	{MOVEKEY_LEFT, ATTACK_GRAB}
};


vector<CInput> CCharacter::Command_236UltimateAttack =
{
	{MOVEKEY_DOWN, ATTACK_NONE},
	{MOVEKEY_DOWN_RIGHT, ATTACK_NONE},
	{MOVEKEY_RIGHT, ATTACK_NONE},
	{MOVEKEY_RIGHT, ATTACK_GRAB}
};


vector<CInput> CCharacter::Command_236UltimateAttack_Side =
{
	{MOVEKEY_DOWN, ATTACK_NONE},
	{MOVEKEY_DOWN_RIGHT, ATTACK_NONE},
	{MOVEKEY_RIGHT, ATTACK_NONE},
	{MOVEKEY_DOWN, ATTACK_GRAB}
};

vector<CInput> CCharacter::Command_236UltimateAttack_Side_Extra =
{
	{MOVEKEY_DOWN, ATTACK_NONE},
	{MOVEKEY_DOWN_RIGHT, ATTACK_NONE},
	{MOVEKEY_RIGHT, ATTACK_NONE},
	{MOVEKEY_DOWN, ATTACK_NONE},
	{MOVEKEY_DOWN, ATTACK_GRAB}
};

vector<CInput> CCharacter::Command_BackDash =
{
	{MOVEKEY_LEFT, ATTACK_NONE},
	{MOVEKEY_NEUTRAL, ATTACK_NONE},
	{MOVEKEY_LEFT, ATTACK_NONE}
};

vector<CInput> CCharacter::Command_Forward =
{
	{MOVEKEY_RIGHT, ATTACK_NONE},
	{MOVEKEY_NEUTRAL, ATTACK_NONE},
	{ MOVEKEY_RIGHT, ATTACK_NONE }

};
vector<CInput> CCharacter::Command_Crouch_Crouch_SpecialAttack =
{
	{MOVEKEY_DOWN, ATTACK_NONE},
	{MOVEKEY_NEUTRAL, ATTACK_NONE},
	{MOVEKEY_DOWN, ATTACK_NONE},
	{MOVEKEY_DOWN, ATTACK_SPECIAL},

};



vector<CInput> CCharacter::Command_LightAttack = { {MOVEKEY_NEUTRAL, ATTACK_LIGHT} };
vector<CInput> CCharacter::Command_MediumAttack = { {MOVEKEY_NEUTRAL, ATTACK_MEDIUM} };

vector<CInput> CCharacter::Command_MediumAttack_Extra = { {MOVEKEY_RIGHT, ATTACK_MEDIUM} };

vector<CInput> CCharacter::Command_HeavyAttack = { {MOVEKEY_NEUTRAL, ATTACK_HEAVY} };
vector<CInput> CCharacter::Command_SpecialAttack = { {MOVEKEY_NEUTRAL, ATTACK_SPECIAL} };

vector<CInput> CCharacter::Command_HeavyAttack_Extra = { {MOVEKEY_RIGHT, ATTACK_HEAVY} };

vector<CInput> CCharacter::Command_Grab = { {MOVEKEY_NEUTRAL, ATTACK_GRAB} };


vector<CInput> CCharacter::Command_Crouch_LightAttack = { {MOVEKEY_DOWN, ATTACK_LIGHT} };
vector<CInput> CCharacter::Command_Crouch_MediumAttack = { {MOVEKEY_DOWN, ATTACK_MEDIUM} };
vector<CInput> CCharacter::Command_Crouch_HeavyAttack = { {MOVEKEY_DOWN, ATTACK_HEAVY} };
vector<CInput> CCharacter::Command_Crouch_SpecialAttack = { {MOVEKEY_DOWN, ATTACK_SPECIAL} };


vector<CInput> CCharacter::Command_Crouch_MediumAttack_Extra = { {MOVEKEY_DOWN_RIGHT, ATTACK_MEDIUM} };
vector<CInput> CCharacter::Command_Crouch_HeavyAttack_Extra = { {MOVEKEY_DOWN_RIGHT, ATTACK_HEAVY} };

vector<CInput> CCharacter::Command_Reflect = { {MOVEKEY_LEFT, ATTACK_SPECIAL} };

vector<CInput> CCharacter::Command_Up_SpecialAttack = { {MOVEKEY_UP, ATTACK_SPECIAL} };


vector<CInput> CCharacter::Command_LowBenishingAttack = { {MOVEKEY_DOWN, ATTACK_BENISHING} };
vector<CInput> CCharacter::Command_BenishingAttack = { {MOVEKEY_NEUTRAL, ATTACK_BENISHING} };


vector<CInput> CCharacter::Command_Transform = { {MOVEKEY_DOWN, ATTACK_TRANSFORM} };






CCharacter::CCharacter(ID3D11Device* pDevice, ID3D11DeviceContext* pContext)
	: CGameObject{ pDevice, pContext }
	, m_pUI_Manager{ CUI_Manager::Get_Instance() }
{
	Safe_AddRef(m_pUI_Manager);
}

CCharacter::CCharacter(const CCharacter& Prototype)
	: CGameObject{ Prototype }
	, m_pFrameEvent{ Prototype.m_pFrameEvent }
	, m_pUI_Manager{ CUI_Manager::Get_Instance() }
	, m_pEffect_Manager{ CEffect_Manager::Get_Instance() }
{
	Safe_AddRef(m_pUI_Manager);
	Safe_AddRef(m_pEffect_Manager);
}

HRESULT CCharacter::Initialize_Prototype()
{

	return S_OK;
}

HRESULT CCharacter::Initialize(void* pArg)
{
	Character_DESC* pDesc = static_cast<Character_DESC*>(pArg);

	if (pArg == nullptr)
	{
		FlipDirection(1);
		return S_OK;
	}

	m_pFrameEvent = CFrameEvent_Manager::Get_Instance()->Get_pFrameEventMap();

	if (FAILED(__super::Initialize(pArg)))
		return E_FAIL;

	Character_DESC* pSlotDesc = static_cast<Character_DESC*>(pArg);
	m_ePlayerSlot = pSlotDesc->ePlayerSlot;
	m_tCharacterDesc.ePlayer_Slot = m_ePlayerSlot;


	m_iPlayerTeam = pDesc->iTeam;

	if (FAILED(Ready_Components()))
		return E_FAIL;

	if (m_iPlayerTeam == 1)
	{
		m_pTransformCom->Set_State(CTransform::STATE_POSITION, XMVectorSet(0.f, -3.f, 0.f, 1.f));
		FlipDirection(1);
	}
	else
	{
		m_pTransformCom->Set_State(CTransform::STATE_POSITION, XMVectorSet(2.f, -3.f, 0.f, 1.f));
		FlipDirection(-1);
	}



	inputBuffer.push_back(CInput(MOVEKEY_NEUTRAL, ATTACK_NONE));



	return S_OK;
}

void CCharacter::Player_Update(_float fTimeDelta)
{
	m_tCharacterDesc.bStun = m_bRedHp;

	m_tCharacterDesc.bAttBuf = m_bAttBuf;
	m_tCharacterDesc.iHp = m_iHP;
	m_tCharacterDesc.bHit = m_bHit;

	m_tCharacterDesc.iComboCount = CBattleInterface_Manager::Get_Instance()->Get_HitCount(m_iPlayerTeam);

	if (m_iPrevComboCount < m_tCharacterDesc.iComboCount)
	{
		m_bHit = false;
	}


	if (m_bPlaying && m_bDying)
	{
		CBattleInterface_Manager::Get_Instance()->Reset_HitCount(m_iPlayerTeam);
	}

	m_tCharacterDesc.iSKillCount = m_iSKillCount;
	m_tCharacterDesc.iSKillPoint = m_iSKillPoint;
	m_tCharacterDesc.ePlayer_Slot = m_ePlayerSlot;
	m_tCharacterDesc.ePlayerID = m_eCharacterID;
	m_tCharacterDesc.iTeam = m_iPlayerTeam;

	m_iPrevComboCount = m_tCharacterDesc.iComboCount;
}

void CCharacter::Camera_Update(_float fTimeDelta)
{


}

void CCharacter::Update(_float fTimeDelta)
{
	if (m_bAnimationLock == false)
	{

	}
	else
	{
		m_fAccAnimationLock += fTimeDelta;
		if (m_fAccAnimationLock > m_fMaxAnimationLock)
		{
			m_fAccAnimationLock = 0.f;
			m_bAnimationLock = false;
		}
	}

}

void CCharacter::Late_Update(_float fTimeDelta)
{


	if (m_bPlaying || m_bTag_In)
	{
		m_pRenderInstance->Add_RenderObject(CRenderer::RG_PLAYER, this, &m_RendererDesc);


	}

#ifdef _DEBUG
	m_pRenderInstance->Add_DebugComponent(m_pColliderCom);
#endif

}

HRESULT CCharacter::Render(_float fTimeDelta)
{
	if (FAILED(Bind_ShaderResources()))
		return E_FAIL;

	_uint		iNumMeshes = m_pModelCom->Get_NumMeshes();

	for (size_t i = 0; i < iNumMeshes; i++)
	{
		/* ���� ������ �ִ� ���׸��� �� i��° �޽ð� ����ؾ��ϴ� ���׸�����ü�� aiTextureType_DIFFUSE��° �ؽ��ĸ� */
		/* m_pShaderCom�� �ִ� g_DiffuseTexture������ ����. */
		if (FAILED(m_pModelCom->Bind_MaterialSRV(m_pShaderCom, aiTextureType_DIFFUSE, "g_DiffuseTexture", i)))
			return E_FAIL;
		// m_pModelCom->Bind_MaterialSRV(m_pShaderCom, aiTextureType_NORMALS, "g_NormalTexture", i);

		/* ���� ������ �ִ� ���� �߿��� ���� �������ҷ��� �ߴ� i��° �޽ð� ����ϴ� ������ �迭�� ���� ���̴��� �����ش�.  */
		m_pModelCom->Bind_BoneMatrices(m_pShaderCom, "g_BoneMatrices", i);

		if (FAILED(m_pShaderCom->Begin(0)))
			return E_FAIL;

		if (FAILED(m_pModelCom->Render(i)))
			return E_FAIL;
	}

	return S_OK;
}



_bool CCharacter::CompareNextAnimation(_uint iAnimationIndex, _float fNextPosition)
{
	_bool bCompare = true;

	if (fNextPosition != 0)
	{
		if (m_fNextAnimationCurrentPosition != fNextPosition)
			bCompare = false;
	}

	if (iAnimationIndex != m_iNextAnimation.first)
		bCompare = false;

	return bCompare;
}

void CCharacter::Set_CurrentAnimationPositionJump(_float fAnimationPosition)
{
	m_pModelCom->CurrentAnimationPositionJump(fAnimationPosition);
}

void CCharacter::ProcessEventsFramesZero(_uint characterIndex, _uint animationIndex)
{

	//�ִϸ��̼� ����� 0��° �������̺�Ʈ�� �����ϱ� ����

	auto characterIt = m_pFrameEvent->find(m_eCharacterIndex);   //�׽�Ʈ��
	if (characterIt != m_pFrameEvent->end())
	{
		auto& animationMap = characterIt->second;
		auto animationIt = animationMap.find(animationIndex);
		if (animationIt != animationMap.end())
		{
			auto& frameMap = animationIt->second;

			auto frameIt = frameMap[0];

			for (auto event : frameIt)
			{

				CFrameEvent_Manager::Get_Instance()->UseEvent(event, this);
			}

		}
	}



}

void CCharacter::ProcessEventsBetweenFrames2(int characterIndex, int animationIndex, float prevFrame, float currentFrame)
{

	// ĳ���� �ε��� Ž��
	auto characterIt = m_pFrameEvent->find(m_eCharacterIndex);  
	if (characterIt != m_pFrameEvent->end())
	{
		auto& animationMap = characterIt->second;
		auto animationIt = animationMap.find(animationIndex);
		if (animationIt != animationMap.end())
		{
			auto& frameMap = animationIt->second;


			for (auto frameIt = frameMap.lower_bound(prevFrame); frameIt != frameMap.end() && frameIt->first <= currentFrame; ++frameIt)
			{
				// �ش� �����ӿ����� �̺�Ʈ ����Ʈ�� ���
				for (string event : frameIt->second)
				{
					//���
					CFrameEvent_Manager::Get_Instance()->UseEvent(event, this);

				}
			}

		}
	}


	
}

_bool CCharacter::InputCommand()
{



	ButtonInput iAttackkey = ATTACK_NONE;
	DirectionInput iMoveKey = MOVEKEY_NEUTRAL;

	_int DirectionX = 0;
	_int DirectionY = 0;


	if (m_iPlayerTeam == 1)
	{

		if (m_pGameInstance->Key_Pressing(DIK_W))
		{
			DirectionY = 1;
		}

		else if (m_pGameInstance->Key_Pressing(DIK_S))
		{
			DirectionY = -1;
		}

		if (m_pGameInstance->Key_Pressing(DIK_A))
		{
			DirectionX -= m_iLookDirection;
		}

		else if (m_pGameInstance->Key_Pressing(DIK_D))
		{
			DirectionX += m_iLookDirection;
		}

		//�� �� 0�ΰ��� �⺻���̹Ƿ� �������� ���� �밢�� ���� ���̴� Ŀ�ǵ尡 �����Ƿ� �������� ����
		//if(DirectionX==0 && DirectionY ==0)

		if (DirectionX == -1 && DirectionY == 0)
			iMoveKey = MOVEKEY_LEFT;

		else if (DirectionX == 0 && DirectionY == 1)
			iMoveKey = MOVEKEY_UP;

		else if (DirectionX == -1 && DirectionY == -1)
			iMoveKey = MOVEKEY_DOWN_LEFT;

		else if (DirectionX == 0 && DirectionY == -1)
			iMoveKey = MOVEKEY_DOWN;

		else if (DirectionX == 1 && DirectionY == -1)
			iMoveKey = MOVEKEY_DOWN_RIGHT;

		else if (DirectionX == 1 && DirectionY == 0)
			iMoveKey = MOVEKEY_RIGHT;

		else if (DirectionX == -1 && DirectionY == 1)
			iMoveKey = MOVEKEY_UP_LEFT;

		else if (DirectionX == 1 && DirectionY == 1)
			iMoveKey = MOVEKEY_UP_RIGHT;




		if (m_pGameInstance->Key_Down(DIK_U))
		{
			iAttackkey = ATTACK_LIGHT;
		}

		if (m_pGameInstance->Key_Down(DIK_I))
		{
			iAttackkey = ATTACK_MEDIUM;

		}
		if (m_pGameInstance->Key_Down(DIK_J))
		{
			iAttackkey = ATTACK_SPECIAL;

		}
		if (m_pGameInstance->Key_Down(DIK_K))
		{
			iAttackkey = ATTACK_HEAVY;

		}


		if (m_pGameInstance->Key_Down(DIK_O))
		{
			iAttackkey = ATTACK_GRAB;

		}
		if (m_pGameInstance->Key_Down(DIK_L))
		{
			iAttackkey = ATTACK_BENISHING;
		}
		if (m_pGameInstance->Key_Down(DIK_M))
		{
			iAttackkey = ATTACK_TRANSFORM;
		}
		

		GetUI_Input(iMoveKey, iAttackkey, 1);

	}
	else  //2��
	{
		if (m_pGameInstance->Key_Pressing(DIK_UP))
		{
			DirectionY = 1;
		}

		else if (m_pGameInstance->Key_Pressing(DIK_DOWN))
		{
			DirectionY = -1;
		}

		if (m_pGameInstance->Key_Pressing(DIK_LEFT))
		{
			DirectionX -= m_iLookDirection;
		}

		else if (m_pGameInstance->Key_Pressing(DIK_RIGHT))
		{
			DirectionX += m_iLookDirection;
		}

		//�� �� 0�ΰ��� �⺻���̹Ƿ� �������� ���� �밢�� ���� ���̴� Ŀ�ǵ尡 �����Ƿ� �������� ����
		//if(DirectionX==0 && DirectionY ==0)

		if (DirectionX == -1 && DirectionY == 0)
			iMoveKey = MOVEKEY_LEFT;

		else if (DirectionX == 0 && DirectionY == 1)
			iMoveKey = MOVEKEY_UP;

		else if (DirectionX == -1 && DirectionY == -1)
			iMoveKey = MOVEKEY_DOWN_LEFT;

		else if (DirectionX == 0 && DirectionY == -1)
			iMoveKey = MOVEKEY_DOWN;

		else if (DirectionX == 1 && DirectionY == -1)
			iMoveKey = MOVEKEY_DOWN_RIGHT;

		else if (DirectionX == 1 && DirectionY == 0)
			iMoveKey = MOVEKEY_RIGHT;

		else if (DirectionX == -1 && DirectionY == 1)
			iMoveKey = MOVEKEY_UP_LEFT;

		else if (DirectionX == 1 && DirectionY == 1)
			iMoveKey = MOVEKEY_UP_RIGHT;





		if (m_pGameInstance->Key_Down(DIK_NUMPAD7))
		{
			iAttackkey = ATTACK_LIGHT;
		}

		if (m_pGameInstance->Key_Down(DIK_NUMPAD8))
		{
			iAttackkey = ATTACK_MEDIUM;

		}
		if (m_pGameInstance->Key_Down(DIK_NUMPAD4))
		{
			iAttackkey = ATTACK_SPECIAL;

		}
		if (m_pGameInstance->Key_Down(DIK_NUMPAD5))
		{
			iAttackkey = ATTACK_HEAVY;

		}


		if (m_pGameInstance->Key_Down(DIK_NUMPAD9))
		{
			iAttackkey = ATTACK_GRAB;

		}
		if (m_pGameInstance->Key_Down(DIK_NUMPAD6))
		{
			iAttackkey = ATTACK_BENISHING;
		}
		if (m_pGameInstance->Key_Down(DIK_NUMPAD1))
		{
			iAttackkey = ATTACK_TRANSFORM;
		}
		// if (m_pGameInstance->Key_Pressing(DIK_Y))
		// {
		//	 iAttackkey = ATTACK_LIGHT;
		//
		// }
		GetUI_Input(iMoveKey, iAttackkey, 2);
	}


	_bool bNewKey = false;

	CInput newInput(iMoveKey, iAttackkey);

	if (inputBuffer.size() > 0)
	{
		//������ ���¿� Ű �Է� ���°� �Ȱ����� �������� ����
		if (inputBuffer.back() == newInput)
		{

		}
		else
		{
			UpdateInputBuffer(CInput(iMoveKey, iAttackkey));
			bNewKey = true;
		}
	}
	else
	{
		UpdateInputBuffer(CInput(iMoveKey, iAttackkey));
		bNewKey = true;
	}




	return bNewKey;
}

void CCharacter::InputedCommandUpdate(_float fTimeDelta)
{



	inputBuffer.erase(
		remove_if(inputBuffer.begin(), inputBuffer.end(), [fTimeDelta](CInput& input) {
			input.frameTime += fTimeDelta;  // frameTime�� fTimeDelta ���ϱ�
			return input.frameTime >= 0.35f; // 0.3 �̻��� ��� ����
			}),
		inputBuffer.end()
	);



}


_bool CCharacter::Character_Play_Animation(_float fTimeDelta)
{

	_bool bAnimationEnd = false;
	_float fPrePosition = m_pModelCom->m_fCurrentAnimPosition;


	if (fPrePosition == 0)
	{
		ProcessEventsFramesZero(m_eCharacterIndex, m_pModelCom->m_iCurrentAnimationIndex);
		fPrePosition += 0.001;

	}

	if (m_pModelCom->Play_Animation_Lick(fTimeDelta))
	{
		//����� ��������, ������
		if (m_pModelCom->m_isLoopAnim)
		{
			fPrePosition = 0.001;
			ProcessEventsFramesZero(m_eCharacterIndex, m_pModelCom->m_iCurrentAnimationIndex);
		}
		bAnimationEnd = true;
		m_bMotionPlaying = false;
	}
	else
		m_bMotionPlaying = true;


	_float fCurPosition = m_pModelCom->m_fCurrentAnimPosition;

	//�ִϸ��̼� Position ���İ� ���̿� �ִϸ��̼� �̺�Ʈ�� ������ ���
	ProcessEventsBetweenFrames2(0, m_pModelCom->m_iCurrentAnimationIndex, fPrePosition, fCurPosition);



	return bAnimationEnd;
}

_bool CCharacter::Character_Play_Animation_NoXZ(_float fTimeDelta)
{
	_bool bAnimationEnd = false;

	_float fPrePosition = m_pModelCom->m_fCurrentAnimPosition;


	if (fPrePosition == 0)
	{

		ProcessEventsFramesZero(m_eCharacterIndex, m_pModelCom->m_iCurrentAnimationIndex);
		fPrePosition += 0.001;

	}

	if (m_pModelCom->Play_Animation_Lick2(fTimeDelta, m_pTransformCom))
		//if (m_pModelCom->Play_Animation(fTimeDelta))
	{
		//����� ��������, ������
		if (m_pModelCom->m_isLoopAnim)
		{
			fPrePosition = 0.001;
			ProcessEventsFramesZero(m_eCharacterIndex, m_pModelCom->m_iCurrentAnimationIndex);
			
		}
		bAnimationEnd = true;
		m_bMotionPlaying = false;
	}
	else
		m_bMotionPlaying = true;


	_float fCurPosition = m_pModelCom->m_fCurrentAnimPosition;


	ProcessEventsBetweenFrames2(0, m_pModelCom->m_iCurrentAnimationIndex, fPrePosition, fCurPosition);



	return bAnimationEnd;
}

_bool CCharacter::Check_bCurAnimationisAirMove(_uint iAnimation)
{
	_uint iModelIndex = iAnimation;

	if (iAnimation == 1000)
		iModelIndex = m_pModelCom->m_iCurrentAnimationIndex;



	if (iModelIndex == m_iJumpAnimationIndex || iModelIndex == m_iFallAnimationIndex)
	{
		return true;
	}

	return false;
}

bool CCharacter::CheckCommandSkippingExtras(const vector<CInput>& pattern, int timeWindow)
{
	if (inputBuffer.size() < pattern.size()) return false;

	int patternIndex = 0;

	// �Է� ���ۿ��� ������ ã�� ����
	for (int i = 0; i < inputBuffer.size(); ++i) {
		const CInput& input = inputBuffer[i];
		const CInput& expected = pattern[patternIndex];

		// ���ʿ��� �Է��� �ǳʶ�
		if (input.direction == expected.direction && input.button == expected.button) {
			// ������ ��ġ�ϸ� ���� �������� �Ѿ
			patternIndex++;

			// ��� ������ ��ġ�ϸ� ����
			if (patternIndex >= pattern.size())
			{
				inputBuffer.clear();
				return true;
			}
		}


	}

	return false;
}

bool CCharacter::CheckCommand_Exactly(const std::vector<CInput>& pattern, int timeWindow)
{
	if (inputBuffer.size() < pattern.size()) return false;  // �Է� ���۰� ���Ϻ��� ª���� ����


	// �Է� ���� ��ü�� ��ȸ�ϸ鼭 ������ ã��
	for (int i = 0; i <= inputBuffer.size() - pattern.size(); ++i)
	{
		bool isPatternMatched = true;

		// ���� ��ġ���� ������ ��
		for (int j = 0; j < pattern.size(); ++j) {
			const CInput& inputCheck = inputBuffer[i + j];
			const CInput& expected = pattern[j];

			// ���ϰ� ��ġ���� ������ ����
			if (inputCheck.direction != expected.direction || inputCheck.button != expected.button) {
				isPatternMatched = false;
				break;
			}


		}

		// ������ ��ġ������ true ��ȯ
		if (isPatternMatched)
		{
			inputBuffer.clear();
			return true;
		}
	}

	return false;  // ������ ã�� ���ϸ� ����
}


_uint CCharacter::CheckAllCommands()
{


	for (const auto& command : MoveCommandPatternsFunction)
	{
		if (CheckCommandSkippingExtras(command.pattern, 0)) {
			command.action();  // �ش� ������ ��Ī�Ǹ� �ش� ��� ����

			return 0;
		}
	}


	//��Ȯ�ؾ��ϸ� �ϴ� ���� ���� ����
	for (const auto& command : MoveCommandPatternsFunction_Exactly)
	{
		if (CheckCommand_Exactly(command.pattern, 0)) {
			command.action();  // �ش� ������ ��Ī�Ǹ� �ش� ��� ����

			return 0;
		}
	}
	return 0;


}


void CCharacter::ShowInputBuffer()
{
	inputBuffer;
	m_fGravityTime;
	m_pModelCom->m_iCurrentAnimationIndex;
	m_pModelCom->m_fCurrentAnimPosition;
	_float fHeight = Get_fHeight();
	_bool bDebug = true;
}

void CCharacter::DebugPositionReset(_short iDirection)
{
	_float fHegiht = Get_fHeight();

	if (iDirection == 0)
		m_pTransformCom->Set_State(CTransform::STATE_POSITION, { (_float)m_iPlayerTeam,fHegiht,0,1 });
	else if (iDirection == -1)
	{
		m_pTransformCom->Set_State(CTransform::STATE_POSITION, { -10.5f + (_float)m_iPlayerTeam,fHegiht,0,1 });
	}
	else
	{
		m_pTransformCom->Set_State(CTransform::STATE_POSITION, { 10.f + (_float)m_iPlayerTeam,fHegiht,0,1 });
	}

}

void CCharacter::FlipDirection(_int iDirection)
{
	if (iDirection == 0)
	{
		m_iLookDirection = -m_iLookDirection;

		m_pTransformCom->Set_Scaled(-1, 1, 1);
	}
	else if (m_iLookDirection != iDirection)
	{

		m_iLookDirection = iDirection;

		m_pTransformCom->Set_Scaled(-1, 1, 1);
	}


}

void CCharacter::Create_Effect(_int iEffectIndex)
{
	switch (iEffectIndex)
	{
	case 0:
		//Create_kamehameha();
		break;

	case 1:
		//Create_Smash();
		break;

	default:
		break;
	}
}

_float CCharacter::Get_fHeight()
{
	return 	XMVectorGetY(m_pTransformCom->Get_State(CTransform::STATE_POSITION));

}

CCharacter* CCharacter::Get_pEnemy()
{
	return m_pEnemy;
}

void CCharacter::Set_ForcedGravityDown()
{

	//���� �մ�� ������ �߷�
	m_fGravityTime = 0.255f;


}

void CCharacter::Set_ForcedGravityTime_LittleUp()
{
	m_fGravityTime = 0.135f;

	if (m_fJumpPower == 0)
	{
		m_fJumpPower = fJumpPower;
	}
}

void CCharacter::Set_ForcveGravityTime(_float fGravityTime)
{
	m_fGravityTime = fGravityTime;
}

void CCharacter::Set_bAttackGravity(_bool bAttackGravity)
{
	m_bAttackGravity = bAttackGravity;

	if (bAttackGravity)
		_bool bDebug = false;


}

void CCharacter::AttckCancleJump()
{
	if (m_pModelCom->m_iCurrentAnimationIndex == m_iStandingMidAttackAnimationIndex && m_bAttackBackEvent)
	{

		//1��
		if (m_iPlayerTeam == 1 && m_pGameInstance->Key_Down(DIK_W))
		{

			Set_fJumpPower(3.f);

			Set_Animation(m_iJumpAnimationIndex, false);


			if (m_pGameInstance->Key_Pressing(DIK_A))
			{
				Set_fImpulse(-5.f);
			}

			else if (m_pGameInstance->Key_Pressing(DIK_D))
			{
				Set_fImpulse(5.f);
			}
		}

		//2��
		else if (m_iPlayerTeam == 2 && m_pGameInstance->Key_Down(DIK_UP))
		{
			Set_fJumpPower(3.f); 

			Set_Animation(m_iJumpAnimationIndex, false);


			if (m_pGameInstance->Key_Pressing(DIK_LEFT))
			{
				Set_fImpulse(-5.f);
			}

			else if (m_pGameInstance->Key_Pressing(DIK_RIGHT))
			{
				Set_fImpulse(5.f);
			}
		}

	}


	else if (m_bDoubleJumpEnable && (
		m_pModelCom->m_iCurrentAnimationIndex == m_iJumpAnimationIndex || m_pModelCom->m_iCurrentAnimationIndex == m_iFallAnimationIndex ||
		m_pModelCom->m_iCurrentAnimationIndex == m_iAttack_Air1 || m_pModelCom->m_iCurrentAnimationIndex == m_iAttack_Air2 || m_pModelCom->m_iCurrentAnimationIndex == m_iAttack_AirUpper))
	{

		//1��
		if (m_iPlayerTeam == 1 && m_pGameInstance->Key_Down(DIK_W))
		{

			Set_fJumpPower(3.f); 
			Set_ForcveGravityTime(0.03f);


			if (m_pModelCom->m_iCurrentAnimationIndex == m_iJumpAnimationIndex || m_pModelCom->m_iCurrentAnimationIndex == m_iFallAnimationIndex)
				m_pModelCom->CurrentAnimationPositionJump(0.f);

			else
				Set_NextAnimation(m_iJumpAnimationIndex, 0.5f);



			if (m_pGameInstance->Key_Pressing(DIK_A))
			{
				Set_fImpulse(-5.f);
			}

			else if (m_pGameInstance->Key_Pressing(DIK_D))
			{
				Set_fImpulse(5.f);
			}
			else
				Set_fImpulse(0.f);


			m_bDoubleJumpEnable = false;

		}

		//2��
		else if (m_iPlayerTeam == 2 && m_pGameInstance->Key_Down(DIK_UP))
		{
			Set_fJumpPower(3.f); 
			Set_ForcveGravityTime(0.03f);

			if (m_pModelCom->m_iCurrentAnimationIndex == m_iJumpAnimationIndex || m_pModelCom->m_iCurrentAnimationIndex == m_iFallAnimationIndex)
				m_pModelCom->CurrentAnimationPositionJump(0.f);

			else
				Set_NextAnimation(m_iJumpAnimationIndex, 0.5f);




			Set_ForcveGravityTime(0.03f);

			if (m_pGameInstance->Key_Pressing(DIK_LEFT))
			{
				Set_fImpulse(-5.f);
			}

			else if (m_pGameInstance->Key_Pressing(DIK_RIGHT))
			{
				Set_fImpulse(5.f);
			}
			else
				Set_fImpulse(0.f);


			m_bDoubleJumpEnable = false;

		}


	}

}


void CCharacter::Chase2(_float fTimeDelta)
{




	//����׿� ����ó��.
	if (fTimeDelta > 1)
	{
		return;
	}

	if (m_bStun)
	{
		m_bChase = false;

	}


	//�غ��ڼ��� �̷��� �Ѵ�.
	if (m_pModelCom->m_iCurrentAnimationIndex == m_iFallAnimationIndex)
	{

		Add_Move({ -1.f * fTimeDelta,fTimeDelta * 4.8f });

		m_fAccChaseTime += fTimeDelta;

		if (m_fAccChaseTime > 0.2f)
		{
			m_pModelCom->SetUp_Animation(m_iChaseAnimationIndex, false);
			m_fJumpPower = fJumpPower;

			CEffect_Layer::COPY_DESC tDesc{};

			tDesc.pPlayertMatrix = m_pModelCom->Get_BoneMatrixPtr("G_head");
			tDesc.pTransformCom = m_pTransformCom;
			tDesc.m_isPlayerDirRight = m_iLookDirection;


			m_pChaseEffectLayer = CEffect_Manager::Get_Instance()->Copy_Layer_AndGet(m_ChaseEffectName, &tDesc);

		
			{
				//�������� �׽�Ʈ
				{

					CAttackObject::ATTACK_DESC Desc{};

					if (m_iPlayerTeam == 1)
						Desc.ColliderDesc.colliderGroup = CCollider_Manager::COLLIDERGROUP::CG_1P_Melee_Attack;
					else
						Desc.ColliderDesc.colliderGroup = CCollider_Manager::COLLIDERGROUP::CG_2P_Melee_Attack;
					Desc.ColliderDesc.pMineGameObject = this;
					Desc.ColliderDesc.vCenter = { 0.f,0.5f,0.f };
					Desc.ColliderDesc.vExtents = { 1.f,1.f,0.2f };


					Desc.fhitCharacter_Impus = { 0.7f * m_iLookDirection,0.3f };

					Desc.fhitCharacter_StunTime = 0.6f;
					Desc.iDamage = 300 * Get_DamageScale();
					Desc.fLifeTime = 5.f;
					Desc.ihitCharacter_Motion = { HitMotion::HIT_CHASE };

					Desc.iTeam = m_iPlayerTeam;
					Desc.fAnimationLockTime = 0.1f;
					Desc.pOwner = this;

					Desc.bReflect = true;

					m_pGameInstance->Add_GameObject_ToLayer(LEVEL_GAMEPLAY, TEXT("Prototype_GameObject_Attack_Chase"), TEXT("Layer_AttackObject"), &Desc);

				
				}
			}
		}
		else
		{
			return;
		}
	}

	//�������̸� �̷��� �Ѵ�
	else if (m_pModelCom->m_iCurrentAnimationIndex == m_iChaseAnimationIndex)
	{

		m_fAccChaseTime += fTimeDelta;

		if (m_fAccChaseTime > 20.f)
		{
			m_bChase = false;
		
			return;
		}
	}
	else   //�����ߵ� �غ��ڼ��� �ƴϸ�
	{
		return;

	}


	CTransform* pTarget = static_cast<CTransform*>(m_pEnemy->Get_Component(TEXT("Com_Transform")));

	_vector vTargetPos = pTarget->Get_State(CTransform::STATE_POSITION);

	_vector vMyPos = m_pTransformCom->Get_State(CTransform::STATE_POSITION);



	_float vLength = GetVectorLength((vTargetPos - vMyPos));

	if (vLength < 0.5f) //0.3
	{
		m_bChase = false;


		//�׽�Ʈ
		m_fAccChaseTime = 0.f;
		m_fGravityTime = 0.185f;
		m_pModelCom->SetUp_Animation(m_iFallAnimationIndex, false);


		return;
	}


	m_vChaseDir = XMVector4Normalize(vTargetPos - vMyPos);
	Set_fImpulse(XMVectorGetX(m_vChaseDir) * 2.f);




	//�ִϸ��̼� �̿��� ���� �������� Ư�� ó�� �� �ʿ䰡 ����
	_float angle = atan2(XMVectorGetY(m_vChaseDir), XMVectorGetX(m_vChaseDir)) * (180.0 / 3.14);

	_float EffectAngle = angle;

	if (m_pChaseEffectLayer != nullptr && m_fAccChaseTime < 2.f)
	{
		/* ü�̽� 2P ���� */

		if (m_iLookDirection == 1)
			m_pChaseEffectLayer->Set_Copy_Layer_Rotation({ 0.f, 0.f, EffectAngle });
		else if (m_iLookDirection == -1)
			m_pChaseEffectLayer->Set_Copy_Layer_Rotation({ 0.f, 0.f, 180 - EffectAngle });


		_float xdegree = XMVectorGetX(m_vChaseDir);


		cout << angle << endl;

		_float closeness = 70.0f / (1.0f + abs(EffectAngle - 90));



	}

	angle = (angle + 90) * 0.5f;

	if (0 < angle && angle < 90)  //���� �����ʿ� �ִ� ���
	{
		//ĳ���� ���� ���� ���������� ����
		FlipDirection(1);
	}

	else if (angle > 90)   //���� ���� ���� �ִ� ��� 
	{
		//110�� ��� 70���� �ٲ�� �Ѵ�.    �ʰ��� 20.   90���κ��� �ʰ��� ��ŭ ���� ��
		// angle = 90 - (90 - angle);    =  180-angle;

		FlipDirection(-1);
		angle = 180 - angle;
	}
	else if (angle < 0)   //���� ���ʿ� �Ʒ��� �ִ� ��� 
	{
		FlipDirection(-1);
		angle = -angle;
	}


	//���� �ӵ��� ���� ������
	m_pTransformCom->Add_MoveVector(m_vChaseDir * m_fAccChaseTime * m_fAccChaseTime * 0.7f);


	//�ִϸ��̼��� position�� ������ �ǹ��� (1:1�� �ƴϰ� Ư��ó���Ǿ�����)
	Set_CurrentAnimationPositionJump(angle);



}








void CCharacter::Chase_Ready(_float fTimeDelta, _bool bNoReady)
{
	if (m_bChaseEnable == false || m_pModelCom->m_iCurrentAnimationIndex == m_iSparkingAnimationIndex)
		return;


	_short iCheck = Check_bCurAnimationisCanChase();
	if (iCheck == 0)
		return;
	else
		m_fAccChaseTime = iCheck * 0.01f;


	if (iCheck == 1 && bNoReady != true)
	{
		CEffect_Layer::COPY_DESC tDesc{};
		tDesc.pPlayertMatrix = m_pTransformCom->Get_WorldMatrixPtr();
		m_pEffect_Manager->Copy_Layer(TEXT("BurstR-01"), &tDesc);


	}

	m_bChaseEnable = false;

	if (m_pModelCom->m_iCurrentAnimationIndex == m_iAttack_LightLast)
	{
		m_bChaseStoping = false;

		Set_NextAnimation(m_iFallAnimationIndex, 5.f);

		m_bChase = true;

		m_fAccChaseTime = 0.5f;

	}


	if (Check_bCurAnimationisGroundMove() || m_pModelCom->m_iCurrentAnimationIndex == m_iJumpAnimationIndex || m_pModelCom->m_iCurrentAnimationIndex == m_iFallAnimationIndex)
	{

		m_bChaseStoping = false;

		m_pModelCom->SetUp_Animation(m_iFallAnimationIndex, false);

		m_bChase = true;

		if (XMVectorGetY(m_pTransformCom->Get_State(CTransform::STATE_POSITION)) < 0.5)
		{
			//m_pTransformCom->Add_Move({ 0.f,0.6f,0.f });

		}



	}
	else
	{
		Set_NextAnimation(m_iFallAnimationIndex, 1.f);
		m_bChase = true;
	}

}


void CCharacter::Chase_Grab(_float fTimeDelta)
{

	//����׿� ����ó��.  ��������� ������
	if (fTimeDelta > 1)
	{
		return;
	}

	//��� ������ ���� �������� ����
	if (m_pModelCom->m_fCurrentAnimPosition > 25)
	{




		return;
	}


	//�غ��ڼ��� �̷��� �Ѵ�.
	if (m_pModelCom->m_iCurrentAnimationIndex == m_iGrabReadyAnimationIndex)
	{
		//����Ʈ���� 1ȸ?
		if (m_fAccGrabTime == 0.f)
		{
			;
		}
		return;
	}

	//�غ��ڼ��� ����ڼ��� �ƴѵ� �� �Լ��� ���� ��� �ʱ�ȭ �� ����.
	else if (m_pModelCom->m_iCurrentAnimationIndex != m_iGrabAnimationIndex)
	{
		m_fAccGrabTime = 0.f;
		m_bGrab = false;
		return;
	}

	m_fAccGrabTime += fTimeDelta;








	CTransform* pTarget = static_cast<CTransform*>(m_pEnemy->Get_Component(TEXT("Com_Transform")));

	_vector vTargetPos = pTarget->Get_State(CTransform::STATE_POSITION);
	_vector vMyPos = m_pTransformCom->Get_State(CTransform::STATE_POSITION);


	m_vChaseDir = XMVector4Normalize(vTargetPos - vMyPos);
	Set_fImpulse(XMVectorGetX(m_vChaseDir) * 2.f);

	if (m_bGrab_Air == true)
	{
		m_vChaseDir = XMVectorSetX(m_vChaseDir, XMVectorGetX(m_vChaseDir) * 1.5f);

		m_pTransformCom->Add_MoveVector(m_vChaseDir * (15 - m_fAccChaseTime * m_fAccChaseTime * 10.f) * fTimeDelta);

	}
	else
	{
		m_vChaseDir = XMVectorSetY(m_vChaseDir, 0.f);
		m_pTransformCom->Add_MoveVector(m_vChaseDir * (15 - m_fAccChaseTime * m_fAccChaseTime * 10.f) * fTimeDelta);
	}



}


void CCharacter::Character_Attack_Grab(_float fTimeDelta)
{
	//�������ΰ��
	if (m_pModelCom->m_fCurrentAnimPosition > 120 && m_pModelCom->m_fCurrentAnimPosition < 138)
	{

		//��ٴ� Ƚ�� �Ҹ��Ҷ����� ����.   
		if (m_iGrabLoof > 0)
		{
			//cout << m_iGrabLoof << endl;
			m_iGrabLoof--;
			m_pModelCom->CurrentAnimationPositionJump(26.f);
		}
		else //�� ������ ���� ���¿� ���� ������ ����
		{
			m_bGrab = false;


			//��� ������ �������
			if (m_bGrabDraw)
			{

				//QTE ���� �ڷ� ����
				if (m_iQTE == 0)
				{

					Add_Move({ -0.4f * m_iLookDirection,0.3f });

					Set_Animation(m_iBreakFall_Air);
					Set_NextAnimation(m_iIdleAnimationIndex, 2.f);
					Set_ForcedGravityDown();

					Reset_AttackStep();
					Set_fImpulse({ -5.f * m_iLookDirection, 2.f });
				}

				//QTE �̰����� ����
				else if (m_iQTE == 1)
				{
					Add_Move({ -0.2f * m_iLookDirection,0.f });


					if (Get_fHeight() == 0)
						Set_Animation(m_iAttack_Heavy);
					else
					{
						Set_Animation(m_iAttack_Air3);
						Set_CurrentAnimationPositionJump(m_fAIrGrabEndAnimationPositon);
						Set_ForcedGravityDown();
					}
				}
				//QTE ������ �ĸ��� �غ�
				else if (m_iQTE == -1)
				{
					Set_AnimationStop(0.3f);
				}

				m_bCreateQTE = false;
				m_iQTE = -1;

			}
			else //���� ������
			{
				Add_Move({ -0.4f * m_iLookDirection,0.f });

				if (Get_fHeight() == 0)
					Set_Animation(m_iAttack_Heavy);
				else
				{
					Set_Animation(m_iAttack_Air3);
					Set_CurrentAnimationPositionJump(m_fAIrGrabEndAnimationPositon);
					Set_ForcedGravityDown();
				}
			}

			

		}
	}

}

void CCharacter::Grab_LateDraw()
{
	Add_Move({ 0.f,0.2f });
	Set_GrabLoofCount(1);
	Set_bGrabDraw(true);


	Set_Animation(m_iGrabAnimationIndex, false);
	Set_CurrentAnimationPositionJump(25.f);  	//ĳ���͸��� �ٸ���������


}


void CCharacter::Move(_float fTimeDelta)
{


	if (Check_bCurAnimationisGroundMove() || m_pModelCom->m_iCurrentAnimationIndex == m_iForwardDashAnimationIndex)
	{
		if (Check_bCurAnimationisGroundMove(m_iNextAnimation.first))
		{
			Reset_AttackCount();

			if (m_iPlayerTeam == 1)
				MoveKey1Team(fTimeDelta);
			else
				MoveKey2Team(fTimeDelta);


		}
	}
}

void CCharacter::MoveKey1Team(_float fTimeDelta)
{
	_short MoveKey = 0;
	if (m_pGameInstance->Key_Pressing(DIK_W) && m_bJumpLock == false)
	{
		//���� ����
		CEffect_Layer::COPY_DESC tDesc{};
		tDesc.pPlayertMatrix = m_pTransformCom->Get_WorldMatrixPtr();


		//���� ����
		m_pEffect_Manager->Copy_Layer(TEXT("Smoke01"), &tDesc);
		m_pEffect_Manager->Copy_Layer(TEXT("Smoke01_BackZ"), &tDesc);
		m_pEffect_Manager->Copy_Layer(TEXT("Smoke02"), &tDesc);
		m_pEffect_Manager->Copy_Layer(TEXT("Smoke02_Small"), &tDesc);
		m_pEffect_Manager->Copy_Layer(TEXT("Smoke04"), &tDesc);


		m_pTransformCom->Add_Move({ 0,0.3f,0 });

		Set_fJumpPower(3.f); 


		m_fGravityTime = 0.f;

		Set_Animation(m_iJumpAnimationIndex);


		if (m_pGameInstance->Key_Pressing(DIK_A))
		{
			Set_fImpulse(-5.f);
		}

		else if (m_pGameInstance->Key_Pressing(DIK_D))
		{
			Set_fImpulse(5.f);
		}

		//���� ����
		m_pGameInstance->Stop_Sound(CSound_Manager::SOUND_KEY_NAME::Common_Dash_Start_SFX);
		m_pGameInstance->Play_Sound(CSound_Manager::SOUND_KEY_NAME::Common_Jump_SFX, false, 1.f);

	}

	else if (m_pGameInstance->Key_Pressing(DIK_S))
	{
		if (m_pModelCom->m_iCurrentAnimationIndex != m_iForwardDashAnimationIndex)
		{
			m_pModelCom->SetUp_Animation(m_iCrouchAnimationIndex, true);
		}
	}

	else
	{
		if (m_pGameInstance->Key_Pressing(DIK_A))
		{
			MoveKey -= m_iLookDirection;
		}

		else if (m_pGameInstance->Key_Pressing(DIK_D))
		{
			MoveKey += m_iLookDirection;
		}


		if (MoveKey == -1)
		{
			m_pModelCom->SetUp_Animation(m_iBackWalkAnimationIndex, false);

			m_iNextAnimation.first = m_iIdleAnimationIndex;

			m_iNextAnimation.second = 100.f;

		}
		else if (MoveKey == 1)
		{
			if (m_pModelCom->m_iCurrentAnimationIndex == m_iForwardDashAnimationIndex)
			{
				m_pModelCom->SetUp_Animation(m_iForwardDashAnimationIndex, true);

				m_fAccSmokeTime += fTimeDelta;
				if (m_fAccSmokeTime > 0.2f)
				{
					m_fAccSmokeTime = 0.f;
					Character_Make_Effect(TEXT("Smoke_Run"));

				}

			}
			else
				m_pModelCom->SetUp_Animation(m_iForwardWalkAnimationIndex, false);

			m_iNextAnimation.first = m_iIdleAnimationIndex;
			m_iNextAnimation.second = 100.f;
		}
		else
		{
			if (m_pModelCom->m_iCurrentAnimationIndex == m_iForwardDashAnimationIndex)
			{
				m_pModelCom->SetUp_Animation(m_iForwardDashEndAnimationIndex, false);
				//������ ��� ������ ��
				m_pGameInstance->Stop_Sound(CSound_Manager::SOUND_KEY_NAME::Common_DownHook_Dash_SFX);
				CEffect_Layer::COPY_DESC tDesc{};
				tDesc.pPlayertMatrix = m_pTransformCom->Get_WorldMatrixPtr();
				m_pEffect_Manager->Copy_Layer(TEXT("Smoke03_Stop"), &tDesc);

			}
			else
				m_pModelCom->SetUp_Animation(m_iIdleAnimationIndex, true);

			m_iNextAnimation.first = m_iIdleAnimationIndex;
			m_iNextAnimation.second = 100.f;
		}
	}
}

void CCharacter::MoveKey2Team(_float fTimeDelta)
{
	_short MoveKey = 0;
	if (m_pGameInstance->Key_Pressing(DIK_UP) && m_bJumpLock == false)
	{

		CEffect_Layer::COPY_DESC tDesc{};
		tDesc.pPlayertMatrix = m_pTransformCom->Get_WorldMatrixPtr();
		//���� ����
		m_pEffect_Manager->Copy_Layer(TEXT("Smoke01"), &tDesc);
		m_pEffect_Manager->Copy_Layer(TEXT("Smoke01_BackZ"), &tDesc);
		m_pEffect_Manager->Copy_Layer(TEXT("Smoke02"), &tDesc);
		m_pEffect_Manager->Copy_Layer(TEXT("Smoke02_Small"), &tDesc);
		m_pEffect_Manager->Copy_Layer(TEXT("Smoke04"), &tDesc);

		m_pTransformCom->Add_Move({ 0,0.3f,0 });

		Set_fJumpPower(3.f); 


		Set_Animation(m_iJumpAnimationIndex);

		m_fGravityTime = 0.f;

		if (m_pGameInstance->Key_Pressing(DIK_LEFT))
		{
			Set_fImpulse(-5.f);
		}

		else if (m_pGameInstance->Key_Pressing(DIK_RIGHT))
		{
			Set_fImpulse(5.f);
		}

		//���� ����
		m_pGameInstance->Play_Sound(CSound_Manager::SOUND_KEY_NAME::Common_Dash_SFX, false, 1.f);
	}

	else if (m_pGameInstance->Key_Pressing(DIK_DOWN))
	{
		if (m_pModelCom->m_iCurrentAnimationIndex != m_iForwardDashAnimationIndex)
		{
			m_pModelCom->SetUp_Animation(m_iCrouchAnimationIndex, true);
		}
	}

	else
	{
		if (m_pGameInstance->Key_Pressing(DIK_LEFT))
		{
			MoveKey -= m_iLookDirection;
		}

		else if (m_pGameInstance->Key_Pressing(DIK_RIGHT))
		{
			MoveKey += m_iLookDirection;
		}


		if (MoveKey == -1)
		{
			m_pModelCom->SetUp_Animation(m_iBackWalkAnimationIndex, false);

			m_iNextAnimation.first = m_iIdleAnimationIndex;

			m_iNextAnimation.second = 100.f;

		}
		else if (MoveKey == 1)
		{
			if (m_pModelCom->m_iCurrentAnimationIndex == m_iForwardDashAnimationIndex)
			{
				m_pModelCom->SetUp_Animation(m_iForwardDashAnimationIndex, true);
				m_fAccSmokeTime += fTimeDelta;
				if (m_fAccSmokeTime > 0.2f)
				{
					m_fAccSmokeTime = 0.f;
					Character_Make_Effect(TEXT("Smoke_Run"));

				}
			}
			else
				m_pModelCom->SetUp_Animation(m_iForwardWalkAnimationIndex, false);

			m_iNextAnimation.first = m_iIdleAnimationIndex;
			m_iNextAnimation.second = 100.f;
		}
		else
		{
			if (m_pModelCom->m_iCurrentAnimationIndex == m_iForwardDashAnimationIndex)
			{
				m_pModelCom->SetUp_Animation(m_iForwardDashEndAnimationIndex, false);
				//������ ��� ������ ��

				CEffect_Layer::COPY_DESC tDesc{};
				tDesc.pPlayertMatrix = m_pTransformCom->Get_WorldMatrixPtr();
				m_pEffect_Manager->Copy_Layer(TEXT("Smoke03_Stop"), &tDesc);

			}
			else
				m_pModelCom->SetUp_Animation(m_iIdleAnimationIndex, true);

			m_iNextAnimation.first = m_iIdleAnimationIndex;
			m_iNextAnimation.second = 100.f;
		}
	}

}

void CCharacter::Reset_AttackCount()
{
	m_bChaseEnable = true;
	m_bAriDashEnable = true;
}

void CCharacter::Set_bInivisible(_bool bInvisible)
{
	m_bInvisible = bInvisible;
}



AttackColliderResult CCharacter::Set_Hit4(_uint eAnimation, AttackGrade eAttackGrade, AttackType eAttackType, _float fStunTime, _uint iDamage, _float fStopTime, _short iDirection, _float2 Impus, _bool bParticle)
{

	cout << "HP : " << m_iHP << " , Damage :" << iDamage << endl;

	if (m_pModelCom->m_iCurrentAnimationIndex == m_iBreakFall_Air || m_pModelCom->m_iCurrentAnimationIndex == m_iBreakFall_Ground || m_pModelCom->m_iCurrentAnimationIndex == m_iBound_Ground
		|| m_pModelCom->m_iCurrentAnimationIndex == m_iLayUp)
		return RESULT_MISS;

	//���ϻ���, ���ٴڿ� �������� �˻�
	else if (m_bHitGroundSmashed && Get_fHeight() == 0)
	{
		if (eAttackGrade != GRADE_ULTIMATE)
			return RESULT_MISS;
	}

	m_bInvisible = false;
	HitStopEffect();

	//���� ���°� �ƴϸ� ���� üũ
	if (m_bStun == false)
	{

		AttackColliderResult eResult = Guard_Check3(eAttackType);

		//�������� ������ iDirection  �ǰ��ڴ� ���ֺ����ϴ� �� �ݴ�.

		if (eResult == RESULT_GUARD)
		{


			if (m_pModelCom->m_iCurrentAnimationIndex == m_iCrouchAnimationIndex)
				Set_Animation(m_iGuard_CrouchAnimationIndex);

			else if (m_pModelCom->m_iCurrentAnimationIndex == m_iIdleAnimationIndex || m_pModelCom->m_iCurrentAnimationIndex == m_iBackWalkAnimationIndex)
				Set_Animation(m_iGuard_GroundAnimationIndex);

			else if (m_pModelCom->m_iCurrentAnimationIndex == m_iJumpAnimationIndex || m_pModelCom->m_iCurrentAnimationIndex == m_iFallAnimationIndex)
				Set_Animation(m_iGuard_AirAnimationIndex);


		

			CEffect_Layer::COPY_DESC tDesc{};
			tDesc.pPlayertMatrix = m_pTransformCom->Get_WorldMatrixPtr();
			//���� ����Ʈ
			switch (eAnimation)
			{
			case Client::HIT_LIGHT:
			case Client::HIT_CHASE:
				m_pEffect_Manager->Copy_Layer(TEXT("Guard01"), &tDesc);
				break;


			case Client::HIT_CROUCH_MEDIUM:
			case Client::HIT_MEDIUM:
				m_pEffect_Manager->Copy_Layer(TEXT("Guard02"), &tDesc);
				break;

			case Client::HIT_HEAVY:
			case Client::HIT_HEAVY_DOWN:
			case Client::HIT_KNOCK_AWAY_LEFT:
			case Client::HIT_KNOCK_AWAY_UP:
			case Client::HIT_KNOCK_AWAY_UP_GRAVITY:
			case Client::HIT_KNOCK_AWAY_LEFTDOWN:
			case Client::HIT_SPIN_AWAY_LEFTUP:
			case Client::HIT_SPIN_AWAY_UP:
				m_pEffect_Manager->Copy_Layer(TEXT("Guard03"), &tDesc);
				break;

			case Client::HIT_WALLBOUNCE:
			case Client::HIT_NONE:
			default:
				break;
			}


			Set_CurrentAnimationPositionJump(0.f);

			return RESULT_GUARD;

		}
		else if (eResult != RESULT_HIT)    //ȸ�ǳ� ��� ��� �ƴϸ� �ϴ� ����.   �� ���� ���߿� ���� ó��
			return eResult;


	}


	Set_bAura(false);

	m_bHit = TRUE;
	m_bStun = true;


	m_fMaxStunTime = fStunTime;

	if (Get_fHeight() > 1)
	{
		m_fMaxStunTime *= 1.1f;
	}

	m_fMaxStunTime *= 1.f - 0.01f * CBattleInterface_Manager::Get_Instance()->Get_HitAttackStep(m_iPlayerTeam);



	m_fAccStunTime = 0.f;

	Set_HitAnimation(eAnimation, Impus,bParticle);
	Set_AnimationStop(fStopTime);

	Set_bRedHP(true);

	if (iDirection == 1)
		FlipDirection(-1);
	else if (iDirection == -1)
		FlipDirection(1);

	//0�ΰ��� ������ ����


	m_iHP -= iDamage;  // ���⿡ �޺���� ���Ұ�


	m_iDebugComoboDamage += iDamage;


	if (m_iHP < 0)
	{
		m_iHP = 0;
	}

	return RESULT_HIT;
}





//void CCharacter::Set_HitAnimation(_uint eAnimation, _float2 Impus)
void CCharacter::Set_HitAnimation(_uint eAnimation, _float2 Impus, _bool bParticle)
{

	//�ϳ��� 0�� �ƴϸ� ����
	if (Impus.x != 0 || Impus.y != 0)
	{
		m_fImpuse = Impus;
	}


	m_bWallBounce = true;

	switch (eAnimation)
	{
	case Client::HitMotion::HIT_CHASE:  //break ����. ������
	{
		if (Get_fHeight() == 0)
			m_pTransformCom->Add_Move({ 0.f,0.3f,0.f });
	}

	case Client::HitMotion::HIT_LIGHT:
	{
		_vector position = m_pTransformCom->Get_State(CTransform::STATE_POSITION);
		_vector FinalPosition = XMVectorAdd(position, XMVectorSet(0.f, 1.f, 0.f, 0.f));
		if(bParticle)
			CParticle_Manager::Get_Instance()->Play(CParticle_Manager::COMMON_HIT_PARTICLE, FinalPosition);

		if (m_pModelCom->m_iCurrentAnimationIndex == m_iCrouchAnimationIndex)
		{
			Set_Animation(m_iHit_Crouch_AnimationIndex, false);
			m_fImpuse.y = 0;


			Set_CurrentAnimationPositionJump(0.f);
		}
		else if (Get_fHeight() > 0)
		{
			Set_Animation(m_iHit_Air_LightAnimationIndex, false);
			Set_ForcedGravityTime_LittleUp();
			Set_CurrentAnimationPositionJump(0.f);

		}
		else
		{
			Set_Animation(m_iHit_Stand_LightAnimationIndex, false);
			m_fImpuse.y = 0;
			Set_CurrentAnimationPositionJump(0.f);

		}
	}
	break;


	case Client::HitMotion::HIT_MEDIUM:
	{
		_vector position = m_pTransformCom->Get_State(CTransform::STATE_POSITION);
		_vector FinalPosition = XMVectorAdd(position, XMVectorSet(0.f, 1.f, 0.f, 0.f));
		if (bParticle)
			CParticle_Manager::Get_Instance()->Play(CParticle_Manager::COMMON_HIT_PARTICLE, FinalPosition);

		if (m_pModelCom->m_iCurrentAnimationIndex == m_iCrouchAnimationIndex)
		{
			Set_Animation(m_iHit_Crouch_AnimationIndex, false);
		}
		else if (Get_fHeight() > 0)
		{
			Set_Animation(m_iHit_Air_LightAnimationIndex, false);
			Set_ForcveGravityTime(0.05f);

		}
		else
			Set_Animation(m_iHit_Stand_LightAnimationIndex, false);

		Set_CurrentAnimationPositionJump(0.f);

	}
	break;
	case Client::HitMotion::HIT_HEAVY:
		break;
	case Client::HitMotion::HIT_HEAVY_DOWN:
	{
		_vector position = m_pTransformCom->Get_State(CTransform::STATE_POSITION);
		_vector FinalPosition = XMVectorAdd(position, XMVectorSet(0.f, 1.f, 0.f, 0.f));
		if (bParticle)
			CParticle_Manager::Get_Instance()->Play(CParticle_Manager::COMMON_HIT_PARTICLE, FinalPosition);

		if (Get_fHeight() > 0)
		{
			Set_Animation(m_iHit_Away_LeftDownAnimationIndex, false);
			Set_ForcveGravityTime(0.3f);
			Set_CurrentAnimationPositionJump(0.f);

		}
		else
		{
			Add_Move({ 0.f,0.1f });
			Set_Animation(m_iHit_Air_LightAnimationIndex, false);
			Set_ForcedGravityDown();

			Set_CurrentAnimationPositionJump(58.f);
		}


	}
	break;
	case Client::HitMotion::HIT_CROUCH_MEDIUM:
	{
		_vector position = m_pTransformCom->Get_State(CTransform::STATE_POSITION);
		_vector FinalPosition = XMVectorAdd(position, XMVectorSet(0.f, 1.f, 0.f, 0.f));
		if (bParticle)
			CParticle_Manager::Get_Instance()->Play(CParticle_Manager::COMMON_HIT_PARTICLE, FinalPosition);

		Set_Animation(m_iHit_Air_FallAnimationIndex);
		m_pTransformCom->Add_Move({ 0.f,0.3f,0.f });
		Set_ForcedGravityTime_LittleUp();
	}
	break;

	case Client::HitMotion::HIT_KNOCK_AWAY_LEFT_NONEBOUNDE:
	{
		_vector position = m_pTransformCom->Get_State(CTransform::STATE_POSITION);
		_vector FinalPosition = XMVectorAdd(position, XMVectorSet(0.f, 1.f, 0.f, 0.f));

		if (bParticle)
			CParticle_Manager::Get_Instance()->Play(CParticle_Manager::COMMON_HIT_PARTICLE, FinalPosition);

		m_bWallBounce = false;
		Set_Animation(m_iHit_Away_LeftAnimationIndex, false);
		if (Get_fHeight() == 0)
		{
			Add_Move({ 0.f,0.2f });
		}
		Set_ForcedGravityDown();

	}
	break;
	case Client::HitMotion::HIT_KNOCK_AWAY_LEFT:
	{
		_vector position = m_pTransformCom->Get_State(CTransform::STATE_POSITION);
		_vector FinalPosition = XMVectorAdd(position, XMVectorSet(0.f, 1.f, 0.f, 0.f));
		if (bParticle)
			CParticle_Manager::Get_Instance()->Play(CParticle_Manager::COMMON_HIT_PARTICLE, FinalPosition);

		m_bWallBounce = true;

		Set_Animation(m_iHit_Away_LeftAnimationIndex, false);
		if (Get_fHeight() == 0)
		{
			Add_Move({ 0.f,0.2f });
		}

	}
	break;
	case Client::HitMotion::HIT_KNOCK_AWAY_UP:
	{
		_vector position = m_pTransformCom->Get_State(CTransform::STATE_POSITION);
		_vector FinalPosition = XMVectorAdd(position, XMVectorSet(0.f, 1.f, 0.f, 0.f));
		if (bParticle)
			CParticle_Manager::Get_Instance()->Play(CParticle_Manager::COMMON_HIT_PARTICLE, FinalPosition);

		m_bAwayUpGravity = false;
		Set_Animation(m_iHit_Away_UpAnimationIndex, false);
		Set_ForcedGravityTime_LittleUp();
	}
	break;
	case Client::HitMotion::HIT_KNOCK_AWAY_UP_GRAVITY:
	{
		_vector position = m_pTransformCom->Get_State(CTransform::STATE_POSITION);
		_vector FinalPosition = XMVectorAdd(position, XMVectorSet(0.f, 1.f, 0.f, 0.f));
		if (bParticle)
			CParticle_Manager::Get_Instance()->Play(CParticle_Manager::COMMON_HIT_PARTICLE, FinalPosition);

		m_bAwayUpGravity = true;
		Set_Animation(m_iHit_Away_UpAnimationIndex, false);
		if (Get_fHeight() == 0)
		{
			Add_Move({ 0.f,0.3f });
		}
		Set_ForcveGravityTime(0.f);

	}
	break;
	case Client::HitMotion::HIT_KNOCK_AWAY_LEFTDOWN:
	{
		_vector position = m_pTransformCom->Get_State(CTransform::STATE_POSITION);
		_vector FinalPosition = XMVectorAdd(position, XMVectorSet(0.f, 1.f, 0.f, 0.f));
		if (bParticle)
			CParticle_Manager::Get_Instance()->Play(CParticle_Manager::COMMON_HIT_PARTICLE, FinalPosition);

		Set_Animation(m_iHit_Away_LeftDownAnimationIndex, false);

		Set_ForcveGravityTime(0.3f);

		m_fImpuse;
		_bool bDebug = true;
	}
	break;
	case Client::HitMotion::HIT_SPIN_AWAY_LEFTUP:
	{
		_vector position = m_pTransformCom->Get_State(CTransform::STATE_POSITION);
		_vector FinalPosition = XMVectorAdd(position, XMVectorSet(0.f, 1.f, 0.f, 0.f));
		if (bParticle)
			CParticle_Manager::Get_Instance()->Play(CParticle_Manager::COMMON_HIT_PARTICLE, FinalPosition);

		Set_Animation(m_iHit_Air_Spin_LeftUp, false);

		if (Get_fHeight() == 0)
			m_pTransformCom->Add_Move({ 0.f,0.3f,0.f });

		Set_ForcveGravityTime(0.f);

	}
	break;

	case Client::HitMotion::HIT_WALLBOUNCE:
	{
		_vector position = m_pTransformCom->Get_State(CTransform::STATE_POSITION);
		_vector FinalPosition = XMVectorAdd(position, XMVectorSet(0.f, 1.f, 0.f, 0.f));
		if (bParticle)
			CParticle_Manager::Get_Instance()->Play(CParticle_Manager::COMMON_HIT_PARTICLE, FinalPosition);

		Set_Animation(m_iHit_WallBouce);
	}
	break;
	case Client::HitMotion::HIT_NONE:
	{

	}
	break;

	case Client::HIT_SPIN_AWAY_UP:
	{
		_vector position = m_pTransformCom->Get_State(CTransform::STATE_POSITION);
		_vector FinalPosition = XMVectorAdd(position, XMVectorSet(0.f, 1.f, 0.f, 0.f));
		if (bParticle)
			CParticle_Manager::Get_Instance()->Play(CParticle_Manager::COMMON_HIT_PARTICLE, FinalPosition);

		Set_Animation(m_iHit_Air_Spin_Up);
	}
	break;
	default:
		break;
	}

}



void CCharacter::Set_AnimationStop(_float fStopTime)
{
	if (fStopTime != 0)
	{
		m_bAnimationLock = true;
	}
	m_fMaxAnimationLock = fStopTime;
	m_fAccAnimationLock = 0.f;

	m_pModelCom->Play_Animation(0.f);
}

void CCharacter::Set_UnlockAnimationStop()
{

	m_bAnimationLock = false;
	m_fMaxAnimationLock = 0.f;
	m_fAccAnimationLock = 0.f;
}

void CCharacter::Set_AnimationStopWithoutMe(_float fStopTime)
{
	CBattleInterface_Manager::Get_Instance()->Stop_CharacterWithoutMe(m_iPlayerTeam, m_ePlayerSlot - (m_iPlayerTeam - 1) * 2, fStopTime);
}






void CCharacter::Check_StunEnd()
{

}

void CCharacter::Stun_Shake()
{
	m_bStunShakeDirection = !m_bStunShakeDirection;

	m_pTransformCom->Add_Move({ 0.02f - m_bStunShakeDirection * (0.04f),0,0 });

}

void CCharacter::Update_AnimationLock(_float fTimeDelta)
{
	m_fAccAnimationLock += fTimeDelta;
	if (m_fAccAnimationLock > m_fMaxAnimationLock)
	{
		m_bAnimationLock = false;
		m_fAccAnimationLock = 0.f;
		m_fMaxAnimationLock = 0.f;
	}

}

void CCharacter::Update_StunImpus(_float fTimeDelta)
{

	//���߿��� �°� �����߿��� �߷� ����ϰ� ����
	if (m_pModelCom->m_iCurrentAnimationIndex == m_iHit_Air_LightAnimationIndex || m_pModelCom->m_iCurrentAnimationIndex == m_iHit_Air_FallAnimationIndex)
	{
		;
	}

	//������ ���ϰ� �¾������ ���ӵ� �ִ밪�� ������
	else if (Check_bCurAnimationisHitGround())
	{
		//�����϶� ������ �ȵ�
		if (m_fImpuse.x > 0.5f)
		{
			m_fImpuse.x = 0.5f;
		}
		else if (m_fImpuse.x < -0.5f)
		{
			m_fImpuse.x = -0.5f;
		}



		m_pTransformCom->Add_Move({ m_fImpuse.x * fTimeDelta, m_fImpuse.y * fTimeDelta, 0 });

	}

	//�� �ܿ� �°� ���ϰ� ���󰡴� �߿��� ���� ���ӵ��� ����
	else
	{
		//���� �ñ� �� �ִ� �������� �״�� ���ư���, �ƴѰŴ� �߷±��� ����. ���⼭ ó���Ϸ��ٰ� �߷����� ��, ������� �����?
		//���⼭ ó���ϸ� Height<0 �� ��찡 ó���� �ȵǼ� 1������ ���� ����

		if (m_bWallBounce)
			m_pTransformCom->Add_Move({ m_fImpuse.x * fTimeDelta, m_fImpuse.y * fTimeDelta, 0 });

		//���� ƨ�� �� �ִ� ����
		if (m_pModelCom->m_iCurrentAnimationIndex == m_iHit_Away_LeftAnimationIndex)
		{

			//�Ÿ��� �־����� ���� ������ ��
			if (Check_bWall())
			{

				if (m_bWallBounce)
				{
					Set_Animation(m_iHit_WallBouce);

					Character_Make_Effect(TEXT("Right_Wall_Crash"));

					CMain_Camera* mainCamera = static_cast<CMain_Camera*>(m_pGameInstance->Get_GameObject(LEVEL_GAMEPLAY, TEXT("Layer_Main_Camera")));
					mainCamera->StartCameraShake(0.5f, 0.2f);

					Set_AnimationStop(0.2f);

					Set_fImpulse({ m_iLookDirection * 4.f,0.1f - Get_fHeight() });


					Set_ForcveGravityTime(0.f);


					//���ο� ����
					m_fMaxStunTime = 1.f;
					m_fAccStunTime = 0.f;

					m_pGameInstance->Play_Sound(CSound_Manager::SOUND_KEY_NAME::Common_Crash_Air_Wall_SFX, false, 1.f);
				}
				else
				{
					

				}

			}

		}
	}


}

void CCharacter::Set_BreakFall_Ground()
{



	Set_Animation(m_iBreakFall_Ground, 2.f);
	Set_NextAnimation(m_iIdleAnimationIndex, 2.f);

	Set_bRedHP(false);
	Reset_AttackStep();


	if (inputBuffer.size() == 0)
	{
		inputBuffer.push_back(CInput(MOVEKEY_NEUTRAL, ATTACK_NONE));
	}
	DirectionInput iMoveKey = inputBuffer.back().direction;

	if (iMoveKey == MOVEKEY_UP || iMoveKey == MOVEKEY_UP_LEFT)
	{
		Set_fImpulse({ -3.f * m_iLookDirection,1.f });
		Set_ForcveGravityTime(0.f);
	}
	else if (iMoveKey == MOVEKEY_RIGHT)
	{
		Set_fImpulse({ 0.f , 0.1f });

		Set_ForcedGravityTime_LittleUp();
	}
	else if (iMoveKey == MOVEKEY_DOWN)
	{
		Set_Animation(m_iBound_Ground, 2.f);
		Set_NextAnimation(m_iLayUp, 2.f);
	}

	else //if (iMoveKey == MOVEKEY_LEFT)
	{
		Set_fImpulse({ -5.f * m_iLookDirection, 0.f });
		Set_ForcedGravityTime_LittleUp();
	}





}

void CCharacter::BreakFall_Air()
{
	if (m_bStun)
		return;

	//���ٴڿ��� ���� ������ ��ǵ� �����ǰ��̶� ���� �߰�
	if ((m_pModelCom->m_iCurrentAnimationIndex == m_iHit_Air_Spin_LeftUp || Check_bCurAnimationisAirHit()) && m_bHitGroundSmashed == false)
	{
		InputCommand();

		CInput InputKey = inputBuffer.back();

		if (InputKey.button != ATTACK_NONE)
		{
			Set_Animation(m_iBreakFall_Air);
			Set_NextAnimation(m_iIdleAnimationIndex, 2.f);
			Set_ForcedGravityDown();

			Reset_AttackStep();


			if (InputKey.direction == MOVEKEY_UP)
			{
				Set_fImpulse({ 0.f, 5.f });
			}
			else if (InputKey.direction == MOVEKEY_DOWN)
			{
				Set_fImpulse({ 0.f, -15.f });
			}

			else if (InputKey.direction == MOVEKEY_LEFT || InputKey.direction == MOVEKEY_UP_LEFT)
			{
				Set_fImpulse({ -10.f * m_iLookDirection, 1.f });
			}

			else //(InputKey.direction == MOVEKEY_RIGHT || InputKey.direction == MOVEKEY_UP_RIGHT)
			{
				Set_fImpulse({ 10.f * m_iLookDirection, 1.f });
			}
			Set_bRedHP(false);


		}

	}
}

void CCharacter::Set_bNoGravity(_bool bNoGravity, _float MaxfNoGravitySafeTime)
{
	m_bNoGravity = bNoGravity;
	m_fNoGravitySafeTime = 0.f;
	m_fMaxfNoGravitySafeTime = MaxfNoGravitySafeTime;

}

_uint CCharacter::Get_iHP()
{
	return m_iHP;
}

void CCharacter::Full_HP()
{
	m_iHP = 10000;
}

_bool CCharacter::Update_Tag_In(_float fTimeDelta)
{
	if (m_bTag_In == false)
		return false;



	m_fAccTag_InTime += fTimeDelta;
	Add_Move({ 0.f,1.f * m_fAccTag_InTime });

	m_pModelCom->Play_Animation(fTimeDelta);

	if (m_fAccTag_InTime > 0.3f)
	{
		m_bTag_In = false;

		Character_Make_Effect(TEXT("Moving_Line_Down"));
		m_pTransformCom->Set_State_Position({ -100.f,-100.f,0.f });
		m_pColliderCom->Update(m_pTransformCom->Get_State(CTransform::STATE_POSITION));

		return true;
	}

	return false;
}

_uint CCharacter::Get_NewCharacterslot()
{
	//¦���� +1  Ȧ���� -1
	if (m_ePlayerSlot % 2 == 0)
	{
		return 1;
	}
	else
		return 0;

}

void CCharacter::Gain_AttackStep(_ushort iStep)
{
	//�޺� �� ��ü�Ͽ� ������ �� ������ AttackStep�� ĳ���Ͱ� �ƴ� BattleInterface�� ������ �ֱ��

	if (m_iPlayerTeam == 1)
		CBattleInterface_Manager::Get_Instance()->Gain_HitAttackStep(iStep, 2);
	else
		CBattleInterface_Manager::Get_Instance()->Gain_HitAttackStep(iStep, 1);
}

void CCharacter::Gain_HitCount(_ushort iHit)
{

	if (iHit == 0)
		return;

	if (m_iPlayerTeam == 1)
		CBattleInterface_Manager::Get_Instance()->Gain_HitCount(iHit, 2);

	else
		CBattleInterface_Manager::Get_Instance()->Gain_HitCount(iHit, 1);

}


void CCharacter::Set_GroundSmash(_bool bSmash)
{
	m_bHitGroundSmashed = bSmash;
}



_float CCharacter::Get_DamageScale(_bool bUltimate)
{

	//������ ���� ����
	//Step Count	0	1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16	17 +
	//Next Hit		0%	10%	20% 30% 40% 50% 60% 70% 70% 70% 70% 75% 75% 75% 80% 80% 80% 85%
	//����������    1.0 0.9 0.8 ~               0.3 ~

	_uint iAttackStepCount;
	if (m_iPlayerTeam == 1)
		iAttackStepCount = CBattleInterface_Manager::Get_Instance()->Get_HitAttackStep(2);
	else
		iAttackStepCount = CBattleInterface_Manager::Get_Instance()->Get_HitAttackStep(1);


	_float fDamageScale;// = 1.f;

	if (iAttackStepCount <= 7)
	{
		fDamageScale = 1.0f - iAttackStepCount * 0.1f;
	}

	else if (iAttackStepCount <= 10)
	{
		fDamageScale = 0.3f;
	}

	else if (iAttackStepCount <= 13)
	{
		fDamageScale = 0.25f;
	}

	else if (iAttackStepCount <= 16)
	{
		fDamageScale = 0.2f;
	}
	else
	{
		fDamageScale = 0.15f;
	}



	//�ʻ���� ��� �ּ� 35%�� ����
	if (bUltimate)
	{
		if (fDamageScale < 0.35f)
			fDamageScale = 0.35f;

	}


	//������ ���� ����
	if (m_bSparking)
	{
		//fDamageScale *= 1.2f;	  //������ .  15%->16%   �ʹ� ������ ������ ���۹ݿ�.
		//fDamageScale += 0.2f;   //�տ���. �ʹ� ū��?  15%->35%
		fDamageScale += 0.1f;	  //Ÿ��
	}

	return fDamageScale * 0.7f;
}

void CCharacter::Set_GrabLoofCount(_ushort iLoofCount)
{
	m_iGrabLoof = iLoofCount;
}

AttackColliderResult CCharacter::Guard_Check3(AttackType eAttackType)
{
	//���� �߿��� � ���� ���͵� ������ ���� ����
	if (Check_bCurAnimationisGuard())
	{
		//���� �Ҹ�
		m_pGameInstance->Play_Sound(CSound_Manager::SOUND_KEY_NAME::Common_Medium_Guard_SFX, false, 1.f);
		return RESULT_GUARD;
	}


	if (eAttackType == ATTACKTYPE_GRAB_GROUND || eAttackType == ATTACKTYPE_GRAB_AIR || eAttackType == ATTACKTYPE_COMMANDGRAB)
	{
		return CompareGrabType3(eAttackType);
	}

	// �����̳� �ൿ�� ���� �ʰ� �������� ���� üũ.  ���� �ϰ��־����� ������ �������.
	if (Check_bCurAnimationisGroundMove() || m_pModelCom->m_iCurrentAnimationIndex == m_iFallAnimationIndex || m_pModelCom->m_iCurrentAnimationIndex == m_iJumpAnimationIndex)
	{


		if (m_iPlayerTeam == 1)
		{
			//���� �ִ� ������ �ݴ븦 ������ ���� ��,   �����ϴ� üũ (��� ����)
			if (m_iLookDirection == 1 && m_pGameInstance->Key_Pressing(DIK_A))
			{
				return CompareGuardType3(eAttackType);

			}

			else if (m_iLookDirection == -1 && m_pGameInstance->Key_Pressing(DIK_D))
			{
				return CompareGuardType3(eAttackType);
			}

			//�ȴ������� �������
			else
				return RESULT_HIT;
		}

		else
		{
			//���� �ִ� ������ �ݴ븦 ������ ���� ��,   �����ϴ� üũ (��� ����)
			if (m_iLookDirection == 1 && m_pGameInstance->Key_Pressing(DIK_LEFT))
			{
				return CompareGuardType3(eAttackType);
			}

			else if (m_iLookDirection == -1 && m_pGameInstance->Key_Pressing(DIK_RIGHT))
			{
				return CompareGuardType3(eAttackType);
			}

			//�ȴ������� �������
			else
				return RESULT_HIT;
		}
	}
	else
	{
		return RESULT_HIT;
	}
}

_bool CCharacter::CompareGuardType(AttackType eAttackType)
{
	//����� ������ ���� ����
	if (eAttackType == ATTACKTYPE_HIGH)
		return true;

	//�ߴ��� �ɾ������� ���� ����
	else if (eAttackType == ATTACKTYPE_MIDDLE)
	{
		if (m_pModelCom->m_iCurrentAnimationIndex == m_iCrouchAnimationIndex)
			return false;

		else
			return true;
	}

	//�ϴ��� �������� ���� ����.  �ȴ��ߵ� ���ԵǴµ�  �ٲ���Ѵ�.      �ɾ��ְų� �����̸� ����?
	else if (eAttackType == ATTACKTYPE_LOW)
	{

		if (m_pModelCom->m_iCurrentAnimationIndex == m_iCrouchAnimationIndex || Get_fHeight() > 0)
			return true;

		else
			return false;



	}

	//���� ����ư���� ��� ����
	else if (eAttackType == ATTACKTYPE_GRAB_GROUND)
	{

		//����� ���̰� 0�� �ƴϸ� ����
		if (Get_fHeight() != 0)
			return false;

		//��� ��ư���� ��������� ����.
		else if (m_iPlayerTeam == 1 && m_pGameInstance->Key_Pressing(DIK_O))
			return false;

		else if (m_iPlayerTeam == 2 && m_pGameInstance->Key_Pressing(DIK_NUMPAD9))
			return false;

		else
			return true;


		//��ġ���°� �ƴ� �ǰ��߿��� ���� ���� ���� �´°� ������

	}

	//���߿�����  ���߿� �ִ� ������׸� ����.
	else if (eAttackType == ATTACKTYPE_GRAB_AIR)
	{

		//��밡 ������ �ƴϸ� ����
		if (Get_fHeight() == 0)
			return false;

		//��밡 ��� ��ư���� ��������� ����.
		else if (m_iPlayerTeam == 1 && m_pGameInstance->Key_Pressing(DIK_O))
			return false;

		else if (m_iPlayerTeam == 2 && m_pGameInstance->Key_Pressing(DIK_NUMPAD9))
			return false;

		else
			return true;
	}

	//����� ���� ����  �����θ� ����.
	else if (eAttackType == ATTACKTYPE_COMMANDGRAB)
	{
		//�������� ��� �ִϸ��̼����� �ؾ��ϳ�? 
		if (Get_fHeight() > 0)
			return false;
		else
			return true;
	}



}

AttackColliderResult CCharacter::CompareGuardType3(AttackType eAttackType)
{
	//����� ������ ���� ����
	if (eAttackType == ATTACKTYPE_HIGH)
	{
		//���� �Ҹ�
		m_pGameInstance->Play_Sound(CSound_Manager::SOUND_KEY_NAME::Common_Medium_Guard_SFX, false, 1.f);
		return RESULT_GUARD;
	}

	//�ߴ��� �ɾ������� ���� ����
	else if (eAttackType == ATTACKTYPE_MIDDLE)
	{
		if (m_pModelCom->m_iCurrentAnimationIndex == m_iCrouchAnimationIndex)
			return RESULT_HIT;

		else
			return RESULT_GUARD;
	}

	//�ϴ��� �������� ���� ����.  �ȴ��ߵ� ���ԵǴµ�  �ٲ���Ѵ�.      �ɾ��ְų� �����̸� ����?
	else if (eAttackType == ATTACKTYPE_LOW)
	{
	
		if (m_pModelCom->m_iCurrentAnimationIndex == m_iCrouchAnimationIndex || Get_fHeight() > 0)
			return RESULT_GUARD;

		else
			return RESULT_HIT;



	}





}

AttackColliderResult CCharacter::CompareGrabType3(AttackType eAttackType)
{
	//���� ����ư���� ��� ����
	if (eAttackType == ATTACKTYPE_GRAB_GROUND)
	{

	
		//����� ���̰� 0�� �ƴϸ� ����
		if (Get_fHeight() != 0)
			return RESULT_MISS;

		//��� ��ư���� ��������� ����.
		else if (m_iPlayerTeam == 1 && m_pGameInstance->Key_Pressing(DIK_O) && (m_pModelCom->m_iCurrentAnimationIndex == m_iGrabReadyAnimationIndex || Check_bCurAnimationisGroundMove()))
			return RESULT_DRAW;

		else if (m_iPlayerTeam == 2 && m_pGameInstance->Key_Pressing(DIK_NUMPAD9) && (m_pModelCom->m_iCurrentAnimationIndex == m_iGrabReadyAnimationIndex || Check_bCurAnimationisGroundMove()))
			return RESULT_DRAW;

		else
			return RESULT_HIT;


		//��ġ���°� �ƴ� �ǰ��߿��� ���� ���� ���� �´°� ������
	}

	//���߿����� ���߿� �ִ� ������׸� ����.
	else if (eAttackType == ATTACKTYPE_GRAB_AIR)
	{
		

		//��밡 ������ �ƴϸ� ����
		if (Get_fHeight() == 0)
			return RESULT_MISS;

		//��밡 ��� ��ư���� ��������� ����.
		else if (m_iPlayerTeam == 1 && m_pGameInstance->Key_Pressing(DIK_O) && (m_pModelCom->m_iCurrentAnimationIndex == m_iGrabReadyAnimationIndex || Check_bCurAnimationisAirMove()))
			return RESULT_DRAW;

		else if (m_iPlayerTeam == 2 && m_pGameInstance->Key_Pressing(DIK_NUMPAD9) && (m_pModelCom->m_iCurrentAnimationIndex == m_iGrabReadyAnimationIndex || Check_bCurAnimationisAirMove()))
			return RESULT_DRAW;

		else
			return RESULT_HIT;
	}

	//����� ���� ���� �����θ� ����.
	else if (eAttackType == ATTACKTYPE_COMMANDGRAB)
	{
		if (Get_fHeight() > 0)
			return RESULT_MISS;
		else
		{
			//���� �������߸� �ƴϸ� ��
			if (m_pModelCom->m_iCurrentAnimationIndex == m_iHit_Air_LightAnimationIndex && m_pModelCom->m_fCurrentAnimPosition > 55.f && m_bHitGroundSmashed)
				return RESULT_MISS;
		}
		return RESULT_HIT;
	}
}

void CCharacter::Teleport_ToEnemy(_float OffsetX, _float OffsetY)
{

	_vector vTargetPos = static_cast<CTransform*>(m_pEnemy->Get_Component(TEXT("Com_Transform")))->Get_State(CTransform::STATE_POSITION);

	vTargetPos += {OffsetX* m_iLookDirection, OffsetY, 0, 0};

	m_pTransformCom->Set_State(CTransform::STATE_POSITION, vTargetPos);


}

void CCharacter::Set_Grab(_bool bAir)
{
	m_bGrab = true;
	m_bGrab_Air = bAir;
	m_bGrabDraw = false;
}

void CCharacter::Set_ChaseStop()
{
	m_bChase = false;

	m_fAccChaseTime = 0.f;


	m_fGravityTime = 0.185 - m_pModelCom->m_fCurrentAnimPosition * 0.002f;



}

void CCharacter::Set_ChaseStoping()
{
	m_bChaseStoping = true;

	if (m_pChaseEffectLayer != nullptr)
	{
		m_pChaseEffectLayer->m_bIsDoneAnim = true;
		m_pChaseEffectLayer = nullptr;
	}
}

_ushort CCharacter::Get_BreakFall_AirAnimationIndex()
{
	return m_iBreakFall_Air;
}

_ushort CCharacter::Get_JumpAirAnimationIndex()
{
	return m_iJumpAnimationIndex;
}

_bool CCharacter::Get_bStun()
{
	return m_bStun;
}



void CCharacter::Update_PreviousXPosition()
{
	m_fPreviousX = XMVectorGetX(m_pTransformCom->Get_State(CTransform::STATE_POSITION));
}

_float CCharacter::Get_fCalculatePreviousXPosition()
{
	return  m_fPreviousX - XMVectorGetX(m_pTransformCom->Get_State(CTransform::STATE_POSITION));
}

_float CCharacter::Get_fAbsCalculatePreviousXPosition()
{
	return  abs(m_fPreviousX - XMVectorGetX(m_pTransformCom->Get_State(CTransform::STATE_POSITION)));
}



void CCharacter::OnCollisionEnter(CCollider* other, _float fTimeDelta)
{

	//����߿��� ���ĵ� ��
	if (m_bGrabbed || m_bPlaying == false)
		return;


	if (m_iPlayerTeam == 1 && other->m_ColliderGroup == CCollider_Manager::COLLIDERGROUP::CG_2P_BODY)
	{
		
		CCharacter* pCharacter = static_cast<CCharacter*>(other->GetMineGameObject());

		
		_float fMyabsPos = fabsf(Get_fPositionX());
		_float fCharacterabsPos = fabsf(pCharacter->Get_fPositionX());

		if (fMyabsPos > 11.f || fCharacterabsPos > 11.f)
		{
			if (fMyabsPos < fCharacterabsPos)
			{
				//�󸶳� �и��°�? ��ģ��ŭ? 
				m_pTransformCom->Add_Move({ -m_iLookDirection * m_pColliderCom->Get_Overlap_X(other) ,0.f,0.f });
			}

		}

		if (m_bStun == true || Check_bCurAnimationisAirHit())
		{
			m_pTransformCom->Add_Move({ -m_iLookDirection * m_pColliderCom->Get_Overlap_X(other),0.f,0.f });
		}

		else 
		{



			//���� �ϳ� ���������� �� �켱, ���밪�� ���� ����� �и�.



			//�̵����� �������� �з��� .   
			_float CompareMoveX = pCharacter->Get_fAbsCalculatePreviousXPosition() - Get_fAbsCalculatePreviousXPosition();

			if (CompareMoveX > 0)
			{
				m_pTransformCom->Add_Move({ -m_iLookDirection * m_pColliderCom->Get_Overlap_X(other),0.f,0.f });
				Update_PreviousXPosition();

				pCharacter->Update_PreviousXPosition();
			}
			else if (CompareMoveX == 0)
			{
				

				//������ ĳ���Ͱ� ������ �� ĳ���Ͱ� �и���

				_float fEnemyHeight = pCharacter->Get_fHeight();
				_float fMyHeight = Get_fHeight();

				if (fMyHeight > fEnemyHeight)
				{
					m_pTransformCom->Add_Move({ -m_iLookDirection * m_pColliderCom->Get_Overlap_X(other),0.f,0.f });
				}
				//�������� �Ұ���,  �������� �Ʒ��� ó��

			}



		}

	}
	else if (m_iPlayerTeam == 2 && other->m_ColliderGroup == CCollider_Manager::COLLIDERGROUP::CG_1P_BODY)
	{
		

		CCharacter* pCharacter = static_cast<CCharacter*>(other->GetMineGameObject());
		//���ӵ��� �����ʴ�� �̵�?  ���� vs ���̸� ���� �켱?

		//1.���̺�.   ���� vs ���� ��� ���� �켱.  
		_float fMyabsPos = fabsf(Get_fPositionX());
		_float fCharacterabsPos = fabsf(pCharacter->Get_fPositionX());

		if (fMyabsPos > 11.f || fCharacterabsPos > 11.f)
		{
			if (fMyabsPos < fCharacterabsPos)
			{
				//�󸶳� �и��°�? ��ģ��ŭ? 
				m_pTransformCom->Add_Move({ -m_iLookDirection * m_pColliderCom->Get_Overlap_X(other) ,0.f,0.f });
			}

		}

		if (m_bStun == true || Check_bCurAnimationisAirHit())
		{
			m_pTransformCom->Add_Move({ -m_iLookDirection * m_pColliderCom->Get_Overlap_X(other),0.f,0.f });
		}



		//�� �� stun���°� �ƴϰ�, ����������
		else 
		{


			//���� �ϳ� ���������� �� �켱, ���밪�� ���� ����� �и�.

			_float fMyabsPos = fabsf(Get_fPositionX());
			_float fCharacterabsPos = fabsf(pCharacter->Get_fPositionX());

			if (fMyabsPos > 11.f || fCharacterabsPos > 11.f)
			{
				if (fMyabsPos < fCharacterabsPos)
				{
					//�󸶳� �и��°�? ��ģ��ŭ? 
					m_pTransformCom->Add_Move({ -m_iLookDirection * m_pColliderCom->Get_Overlap_X(other)  ,0.f,0.f });
				}

			}

			//�̵����� �������� �з��� . 
			//�з������� �� �̵����� ������� �ٽ� �о�� �ʰ� �̵����� ������Ʈ�������


			_float CompareMoveX = pCharacter->Get_fAbsCalculatePreviousXPosition() - Get_fAbsCalculatePreviousXPosition();

			if (CompareMoveX > 0)
			{
				m_pTransformCom->Add_Move({ -m_iLookDirection * m_pColliderCom->Get_Overlap_X(other),0.f,0.f });
				Update_PreviousXPosition();

				pCharacter->Update_PreviousXPosition();
			}
			else if (CompareMoveX == 0)
			{
				



			}



		}
	}
}


void CCharacter::OnCollisionStay(CCollider* other, _float fTimeDelta)
{



	//����߿��� ���ĵ� ��
	if (m_bGrabbed || static_cast<CCharacter*>(other->GetMineGameObject())->Get_bGrabbed() || m_bPlaying == false || m_bDebugInputLock)
		return;


	_bool debugA = true;
	if (m_iPlayerTeam == 1 && other->m_ColliderGroup == CCollider_Manager::COLLIDERGROUP::CG_2P_BODY)
	{
	
		CCharacter* pCharacter = static_cast<CCharacter*>(other->GetMineGameObject());

		//1. �ϴ� stun�γ� ������ �׳��� �з���
	
		_float fMyabsPos = fabsf(Get_fPositionX());
		_float fCharacterabsPos = fabsf(pCharacter->Get_fPositionX());

		if (fMyabsPos > 11.f || fCharacterabsPos > 11.f)
		{
			if (fMyabsPos < fCharacterabsPos)
			{
				//�󸶳� �и��°�? ��ģ��ŭ? 
				m_pTransformCom->Add_Move({ -m_iLookDirection * m_pColliderCom->Get_Overlap_X(other) ,0.f,0.f });

				if (pCharacter->Get_bStun())
				{
					m_fImpuse.x = 0;
				}
			}

		}

		if (m_bStun == true || Check_bCurAnimationisAirHit())
		{
			m_pTransformCom->Add_Move({ -m_iLookDirection * m_pColliderCom->Get_Overlap_X(other),0.f,0.f });
		}

		//�� �� stun���°� �ƴϰ�, ����������
		else //if (pCharacter->Get_fHeight() == 0 && Get_fHeight() == 0)
		{



			//���� �ϳ� ���������� �� �켱, ���밪�� ���� ����� �и�.



			//�̵����� �������� �з��� . 
			//�з������� �� �̵����� ������� �ٽ� �о�� �ʰ� �̵����� ������Ʈ�������
			_float CompareMoveX = pCharacter->Get_fAbsCalculatePreviousXPosition() - Get_fAbsCalculatePreviousXPosition();

			if (CompareMoveX > 0)
			{
				m_pTransformCom->Add_Move({ -m_iLookDirection * m_pColliderCom->Get_Overlap_X(other),0.f,0.f });
				Update_PreviousXPosition();

				pCharacter->Update_PreviousXPosition();
			}
			else if (CompareMoveX == 0)
			{

				_float fEnemyHeight = pCharacter->Get_fHeight();
				_float fMyHeight = Get_fHeight();

				if (fMyHeight > fEnemyHeight)
				{
					m_pTransformCom->Add_Move({ -m_iLookDirection * m_pColliderCom->Get_Overlap_X(other),0.f,0.f });
				}

			}



		}

	}
	else if (m_iPlayerTeam == 2 && other->m_ColliderGroup == CCollider_Manager::COLLIDERGROUP::CG_1P_BODY)
	{
		

		CCharacter* pCharacter = static_cast<CCharacter*>(other->GetMineGameObject());
		
		//1.���̺�.   ���� vs ���� ��� ���� �켱.    ���߿� �ִ� ĳ���� �з���
		_float fMyabsPos = fabsf(Get_fPositionX());
		_float fCharacterabsPos = fabsf(pCharacter->Get_fPositionX());

		if (fMyabsPos > 11.f || fCharacterabsPos > 11.f)
		{
			if (fMyabsPos < fCharacterabsPos)
			{
				//�󸶳� �и��°�? ��ģ��ŭ? 
				m_pTransformCom->Add_Move({ -m_iLookDirection * m_pColliderCom->Get_Overlap_X(other) ,0.f,0.f });

				if (pCharacter->Get_bStun())
				{
					m_fImpuse.x = 0;
				}
			}

		}

		if (m_bStun == true || Check_bCurAnimationisAirHit())
		{
			m_pTransformCom->Add_Move({ -m_iLookDirection * m_pColliderCom->Get_Overlap_X(other),0.f,0.f });
		}



		//�� �� stun���°� �ƴϰ�, ����������
		else 
		{


			//���� �ϳ� ���������� �� �켱, ���밪�� ���� ����� �и�.
			_float fMyabsPos = fabsf(Get_fPositionX());
			_float fCharacterabsPos = fabsf(pCharacter->Get_fPositionX());

			if (fMyabsPos > 11.f || fCharacterabsPos > 11.f)
			{
				if (fMyabsPos < fCharacterabsPos)
				{
					//�󸶳� �и��°�? ��ģ��ŭ? 
					m_pTransformCom->Add_Move({ -m_iLookDirection * m_pColliderCom->Get_Overlap_X(other)  ,0.f,0.f });
				}

			}

			//�̵����� �������� �з��� . 
			//�з������� �� �̵����� ������� �ٽ� �о�� �ʰ� �̵����� ������Ʈ�������


			_float CompareMoveX = pCharacter->Get_fAbsCalculatePreviousXPosition() - Get_fAbsCalculatePreviousXPosition();

			if (CompareMoveX > 0)
			{
				//m_pTransformCom->Add_Move({ m_iLookDirection * -0.05f,0.f,0.f });
				m_pTransformCom->Add_Move({ -m_iLookDirection * m_pColliderCom->Get_Overlap_X(other),0.f,0.f });
				Update_PreviousXPosition();

				pCharacter->Update_PreviousXPosition();
			}
			else if (CompareMoveX == 0)
			{

				_float fEnemyHeight = pCharacter->Get_fHeight();
				_float fMyHeight = Get_fHeight();

				if (fMyHeight > fEnemyHeight)
				{
					m_pTransformCom->Add_Move({ -m_iLookDirection * m_pColliderCom->Get_Overlap_X(other),0.f,0.f });
				}

			}



		}
	}

}

void CCharacter::OnCollisionExit(CCollider* other)
{
	_bool debugA = true;

}

_float CCharacter::Get_fPositionX()
{
	return 	XMVectorGetX(m_pTransformCom->Get_State(CTransform::STATE_POSITION));
}

_vector CCharacter::Get_vPosition()
{
	return m_pTransformCom->Get_State(CTransform::STATE_POSITION);
}


void CCharacter::Set_bGrabbed(_bool bGrabbed)
{
	m_bGrabbed = bGrabbed;

}

void CCharacter::Set_bGrabbedGravity(_bool bGrabbedGravity)
{
	m_bGrabbedGravity = bGrabbedGravity;
}

_bool CCharacter::Get_bGrabbed()
{
	return m_bGrabbed;
}

void CCharacter::Set_bRedHP(_bool bRedHP)
{
	if (bRedHP == true)
		m_tCharacterDesc.iHp = m_iHP;

	m_bRedHp = bRedHP;
	m_tCharacterDesc.bStun = m_bRedHp;
}

void CCharacter::Set_GrabAnimation()
{
	Set_Animation(m_iGrabAnimationIndex);
}

void CCharacter::Set_bBenishingAttack(_bool bBenishing)
{
	m_bBenishingAttack = bBenishing;
}

_bool CCharacter::Get_bBenishingAttack()
{
	return m_bBenishingAttack;
}

void CCharacter::Add_Move(_float2 fMovement)
{
	m_pTransformCom->Add_Move({ fMovement.x, fMovement.y,0 });
}

void CCharacter::Sparking_ON(_float fTimeDelta)
{

	//����ŷ�� �����ִ°�� �Ѵ��� Ȯ��
	if (m_bSparking == false)
	{
		if (m_iPlayerTeam == 1)
		{
			if (m_pGameInstance->Key_Down(DIK_R) && m_pGameInstance->Key_Pressing(DIK_O) && CBattleInterface_Manager::Get_Instance()->Get_bSparkingEnable(m_iPlayerTeam))
			{
				if (Check_bCurAnimationisGroundMove() || Check_bCurAnimationisAirMove() || m_pModelCom->m_iCurrentAnimationIndex == m_iGrabReadyAnimationIndex)
				{
					Set_Animation(m_iSparkingAnimationIndex);
					Set_NextAnimation(m_iIdleAnimationIndex, 3.f);
					CBattleInterface_Manager::Get_Instance()->Set_bSparkingEnable(false, m_iPlayerTeam);
					m_bSparking = true;
					Set_bAura(true);
					//�ο��� ���ǹ�

					_ushort iAliveMemberCount = CBattleInterface_Manager::Get_Instance()->Get_iAliveMemberCount(m_iPlayerTeam);


					if (m_pGameInstance->Key_Pressing(DIK_HOME))
						m_fMaxSparkingTime = 15.f;

					else if (iAliveMemberCount == 1)
						m_fMaxSparkingTime = 30.f;
					else
						m_fMaxSparkingTime = 15.f;



					//UI���� �Ҵٰ� �����ֱ�
					CUI_Manager::Get_Instance()->UsingAttckBuff(m_ePlayerSlot);
					Character_Make_Effect(TEXT("RO"), { 0.f,0.8f });

				}


			}

		}
		else
		{
			if (m_pGameInstance->Key_Down(DIK_PGDN) && m_pGameInstance->Key_Pressing(DIK_NUMPAD9) && CBattleInterface_Manager::Get_Instance()->Get_bSparkingEnable(m_iPlayerTeam))
			{
				if (Check_bCurAnimationisGroundMove() || Check_bCurAnimationisAirMove() || m_pModelCom->m_iCurrentAnimationIndex == m_iGrabReadyAnimationIndex)
				{
					Set_Animation(m_iSparkingAnimationIndex);
					Set_NextAnimation(m_iIdleAnimationIndex, 3.f);
					CBattleInterface_Manager::Get_Instance()->Set_bSparkingEnable(false, m_iPlayerTeam);
					m_bSparking = true;
					Set_bAura(true);

					//�ο��� ���ǹ�

					_ushort iAliveMemberCount = CBattleInterface_Manager::Get_Instance()->Get_iAliveMemberCount(m_iPlayerTeam);

					if (m_pGameInstance->Key_Pressing(DIK_HOME))
						m_fMaxSparkingTime = 15.f;

					if (iAliveMemberCount == 1)
						m_fMaxSparkingTime = 30.f;
					else
						m_fMaxSparkingTime = 15.f;

					//UI���� �Ҵٰ� �����ֱ�
					CUI_Manager::Get_Instance()->UsingAttckBuff(m_ePlayerSlot);
					Character_Make_Effect(TEXT("RO"),{0.f,0.8f});
				}
			}
		}
	}


}

void CCharacter::Sparking_TimeCount(_float fTimeDelta)
{
	//�̹� �����ִ°�� Ÿ�̸� üũ
	if (m_bSparking)
	{
		m_fAccSparkingTime += fTimeDelta;
		if (m_fAccSparkingTime > m_fMaxSparkingTime)
		{
			m_bSparking = false;
			m_fAccSparkingTime = 0.f;
			//UI���� ���ٰ� �����ֱ�
			CUI_Manager::Get_Instance()->UsingAttackDestroy(m_ePlayerSlot);
			Set_bAura(false);

		}
		//�߰��з�.
		else
			Set_bAura(true);

	}
}

_bool CCharacter::Get_bSparking()
{
	return m_bSparking;
}

void CCharacter::Gain_KiAmount(_ushort iKiAmount)
{
	CBattleInterface_Manager::Get_Instance()->Gain_KiGuage(iKiAmount, m_iPlayerTeam);
}

_bool CCharacter::Get_bCharacterDead()
{
	return m_bCharacterDead;
}

void CCharacter::Tag_KeyCheck()
{

	if (m_bAnimationLock)
		return;

	if (m_iPlayerTeam == 1)
	{


		//���븦 ������ 
		// ���ְų�,     ���� ������ ���� ���߽�   
		if (m_pGameInstance->Key_Down(DIK_F3) &&
			(m_pModelCom->m_iCurrentAnimationIndex == m_iIdleAnimationIndex ||
				((m_pModelCom->m_iCurrentAnimationIndex == m_iAttack_LightLast ||
					m_pModelCom->m_iCurrentAnimationIndex == m_iAttack_Heavy ||
					m_pModelCom->m_iCurrentAnimationIndex == m_iAttack_Crouch_Heavy) && m_bAttackBackEvent)))
		{
			
			Tag_In(0);
		}
	}
	else if (m_iPlayerTeam == 2)
	{
		if (m_pGameInstance->Key_Down(DIK_F4) &&
			(m_pModelCom->m_iCurrentAnimationIndex == m_iIdleAnimationIndex ||
				((m_pModelCom->m_iCurrentAnimationIndex == m_iAttack_LightLast ||
					m_pModelCom->m_iCurrentAnimationIndex == m_iAttack_Heavy ||
					m_pModelCom->m_iCurrentAnimationIndex == m_iAttack_Crouch_Heavy) && m_bAttackBackEvent))) {
			Tag_In(0);
		}
	}
}

void CCharacter::Tag_In(_ubyte iTagSlot)
{

	_bool bTag_Succes = false;





	//��밡 ĳ���� ��ü�� Enemy�� ������

	if (m_ePlayerSlot % 2 == 0)
	{
		bTag_Succes = CBattleInterface_Manager::Get_Instance()->Tag_CharacterAIO(m_iPlayerTeam, 1, m_pTransformCom->Get_State(CTransform::STATE_POSITION));
	}
	else
		bTag_Succes = CBattleInterface_Manager::Get_Instance()->Tag_CharacterAIO(m_iPlayerTeam, 0, m_pTransformCom->Get_State(CTransform::STATE_POSITION));


	if (bTag_Succes)
	{
		m_bPlaying = false;

		//�����̵� ����Ʈ
		m_bTag_In = true;
		m_fAccTag_InTime = 0.f;

		Set_Animation(m_iJumpAnimationIndex);
		m_pModelCom->Play_Animation(0.f);


		if (m_bSparking)
		{
			m_bSparking = false;

			//UI���� ���ٰ� �����ֱ�
			CUI_Manager::Get_Instance()->UsingAttackDestroy(m_ePlayerSlot);

		}

		if (m_iPlayerTeam == 1)
		{
			m_pUI_Manager->UsingChangeCharacher(static_cast<CUI_Define::PLAYER_SLOT>(0));
		}
		else if (m_iPlayerTeam == 2)
		{
			m_pUI_Manager->UsingChangeCharacher(static_cast<CUI_Define::PLAYER_SLOT>(3));
		}

		Set_bRedHP(false);
	}
}

void CCharacter::RegisterEnemy(CCharacter* pEnemy)
{
	m_pEnemy = pEnemy;
}

void CCharacter::pEnemyCheck()
{
	if (m_pEnemy == nullptr)
	{
		m_pEnemy = CBattleInterface_Manager::Get_Instance()->EnemyInitalize(m_iPlayerTeam);
	}

}


void CCharacter::Tag_Out(_vector vPosition)
{

	pEnemyCheck();

	//�����¼��� ����ϱ�
	CTransform* pEnemyTransform = static_cast<CTransform*>(m_pEnemy->Get_Component(TEXT("Com_Transform")));

	//�� ������ X�� üũ
	_float fX = XMVectorGetX(pEnemyTransform->Get_State(CTransform::STATE_POSITION) - vPosition);


	//���̰� ������ ���� ����. �� �� ���� �پ����� �� ���.
	if (fabsf(fX) > 0.05)
	{

		if (fX > 0)
		{
			FlipDirection(1);
		}
		else
		{
			FlipDirection(-1);
		}

	}


	m_pTransformCom->Set_State(CTransform::STATE_POSITION, vPosition + _vector{ -6.f * m_iLookDirection,0.5f,0.f,0.f });

	m_bPlaying = true;

	m_bTag_In = false;


	m_bAnimationLock = false;
	m_fMaxAnimationLock = 0.f;
	m_fAccAnimationLock = 0.f;


	Chase_Ready(0.4f, true);
	Chase2(0.3f);



}

void CCharacter::Set_AttackBackEvent(_bool bEvent)
{
	m_bAttackBackEvent = bEvent;
}

void CCharacter::Set_ReflectAttackBackEvent(_bool bEvent)
{
	m_bAttackBackEvent = bEvent;
	m_bReflect = bEvent;

	if (m_pModelCom->m_iCurrentAnimationIndex == m_iReflectAnimationIndex)
	{
		Set_CurrentAnimationPositionJump(25.f);


	}
}

_bool CCharacter::Get_bAttackBackEvent()
{
	return m_bAttackBackEvent;
}

void CCharacter::Set_bGrabDraw(_bool bGrabDraw)
{
	m_bGrabDraw = bGrabDraw;
}

_bool CCharacter::Check_bWall()
{


	if (m_bDynamicMove)
		return false;

	if (Get_fPositionX() < -12.f || Get_fPositionX() > 12.f || fabsf(Get_fPositionX() - m_pEnemy->Get_fPositionX()) > 8)
		return true;

	return false;

}

void CCharacter::Move_ForWall()
{
	//�� ������ �Ѿ�� �ʴ� �Լ�

	_float fPosX = Get_fPositionX();

	if (fPosX < -12.f)
	{
		Add_Move({ -fPosX - 12.f,0.f });
	}
	else if (fPosX > 12.f)
	{
		Add_Move({ -fPosX + 12.f,0.f });
	}
	else  //����� ���� �̻� ������ ������ �Ÿ��� 8 �̻��ΰŴ� �׺κ��� �˻����� ����
	{
		_float fEnemyfPosX = m_pEnemy->Get_fPositionX();

		//���� ����? �ڽ��� ��� ���̻� �������� ������
		if (fPosX < fEnemyfPosX)
		{
			Add_Move({ fEnemyfPosX - fPosX - 8.f,0.f });
		}
		else
		{
			Add_Move({ fEnemyfPosX - fPosX + 8.f,0.f });
		}

	}


}

void CCharacter::Set_bDynamicMove(_bool bDynamicMove)
{
	m_bDynamicMove = bDynamicMove;
}

void CCharacter::Update_Dying(_float fTimeDelta)
{

	//m_fMaxDyingTime �ٲٱ�


	if (m_bDying == false)
	{
		if (m_bGrabbed == true || m_bUnDying == true)
			return;

		if (m_iHP < 1)
		{
			m_bDying = true;

			if (m_bFinalSkillRoundEnd == false)
			{
				if (m_pModelCom->m_iCurrentAnimationIndex == m_iHit_Away_LeftAnimationIndex)
				{
					m_bDynamicMove = true;
					static_cast<CMain_Camera*>(*(m_pGameInstance->Get_Layer(LEVEL_GAMEPLAY, TEXT("Layer_Main_Camera")).begin()))->Set_DyingTeam(m_iPlayerTeam);

					_float2 fMapToImpulse = CMap_Manager::Get_Instance()->Active_DestructiveFinish(m_iLookDirection == -1 ? true : false);

					m_pEnemy->Set_bDynamicMove(true);

					XMStoreFloat4(&m_vDyingPosition, m_pTransformCom->Get_State(CTransform::STATE_POSITION));

					Set_fImpulse(fMapToImpulse);

					m_bDestructiveFinish = true;
					m_fMaxDyingTime = 5.f;
				}

				Set_AnimationStopWithoutMe(2.f);
				Set_AnimationStop(2.f);

				CUI_Manager::Get_Instance()->UsingCreateEndUI();

				_uint iModelAnimationIndex = m_pModelCom->m_iCurrentAnimationIndex;

				//������ �´¸��-> �׳� �����ɱ�
				//���߿��� �¾����� ���ٴڿ��� Bound �ϰ� ���Ͼ��


				if (iModelAnimationIndex == m_iHit_Stand_LightAnimationIndex || iModelAnimationIndex == m_iHit_Stand_MediumAnimationIndex || iModelAnimationIndex == m_iHit_Crouch_AnimationIndex)
				{
					Set_Animation(m_iDyingStandingAnimationIndex);
				}
				else
				{
					Set_NextAnimation(m_iBound_Ground, 200.f);
				}

				Set_bRedHP(false);
			}
			else  // �ʻ��� ������
			{
				m_fMaxDyingTime = 11.8f;


				//��밡 ������ ĳ���͸�
				if (m_bFinalSkillRoundEndSolo)
				{
					m_fMaxDyingTime = 5.f;
				}

			}




		}


	}

}

_bool CCharacter::Get_bDying()
{
	return m_bDying;
}

void CCharacter::Set_FinalSkillRoundEnd(_bool bSkillRoundEnd, _ushort iIndex)
{
	m_bFinalSkillRoundEnd = bSkillRoundEnd;

	//����ִ� ������ ������
	if (CBattleInterface_Manager::Get_Instance()->Check_survivor(m_iPlayerTeam, Get_NewCharacterslot()) == false)
	{
		m_bFinalSkillRoundEndSolo = true;
	}
}

void CCharacter::Play_WinAnimation()
{
	//�� ��ǥ�̵�, ī�޶��ƾ�, ui�� �ٸ� ĳ���͵� �Ⱥ��̰�


	_short iMySlot = Get_NewCharacterslot();

	if (iMySlot == 0)
		iMySlot = 1;
	else if (iMySlot == 1)
		iMySlot = 0;


	//�ٸ�ĳ���͵� �Ⱥ��̰�
	CBattleInterface_Manager::Get_Instance()->Set_InvisibleWithoutMe(m_iPlayerTeam, iMySlot);


	m_pTransformCom->Set_State(CTransform::STATE_POSITION, { -3.f,0,0,1.f });

	Set_Animation(m_iWinAnimationIndex);

	m_bDynamicMove = true;
	m_pEnemy->Set_bDynamicMove(true);

	FlipDirection(1);


	{
		//Change_Level_ForCharacter
		static_cast<CLevel_GamePlay*>(m_pGameInstance->Get_Level())->Change_Level_ForCharacter();
	}


	CUI_Manager::Get_Instance()->CutSceneUI(false);
}

void CCharacter::Play_NewRound_Loser()
{
	

	m_bGrabbed = true;
	m_bOpening = true;
	m_fMaxOpeningTime = 3.5f;

	m_pTransformCom->Set_State(CTransform::STATE_POSITION, { 0.f,0.5f, 0.f, 1.f });

	Set_Animation(m_iNextRound_RightHandAppear_Cutscene_AnimationIndex);




	CMain_Camera* pMainCamera = static_cast<CMain_Camera*>(m_pGameInstance->Get_GameObject(LEVEL_GAMEPLAY, TEXT("Layer_Main_Camera")));
	pMainCamera->Set_Player(this);

	if (m_iPlayerTeam == 1)
	{
		pMainCamera->Play(CMain_Camera::VIRTUAL_CAMERA_COMMON_APPEAR, 0, this, nullptr, true);
		FlipDirection(1);
	}
	else
	{
		pMainCamera->Play(CMain_Camera::VIRTUAL_CAMERA_COMMON_APPEAR, 0, this);
		FlipDirection(-1);
	}

	pMainCamera->StartCameraShake(2.f, 0.2f);
}

void CCharacter::Play_NewRound_Winner()
{
	m_bGrabbed = true;
	m_bOpening = true;
	m_fMaxOpeningTime = 3.5f;

	m_pTransformCom->Set_State(CTransform::STATE_POSITION, { 0.f,0.5f, 0.f, 1.f });


	Set_Animation(m_iNextRound_LeftHand_Cutscene_AnimationIndex);

	CMain_Camera* pMainCamera = static_cast<CMain_Camera*>(m_pGameInstance->Get_GameObject(LEVEL_GAMEPLAY, TEXT("Layer_Main_Camera")));
	pMainCamera->Set_Player(this);


	if (m_iPlayerTeam == 1)
	{
		FlipDirection(1);
	}
	else
		FlipDirection(-1);
}

void CCharacter::Update_Collider()
{
	m_pColliderCom->Update(m_pTransformCom->Get_State(CTransform::STATE_POSITION));
}

_bool CCharacter::Play_FirstOpening()
{

	Set_AnimationStopWithoutMe(30.f);
	Set_AnimationStop(1.f);

	m_bDynamicMove = true;
	m_bGrabbed = true;
	Set_Animation(m_iStartAnimatonIndex);

	//����׿���, �׽�Ʈ�ϰ� ���߿� ���� ��
	Set_CurrentAnimationPositionJump(0.f);

	m_bInvisible = false;


	//ĳ���͸��� ī�޶� �б�ó��
	CMain_Camera* mainCamera = static_cast<CMain_Camera*>(m_pGameInstance->Get_GameObject(LEVEL_GAMEPLAY, TEXT("Layer_Main_Camera")));
	switch (m_eCharacterIndex)
	{
	case Client::PLAY_GOKU:
		if (m_iPlayerTeam == 1)
		{
			mainCamera->Play(CMain_Camera::VIRTUAL_CAMERA_GOKU_ENTRY, 0, this);
		}
		else if (m_iPlayerTeam == 2)
		{
			//Flip����
			mainCamera->Play(CMain_Camera::VIRTUAL_CAMERA_GOKU_ENTRY, 1, this, nullptr, true);
		}
		break;
	case Client::PLAY_FRN:
		if (m_iPlayerTeam == 1)
		{
			mainCamera->Play(CMain_Camera::VIRTUAL_CAMERA_FRIEZA_ENTRY, 0, this);
		}
		else if (m_iPlayerTeam == 2)
		{
			mainCamera->Play(CMain_Camera::VIRTUAL_CAMERA_FRIEZA_ENTRY, 1, this, nullptr, true);
		}
		break;
	case Client::PLAY_21:
		if (m_iPlayerTeam == 1)
		{
			mainCamera->Play(CMain_Camera::VIRTUAL_CAMERA_21_ENTRY, 0, this);

		}
		else if (m_iPlayerTeam == 2)
		{
			mainCamera->Play(CMain_Camera::VIRTUAL_CAMERA_21_ENTRY, 1, this, nullptr, true);
		}
		break;
	case Client::PLAY_HIT:
		if (m_iPlayerTeam == 1)
		{
			mainCamera->Play(CMain_Camera::VIRTUAL_CAMERA_HIT_ENTRY, 0, this);
		}
		else if (m_iPlayerTeam == 2)
		{
			mainCamera->Play(CMain_Camera::VIRTUAL_CAMERA_HIT_ENTRY, 1, this, nullptr, true);
		}
		break;
	}


	return true;
}


void CCharacter::Update_Opening(_float fTimeDelta)
{
	if (m_bOpening == false)
		return;


	m_fAccOpeningTime += fTimeDelta;

	if (m_fAccOpeningTime > m_fMaxOpeningTime)
	{
		m_fAccOpeningTime = 0.f;
		m_bOpening = false;
		m_bGrabbed = false;
		m_bDynamicMove = false;

		Add_Move({ (-1.5f + m_iPlayerTeam) * 0.5f,0.f });
		Set_Animation(m_iBreakFall_Air);
		Set_fImpulse({ (-1.5f + m_iPlayerTeam) * 8.f, 4.f });
	}


}

void CCharacter::Set_bPlaying(_bool bPlaying)
{
	m_bPlaying = bPlaying;
}


void CCharacter::Set_StopAllAttackObject(_float fStopTime)
{
	CBattleInterface_Manager::Get_Instance()->Stop_AllAttackObject(fStopTime);
}

_bool CCharacter::Get_bReflect()
{
	return m_bReflect;
}



void CCharacter::Set_bBeReflecting(_short iDirection)
{
	m_bBeReflecting = true;
	m_fAccBeReflectingTime = 0.f;

}

_bool CCharacter::Update_BeReflecting(_float fTimeDelta)
{
	if (m_bBeReflecting)
	{
		m_fAccBeReflectingTime += fTimeDelta;



		Add_Move({ (0.3f - m_fAccBeReflectingTime) * m_iLookDirection * -20.f * fTimeDelta, 0.f });

		if (m_fAccBeReflectingTime > 0.3)
		{
			m_bBeReflecting = false;
			m_fAccBeReflectingTime = 0.f;
		}

	}

	return true;
}

void CCharacter::Set_bFinalSkillQTE(_bool bFinalSkillQTE)
{
	m_iQTE = bFinalSkillQTE;
}

CHARACTER_INDEX CCharacter::Get_eCharacterIndex()
{
	return m_eCharacterIndex;
}




void CCharacter::Set_AnimationMoveXZ(_bool bValue)
{
	m_pModelCom->m_bNoMoveXZ = bValue;
	m_bCinematic_NoMoveXZ = bValue;


}

void CCharacter::Set_bHeavySkill(_bool bHeavySkill)
{
	m_bHeavySkill = bHeavySkill;
}

void CCharacter::Set_bForcedAura(_bool bForcedAura)
{
	m_bForcedAura = bForcedAura;
}

void CCharacter::Set_bAura(_bool bAura)
{
	if (bAura != m_bAura)
	{
		if (m_bAura == true && bAura == false)
		{
			LIGHT_DESC* pLight_Desc = m_pRenderInstance->Get_LightDesc(CLight_Manager::LIGHT_PLAYER, 0, m_strName);
			pLight_Desc->vAuraColor = _float4(0.f, 0.f, 0.f, 0.f);
			m_bAura = false;
		}

		else if (m_bAura == false && bAura == true)
		{
			LIGHT_DESC* pLight_Desc = m_pRenderInstance->Get_LightDesc(CLight_Manager::LIGHT_PLAYER, 0, m_strName);
			pLight_Desc->vAuraColor = m_fAuraColor;
			m_bAura = true;
		}
	}



}

void CCharacter::Set_fAuraColor(_float4 fAuraColor)
{
	LIGHT_DESC* pLight_Desc = m_pRenderInstance->Get_LightDesc(CLight_Manager::LIGHT_PLAYER, 0, m_strName);
	pLight_Desc->vAuraColor = fAuraColor;
}

void CCharacter::Reset_AttackStep()
{
	CBattleInterface_Manager::Get_Instance()->Reset_HitCount(m_iPlayerTeam);
	CBattleInterface_Manager::Get_Instance()->Reset_HitAttackStep(m_iPlayerTeam);

	Set_bRedHP(false);
}

void CCharacter::Update_NoEventAnimationLoof(_float fTimeDelta)
{

	_float fTickPersecond = m_pModelCom->m_Animations[0]->m_fTickPerSecond;
	_float fAfterAnimationPostion = m_pModelCom->m_fCurrentAnimPosition + fTickPersecond * fTimeDelta;


	if (fAfterAnimationPostion >= m_fNoEventLoofMaxPosition)
	{
		fAfterAnimationPostion = m_fNoEventLoofMinPosition + fmod(fAfterAnimationPostion - m_fNoEventLoofMaxPosition, m_fNoEventLoofMaxPosition - m_fNoEventLoofMinPosition);
		Set_CurrentAnimationPositionJump(fAfterAnimationPostion);
	}
	else
		m_pModelCom->Play_Animation_Lick(fTimeDelta);


}

void CCharacter::Update_ForcedEventAnimationLoof(_float fTimeDelta)
{

	_float fPrePosition = m_pModelCom->m_fCurrentAnimPosition;

	_float fTickPersecond = m_pModelCom->m_Animations[0]->m_fTickPerSecond;
	_float fAfterAnimationPostion = m_pModelCom->m_fCurrentAnimPosition + fTickPersecond * fTimeDelta;


	if (fAfterAnimationPostion >= m_fNoEventLoofMaxPosition)
	{
		fAfterAnimationPostion = m_fNoEventLoofMinPosition + fmod(fAfterAnimationPostion - m_fNoEventLoofMaxPosition, m_fNoEventLoofMaxPosition - m_fNoEventLoofMinPosition);
		Set_CurrentAnimationPositionJump(fAfterAnimationPostion);
	}
	else
		m_pModelCom->Play_Animation_Lick(fTimeDelta);


	_float fCurPosition = m_pModelCom->m_fCurrentAnimPosition;

	//����ϰ� ��������� �̺�Ʈ�� ����ϰ� ���
	if (fPrePosition < fCurPosition)
		ProcessEventsBetweenFrames2(0, m_pModelCom->m_iCurrentAnimationIndex, fPrePosition, fCurPosition);
	else if (fPrePosition > fCurPosition) //�ѹ��� �� ��� �ּҺ��� ���� ���̿� �ִ� �̺�Ʈ ���
	{
		ProcessEventsBetweenFrames2(0, m_pModelCom->m_iCurrentAnimationIndex, m_fNoEventLoofMinPosition, fCurPosition);
	}
}

void CCharacter::Update_NoEventTime(_float fTimeDelta)
{
	m_fAccNoEventLoofTime += fTimeDelta;
	if (m_fAccNoEventLoofTime > m_fMaxNoEventLoofTime)
	{
		m_bNoEventLoofAnimation = false;
		m_fAccNoEventLoofTime = 0.f;
		m_fMaxNoEventLoofTime = 0.f;

		m_bForcedEventLoofAnimation = false;
	}
}

void CCharacter::Set_NoEventAnmationLoof(_float fMinPosition, _float fMaxPosition, _float fTime)
{
	m_bNoEventLoofAnimation = true;
	m_fNoEventLoofMinPosition = fMinPosition;
	m_fNoEventLoofMaxPosition = fMaxPosition;
	m_fAccNoEventLoofTime = 0.f;
	m_fMaxNoEventLoofTime = fTime;

}

void CCharacter::Set_EventAnmationLoof(_float fMinPosition, _float fMaxPosition, _float fTime)
{
	m_bNoEventLoofAnimation = true;
	m_fNoEventLoofMinPosition = fMinPosition;
	m_fNoEventLoofMaxPosition = fMaxPosition;
	m_fAccNoEventLoofTime = 0.f;
	m_fMaxNoEventLoofTime = fTime;

	m_bForcedEventLoofAnimation = true;
}

_float4x4 CCharacter::Make_BoneMatrix(char* BoneName)
{

	_float4x4 tFinalMatrix;
	XMStoreFloat4x4(&tFinalMatrix, XMLoadFloat4x4(m_pModelCom->Get_BoneMatrixPtr(BoneName)) * XMLoadFloat4x4(m_pTransformCom->Get_WorldMatrixPtr()));


	return tFinalMatrix;

}

void CCharacter::Character_Make_BoneEffect_Offset(char* BoneName, _wstring strEffectName, _float2 fOffset, _bool bFlipDirection)
{

	_float4x4 Result4x4;

	if (fOffset.x == 0 && fOffset.y == 0 && bFlipDirection == false)
	{
		Result4x4 = Make_BoneMatrix(BoneName);
	}
	else
	{
		Result4x4 = Make_BoneMatrix_Offset(BoneName, fOffset, bFlipDirection);
	}

	CEffect_Layer::COPY_DESC tDesc{};
	tDesc.pPlayertMatrix = &Result4x4;
	tDesc.pTransformCom = m_pTransformCom;
	CEffect_Manager::Get_Instance()->Copy_Layer(strEffectName, &tDesc);


}

_float4x4 CCharacter::Make_BoneMatrix_Offset(char* BoneName, _float2 fOffset, _bool bFlipDirection)
{
	XMMATRIX matrixBody = XMLoadFloat4x4(m_pTransformCom->Get_WorldMatrixPtr());
	

	//Body�� x��ǥ
	matrixBody.r[3].m128_f32[0] += fOffset.x * m_iLookDirection;
	matrixBody.r[3].m128_f32[1] += fOffset.y;


	if (bFlipDirection)
		matrixBody.r[0].m128_f32[0] *= -1.f;

	_float4x4 tFinalMatrix;
	XMStoreFloat4x4(&tFinalMatrix, XMLoadFloat4x4(m_pModelCom->Get_BoneMatrixPtr(BoneName)) * matrixBody);

	return tFinalMatrix;
}

CEffect_Layer* CCharacter::Character_Make_BoneEffect(char* BoneName, _wstring strEffectName)
{
	CEffect_Layer::COPY_DESC tDesc{};
	tDesc.pPlayertMatrix = m_pModelCom->Get_BoneMatrixPtr(BoneName);
	tDesc.pTransformCom = m_pTransformCom;
	return CEffect_Manager::Get_Instance()->Copy_Layer_AndGet(strEffectName, &tDesc);
}






_float4x4 CCharacter::Character_Make_Matrix(_float2 fOffset, _bool bFlipDirection)
{
	_vector vPos = m_pTransformCom->Get_State(CTransform::STATE_POSITION);
	_float3 fPos;
	XMStoreFloat3(&fPos, vPos);



	_matrix ovelapMatrix = XMMatrixScaling((_float)Get_iDirection() * (1 - (2 * bFlipDirection)), 1.f, 1.f) * XMMatrixTranslation(fPos.x + (fOffset.x * Get_iDirection()), fPos.y + fOffset.y, fPos.z);

	XMFLOAT4X4 Result4x4;
	XMStoreFloat4x4(&Result4x4, ovelapMatrix);

	return Result4x4;



}






CEffect_Layer* CCharacter::Character_Make_Effect(_wstring strEffectName, _float2 fOffset, _bool bFlipDirection)
{


	_float4x4 Result4x4;

	if (fOffset.x == 0 && fOffset.y == 0 && bFlipDirection == false)
	{
		XMStoreFloat4x4(&Result4x4, m_pTransformCom->Get_WorldMatrix());
	}
	else
		Result4x4 = Character_Make_Matrix(fOffset, bFlipDirection);


	CEffect_Layer::COPY_DESC tDesc{};
	tDesc.pPlayertMatrix = &Result4x4;

	return CEffect_Manager::Get_Instance()->Copy_Layer_AndGet(strEffectName, &tDesc);

}



void CCharacter::Character_Create_Distortion(_float3 vDir, _float2 vOffSetPos, _float2 vOffSetScale, _float fLifeTime)
{
	_float4 fPos{};
	XMStoreFloat4(&fPos, m_pTransformCom->Get_State(CTransform::STATE_POSITION));
	m_pRenderInstance->Create_HitDistortion(fPos, { vDir.x * m_iLookDirection, vDir.y, vDir.z }, vOffSetPos, vOffSetScale, fLifeTime);

}

void CCharacter::Character_Create_Distortion(_float3 vDir, _float3 vOffSetPos, _float2 vOffSetScale, _float fLifeTime)
{
	_float4 fPos{};
	XMStoreFloat4(&fPos, m_pTransformCom->Get_State(CTransform::STATE_POSITION));
	fPos.z += vOffSetPos.z;

	m_pRenderInstance->Create_HitDistortion(fPos, { vDir.x * m_iLookDirection, vDir.y, vDir.z }, { vOffSetPos.x, vOffSetPos.y }, vOffSetScale, fLifeTime);

}

void CCharacter::Set_LoofAnimationCreate(_wstring strEffectName, _float fMaxTime, _float fPeriodTime, _float2 fOffset, _bool bFlipDirection)
{

	m_bEffectLoofCreate = true;;
	m_fAccEffectLoofCreateTime = 0.f;
	m_fMaxEffectLoofCreateTime = fMaxTime;
	m_strEffectLoofCreateName = strEffectName;


	m_fAccEffectPeriodTime = fPeriodTime;
	m_fMaxEffectPeriodTime = fPeriodTime;

	m_fEffectLoofCreateOffset = fOffset;
	m_bEffectLoofCreateFlip = bFlipDirection;

}

void CCharacter::Update_LoofAnimationCreate(_float fTimeDelta)
{
	if (m_bEffectLoofCreate)
	{
		m_fAccEffectLoofCreateTime += fTimeDelta;
		if (m_fAccEffectLoofCreateTime > m_fMaxEffectLoofCreateTime)
		{
			m_bEffectLoofCreate = false;
			m_fAccEffectLoofCreateTime = 0.f;
		}

		m_fAccEffectPeriodTime += fTimeDelta;
		if (m_fAccEffectPeriodTime > m_fMaxEffectPeriodTime)
		{
			m_fAccEffectPeriodTime = 0.f;
			Character_Make_Effect(m_strEffectLoofCreateName, m_fEffectLoofCreateOffset, m_bEffectLoofCreateFlip);
		}
	}

}

const _float4x4* CCharacter::Get_pTransformMatrix()
{
	return m_pTransformCom->Get_WorldMatrixPtr();

}






_uint* CCharacter::Get_pAnimationIndex()
{
	return &(m_pModelCom->m_iCurrentAnimationIndex);
}

_short CCharacter::Get_iAnimationIndex()
{
	return m_pModelCom->m_iCurrentAnimationIndex;
}



_bool CCharacter::Check_bCurAnimationisAirHit(_uint iAnimation)
{
	_uint iModelIndex = iAnimation;

	if (iAnimation == 1000)
		iModelIndex = m_pModelCom->m_iCurrentAnimationIndex;



	//if (iModelIndex == m_iHit_Air_LightAnimationIndex || iModelIndex == m_iHit_Away_LeftAnimationIndex || iModelIndex == m_iHit_Away_UpAnimationIndex || iModelIndex == m_iHit_Air_FallAnimationIndex)
	if (iModelIndex == m_iHit_Air_LightAnimationIndex || iModelIndex == m_iHit_Air_FallAnimationIndex)
	{
		return true;
	}

	return false;
}

_bool CCharacter::Check_bCurAnimationisHitAway(_uint iAnimation)
{
	_uint iModelIndex = iAnimation;

	if (iAnimation == 1000)
		iModelIndex = m_pModelCom->m_iCurrentAnimationIndex;



	if (iModelIndex == m_iHit_Away_LeftAnimationIndex || iModelIndex == m_iHit_Away_UpAnimationIndex || iModelIndex == m_iHit_Away_LeftDownAnimationIndex)
	{
		return true;
	}

	return false;
}

_bool CCharacter::Check_bCurAnimationisHitGround(_uint iAnimation)
{
	_uint iModelIndex = iAnimation;

	if (iAnimation == 1000)
		iModelIndex = m_pModelCom->m_iCurrentAnimationIndex;



	if (iModelIndex == m_iHit_Stand_LightAnimationIndex || iModelIndex == m_iHit_Stand_MediumAnimationIndex || iModelIndex == m_iHit_Crouch_AnimationIndex)
	{
		return true;
	}

	return false;
}

_bool CCharacter::Check_bCurAnimationisChase(_uint iAnimation)
{
	_uint iModelIndex = iAnimation;

	if (iAnimation == 1000)
		iModelIndex = m_pModelCom->m_iCurrentAnimationIndex;



	if (iModelIndex == m_iChaseAnimationIndex || m_bChase)
	{
		return true;
	}

	return false;
}

_bool CCharacter::Check_bCurAnimationisReflect(_uint iAnimation)
{

	//if (m_pModelCom->m_iCurrentAnimationIndex == m_iReflectAnimationIndex )
	//{
	//	return true;
	//}

	return m_bReflect;

	return false;
}

_bool CCharacter::Check_bCurAnimationisGuard(_uint iAnimation)
{
	//_uint iModelIndex = iAnimation;
	//if (iAnimation == 1000)

	_uint iModelIndex = iModelIndex = m_pModelCom->m_iCurrentAnimationIndex;


	if (iModelIndex == m_iGuard_AirAnimationIndex || iModelIndex == m_iGuard_CrouchAnimationIndex || iModelIndex == m_iGuard_GroundAnimationIndex)
	{
		return true;
	}

	return false;
}

_bool CCharacter::Check_bCurAnimationisGrab(_uint iAnimation)
{
	//_uint iModelIndex = iAnimation;
	//if (iAnimation == 1000)

	_uint iModelIndex = iModelIndex = m_pModelCom->m_iCurrentAnimationIndex;


	if (iModelIndex == m_iGrabAnimationIndex || iModelIndex == m_iGrabReadyAnimationIndex)
	{
		return true;
	}

	return false;
}

_bool CCharacter::Check_bCurAnimationisGroundSmash(_uint iAnimation)
{
	_uint iModelIndex = iModelIndex = m_pModelCom->m_iCurrentAnimationIndex;


	if (m_bHitGroundSmashed)
		return true;

	if (iModelIndex == m_iHit_Air_LightAnimationIndex && m_pModelCom->m_fCurrentAnimPosition >= 55)
	{
		return true;
	}

	return false;
}


void CCharacter::Set_NextAnimation(_uint iAnimationIndex, _float fLifeTime, _float fAnimationPosition)
{
	m_iNextAnimation.first = iAnimationIndex;
	m_iNextAnimation.second = fLifeTime;


	m_fNextAnimationCurrentPosition = fAnimationPosition;

}

void CCharacter::AttackNextMoveCheck()
{
	if (m_iNextAnimation.first != m_iIdleAnimationIndex)
	{


		if (m_bNextAnimationGravityEvent) 	//Set_Animation���� ���� �־����
		{
			m_bNextAnimationGravityEvent = false;
			Set_ForcedGravityTime_LittleUp();
		}

		Set_Animation(m_iNextAnimation.first);

		m_iNextAnimation.first = m_iIdleAnimationIndex;
		m_iNextAnimation.second = 1000.f;

		if (m_fNextAnimationCurrentPosition != 0)
		{
			m_pModelCom->CurrentAnimationPositionJump(m_fNextAnimationCurrentPosition);
			m_fNextAnimationCurrentPosition = 0.f;
		}

	}
}

void CCharacter::AnimeEndNextMoveCheck()
{

	Set_Animation(m_iNextAnimation.first);

	m_iNextAnimation.first = m_iIdleAnimationIndex;
	m_iNextAnimation.second = 1000.f;



}

void CCharacter::Set_Animation(_uint iAnimationIndex, _bool bloof)
{



	m_bMotionPlaying = true;

	m_bAttackBackEvent = false;

	if (iAnimationIndex == m_iIdleAnimationIndex)
		m_pModelCom->SetUp_Animation(iAnimationIndex, true);
	else
		m_pModelCom->SetUp_Animation(iAnimationIndex, bloof);

	if (iAnimationIndex == m_iHit_Air_LightAnimationIndex || iAnimationIndex == m_iHit_Stand_LightAnimationIndex || iAnimationIndex == m_iHit_Stand_MediumAnimationIndex)
	{
		m_pModelCom->CurrentAnimationPositionJump(0.f);
	}

}

void CCharacter::Set_IdleAnimation()
{
	Set_Animation(m_iIdleAnimationIndex);
}

void CCharacter::Gravity(_float fTimeDelta)
{




	if (m_bChase == true)
	{
		return;
	}

	if (m_bNoGravity == true)
	{
		m_fNoGravitySafeTime += fTimeDelta;

		if (m_fNoGravitySafeTime > m_fMaxfNoGravitySafeTime)
		{
			m_bNoGravity = false;
			m_fNoGravitySafeTime = 0.f;
		}

		return;
	}

	_vector vPos = m_pTransformCom->Get_State(CTransform::STATE_POSITION);
	_float fHeight = XMVectorGetY(vPos);



	if (fHeight > 0)
	{



		// IDLE�̸� ���� �ϰ�������� ����


		if (m_bStun)
		{

		}


		else if (Check_bCurAnimationisGroundMove())
			m_pModelCom->SetUp_Animation(m_iFallAnimationIndex, false);


		// if (Check_bCurAnimationisGroundMove())
		//m_pModelCom->SetUp_Animation(m_iFallAnimationIndex, false);

		//�߷� ver1 �϶��� �׻� ���ؾ� �ڿ������ 2������ �ƴ�
		//if (m_fGravityTime < m_fJumpPower)
		//{
		//	m_fGravityTime += fTimeDelta;
		//}


		//ver1  �������� �ʹ� �սǵս���  ������4 ���̽�.
		//_float fGravity = ( - 0.3f * (m_fGravityTime - m_fJumpPower) * (m_fGravityTime - m_fJumpPower) + 2) *0.03f;

		//ver  ������ �ӵ����� �� �������� ��ü������ ����, ������ 3 ���̽�.
		//_float fGravity = (-0.7f * (m_fGravityTime - m_fJumpPower) * (m_fGravityTime - m_fJumpPower) + 4) * 0.03f;

		//Ver3  ������ 3
		//_float fGravity = (-0.7f * (m_fGravityTime - m_fJumpPower) * (m_fGravityTime - m_fJumpPower) + 4) * 0.05f;


		//1~3¥�� ���� �Ǽ��� Gravity �ι��� ȣ����.  

		//Ver4 ������3.   ������ ���� *0.1 ��� *0.08�ص� �ڿ�������
		//_float fGravity = (-0.7f * (m_fGravityTime - m_fJumpPower) * (m_fGravityTime - m_fJumpPower) + 4) * 0.1;
		_float fGravity = (-0.7f * (2 * m_fGravityTime - m_fJumpPower) * (2 * m_fGravityTime - m_fJumpPower) + 4) * 0.1;

		if (m_pModelCom->m_iCurrentAnimationIndex == m_iHit_Away_LeftDownAnimationIndex && fGravity < 0)
		{
			_bool bDebug = true;

		}



		//��������, �����߿� �߷� ���� 
		//if (m_pModelCom->m_iCurrentAnimationIndex == m_iFallAnimationIndex || m_pModelCom->m_iCurrentAnimationIndex == m_iJumpAnimationIndex)

		//���� ��������� �´��� �߰�
		//if (m_pModelCom->m_iCurrentAnimationIndex == m_iFallAnimationIndex || m_pModelCom->m_iCurrentAnimationIndex == m_iJumpAnimationIndex || m_pModelCom->m_iCurrentAnimationIndex == m_iHit_Air_LightAnimationIndex)

		//���� �⺻������ �߰�( ��ź����)
		//if (m_pModelCom->m_iCurrentAnimationIndex == m_iFallAnimationIndex || m_pModelCom->m_iCurrentAnimationIndex == m_iJumpAnimationIndex ||
		//	m_pModelCom->m_iCurrentAnimationIndex == m_iAttack_Air1 || m_pModelCom->m_iCurrentAnimationIndex == m_iAttack_Air2 || m_pModelCom->m_iCurrentAnimationIndex == m_iAttack_Air3 ||
		//	m_pModelCom->m_iCurrentAnimationIndex == m_iHit_Air_LightAnimationIndex)
		if (m_pModelCom->m_iCurrentAnimationIndex == m_iFallAnimationIndex || m_pModelCom->m_iCurrentAnimationIndex == m_iJumpAnimationIndex ||
			m_pModelCom->m_iCurrentAnimationIndex == m_iAttack_Air1 || m_pModelCom->m_iCurrentAnimationIndex == m_iAttack_Air2 || m_pModelCom->m_iCurrentAnimationIndex == m_iAttack_Air3 ||
			m_pModelCom->m_iCurrentAnimationIndex == m_iAttack_AirUpper || m_pModelCom->m_iCurrentAnimationIndex == m_iBreakFall_Ground ||
			m_pModelCom->m_iCurrentAnimationIndex == m_iHit_Air_Spin_LeftUp || m_pModelCom->m_iCurrentAnimationIndex == m_iHit_Air_Spin_Up ||
			m_pModelCom->m_iCurrentAnimationIndex == m_iHit_WallBouce ||
			Check_bCurAnimationisAirHit() || Check_bCurAnimationisHitAway() || m_pModelCom->m_iCurrentAnimationIndex == m_iGuard_AirAnimationIndex
			|| Check_bCurAnimationisHalfGravityStop())
		{




			//���Ž� �������� �ð� ������ ����.   ���� �Ʒ��� �߿��� ������ ����
			// 
			//�ٸ� ���� ���ñ�� ���� ���Ž��� ��� ����
			if (m_pModelCom->m_iCurrentAnimationIndex == m_iHit_Away_LeftAnimationIndex && m_bWallBounce == false)
			{
				m_fGravityTime += fTimeDelta;
				m_pTransformCom->Add_Move({ m_fImpuse.x * fTimeDelta,-fGravity,0 });
			}

			else if (m_pModelCom->m_iCurrentAnimationIndex == m_iHit_Away_UpAnimationIndex && m_bAwayUpGravity)
			{
				m_fGravityTime += fTimeDelta;
				m_pTransformCom->Add_Move({ m_fImpuse.x * fTimeDelta,-fGravity,0 });
			}

			else if (Check_bCurAnimationisHitAway() || m_pModelCom->m_iCurrentAnimationIndex == m_iAttack_AirUpper || (m_bAttackGravity == false && Check_bCurAnimationisHalfGravityStop()))
			{
				;
			}

			else if (m_fGravityTime * 2.f < m_fJumpPower)
			{
				m_fGravityTime += fTimeDelta;

				//�Ͻ������ؼ� ���⼭ �Ѿ�� ���� Ȯ ������ �� ����.  ����ó���ؼ� �ð��� �ѹ� ��?
			}
			else if (m_fGravityTime * 2.f > m_fJumpPower)
			{
				m_fGravityTime = m_fJumpPower * 0.5f;
			}


			//�Ϻ� ������ ���  Gravity �� false�� �߷� ���� ����
			if (m_bAttackGravity == false && Check_bCurAnimationisHalfGravityStop())
			{
				;
			}

			else if (m_pModelCom->m_iCurrentAnimationIndex == m_iBreakFall_Ground || m_pModelCom->m_iCurrentAnimationIndex == m_iHit_Air_Spin_LeftUp || m_pModelCom->m_iCurrentAnimationIndex == m_iHit_WallBouce)
			{
				m_pTransformCom->Add_Move({ m_fImpuse.x * fTimeDelta,-fGravity + m_fImpuse.y * fTimeDelta,0 });
			}
			else if (Check_bCurAnimationisHitAway() == false && m_pModelCom->m_iCurrentAnimationIndex != m_iAttack_AirUpper)
				m_pTransformCom->Add_Move({ m_fImpuse.x * fTimeDelta,-fGravity,0 });


		}
		else
		{

			//�߷�Ver2 ���� ó��.  �ö󰡴ٰ� ���ݶ����� ����µ�  ���� ������ �ٽ� �ö󰡴°� �̻��ؼ� ó��
			//if (fGravity < 0 && m_fGravityTime < m_fJumpPower)


			if (m_pModelCom->m_iCurrentAnimationIndex == m_iBreakFall_Air)
			{
				m_pTransformCom->Add_Move({ m_fImpuse.x * fTimeDelta, m_fImpuse.y * fTimeDelta,0.f });
			}



			if (m_bAttackGravity == true)
			{

				if (fGravity < 0 && m_fGravityTime * 2 < m_fJumpPower)
				{
					m_fGravityTime += fTimeDelta;
				}

			}
			//���Ӹ� �ް� �߷��� ���δ� �ڵ�. ��� ��ǿ� ���ӵ� �����Ҳ� �ƴϸ� ������ �̻��ϰ� ����.
			//m_pTransformCom->Add_Move({ m_fImpuse * fTimeDelta,0,0 });


		}



	}




	//�̺κ��� Gravity�� �ٸ��� �и��ص������� 

	//	else if (fHeight <0)   //�� else if ������ ����� �ȳ�. �Ǽ���������
	//if (fHeight <0)
	if (fHeight < 0)
	{
		//m_pEffect_Manager->Copy_Layer(TEXT("Smoke01"), m_pTransformCom->Get_WorldMatrixPtr());
		//m_pEffect_Manager->Copy_Layer(TEXT("Smoke01_BackZ"), m_pTransformCom->Get_WorldMatrixPtr());
		//m_pEffect_Manager->Copy_Layer(TEXT("Smoke02"), m_pTransformCom->Get_WorldMatrixPtr());
		//m_pEffect_Manager->Copy_Layer(TEXT("Smoke02_Small"), m_pTransformCom->Get_WorldMatrixPtr());
		//m_pEffect_Manager->Copy_Layer(TEXT("Smoke04"), m_pTransformCom->Get_WorldMatrixPtr());

		//m_pEffect_Manager->Copy_Layer(TEXT("Smoke05"), m_pTransformCom->Get_WorldMatrixPtr());
		//m_pEffect_Manager->Copy_Layer(TEXT("Aura01"), m_pTransformCom->Get_WorldMatrixPtr());

		//m_pEffect_Manager->Copy_Layer(TEXT("BurstU-2"), m_pTransformCom->Get_WorldMatrixPtr());

		//m_pEffect_Manager->Copy_Layer(TEXT("Smoke03_Stop"), m_pTransformCom->Get_WorldMatrixPtr());

		//m_pEffect_Manager->Copy_Layer(TEXT("Smoke_Run"), m_pTransformCom->Get_WorldMatrixPtr());

		//m_pEffect_Manager->Copy_Layer(TEXT("Guard03"), m_pTransformCom->Get_WorldMatrixPtr());

		//if (m_pModelCom->m_iCurrentAnimationIndex == m_iFallAnimationIndex || Check_bCurAnimationisAirAttack())

		if (m_iPlayerTeam == 1)
		{
			_bool bDebug = true;
		}


		//����
		CEffect_Layer::COPY_DESC tDesc{};
		tDesc.pPlayertMatrix = m_pTransformCom->Get_WorldMatrixPtr();
		m_pEffect_Manager->Copy_Layer(TEXT("Smoke05"), &tDesc);
		m_pEffect_Manager->Copy_Layer(TEXT("Aura01"), &tDesc);


		if (m_pModelCom->m_iCurrentAnimationIndex == m_iFallAnimationIndex || Check_bCurAnimationisAirAttack() || m_pModelCom->m_iCurrentAnimationIndex == m_iBreakFall_Air)
		{
			m_pModelCom->SetUp_Animation(m_iIdleAnimationIndex, true);

			Set_fGravityTime(0.f);
			//Set_fJumpPower(0.f);
			Set_fImpulse(0.f);

			Set_NextAnimation(m_iIdleAnimationIndex, 2.f);
			m_bAriDashEnable = true;
			m_bChaseEnable = true;
			Set_bAttackGravity(true);

			if (m_bJumpLock == false)
			{
				m_bJumpLock = true;
			}

			//����� �����ؼ� �� ����
			m_pGameInstance->Play_Sound(CSound_Manager::SOUND_KEY_NAME::Common_Dash_SFX, false, 1.f);
		}
		else if (Check_bCurAnimationisAirHit() || Check_bCurAnimationisHitAway())
		{
			//m_pModelCom->SetUp_Animation(m_iIdleAnimationIndex, true);

			if (m_bHitGroundSmashed)
			{
				Set_Animation(m_iHit_Air_LightAnimationIndex);
				m_pModelCom->CurrentAnimationPositionJump(55.f);
				Set_NextAnimation(m_iBound_Ground, 5.f);

				//m_bHitGroundSmashed = false;
				//m_pTransformCom->Add_Move({ -1 * fTimeDelta * m_iLookDirection, 0, 0 });

				//��� ������� ��
				m_pGameInstance->Play_Sound(CSound_Manager::SOUND_KEY_NAME::Smash_Hit_SFX, false, 1.f);
				CMain_Camera* mainCamera = static_cast<CMain_Camera*>(m_pGameInstance->Get_GameObject(LEVEL_GAMEPLAY, TEXT("Layer_Main_Camera")));
				mainCamera->StartCameraShake(0.3f, 0.2f);
			}
			else
			{
				//m_pModelCom->SetUp_Animation(m_iBound_Ground, false);

				//���
				//Set_Animation(m_iBreakFall_Ground, 2.f);
				//Set_fImpulse({ 5.f,0.f });
				Set_BreakFall_Ground();

				Set_NextAnimation(m_iIdleAnimationIndex, 2.f);
				//Set_fGravityTime(0.f);

				//õõ�� ������� ��
				m_pGameInstance->Play_Sound(CSound_Manager::SOUND_KEY_NAME::Smash_Hit_SFX, false, 1.f);
			}


			if (m_pModelCom->m_iCurrentAnimationIndex != m_iBreakFall_Ground)
			{
				Set_fGravityTime(0.f);
				Set_fImpulse(0.f);
			}


			m_bAriDashEnable = true;
			Set_bAttackGravity(true);

			if (m_bJumpLock == false)
			{
				m_bJumpLock = true;
			}

		}
		if (m_bHitGroundSmashed == false)
		{
			m_bStun = false;
			m_fAccStunTime = 0.f;
		}
		//m_pTransformCom->Add_Move({ 0,-fHeight,0 });

		if (m_bDying)
		{
			Set_Animation(m_iBound_Ground, false);
		}

		m_pTransformCom->Set_State(CTransform::STATE_POSITION, { XMVectorGetX(vPos),0.f,XMVectorGetZ(vPos),1.f });

	}

	else if (fHeight == 0)
	{

		if (m_bDying)
			return;

		if (m_pModelCom->m_iCurrentAnimationIndex == m_iFallAnimationIndex || m_pModelCom->m_iCurrentAnimationIndex == m_iJumpAnimationIndex)
		{
			m_pModelCom->SetUp_Animation(m_iIdleAnimationIndex, true);

			Set_fGravityTime(0.f);
			//Set_fJumpPower(0.f);
			Set_fImpulse(0.f);
			m_bAriDashEnable = true;
			Set_bAttackGravity(true);
		}

		//else if (m_bHitGroundSmashed == true && m_pModelCom->m_iCurrentAnimationIndex == m_iHit_Air_LightAnimationIndex)
		//{
		//	if (m_bMotionPlaying == false)
		//	{
		//		Set_Animation(m_iBreakFall_Ground, 2.f);
		//		Set_NextAnimation(m_iIdleAnimationIndex, 2.f);
		//		m_bHitGroundSmashed = false;
		//	}
		//
		//}
		//else if (m_bHitGroundSmashed == true && m_pModelCom->m_iCurrentAnimationIndex == m_iHit_Air_LightAnimationIndex)
		else if (m_bHitGroundSmashed == true)
		{
			if (m_pModelCom->m_iCurrentAnimationIndex == m_iHit_Air_LightAnimationIndex)
			{
				//�ٴڿ� ����������� ���� ����.  ���⿡ �̻��ϴٸ� �¾��� �ÿ� FlipDirection �ؾ��Ѵ�
				m_pTransformCom->Add_Move({ -2 * fTimeDelta * m_iLookDirection, 0, 0 });

				m_fAccSmokeTime += fTimeDelta;
				if (m_fAccSmokeTime > 0.2f)
				{
					m_fAccSmokeTime = 0.f;


					Character_Make_Effect(TEXT("Smoke_Run"), { -0.2f,0.f }, true);

				}


				if (m_bMotionPlaying == false)
				{
					Set_Animation(m_iBound_Ground, 2.f);

					//Set_NextAnimation(m_iBreakFall_Ground, 2.f);
					//
					//if (inputBuffer.back() == CInput{ MOVEKEY_UP, ATTACK_LIGHT })
					//{
					//	m_fImpuse = { -3.f * m_iLookDirection, 2.f };
					//}
					//m_bHitGroundSmashed = false;

					m_bHitGroundSmashed = false;
					Set_BreakFall_Ground();

					Set_bAttackGravity(true);

					//Set_NextAnimation(m_iBreakFall_Ground, 2.f);
					//DirectionInput iMoveKey = inputBuffer.back().direction;
					//
					//if (iMoveKey == MOVEKEY_UP || iMoveKey == MOVEKEY_UP_LEFT)
					//{
					//	Set_fImpulse({ -3.f * m_iLookDirection,1.f });
					//	Set_ForcveGravityTime(0.f);
					//}
					//else if (iMoveKey == MOVEKEY_RIGHT)
					//{
					//	//Set_fImpulse({ 0.f , 0.3f });
					//	Set_fImpulse({ 0.f , 0.1f });
					//
					//	Set_ForcedGravityTime_LittleUp();
					//}
					//
					//
					//else //if (iMoveKey == MOVEKEY_LEFT)
					//{
					//	Set_fImpulse({ -5.f * m_iLookDirection, 0.f });
					//	Set_ForcedGravityTime_LittleUp();
					//}
				}

			}
		}
		else if (Check_bCurAnimationisHitAway() || Check_bCurAnimationisAirHit())
		{
			//���� �Ǵ� ���Ž� 
			if (m_bHitGroundSmashed)
			{
				//Set_Animation(m_iHit_Air_LightAnimationIndex);
				//m_pModelCom->CurrentAnimationPositionJump(55.f);
				//Set_NextAnimation(m_iBound_Ground, 5.f);

				//m_bHitGroundSmashed = false;
			}
			else
			{
				//Set_Animation(m_iBound_Ground);
				if (inputBuffer.size() == 0)
				{
					inputBuffer.push_back(CInput(MOVEKEY_NEUTRAL, ATTACK_NONE));
				}
				Set_Animation(m_iBreakFall_Ground, 2.f);
				if (inputBuffer.back() == CInput{ MOVEKEY_UP, ATTACK_LIGHT })
				{
					m_fImpuse = { -3.f * m_iLookDirection, 2.f };
				}
				Set_NextAnimation(m_iIdleAnimationIndex, 2.f);
			}
		}
		//else if (m_bHitGroundSmashed == true && m_pModelCom->m_iCurrentAnimationIndex == m_iHit_Air_LightAnimationIndex)
		//{
		//	if (m_bMotionPlaying == false)
		//	{
		//		Set_Animation(m_iBreakFall_Ground, 2.f);
		//		Set_NextAnimation(m_iIdleAnimationIndex, 2.f);
		//		m_bHitGroundSmashed = false;
		//	}
		//
		//}
		else if (m_pModelCom->m_iCurrentAnimationIndex == m_iBound_Ground)
		{
			if (m_bMotionPlaying == false)
			{
				Set_Animation(m_iBreakFall_Ground);

			}

		}
		if (m_pModelCom->m_iCurrentAnimationIndex == m_iBreakFall_Ground)
		{

			//����üũ
			//1ȸ�� ����ɰ�
			m_fGravityTime += fTimeDelta;
			if (m_fGravityTime * 2.f > m_fJumpPower)
			{
				m_fGravityTime = m_fJumpPower * 0.5f;
			}
			//_float fGravity = (-0.7f * (2 * m_fGravityTime - m_fJumpPower) * (2 * m_fGravityTime - m_fJumpPower) + 4) * 0.1;
			//m_pTransformCom->Add_Move({ m_fImpuse.x * fTimeDelta,-fGravity + m_fImpuse.y * fTimeDelta,0 });
			m_pTransformCom->Add_Move({ m_fImpuse.x * fTimeDelta,0.3f,0 });

		}

		if (m_bJumpLock)
		{
			m_fAccAnimationLock += fTimeDelta;

			if (m_fAccAnimationLock > 0.15f)
			{
				m_bJumpLock = false;
				m_fAccAnimationLock = 0.f;
			}
		}

		m_bDoubleJumpEnable = true;

	}




}



HRESULT CCharacter::Ready_Components()
{
	/* Com_Shader */
	if (FAILED(__super::Add_Component(LEVEL_STATIC, TEXT("Prototype_Component_Shader_VtxAnimMesh"),
		TEXT("Com_Shader"), reinterpret_cast<CComponent**>(&m_pShaderCom))))
		return E_FAIL;

	/* Com_Model */
	//if (FAILED(__super::Add_Component(LEVEL_GAMEPLAY, TEXT("Prototype_Component_Model_untitled"),
	//	TEXT("Com_Model"), reinterpret_cast<CComponent**>(&m_pModelCom))))
	//	return E_FAIL;

	/* Com_Model */
	//if (FAILED(__super::Add_Component(LEVEL_GAMEPLAY, m_strModelName,
	//	TEXT("Com_Model"), reinterpret_cast<CComponent**>(&m_pModelCom))))
	//	return E_FAIL;




	//CCollider_Test::COLLIDER_DESC ColliderDesc{};
	//ColliderDesc.pTransform = m_pTransformCom;
	//ColliderDesc.fSizeX = 1.2f;
	//ColliderDesc.fSizeY = 1.5f;
	//ColliderDesc.fSizeZ = 0.7f;
	//ColliderDesc.Offset = { 0.f, 0.7f, 0.f };


	//CBounding_AABB::BOUNDING_AABB_DESC ColliderDesc{};
	//if (m_iPlayerTeam == 1)
	//	ColliderDesc.colliderGroup = CCollider_Manager::COLLIDERGROUP::CG_1P_BODY;
	//else
	//	ColliderDesc.colliderGroup = CCollider_Manager::COLLIDERGROUP::CG_2P_BODY;
	//ColliderDesc.pMineGameObject = this;
	//ColliderDesc.vCenter = { 0.f,0.8f,0.f };
	//ColliderDesc.vExtents = { 0.5f,0.7f,1.f };
	//
	//
	////Com_Collider
	//if (FAILED(__super::Add_Component(LEVEL_GAMEPLAY, TEXT("Prototype_Component_Collider_AABB"),
	//	TEXT("Com_Collider"), reinterpret_cast<CComponent**>(&m_pColliderCom), &ColliderDesc)))
	//	return E_FAIL;
	//
	//m_pGameInstance->Add_ColliderObject(ColliderDesc.colliderGroup, m_pColliderCom);



	return S_OK;
}

HRESULT CCharacter::Bind_ShaderResources()
{
	if (FAILED(m_pTransformCom->Bind_ShaderResource(m_pShaderCom, "g_WorldMatrix")))
		return E_FAIL;

	if (FAILED(m_pShaderCom->Bind_Matrix("g_ViewMatrix", &m_pGameInstance->Get_Transform_Float4x4(CPipeLine::D3DTS_VIEW))))
		return E_FAIL;

	if (FAILED(m_pShaderCom->Bind_Matrix("g_ProjMatrix", &m_pGameInstance->Get_Transform_Float4x4(CPipeLine::D3DTS_PROJ))))
		return E_FAIL;

	if (FAILED(m_pOutLineCom->Bind_ShaderResource(m_pShaderCom, "g_OutLineTexture", 1)))
		return E_FAIL;

	const LIGHT_DESC* pLightDesc = m_pRenderInstance->Get_LightDesc(CLight_Manager::LIGHT_PLAYER, 0, m_strName);
	if (nullptr == pLightDesc)
		return E_FAIL;

	if (FAILED(m_pShaderCom->Bind_RawValue("g_iPlayerDirection", pLightDesc->pPlayerDirection, sizeof(_int))))
		return E_FAIL;

	return S_OK;
}

void CCharacter::Map_DestructiveFinish()
{
	CGameObject* pGameObject = *(m_pGameInstance->Get_Layer(LEVEL_GAMEPLAY, TEXT("Layer_MeteoBreak")).begin());

	/* ���߿� �� ���ǿ� ���� �б� ó�� �ؾ���*/
	static_cast<CSpaceMeteoBreak*>(pGameObject)->Start_Space_DestructiveFinish();

}

void CCharacter::GetUI_Input(DirectionInput eDirInput, ButtonInput eBtnInput, _uint iTeam)
{
	if (iTeam == 1)
	{

		if (m_iLookDirection == -1)
		{
			switch (eDirInput)
			{
			case Client::MOVEKEY_LEFT:
				eDirInput = MOVEKEY_RIGHT;
				break;
			case Client::MOVEKEY_RIGHT:
				eDirInput = MOVEKEY_LEFT;
				break;
			case Client::MOVEKEY_UP_LEFT:
				eDirInput = MOVEKEY_UP_RIGHT;
				break;
			case Client::MOVEKEY_UP_RIGHT:
				eDirInput = MOVEKEY_UP_LEFT;
				break;
			case Client::MOVEKEY_DOWN_LEFT:
				eDirInput = MOVEKEY_DOWN_RIGHT;
				break;
			case Client::MOVEKEY_DOWN_RIGHT:
				eDirInput = MOVEKEY_DOWN_LEFT;
				break;
			default:
				break;
			}
		}

		m_pUI_Manager->m_eDirInput = eDirInput;
		m_pUI_Manager->m_eBtnInput = eBtnInput;
	}
	else if (iTeam == 2)
	{
		if (m_iLookDirection == 1)
		{
			switch (eDirInput)
			{
			case Client::MOVEKEY_LEFT:
				eDirInput = MOVEKEY_RIGHT;
				break;
			case Client::MOVEKEY_RIGHT:
				eDirInput = MOVEKEY_LEFT;
				break;
			case Client::MOVEKEY_UP_LEFT:
				eDirInput = MOVEKEY_UP_RIGHT;
				break;
			case Client::MOVEKEY_UP_RIGHT:
				eDirInput = MOVEKEY_UP_LEFT;
				break;
			case Client::MOVEKEY_DOWN_LEFT:
				eDirInput = MOVEKEY_DOWN_RIGHT;
				break;
			case Client::MOVEKEY_DOWN_RIGHT:
				eDirInput = MOVEKEY_DOWN_LEFT;
				break;
			default:
				break;
			}
		}
			m_pUI_Manager->m_eDirInput2 = eDirInput;
			m_pUI_Manager->m_eBtnInput2 = eBtnInput;
		
	}


}

void CCharacter::Notify_QTE_Same_Grab(_int result)
{
	m_iQTE = result;

	//switch (result)
	//{
	//	//��
	//case 1:
	//	break;
	//	//��
	//case -1:
	//	break;
	//	//���
	//case 0:
	//	break;
	//}
}

void CCharacter::Notify_QTE_1p_Grab(_int result)
{
	m_iQTE = result;

	//switch (result)
	//{
	//	//��
	//case 1:
	//	break;
	//	//��
	//case -1:
	//	break;
	//}
}


void CCharacter::Notify_QTE_Hit(_int result)
{
	m_iQTE = result;

	//switch (result)
	//{
	//	//��
	//case 1:
	//	break;
	//	//��
	//case -1:
	//	break;
	//}
}

void CCharacter::Notify_QTE_Continuous_Attack(_int result)
{
	m_iQTE = result;

	//switch (result)
	//{
	//	//��
	//case 1:
	//	break;
	//	//��
	//case -1:
	//	break;
	//}
}

void CCharacter::Character_Start_QTE(_uint iQTEID)
{
	/*
	enum QTE_ID
	{
		QTE_ID_SAME_GRAB,
		QTE_ID_HIT,
		QTE_ID_CONTINUOUS_ATTACK,
		QTE_ID_END
	};
	*/
	m_bCreateQTE = true;
	m_iQTE = -1;
	CQTE_Manager::Get_Instance()->Start_QTE((CQTE_Manager::QTE_ID)iQTEID, this);

}
void CCharacter::Add_ChaseLight()
{
	LIGHT_DESC			LightDesc{};

	ZeroMemory(&LightDesc, sizeof(LIGHT_DESC));
	LightDesc.eType = LIGHT_DESC::TYPE_POINT;
	LightDesc.vPosition = _float4(0.f, 0.f, 0.f, 1.f);
	LightDesc.fRange = 30.f;
	LightDesc.vDiffuse = m_vChaseLight;
	//LightDesc.vDiffuse = _float4(1.0f, 0.f, 0.f, 1.f);
	LightDesc.vAmbient = _float4(0.1f, 0.1f, 0.1f, 1.f);
	LightDesc.vSpecular = _float4(1.0f, 0.95f, 0.45f, 1.f);

	LightDesc.fAccTime = 0.f;
	LightDesc.fLifeTime = 1.f;
	LightDesc.strName = "Chase";
	/*LightDesc.pisDone = &m_bChase;*/


	if (FAILED(m_pRenderInstance->Add_Effect_Light(LightDesc.strName, LightDesc)))
		return;
}

CCharacter* CCharacter::Create(ID3D11Device* pDevice, ID3D11DeviceContext* pContext)
{
	CCharacter* pInstance = new CCharacter(pDevice, pContext);

	if (FAILED(pInstance->Initialize_Prototype()))
	{
		MSG_BOX(TEXT("Failed to Created : CCharacter"));
		Safe_Release(pInstance);
	}

	return pInstance;
}

CGameObject* CCharacter::Clone(void* pArg)
{
	CCharacter* pInstance = new CCharacter(*this);

	if (FAILED(pInstance->Initialize(pArg)))
	{
		MSG_BOX(TEXT("Failed to Cloned : CCharacter"));
		Safe_Release(pInstance);
	}

	return pInstance;
}

void CCharacter::Free()
{
	__super::Free();
	Safe_Release(m_pDetailTextureCom);
	Safe_Release(m_p1PTextureCom);
	Safe_Release(m_pOutLineCom);
	Safe_Release(m_pShaderCom);
	Safe_Release(m_pModelCom);

	Safe_Release(m_pUI_Manager);
	Safe_Release(m_pEffect_Manager);
	Safe_Release(m_pOutLineCom);
	Safe_Release(m_pColliderCom);

}
