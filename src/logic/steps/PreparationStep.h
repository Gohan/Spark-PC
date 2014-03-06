#include "logic/scheduler/LogicScheduler.h"
#include "logic/steps/GameStep.h"


class CPreparationStep: public CGameStep {
public:

	CPreparationStep(){
	}
	virtual ~CPreparationStep(void){}
	virtual void OnGameMessage(	GameMessage::GameMessage& message,
								const sparks::shared_ptr<CLogicScheduler>& scheduler,
								const sparks::shared_ptr<CGameDataHolder>& data);
	virtual void OnSchedulerMessage(ScheduleMessage::ScheduleMessage& message, 
									const sparks::shared_ptr<CLogicScheduler>& scheduler,
									const sparks::shared_ptr<CGameDataHolder>& data);
};