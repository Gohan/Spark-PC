#pragma once
#include "common/config.h"
#include <deque>

enum {
	INIT_TYPE_THREE_MORE_PLAYER = 0,
};
class CGameStep;
class CLogicScheduler
{
public:
	CLogicScheduler(void);
	~CLogicScheduler(void);
	void InitLogicScheduler(sparks::int32 nType);

	void OnGameMessage(GameMessage::GameMessage& message);
private:
	std::deque<sparks::shared_ptr<CGameStep>> m_deqSteps;
	sparks::int32 m_nType;
};

