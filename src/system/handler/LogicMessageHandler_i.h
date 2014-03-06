#pragma once
#include "common/config.h"
#include "google/protobuf/message.h"

class CConnection;
class ILogicMessageHandler {
public:
	virtual void OnLogicMessage(const ::google::protobuf::message& msg) = 0;
};