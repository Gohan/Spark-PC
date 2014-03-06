#pragma once
#include "common/config.h"
#include "system/Thread.h"
#include "NetworkConnection_i.h"
#include "ListenerFactory.h"
#include <boost/asio.hpp>
#include <list>
#include <map>

using boost::asio::ip::tcp;

// 这个是服务端使用的网络接收服务类
class CNetworkService {
public:
	CNetworkService();
	~CNetworkService();
	void AddListener(const std::string& listener);
	void RemoveListener(const std::string& listener);
	void OnMessage(const sparks::shared_ptr<INetworkConnection>& conn, const ::google::protobuf::Message& message);
	void Start();
	void Stop();
private:
	void Run();
	void OnConnected(const sparks::shared_ptr<INetworkConnection>& conn);
	void OnDisConnected(const sparks::shared_ptr<INetworkConnection>& conn, sparks::int32 error_code);

	sparks::shared_ptr<CThread> m_spThread;
	typedef std::list<sparks::shared_ptr<INetworkConnection>> NetworkConnectionList;
	NetworkConnectionList m_listConnections;
	typedef std::map<std::string, sparks::shared_ptr<INetworkListener>> NetworkListenerMap;
	NetworkListenerMap m_mapListeners;

	std::map<sparks::shared_ptr<INetworkConnection>, NetworkConnectionList::iterator> m_mapConnections;
};