#pragma once
#include "common/config.h"
#include <google/protobuf/message.h>

enum
{
	TYPE_PREPARATION_STEP = 0,
	TYPE_CHOOSE_BOARD_STEP = 1,
	TYPE_AUCTION_TECHCARD_STEP = 2,
};

class CLogicScheduler;
class CGameDataHolder;

// gohan: 我打算给CGameStep做成一个数据无关的逻辑对象
class CGameStep
{
public:
	CGameStep() {}
	virtual ~CGameStep(void) = 0;
	virtual void OnGameMessage(	GameMessage::GameMessage& message,
								const sparks::shared_ptr<CLogicScheduler>& scheduler,
								const sparks::shared_ptr<CGameDataHolder>& data)
	{

	};

	// 用来处理 STEP 开始/结束的事件
	virtual void OnSchedulerMessage(ScheduleMessage::ScheduleMessage& message, 
									const sparks::shared_ptr<CLogicScheduler>& scheduler,
									const sparks::shared_ptr<CGameDataHolder>& data)
	{

	};
};

