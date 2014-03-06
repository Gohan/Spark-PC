#include "logic/instrument/GameContainer.h"
#include "logic/steps/PreparationStep.h"
#include "test/MockClass/MockPlayer.h"
#include "GameContainerTest.h"

void CGameContainerTest::SetUp()
{
}

void CGameContainerTest::TearDown()
{
}

void CGameContainerTest::TestBody()
{
}

void CGameContainerTest::SetUpTestCase()
{

}

void CGameContainerTest::TearDownTestCase()
{

}


TEST_F(CGameContainerTest, TEST_01) {
	// 新建一个GameContainer, 标识一个游戏
	sparks::shared_ptr<CGameContainer> spGameContainer(new CGameContainer());
	sparks::shared_ptr<CPlayer> spPlayer1(new CMockPlayer());
	sparks::shared_ptr<CPlayer> spPlayer2(new CMockPlayer());
	sparks::shared_ptr<CPlayer> spPlayer3(new CMockPlayer());

	spPlayer1->PlayerId(1);
	spPlayer2->PlayerId(2);
	spPlayer3->PlayerId(3);

	spGameContainer->AddPlayer(spPlayer1);
	spGameContainer->AddPlayer(spPlayer2);
	spGameContainer->AddPlayer(spPlayer3);


}


