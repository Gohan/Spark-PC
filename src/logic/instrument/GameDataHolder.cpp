#include "GameDataHolder.h"


CGameDataHolder::CGameDataHolder(void) {
	m_spHavestSpace.reset(new CHarvestSpace());
}


CGameDataHolder::~CGameDataHolder(void) {
	m_spHavestSpace.reset();
}

void CGameDataHolder::AddPlayer( const sparks::shared_ptr<CPlayer>& player ) {
	m_deqPlayers.push_back(player);
}
