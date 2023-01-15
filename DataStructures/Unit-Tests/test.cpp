#include "pch.h"

#include "LRUCache.h"

namespace LRUCacheTests
{
	TEST(LRUCache, SizeDoesNotExceedCapacity) {
		LRUCache<int, int> cache(5);
		EXPECT_EQ(cache.size(), 0);
		for (int i = 0; i < 10; ++i)
			cache.put(i, i);
		EXPECT_EQ(cache.size(), 5);
	}

}