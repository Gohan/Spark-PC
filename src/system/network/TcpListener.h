#pragma once
#include "NetworkListener_i.h"
#include "NetworkConnection_i.h"
#include "TcpConnection.h"
#include "common/config.h"
#include <boost/asio.hpp>
using boost::asio::ip::tcp;

class CTcpListener : public INetworkListener{
public:
	CTcpListener(boost::asio::io_service& io_service,
		const tcp::endpoint& endpoint)
		: m_oIoService(io_service),
		m_oAcceptor(io_service, endpoint)
	{
		start_accept();
	}

	void Start() {

	}

	void Stop() {

	}

	void start_accept()
	{
		sparks::shared_ptr<CTcpConnection> spNetworkConnection(new CTcpConnection(m_oIoService));
		m_oAcceptor.async_accept(spNetworkConnection->GetSocket(),
			boost::bind(&CTcpListener::handle_accept, this, spNetworkConnection,
			boost::asio::placeholders::error));
	}

	void handle_accept(sparks::shared_ptr<CTcpConnection> conn,
		const boost::system::error_code& error)
	{
		if (!error)
		{
			conn->Start();
		}

		start_accept();
	}

private:
	boost::asio::io_service& m_oIoService;
	tcp::acceptor m_oAcceptor;
};