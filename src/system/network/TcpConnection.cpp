#include "TcpConnection.h"
#include "MessageEncoder.h"

void CTcpConnection::SendAsync( sparks::shared_ptr<GameMessage::GameMessage> msg )
{
	// TODO 用IO的Post来同步数据发送
	m_oSocket.get_io_service().post()
	CMessageEncoder::EncodeGameMessage(*msg);
	bool bHasPendingWrite = m_deqMessage.size() > 0;
	m_deqMessage.push_back(msg);
	if (bHasPendingWrite == false) {
		DoNextWrite();
	}
}

void CTcpConnection::Start()
{
	onConnect();
	// m_oSocket.async_receive();
}

void CTcpConnection::Stop()
{
	onDisConnect(0);
}

void CTcpConnection::HandleWrite( const boost::system::error_code& error )
{
	if (error == 0) {
		m_deqMessage.pop_front();
		DoNextWrite();
	}
}

void CTcpConnection::DoNextWrite()
{
	if (m_deqMessage.size()) {
		sparks::shared_ptr<GameMessage::GameMessage> msg = m_deqMessage.front();
		boost::asio::async_write(m_oSocket, 
			boost::asio::buffer(msg->SerializeAsString().c_str(), msg->ByteSize()), 
			boost::bind(&CTcpConnection::HandleWrite, shared_from_this(), boost::asio::placeholders::error));
	}
}

