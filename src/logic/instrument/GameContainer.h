#pragma once
// GameContainer
// ��������������Ϸ�����Ķ���, �������Ϊһ����Ϸ�Ĺ�����, ����Ϸ��ʼ��������ȫȨ����.
#include "common\config.h"
#include "logic/instrument/Player.h"
#include "logic/scheduler/LogicScheduler.h"
class CGameDataHolder;
class CGameContainer
{
public:
	CGameContainer(void);
	~CGameContainer(void);
	void InitGame();
	void AddPlayer(const sparks::shared_ptr<CPlayer>& spPlayer);
	void SetGameOption();
	sparks::int64 ContainerId() const { return m_nContainerId; }
	void ContainerId(sparks::int64 val) { m_nContainerId = val; }
	sparks::shared_ptr<CGameDataHolder> Holder() const { return m_spHolder; }
	void Holder(sparks::shared_ptr<CGameDataHolder> val) { m_spHolder = val; }
	void OnGameMessage(GameMessage::GameMessage& message);

private:
	sparks::int64 m_nContainerId;
	sparks::shared_ptr<CGameDataHolder> m_spHolder;
	sparks::shared_ptr<CLogicScheduler> m_spScheduler;
};
