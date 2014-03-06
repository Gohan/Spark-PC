#include "gtest\gtest.h"
#include "system/Thread.h"

class CThreadTest : public ::testing::Test{
public:
	static void SetUpTestCase();
	static void TearDownTestCase();

	virtual void SetUp();
	virtual void TearDown();
	virtual void TestBody();
};