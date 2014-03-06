#pragma once
#include "common/config.h"
#include "google/protobuf/message.h"

class CConnection;
class INetworkMessageHandler {
public:
	virtual void OnNetworkMessage(sparks::shared_ptr<CConnection>& conn, const ::google::protobuf::message& msg) = 0;
};