#include "ThreadTest.h"
#include "system/ThreadManager.h"



void CThreadTest::SetUpTestCase()
{

}

void CThreadTest::TearDownTestCase()
{

}

void CThreadTest::SetUp()
{

}

void CThreadTest::TearDown()
{

}

void CThreadTest::TestBody()
{

}

void TEST_01_f()
{
	printf("Current Thread %d\n", GetCurrentThreadId());
}

TEST_F(CThreadTest, TEST_01) {
	sparks::shared_ptr<CThread> spThread(new CThread());
	spThread->SetThreadName("TEST_01 thread");
	spThread->StartThread();
	sparks::shared_ptr<boost::thread>& thread = spThread->GetThread();
	spThread->GetIOService().post(TEST_01_f);
	spThread->GetIOService().post(boost::bind(&CThread::StopThread, spThread));
	thread->join();
}

TEST_F(CThreadTest, TEST_02) {
	sparks::shared_ptr<CThreadManager> spThreadManager(new CThreadManager());
	sparks::shared_ptr<CThread> spThread(new CThread());
	spThread->SetThreadName("TEST_01 thread");
	spThreadManager->AddThread(spThread);
	spThreadManager->AddThread(spThread);
	spThread->StartThread();

	sparks::shared_ptr<boost::thread>& thread = spThread->GetThread();
	spThread->GetIOService().post(TEST_01_f);
	spThread->GetIOService().post(boost::bind(&CThread::StopThread, spThread));
	thread->join();
}

TEST_F(CThreadTest, TEST_03) {
	sparks::shared_ptr<CThreadManager> spThreadManager(new CThreadManager());
	sparks::shared_ptr<CThread> spThread = spThreadManager->GetThreadByName("TEST_02 thread");
	ASSERT_TRUE(spThread == NULL);
}