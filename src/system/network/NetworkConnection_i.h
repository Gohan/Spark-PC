#pragma once
#include "common/config.h"
#include <boost/enable_shared_from_this.hpp>
#include <boost/signals2.hpp>
class INetworkConnection : public boost::enable_shared_from_this<INetworkConnection> {
public:
	boost::signals2::signal<void(const ::google::protobuf::Message& msg)> onMessage;
	boost::signals2::signal<void()> onConnect;
	boost::signals2::signal<void(sparks::int32 error_code)> onDisConnect;
	virtual void SendAsync(sparks::shared_ptr<GameMessage::GameMessage> msg); = 0;
	virtual void Start() = 0;
	virtual void Stop() = 0;
};