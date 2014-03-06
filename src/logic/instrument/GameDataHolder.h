#pragma once

#include "Player.h"
#include "HarvestSpace.h"
#include "common\config.h"
#include <deque>
#include <memory>

class CGameDataHolder
{
public:
	CGameDataHolder(void);
	~CGameDataHolder(void);
	void AddPlayer(const sparks::shared_ptr<CPlayer>& player);
	sparks::uint32 GetPlayerCount(){return m_deqPlayers.size();}

	sparks::shared_ptr<CPlayer> GetPlayerByPlayerId(sparks::uint64 id){
		if (m_deqPlayers.size()) {
			return m_deqPlayers.front();
		}
		return NULL;
	}

	const std::deque<sparks::shared_ptr<CPlayer>>& GetPlayers() {return m_deqPlayers;}

private:
	std::deque<sparks::shared_ptr<CPlayer>> m_deqPlayers;
	sparks::shared_ptr<CHarvestSpace> m_spHavestSpace;
};

