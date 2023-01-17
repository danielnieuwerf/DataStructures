#include "pch.h"

#include "RoundedStack.h"

namespace LRUCacheTests
{
	TEST(RoundedStack, BottomOfStackIsDroppedWhenFull) {
		RoundedStack<int> stack(3);
		for (int i = 1; i <= 4; ++i)
			stack.push(i);
		EXPECT_EQ(stack.size(), 3);
		
		int expectedVal = 4;
		while (!stack.empty())
		{
			auto& t = stack.top();
			stack.pop();
			EXPECT_EQ(t, expectedVal);
			--expectedVal;
		}
	}

	TEST(RoundedStack, InitiallyEmpty)
	{
		RoundedStack<int> stack(3);
		EXPECT_TRUE(stack.empty());
		EXPECT_EQ(stack.size(), 0);
		EXPECT_DEATH(stack.pop(), "");
	}

}