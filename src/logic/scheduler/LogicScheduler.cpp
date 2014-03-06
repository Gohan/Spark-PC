#include "LogicScheduler.h"
#include "logic/steps/PreparationStep.h"
CLogicScheduler::CLogicScheduler(void)
{
}

CLogicScheduler::~CLogicScheduler(void)
{
}

void CLogicScheduler::OnGameMessage(GameMessage::GameMessage& message)
{

}

void CLogicScheduler::InitLogicScheduler( sparks::int32 nType )
{
	m_nType = nType;
	m_deqSteps.push_back(sparks::shared_ptr<CGameStep>(new CPreparationStep()));
}
