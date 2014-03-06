#include "logic/instrument/Player.h"
#include "logic/instrument/GameDataHolder.h"
#include "common/config.h"
#include "PreparationStep.h"
#include <deque>

void CPreparationStep::OnGameMessage( GameMessage::GameMessage& message, const sparks::shared_ptr<CLogicScheduler>& scheduler, const sparks::shared_ptr<CGameDataHolder>& data )
{

}

void CPreparationStep::OnSchedulerMessage( ScheduleMessage::ScheduleMessage& message, const sparks::shared_ptr<CLogicScheduler>& scheduler, const sparks::shared_ptr<CGameDataHolder>& data )
{
	GameMessage::GameMessage msg;
	GameMessage::PlayerGamGeneralActionNotify* pNotify =
		msg.mutable_msg_body()->MutableExtension(GameMessage::player_general_action_notify);
	pNotify->set_type(GameMessage::PlayerGamGeneralActionNotify_Type_ENTER_PREPARATION_STEP);

	const std::deque<sparks::shared_ptr<CPlayer>>& deqPlayers = data->GetPlayers();
	for each (const sparks::shared_ptr<CPlayer>& player in deqPlayers)
	{
		player->OnGameMessage(msg);
	}
}
