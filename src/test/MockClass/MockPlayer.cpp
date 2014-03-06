#include "MockPlayer.h"

void CMockPlayer::OnGameMessage( const GameMessage::GameMessage& message )
{
	m_spMessageDeque->push_back(sparks::shared_ptr<GameMessage::GameMessage>(new GameMessage::GameMessage()));
}

void CMockPlayer::SetMessageResultList( GameMessageDequeSPtr spDeque )
{
	m_spMessageDeque = spDeque;
}