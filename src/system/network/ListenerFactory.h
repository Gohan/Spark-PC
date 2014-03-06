#pragma once
#include "common/config.h"
#include "system/Thread.h"
#include "system/network/TcpListener.h"
#include <boost/asio.hpp>

class CListenerFactory
{
public:
	static sparks::shared_ptr<INetworkListener> CreateListener(const std::string& address, sparks::shared_ptr<CThread> spThread);
private:
	static bool ParseType(const std::string& address, int* start, std::string& type);
	static bool ParseIPAddress(const std::string& address, int* start, std::string& ip);
	static bool ParsePort(const std::string& address, int* start, sparks::int32& port);
};