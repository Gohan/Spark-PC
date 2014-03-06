#include "NetworkServiceTest.h"
#include "system/network/NetworkConnection_i.h"
#include "system/network/NetworkService.h"


void CNetworkServiceTest::SetUpTestCase()
{

}

void CNetworkServiceTest::TearDownTestCase()
{

}

void CNetworkServiceTest::SetUp()
{

}

void CNetworkServiceTest::TearDown()
{

}

void CNetworkServiceTest::TestBody()
{

}

TEST_F(CNetworkServiceTest, TEST_1)
{
	sparks::shared_ptr<CNetworkService> spService(new CNetworkService());
	spService->AddListener("tcp://0.0.0.0:9999");
	spService->Start();
	Sleep(60000);
}