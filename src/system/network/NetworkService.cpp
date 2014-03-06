#include "NetworkService.h"


void CNetworkService::AddListener( const std::string& listener )
{
	sparks::shared_ptr<INetworkListener> spListener = CListenerFactory::CreateListener(listener, m_spThread);
	m_mapListeners[listener] = spListener;
	spListener->Start();
}

void CNetworkService::Start()
{
	m_spThread->StartThread();
}

CNetworkService::CNetworkService()
{
	m_spThread.reset(new CThread());
	m_spThread->SetThreadName("NetworkService Thread");
}

void CNetworkService::Stop()
{
	m_spThread->StopThread();
}

CNetworkService::~CNetworkService()
{

}

void CNetworkService::Run()
{

}

void CNetworkService::OnConnected( const sparks::shared_ptr<INetworkConnection>& conn )
{

}

void CNetworkService::RemoveListener( const std::string& listener )
{

}

void CNetworkService::OnMessage( const sparks::shared_ptr<INetworkConnection>& conn, const ::google::protobuf::Message& message )
{

}

void CNetworkService::OnDisConnected( const sparks::shared_ptr<INetworkConnection>& conn, sparks::int32 error_code )
{

}
