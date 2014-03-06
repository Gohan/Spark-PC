#pragma once
#include "common/config.h"
#include "logic/proto/GameMessage.pb.h"
class CPlayer
{
public:
	CPlayer(void);
	virtual ~CPlayer(void);
	virtual void OnGameMessage(const GameMessage::GameMessage& message);

	sparks::uint64 PlayerId() const { return m_uPlayerId; }
	void PlayerId(sparks::uint64 val) { m_uPlayerId = val; }
private:
	sparks::uint64 m_uPlayerId;
};

