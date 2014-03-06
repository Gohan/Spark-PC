#include "logic/instrument/Player.h"
#include "common/config.h"
#include <deque>

typedef std::deque<sparks::shared_ptr<GameMessage::GameMessage>> GameMessageDeque;
typedef sparks::shared_ptr<GameMessageDeque> GameMessageDequeSPtr;

class CMockPlayer: public CPlayer {
public:
	CMockPlayer(){};
	~CMockPlayer(){
		m_spMessageDeque.reset();
	};
	void SetMessageResultList(GameMessageDequeSPtr spDeque);
	virtual void OnGameMessage( const GameMessage::GameMessage& message );
private:
	GameMessageDequeSPtr m_spMessageDeque;
};