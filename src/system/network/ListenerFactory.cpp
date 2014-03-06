#include "ListenerFactory.h"

sparks::shared_ptr<INetworkListener> CListenerFactory::CreateListener( const std::string& address, sparks::shared_ptr<CThread> spThread )
{
	int nStartPos = 0;
	std::string ip;
	std::string type;
	sparks::int32 port = 0;
	if (ParseType(address, &nStartPos, type)) {
		if (ParseIPAddress(address, &nStartPos, ip)) {
			if (ParsePort(address, &nStartPos, port)) {
				// ½âÎö¸÷¸÷uri×Ö¶Î
			}
		}
	}
	if (type == "tcp" && ip.length() && port != 0) {
		boost::asio::ip::tcp::endpoint point(boost::asio::ip::address::from_string(ip), port);
		return sparks::shared_ptr<INetworkListener>(new CTcpListener(spThread->GetIOService(), point));
	}

	return sparks::shared_ptr<INetworkListener>();
}

bool CListenerFactory::ParseType( const std::string& address, int* start, std::string& type ) {
	if (*start >= address.length() || *start < 0) {
		return false;
	}

	std::string str = address.substr(*start);
	if (str.find("tcp://") == 0) {
		type = "tcp";
		*start += 6;
	} else if (str.find("udp://") == 0) {
		type = "udp";
		*start += 6;
	} else if (str.find("pipe://") == 0) {
		type = "pipe";
		*start += 7;
	} else {
		return false;
	}

	return true;
}

bool CListenerFactory::ParseIPAddress( const std::string& address, int* start, std::string& ip ) {
	if (*start >= address.length() || *start < 0) {
		return false;
	}

	size_t pos = address.find(':', *start);
	ip = address.substr(*start, pos);
	if (pos != address.npos) {
		*start = pos+1;
	} else {
		*start = pos;
	}
	return true;
}

bool CListenerFactory::ParsePort( const std::string& address, int* start, sparks::int32& port )
{
	if (*start >= address.length() || *start < 0) {
		return false;
	}

	size_t pos = address.find_first_not_of("0123456789", *start);
	std::string strPort = address.substr(*start, pos);
	port = strtoul(strPort.c_str(), NULL, 10);
	return true;
}
