#pragma once
#include <deque>
#include <cassert>

template <typename T>
class RoundedStack {
public:
    explicit RoundedStack(uint32_t capacity) : _capacity(capacity) {
        assert(capacity != 0);
        _size = 0;
    }

    bool empty()
    {
        return !_size;
    }

    T& top()
    {
        assert(_size);
        return _queue.back();
    }

    void pop()
    {
        assert(_size);
        --_size;
        _queue.pop_back();
    }

    void push(const T& val)
    {
        if (_size == _capacity)
        {
            _queue.pop_front();
            --_size;
        }

        _queue.push_back(val);
        ++_size;
    }

    size_t size()
    {
        return _size;
    }

private:
    uint32_t _capacity;
    size_t _size;
    std::deque<T> _queue;
};