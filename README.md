# Dragonball_Highlighted_Code

# 주요 구현 코드 설명 (Core Implementation Highlights)


## 1. FrameEvent_Manager
**애니메이션 프레임 기반 이벤트 처리 시스템**

- 격투 게임 특유의 공격 타이밍 / 이펙트 / 사운드 등을 애니메이션 프레임에 맞춰 실행하기 위해 설계
- 애니메이션 이름 + 프레임 번호를 키로 삼아, 프레임마다 이벤트를 트리거함
- 슬라이더 UI 기반 툴로 프레임 확인 및 이벤트 편집 가능 (ImGui 사용)

🔗 관련 코드:
- [FrameEvent_Manager.cpp](./FrameEvent_Manager.cpp)
- [FrameEvent_Manager.h](./FrameEvent_Manager.h)

---

## 2. Character
**캐릭터 상태 및 조작 전체 담당**

격투 게임 장르는 단순한 이동/점프 외에도,
- 프레임 타이밍 기반 입력 반응
- 콤보 연계 조건
- 피격 경직/무적/넉백 등 복합 상태 처리
- 프레임 이벤트 시스템과의 통합 연동

등을 고려해야 하기 때문에, 일반적인 캐릭터보다 코드가 구조적으로 복잡해질 수밖에 없습니다.

이 구조에서는 다음을 목표로 설계했습니다:
- 상태마다 분리된 함수 구성 (UpdateIdle, UpdateAttack 등)
- 애니메이션/이벤트/이펙트/사운드 동기화
- 외부 매니저(콤보/이펙트/사운드 등)와 유연한 연결
- 

🔗 관련 코드:
- [Character.cpp](./Character.cpp)
- [Character.h](./Character.h)

---

## 3. AttackObject_CommandGrab
**커맨드 잡기 공격 오브젝트**

- 특정 조건에서만 유효한 Grab 판정을 생성
- 히트 여부에 따라 연출/이동 처리 분기
- 충돌/거리/상태 조건을 고려한 특수 오브젝트 설계

🔗 관련 코드:
- [AttackObject_CommandGrab.cpp](./AttackObject_CommandGrab.cpp)
- [AttackObject_CommandGrab.h](./AttackObject_CommandGrab.h)
