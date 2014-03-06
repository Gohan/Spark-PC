#include "gtest\gtest.h"
#include "logic\proto\GameMessage.pb.h"

class CGameContainerTest : public ::testing::Test{
public:
	static void SetUpTestCase();
	static void TearDownTestCase();

	virtual void SetUp();
	virtual void TearDown();
	virtual void TestBody();
};