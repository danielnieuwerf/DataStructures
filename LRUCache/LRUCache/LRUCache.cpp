#include <iostream>
#include "LRUCache.h"

int main()
{
    LRUCache<int, int> cache(10);
    int x = 1e2;
    while (x--)
    {
        cache.put(x, x);
    }
    
    x = 1e3;
    while (x--)
    {
        int out;
        if(cache.get(x, out))
            std::cout << "Got " << out << " from " << x << std::endl;
        else
            std::cout << "Failed to get value from " << x << std::endl;
    }

    return 0;
}