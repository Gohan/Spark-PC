#pragma once
#include "logic/proto/GameMessage.pb.h"
#include <google/protobuf/message.h>

class CMessageEncoder {
public:
	CMessageEncoder(){}
	~CMessageEncoder(){}
	static void EncodeGameMessage(GameMessage::GameMessage& msg);

};