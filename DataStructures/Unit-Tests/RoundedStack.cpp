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

	TEST(RoundedStack, BehavesLikeStackIfCapNotExceeded) {
		RoundedStack<char> stack(30);
		std::string s = "data_to_push_on_stack";
		std::string expectedOutput = "kcats_no_hsup_ot_atad";
		std::string output;

		for (auto& c: s)
			stack.push(c);

		EXPECT_EQ(stack.size(), s.length());

		while (!stack.empty())
		{
			output += stack.top();
			stack.pop();
		}

		EXPECT_EQ(output, expectedOutput);
	}

	TEST(RoundedStack, InitiallyEmpty)
	{
		RoundedStack<int> stack(3);
		EXPECT_TRUE(stack.empty());
		EXPECT_EQ(stack.size(), 0);
		EXPECT_DEATH(stack.pop(), "");
	}

}