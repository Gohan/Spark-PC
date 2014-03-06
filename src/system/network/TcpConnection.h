#pragma once
#include "NetworkConnection_i.h"

#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>
#include <boost/asio/io_service.hpp>
#include <deque>

class CTcpConnection : public INetworkConnection {
public:
	CTcpConnection(boost::asio::io_service& io):m_oSocket(io){}
	~CTcpConnection(){}
	boost::asio::ip::tcp::socket& GetSocket() {
		return m_oSocket;
	}

	virtual void SendAsync(sparks::shared_ptr<GameMessage::GameMessage> msg);
	virtual void Start();;
	virtual void Stop();

private:
	void HandleWrite(const boost::system::error_code& error);
	void DoNextWrite();

	boost::asio::ip::tcp::socket m_oSocket;
	std::deque<sparks::shared_ptr<GameMessage::GameMessage>> m_deqMessage;
};