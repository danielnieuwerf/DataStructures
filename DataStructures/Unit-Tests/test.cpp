#include "pch.h"

#include "LRUCache.h"

namespace LRUCacheTests
{
	void zero_capacity()
	{
		LRUCache<int, int> cache(0);
	}

	TEST(LRUCache, SizeDoesNotExceedCapacity) {
		LRUCache<int, int> cache(5);
		EXPECT_EQ(cache.size(), 0);
		for (int i = 0; i < 10; ++i)
			cache.put(i, i);
		EXPECT_EQ(cache.size(), 5);
	}

	TEST(LRUCache, LeastRecentlyUsedEvictedWhenCapacityReached) {
		LRUCache<int, int> cache(5);
		for (int i = 0; i < 10; ++i)
			cache.put(i, i);

		int outValue;
		for (int i = 5; i < 10; ++i)
		{
			EXPECT_TRUE(cache.get(i, outValue));
			EXPECT_EQ(i, outValue);
		}

		for (int i = 0; i < 5; ++i)
		{
			EXPECT_FALSE(cache.get(i, outValue));
		}
	}

	TEST(LRUCache, ThrowIfZeroCapacity) {
		EXPECT_DEATH(zero_capacity(), "");
	}


	TEST(LRUCache, GetUpdatesEvictionOrder) {
		LRUCache<int, int> cache(10);
		for (int i = 0; i < 10; ++i)
			cache.put(i, i);

		int outValue;
		EXPECT_TRUE(cache.get(1, outValue));
		EXPECT_EQ(outValue, 1);

		EXPECT_TRUE(cache.get(3, outValue));
		EXPECT_EQ(outValue, 3);
		
		cache.put(11, 11);
		EXPECT_TRUE(cache.get(11, outValue));
		EXPECT_EQ(outValue, 11);
		EXPECT_FALSE(cache.get(0, outValue));

		cache.put(12, 12);
		EXPECT_TRUE(cache.get(12, outValue));
		EXPECT_EQ(outValue, 12);
		EXPECT_FALSE(cache.get(2, outValue));
		EXPECT_TRUE(cache.get(1, outValue));
		EXPECT_EQ(outValue, 1);
	}
}