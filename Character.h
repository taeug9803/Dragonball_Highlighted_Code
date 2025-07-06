#pragma once

#include "GameObject.h"
#include "Client_Defines.h"
#include "UI_Define.h"
#include "AnimationEvent_Defines.h"
#include "FrameEvent_Manager.h"

#include "Input.h"
#include <functional>

BEGIN(Engine)
class CShader;
class CModel;
END

BEGIN(Client)



class CCharacter : public CGameObject
{
public:


	//������ Ŀ�ǵ���� �־�� ����
	static vector<CInput> Command_236Attack;
	static vector<CInput> Command_236Attack_Extra;
	static vector<CInput> Command_236Attack_Heavy;
	static vector<CInput> Command_236Attack_Heavy_Extra;
	static vector<CInput> Command_214Attack;
	static vector<CInput> Command_214Attack_Extra;
	static vector<CInput> Command_236Special;
	static vector<CInput> Command_236Special_Side;
	static vector<CInput> Command_236Special_Side_Extra;
	static vector<CInput> Command_214Special;
	static vector<CInput> Command_214Special_Extra;
	static vector<CInput> Command_214FinalAttack;
	static vector<CInput> Command_236UltimateAttack;
	static vector<CInput> Command_236UltimateAttack_Side;
	static vector<CInput> Command_236UltimateAttack_Side_Extra;

	
	static vector<CInput> Command_BackDash;
	static vector<CInput> Command_Forward;

	static vector<CInput> Command_LightAttack;
	static vector<CInput> Command_MediumAttack;
	static vector<CInput> Command_MediumAttack_Extra;

	static vector<CInput> Command_HeavyAttack;
	static vector<CInput> Command_SpecialAttack;
	static vector<CInput> Command_HeavyAttack_Extra;

	static vector<CInput> Command_Grab;

	static vector<CInput> Command_Crouch_LightAttack;
	static vector<CInput> Command_Crouch_MediumAttack;
	static vector<CInput> Command_Crouch_MediumAttack_Extra;
	static vector<CInput> Command_Crouch_HeavyAttack;
	static vector<CInput> Command_Crouch_HeavyAttack_Extra;
	static vector<CInput> Command_Crouch_SpecialAttack;
	static vector<CInput> Command_Crouch_Crouch_SpecialAttack;

	static vector<CInput> Command_Up_SpecialAttack;

	static vector<CInput> Command_Reflect;
	static vector<CInput> Command_BenishingAttack;
	static vector<CInput> Command_LowBenishingAttack;

	static vector<CInput> Command_Transform;

public:
	//Ŀ�ǵ� ���� ������
	const int BUFFER_SIZE = 30;
	static const _float fGroundHeight;  //0
	static const _float fJumpPower;
	//const enum LOOK{ LOOK_LEFT = -1,  LOOK_RIGHT = 1};

	typedef struct : CGameObject::GAMEOBJECT_DESC
	{
		_ushort iTeam = 1;
		CUI_Define::PLAYER_SLOT ePlayerSlot = {};
	}Character_DESC;


	struct CommandPattern {
		vector<CInput> pattern;  // �Է� ����
		_uint AnimationIndex;
	};

	struct CommandPatternFunction {
		vector<CInput> pattern;  // �Է� ����
		std::function<void()> action;  // �ش� ������ �������� �� ������ �Լ�
	};

protected:
	CCharacter(ID3D11Device* pDevice, ID3D11DeviceContext* pContext);
	CCharacter(const CCharacter& Prototype);
	virtual ~CCharacter() = default;

public:
	virtual HRESULT Initialize_Prototype() override;
	virtual HRESULT Initialize(void* pArg) override;
	virtual void Player_Update(_float fTimeDelta) override;
	virtual void Camera_Update(_float fTimeDelta) override;
	virtual void Update(_float fTimeDelta) override;
	virtual void Late_Update(_float fTimeDelta) override;
	virtual HRESULT Render(_float fTimeDelta) override;


	//Ŀ�ǵ� �Է�
	virtual _bool InputCommand();

	//������ �Է� �����
	virtual void InputedCommandUpdate(_float fTimeDelta);	//�ð�
	virtual void UpdateInputBuffer(CInput newInput)			//������
	{
		if (inputBuffer.size() >= BUFFER_SIZE) {
			inputBuffer.erase(inputBuffer.begin());  
		}
		inputBuffer.push_back(newInput);
	}

	//�Էµ� Ű�� ���ǥ�߿� ��ġ/�����Ѱ� �ִ��� Ȯ��
	virtual bool CheckCommandSkippingExtras(const vector<CInput>& pattern, int timeWindow);
	bool CheckCommand_Exactly(const std::vector<CInput>& pattern, int timeWindow);
	_uint CheckAllCommands();


	//�ִϸ��̼�
	virtual _bool Character_Play_Animation(_float fTimeDelta);
	virtual _bool Character_Play_Animation_NoXZ(_float fTimeDelta);


	//Ư�� �ִϸ��̼����� üũ
	virtual _bool Check_bCurAnimationisGroundMove(_uint iAnimation = 1000) { return false; };
	virtual _bool Check_bCurAnimationisAirMove(_uint iAnimation = 1000);
	virtual _bool Check_bCurAnimationisAttack(_uint iAnimation = 1000) { return false; };
	virtual _bool Check_bCurAnimationisAirAttack(_uint iAnimation = 1000) { return false; };
	virtual _bool Check_bCurAnimationisAirHit(_uint iAnimation = 1000);
	virtual _bool Check_bCurAnimationisHitAway(_uint iAnimation = 1000);
	virtual _bool Check_bCurAnimationisHitGround(_uint iAnimation = 1000);

	virtual _bool Check_bCurAnimationisChase(_uint iAnimation = 1000);  //Ư���� ���� �ִϸ��̼� �� �� �ƴ϶� m_bChase���� ��������
	virtual _bool Check_bCurAnimationisReflect(_uint iAnimation = 1000);

	virtual _bool Check_bCurAnimationisGuard(_uint iAnimation = 1000);
	virtual _bool Check_bCurAnimationisGrab(_uint iAnimation = 1000);

	virtual _bool Check_bCurAnimationisGroundSmash(_uint iAnimation = 1000);

	virtual _short Check_bCurAnimationisCanChase() { return 0; };  //���� ����� ü�̽��� ���� �������� ���θ� üũ, 0�̸� �Ұ��� �� ���� ���ڴ� ���ۼӵ�*10�ϱ� �޾Ƽ� *0.01f�Ұ�


	//���� ��ź���� �߰��� �߷��� �ٽ� ����� Ư�� ó���ؾ��ϴ°͵� ���� override
	virtual _bool Check_bCurAnimationisHalfGravityStop(_uint iAnimation = 1000) { return false; };


	//�ִϸ��̼�
	void Set_NextAnimation(_uint iAnimationIndex, _float fLifeTime, _float fAnimationPosition = 0);
	virtual void AttackNextMoveCheck();
	virtual void AnimeEndNextMoveCheck();
	virtual void Set_Animation(_uint iAnimationIndex, _bool bloof = false);
	void Set_IdleAnimation();


	_bool		CompareNextAnimation(_uint iAnimationIndex, _float fNextPosition = 0);
	_uint* Get_pAnimationIndex();
	_short Get_iAnimationIndex();

	virtual void Set_CurrentAnimationPositionJump(_float fAnimationPosition);

	//Ű������ �̺�Ʈ
	virtual void ProcessEventsFramesZero(_uint characterIndex, _uint animationIndex);
	virtual void ProcessEventsBetweenFrames2(int characterIndex, int animationIndex, float prevFrame, float currentFrame);

	//Ű������ �̺�Ʈ �Ļ�
	void Create_Effect(_int iEffectIndex);



	void FlipDirection(_int iDirection = 0);
	_int Get_iDirection() { return m_iLookDirection; };


	_uint Get_iPlayerTeam() { return m_iPlayerTeam; };

	virtual void AttackEvent(_int iAttackEvent, _int AddEvent = 0) {};
	virtual void Play_Sound(_uint SoundName, _bool bisLoof, _float fvolume) {};
	virtual void Play_Sound_Stop(_uint SoundName) {};
	virtual void Play_Group_Sound(_uint groupKey, _bool loop, _float volume) {};




	//����׿� �ڵ� 
	virtual void ShowInputBuffer();
	virtual void DebugPositionReset(_short iDirection = 0);



	//�߷°���
	virtual void Gravity(_float fTimeDelta);
	virtual void Set_fJumpPower(_float fJumpPower) { m_fJumpPower = fJumpPower; };
	virtual void Set_fGravityTime(_float fGravityTime) { m_fGravityTime = fGravityTime; };
	virtual void Set_fImpulse(_float2 fImpulse) { m_fImpuse = fImpulse; };
	virtual void Set_fImpulse(_float fImpulseX) { m_fImpuse.x = fImpulseX; };
	

	_float Get_fHeight();
	_bool Get_bAirDashEnable() { return m_bAriDashEnable; };
	void Set_bAirDashEnable(_bool bAirDashEnable) { m_bAriDashEnable = bAirDashEnable; };

	CCharacter* Get_pEnemy();

	void Set_ForcedGravityDown();
	void Set_ForcedGravityTime_LittleUp();

	void Set_ForcveGravityTime(_float fGravityTime);

	void Set_bNextAnimationGravityEvent() { m_bNextAnimationGravityEvent = true; };

	void Set_bAttackGravity(_bool bAttackGravity);
	_float Get_fGravityTime() { return m_fGravityTime; };



	//�������� ���� ���� �ý���
	void AttckCancleJump();

	void Chase2(_float fTimeDelta);
	void Chase_Ready(_float fTimeDelta, _bool bNoReady = false);

	void Set_ChaseStoping();
	void Set_ChaseStop();


	void Chase_Grab(_float fTimeDelta);
	void Character_Attack_Grab(_float fTimeDelta);
	void Grab_LateDraw();


	void Move(_float fTimeDelta);
	void MoveKey1Team(_float fTimeDelta);
	void MoveKey2Team(_float fTimeDelta);
	virtual void Reset_AttackCount();


	void Set_bInivisible(_bool bInvisible);

	//�ǰ� ����
	virtual AttackColliderResult Set_Hit4(_uint eAnimation, AttackGrade eAttackGrade, AttackType eAttackType, _float fStunTime, _uint iDamage, _float fStopTime, _short iDirection, _float2 Impus = { 0,0 }, _bool bParticle =true);
	void Set_HitAnimation(_uint eAnimation, _float2 Impus = { 0,0 },_bool bParticle=true);

	//�ǰ� ����
	void Set_AnimationStop(_float fStopTime);
	void Set_UnlockAnimationStop();
	void Set_AnimationStopWithoutMe(_float fStopTime);

	//�ǰ� ����
	void Check_StunEnd();
	void Stun_Shake();
	void Update_AnimationLock(_float fTimeDelta);
	void Update_StunImpus(_float fTimeDelta);


	//����
	virtual void Set_BreakFall_Ground();
	void BreakFall_Air();

	void Set_bNoGravity(_bool bNoGravity, _float MaxfNoGravitySafeTime = 0.2f);



	//������
	void Gain_AttackStep(_ushort iStep);// 
	void Gain_HitCount(_ushort iHit);// 
	virtual _float Get_DamageScale(_bool bUltimate = false);



	//���� ��������
	void Set_GroundSmash(_bool bSmash);
	AttackColliderResult Guard_Check3(AttackType eAttackType);
	_bool CompareGuardType(AttackType eAttackType);
	AttackColliderResult CompareGuardType3(AttackType eAttackType);
	AttackColliderResult CompareGrabType3(AttackType eAttackType);
	void Set_Grab(_bool bAir);

	//�����̵�
	void Teleport_ToEnemy(_float OffsetX, _float OffsetY);




	_uint	Get_iHP();
	void	Full_HP();
	_bool	Get_bStun();

	_ushort Get_BreakFall_AirAnimationIndex();
	_ushort Get_JumpAirAnimationIndex();
	_bool	Get_bBenishingAttack();


	void	Update_PreviousXPosition();
	_float	Get_fCalculatePreviousXPosition();
	_float	Get_fAbsCalculatePreviousXPosition();
	_float	Get_fPositionX();
	_vector Get_vPosition();
	void	Add_Move(_float2 fMovement);
	void	Set_bBenishingAttack(_bool bBenishing);


	void	Set_GrabLoofCount(_ushort iLoofCount);
	void	Set_bGrabbed(_bool bGrabbed);
	void	Set_bGrabbedGravity(_bool bGrabbedGravity);
	_bool	Get_bGrabbed();
	void	Set_GrabAnimation();  





	//BattleInterface
	void	Sparking_ON(_float fTimeDelta);
	void	Sparking_TimeCount(_float fTimeDelta);
	_bool	Get_bSparking();

	void	Gain_KiAmount(_ushort iKiAmount);
	_bool	Get_bCharacterDead();

	void	Tag_KeyCheck();
	void	Tag_In(_ubyte iTagSlot);
	void	RegisterEnemy(CCharacter* pEnemy);
	void	pEnemyCheck();
	void	Tag_Out(_vector vPosition);

	_bool	Update_Tag_In(_float fTimeDelta);
	_uint	Get_NewCharacterslot();

	void	Set_AttackBackEvent(_bool bEvent);
	void	Set_ReflectAttackBackEvent(_bool bEvent);

	_bool	Get_bAttackBackEvent();

	void	Set_bGrabDraw(_bool bGrabDraw);
	_bool	Check_bWall();
	void	Move_ForWall();

	void	Set_bDynamicMove(_bool bDynamicMove);


	//��� ����
	void	Update_Dying(_float fTimeDelta);
	_bool	Get_bDying();
	void	Set_FinalSkillRoundEnd(_bool bSkillRoundEnd, _ushort iIndex);
	_bool	m_bFinalSkillRoundEnd = false;
	_bool	m_bFinalSkillRoundEndSolo = false;
	_float	m_fMaxDyingTime = { 5.f };

	
	void Set_UnDying(_bool bNoneDying) {m_bUnDying = bNoneDying;};
	_bool m_bUnDying = false;	//��� ������ �ʻ�� �߰��� ���� �ʵ��� �һ� ����

	void Play_WinAnimation();
	void Play_NewRound_Loser();
	void Play_NewRound_Winner();
	void Update_Collider();

	//������ ����
	_bool m_bOpening = false;
	_float m_fAccOpeningTime = {0.f};
	_float m_fMaxOpeningTime = {3.f};
	_float m_fAccfirstOpeningTime = { 0.f };

	void Update_Opening(_float fTimeDelta);
	void Set_bPlaying(_bool bPlaying);
	void Set_StopAllAttackObject(_float fStopTime);
	_bool Play_FirstOpening();


	//�и�
	_bool Get_bReflect();
	void Set_bBeReflecting(_short iDirection);
	_bool Update_BeReflecting(_float fTimeDelta);


	//QTE
	void Set_bFinalSkillQTE(_bool bFinalSkillQTE);
	CHARACTER_INDEX Get_eCharacterIndex();



	
	//�ƾ� ����
	_bool m_bCinematic_NoMoveXZ = { false };
	void Set_AnimationMoveXZ(_bool bValue); // NOMoveXZ �߸���� false�� ������ true�� �ȿ�����
	virtual void Character_CinematicEnd() {};

	//������ ����
	void Set_bHeavySkill(_bool bHeavySkill);
	_bool m_bHeavySkill = { false };

	//�ƿ��
	_float4 m_fAuraColor = {};
	_bool m_bAura = false;
	_bool m_bForcedAura = false;
	void Set_bForcedAura(_bool bForcedAura);
	void Set_bAura(_bool bAura);
	void Set_fAuraColor(_float4 fAuraColor);

	virtual void HitStopEffect() {};

	_bool m_bSoloFinalEndCount = false;
protected:

	//�޺� ������ ���� �ʱ�ȭ
	void Reset_AttackStep();

	//�ִϸ��̼� ���� ��� ������� ����
	void Update_NoEventAnimationLoof(_float fTimeDelta);
	void Update_ForcedEventAnimationLoof(_float fTimeDelta);

	void Update_NoEventTime(_float fTimeDelta);

	//�ִϸ��̼� ���� ����
	void Set_NoEventAnmationLoof(_float fMinPosition, _float fMaxPosition, _float fTime);
	void Set_EventAnmationLoof(_float fMinPosition, _float fMaxPosition, _float fTime);


	_float4x4 Make_BoneMatrix(char* BoneName);
	_float4x4 Make_BoneMatrix_Offset(char* BoneName, _float2 fOffset, _bool bFlipDirection = false);
	_float4x4 Character_Make_Matrix(_float2 fOffset = { 0,0 }, _bool bFlipDirection = false);



public:
	void	Character_Make_BoneEffect_Offset(char* BoneName, _wstring strEffectName, _float2 fOffset = { 0.f,0.f }, _bool bFlipDirection = false);
	class	CEffect_Layer* Character_Make_BoneEffect(char* BoneName, _wstring strEffectName);
	class	CEffect_Layer* Character_Make_Effect(_wstring strEffectName, _float2 fOffset = { 0,0 }, _bool bFlipDirection = false);
	
	void Character_Create_Distortion(_float3 vDir = { 0.f,1.f,0.f }, _float2 vOffSetPos = {0.f,0.f}, _float2 vOffSetScale = { 1.f,1.f }, _float fLifeTime = { 0.3f });
	void Character_Create_Distortion(_float3 vDir, _float3 vOffSetPos, _float2 vOffSetScale = { 1.f,1.f }, _float fLifeTime = { 0.3f });



	void Set_LoofAnimationCreate(_wstring strEffectName, _float fMaxTime, _float fPeriodTime, _float2 fOffset = { 0.f,0.f }, _bool bFlipDirection = false);
	void Update_LoofAnimationCreate(_float fTimeDelta);

	const _float4x4* Get_pTransformMatrix();

public:
	virtual void OnCollisionEnter(class CCollider* other, _float fTimeDelta) override;
	virtual void OnCollisionStay(class CCollider* other, _float fTimeDelta) override;
	virtual void OnCollisionExit(class CCollider* other) override;

	//UI
public:
	void Set_bRedHP(_bool bRedHP);
	void CharacterToUI_Info();

protected:
	CShader* m_pShaderCom = { nullptr };
	CModel* m_pModelCom = { nullptr };
	CTexture* m_pOutLineCom = { nullptr };
	CTexture* m_p2PTextureCom = { nullptr };
	CTexture* m_p1PTextureCom = { nullptr };
	CTexture* m_pDecalTextureCom = { nullptr };
	CTexture* m_pDetailTextureCom = { nullptr };
	
	_float					m_fRandom = {};
	_wstring				m_strModelName{};

	//�ǰ� ���ϰ� �ٸ�
	_float					m_fAccAnimationLock{};
	_float					m_fMaxAnimationLock{};
	_bool					m_bAnimationLock{};

	CHARACTER_INDEX			m_eCharacterIndex = { PLAY_GOKU };

	FrameEventMap* m_pFrameEvent = { nullptr };
	_bool					m_bMotionPlaying = false;

	vector<CInput> inputBuffer;

	_ushort m_iPlayerTeam = { 1 };
	_int	m_iLookDirection = { 1 };

	vector<CommandPattern> MoveCommandPatterns;
	vector<CommandPatternFunction> MoveCommandPatternsFunction;
	vector<CommandPatternFunction> MoveCommandPatternsFunction_Exactly;



	//index,�ð�
	pair<_uint, _float>		m_iNextAnimation{ 0,0 };
	_float					m_fNextAnimationCurrentPosition = {};




	_ushort m_iJumpAnimationIndex = { 6 };
	_ushort m_iFallAnimationIndex = { 7 };

	_ushort m_iIdleAnimationIndex = { 0 };
	_ushort m_iCrouchAnimationIndex = { 4 };
	_ushort m_iBackWalkAnimationIndex = { 10 };
	_ushort m_iForwardWalkAnimationIndex = { 9 };
	_ushort m_iForwardDashAnimationIndex = { 11 };
	_ushort m_iForwardDashEndAnimationIndex = { 14 };

	_ushort m_iStandingMidAttackAnimationIndex = { 46 };
	_ushort m_iChaseAnimationIndex = { 13 };

	_ushort m_iReflectAnimationIndex = { 58 };

	_ushort m_iHit_Stand_LightAnimationIndex = { 21 };		//050

	_ushort m_iHit_Stand_MediumAnimationIndex = { 22 };		//051
	_ushort m_iHit_Crouch_AnimationIndex = { 23 };			//052

	_ushort m_iHit_Away_LeftAnimationIndex = { 33 };
	_ushort m_iHit_Away_UpAnimationIndex = { 35 };
	_ushort m_iHit_Away_LeftDownAnimationIndex = { 39 };

	_ushort m_iHit_WallBouce = { 34 };

	_ushort m_iHit_Air_Spin_LeftUp = { 31 };
	_ushort m_iHit_Air_Spin_Up = { 30 };  //072


	_ushort m_iHit_Air_LightAnimationIndex = { 24 };		//050
	_ushort m_iHit_Air_FallAnimationIndex = { 26 };


	//���
	_ushort m_iBreakFall_Ground = { 41 };   //100
	_ushort m_iBreakFall_Air = { 42 };   //101
	_ushort m_iBound_Ground = { 25 };
	_ushort m_iLayUp = {27};


	_ushort m_iAttack_Air1 = { 52 };
	_ushort m_iAttack_Air2 = { 53 };
	_ushort m_iAttack_Air3 = { 54 };
	_ushort m_iAttack_AirUpper = { 55 };

	_ushort m_iAttack_Heavy = { 45 };
	_ushort m_iAttack_Crouch_Heavy = { 51 };


	_ushort m_iAttack_LightLast = { 47 };

	//����
	_ushort m_iGuard_GroundAnimationIndex = { 18 };
	_ushort m_iGuard_CrouchAnimationIndex = { 19 };
	_ushort m_iGuard_AirAnimationIndex = { 20 };


	//���
	_ushort m_iGrabReadyAnimationIndex = { 17 };
	_ushort m_iGrabAnimationIndex = { 60 };

	_ushort m_iSparkingAnimationIndex = { 59 };  //303

	_ushort m_iDyingStandingAnimationIndex = { 29 };



	//����
	_ushort m_iStartAnimatonIndex = { 75 };  //600cs

	//�¸�
	_ushort m_iWinAnimationIndex = {78 };  //610

	//���庯��
	_ushort m_iNextRound_RightHandAppear_Cutscene_AnimationIndex = { 79 };  //620cs ->630�� ����
	_ushort m_iNextRound_RightHand_AnimationIndex = { 81 };  //621cs ->631���� ���� Durtaion 122

	_ushort m_iNextRound_LeftHand_Cutscene_AnimationIndex = { 80 };  //630 Durtaion 24
	_ushort m_iNextRound_LeftHand_AnimationIndex = { 82 };  //631 Durtaion 24





	_float m_fGravityTime = { 0.f };
	_float m_fJumpPower = 3;// { 0.f };

	//���ӵ�
	//_float m_fImpuse = { 0.f };


	//�ǰݽ� Y�� �̵��� ����� xy�� ����.
	_float2 m_fImpuse = { 0.f,0.f };


	_bool m_bDoubleJumpEnable = { true };
	_bool m_bAriDashEnable = { true };

	_bool m_bJumpLock = { false };
	_float m_fAccJumpLockTime = { 0.f };

	_bool m_bAttackGravity = { true };


	_bool m_bChase = { false };
	_float m_fAccChaseTime = { 0.f };
	_vector m_vChaseDir{ 0 };

	_wstring m_ChaseEffectName = { TEXT("BurstR-02_Rotated_Left") };

	


	//���� ����
	_bool m_bStun = { false };
	_float m_fAccStunTime = {};
	_float m_fMaxStunTime = {};

	_bool m_bStunShakeDirection = { false };

	//����׿� �ӽ� collider
	//CCollider_Test* m_pColliderCom = { nullptr };
	CCollider* m_pColliderCom = { nullptr };

	CCharacter* m_pDebugEnemy = { nullptr };
	CCharacter* m_pEnemy = { nullptr };

	class CEffect_Layer* m_pChaseEffectLayer = { nullptr };

	_short		 m_iHP = 10000;   //�´¼��� ������ �� �� ������ ushort ��� sohrt.  ������   -32,768 ~ 32,767 �ϱ� ���� 


	_float		m_fAccSmokeTime = {};

	_ushort		m_iAttackStepCount = { 0 };  //�޺��� �ƴ�.

	_bool		m_bSparking = false;
	_float		m_fAccSparkingTime = {};
	_float		m_fMaxSparkingTime = {};
	_bool		m_bNextAnimationGravityEvent = false;





	_bool m_bChaseStoping = false;
	_bool m_bChaseEnable = true;

	_bool m_bGrab = false;
	_bool m_bGrab_Air = false;
	_bool m_bGrabDraw = false;

	_float m_fAccGrabTime = {};



	//���ϰ���
	_bool m_bHitGroundSmashed = { false };
	_bool m_bWallBounce = { true };
	_bool m_bNoGravity = { false };
	_float m_fNoGravitySafeTime = { 0.f };
	_float m_fMaxfNoGravitySafeTime = { 0.2f };

	_bool m_bAwayUpGravity = { false };


	
	_float m_fPreviousX = {};

	_bool	m_bGrabbed = { false };
	_bool	m_bGrabbedGravity = { false };
	_ushort m_iGrabLoof = 3;
	_float m_fAIrGrabEndAnimationPositon = { 29.99 }; //���� ���� ��Ÿ�� ����ϴ� �ִϸ��̼��� AttackEvent Posioton 


	_bool m_bCharacterDead = { false };

	_bool m_bTag_In = { false };	//�����Ϸ� ���� ĳ����.
	_bool m_bPlaying = { false };  //�� ĳ���͸� ������

	_float m_fAccTag_InTime = { 0.f };

	_bool m_bNoEventLoofAnimation = false;
	_bool m_bForcedEventLoofAnimation = false;
	_float m_fNoEventLoofMinPosition = {};
	_float m_fNoEventLoofMaxPosition = {};
	_float m_fMaxNoEventLoofTime = {};
	_float m_fAccNoEventLoofTime = {};


	//�������¿��� �ִϸ��̼� ���� ������ ����
	_bool m_bEffectLoofCreate = false;
	_float m_fAccEffectLoofCreateTime = { 0.f };
	_float m_fMaxEffectLoofCreateTime = { 0.f };
	_wstring m_strEffectLoofCreateName = {};

	_float m_fAccEffectPeriodTime = {};
	_float m_fMaxEffectPeriodTime = {};

	_float2 m_fEffectLoofCreateOffset = {};
	_bool m_bEffectLoofCreateFlip = { false };


	_bool m_bDying = { false };
	_float m_fAccDyingTime = {};
	_bool m_bDyingBlack = { true };

	_bool m_bDynamicMove = { false };
	_bool m_bDestructiveFinish = { false };
	_bool m_bAttackBackEvent = { false };

	_bool m_bReflect = { false };

	_bool m_bBeReflecting = { false };
	_float m_fAccBeReflectingTime = { 0.f };
	CGameObject* m_pReflectObject = { nullptr };


	_bool m_bBenishingAttack = { false };
	_bool m_bInvisible = { false };



	//����׿�
	_uint m_iDebugComoboDamage = { 0 };
	_bool m_bDebugInputLock = { false };


	_short m_eChaseSoundIndex = {0};

public:
	void Set_InputActive(_bool isActive) { m_bDebugInputLock = isActive; }

	


public:
	typedef struct
	{
		_bool        bStun = { FALSE };
		_bool        bHit = { FALSE };
		_bool        bAttBuf = { FALSE };

		_int        iHp = { 0 };
		_uint        iComboCount = { 0 };

		_int        iSKillPoint = { 0 };
		_int        iSKillCount = { 0 };

		_uint		iTeam = { 0 };

		CUI_Define::PLAYER_SLOT		ePlayer_Slot = {};
		CUI_Define::PLAYER_ID        ePlayerID = {};

	}Character_INFO_DESC;

public:
	Character_INFO_DESC Get_PawnDesc() { return m_tCharacterDesc; }
	void GetUI_Input(DirectionInput eDirInput, ButtonInput eBtnInput,_uint iTeam);


	//UI���� ����ϴ� ���� 

protected:
	_bool					m_bHit = { FALSE };
private:
	_uint					m_iComboCount = { 0 };
	_int					m_iSKillPoint = { 0 };
	_int					m_iSKillCount = { 0 };

	_bool					m_bRedHp = { FALSE };
	_bool					m_bAttBuf = { FALSE };

	_uint					m_iNumAttBuf = { 1 };
	_uint   m_iPrevComboCount = { 0 };

	//UI�� �������� ����
	Character_INFO_DESC				 m_tCharacterDesc = {};

	_float					m_fAttBufTimer = { 0.f };

protected:
	CUI_Define::PLAYER_ID				m_eCharacterID = {};
	CUI_Define::PLAYER_SLOT				m_ePlayerSlot = { CUI_Define::SLOT_END };
	class CUI_Manager* m_pUI_Manager = { nullptr };
	class CEffect_Manager* m_pEffect_Manager = { nullptr };

	string m_strName = "";
	_float4		m_vDyingPosition = { 0.f,0.f,0.f,1.f };
	
private:
	HRESULT Ready_Components();
public:
	HRESULT Bind_ShaderResources();
	// Layer_MeteoBreak
	void Map_DestructiveFinish();

	// 1: ��, 
	// -1 : �� 
	// 0: ���
	void Notify_QTE_Same_Grab(_int result);

	// 1: ��, 
	// -1 : �� 
	void Notify_QTE_1p_Grab(_int result);

	// 1: ��, 
	// -1 : �� 
	void Notify_QTE_Hit(_int result);

	// 1: ��, 
	// -1 : �� 
	void Notify_QTE_Continuous_Attack(_int result);

	CUI_Define::PLAYER_ID Get_CharacterID() { return m_eCharacterID; };


//public:
	

	void Character_Start_QTE(_uint iQTEID);
protected:
	_short m_iQTE = { -1 };
	_bool m_bCreateQTE = { false };


protected:
	void Add_ChaseLight();
	//m_eCharacterIndex;
	_float4 m_vChaseLight;
	_bool m_isLightChaseDone;

public:
	static CCharacter* Create(ID3D11Device* pDevice, ID3D11DeviceContext* pContext);
	virtual CGameObject* Clone(void* pArg) override;
	virtual void Free() override;


};



END