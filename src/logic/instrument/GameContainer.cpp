#include "GameContainer.h"
#include "GameDataHolder.h"

CGameContainer::CGameContainer(void)
{
	m_spHolder.reset(new CGameDataHolder());
	m_spScheduler.reset(new CLogicScheduler());
}


CGameContainer::~CGameContainer(void)
{
}

void CGameContainer::InitGame()
{

}

void CGameContainer::OnGameMessage( GameMessage::GameMessage& message )
{
	m_spScheduler->OnGameMessage(message);
}

void CGameContainer::AddPlayer( const sparks::shared_ptr<CPlayer>& spPlayer )
{
	m_spHolder->AddPlayer(spPlayer);
}
