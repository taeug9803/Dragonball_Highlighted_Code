#pragma once

#include "GameObject.h"
#include "Client_Defines.h"

#include "AnimationEvent_Defines.h"
#include "AnimationNameMap.h"


BEGIN(Engine)
class CShader;
class CModel;
END

BEGIN(Client)


class CFrameEvent_Manager final : public CBase
{
	DECLARE_SINGLETON(CFrameEvent_Manager)
private:
	CFrameEvent_Manager();
	virtual ~CFrameEvent_Manager() = default;

public:
	FrameEventMap Get_FrameEventMap() { return FrameEvent; };
	FrameEventMap* Get_pFrameEventMap() { return &FrameEvent; };

	void Initalize_NameMap();

	void LoadFile2(const _char* TextFilePath);	//프레임 이벤트 정보가 적혀있는 파일 열어서
	void Add_Event(CHARACTER_INDEX iCharacterIndex, _int iAnimationIndex, _float fPosition, string strText); //프레임 이벤트를 NameMap에 저장

	//디버그용 삭제/다시 불러오기
	void ReLoadFrameEvent(const _char* TextFilePath);
	void ClearFrameEvent();
	void UseEvent_Test(string strEventText, CGameObject* pGameObject);

	//프레임 이벤트 발동될 시, 내용물을 분해해서 함수 사용
	void UseEvent(string strEventText, class CCharacter* pCharacter);



private:
	CHARACTER_INDEX Convert_strtoCharacterIndex(string strText);
	_float			Convert_strtoFloat(string strText);
	_int			Convert_strtoCharacterAnimationIndex(CHARACTER_INDEX eCharacterIndex, string strText);

public:
	FrameEventMap FrameEvent{};

private:
	CAnimationNameMap m_AnimationIndex;
	_bool m_bInitalizeCount = false;

private:
	CGameInstance* m_pGameInstance = { nullptr };

public:

	virtual void Free() override;
};

END