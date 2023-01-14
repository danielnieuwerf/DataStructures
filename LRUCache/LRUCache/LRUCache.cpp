#include <iostream>

template <typename S, typename T>
class LRUCache {
private:
    uint32_t _capacity;

public:
    LRUCache(uint32_t capacity) : _capacity(capacity) {}

    void put(S key, T val)
    {

    }

    T get(S key)
    {
        return {};
    }
};

int main()
{
    LRUCache<int, int> cache(10);
    cache.put(1, 1);

}