#include "logic/instrument/GameDataHolder.h"
#include "logic/steps/PreparationStep.h"
#include "test/MockClass/MockPlayer.h"
#include "PreparationStepTest.h"
void CPreparationStepTest::SetUp()
{
}

void CPreparationStepTest::TearDown()
{
}

void CPreparationStepTest::TestBody()
{
}

void CPreparationStepTest::SetUpTestCase()
{

}

void CPreparationStepTest::TearDownTestCase()
{

}


TEST_F(CPreparationStepTest, TEST_01) {
	// 收到初始化通知后, Step将会给每个玩家发送通知
	sparks::shared_ptr<CGameDataHolder> spDataHolder(new CGameDataHolder());
	sparks::shared_ptr<CPreparationStep> spStep(new CPreparationStep());
	sparks::shared_ptr<CLogicScheduler> spScheduler(new CLogicScheduler());

	GameMessageDequeSPtr spMessageDeque(new GameMessageDeque());
	sparks::shared_ptr<CMockPlayer> players[3];
	sparks::int64 playerIds[3] = {111,222,333};
	for (int i = 0; i < 3; i++) {
		players[i].reset(new CMockPlayer());
		players[i]->SetMessageResultList(spMessageDeque);
		players[i]->PlayerId(playerIds[i]);
		spDataHolder->AddPlayer(players[i]);
	}

	ScheduleMessage::ScheduleMessage msg;
	ScheduleMessage::BasicScheduleEvent* pEvent =
		msg.mutable_msg_body()->MutableExtension(ScheduleMessage::basic_schedule_event);

	pEvent->set_basic_event_type(ScheduleMessage::BasicScheduleEvent_BasicEventType_ENTER_STEP);
	spStep->OnSchedulerMessage(msg, spScheduler, spDataHolder);

	ASSERT_TRUE(spMessageDeque->size() > 0) << "玩家应该收到通知";
}


