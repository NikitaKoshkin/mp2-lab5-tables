#pragma once
//#pragma comment(lib, "gtest.lib")
#include "gtest.h"


int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}