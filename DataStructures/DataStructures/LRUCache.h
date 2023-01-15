#include <unordered_map>
#include <assert.h>

/*
*   LRU Cache implemented with a Hash Map and Doubly Linked List.
*   O(1) average retrieval and insertion.
*   
*   TODO:
*   - Check for memory leaks.
* 
*   Extensions:
*   - Thread Safety.
*   - Custom Hash template.
*   - Custom Key Equals template.
*/


/// <summary>
/// Least Recently Used (LRU) Cache that stores key-value pairs.
/// The capacity of the cache is set at construction and if this capacity
/// is exceeded, the least recently used Key is removed from the Cache.
/// Key must have a hash function and equality comparison function.
/// </summary>
template <typename Key, typename Value>
class LRUCache {
public:
    explicit LRUCache(uint32_t capacity) : _capacity(capacity) {
        assert(capacity != 0);
        head.next = &tail;
        tail.prev = &head;
    }

    ~LRUCache() 
    {
        for (auto& p : _mp)
            delete p.second;    
    };

    void put(Key key, Value value)
    {
        auto it = _mp.find(key);
        if (it != _mp.end())    // Already in cache so just update value and move to head.
        {
            it->second->value = value;
            move_to_head(it->second);
            return;
        }

        Node* node = new Node(key, value, nullptr, nullptr);
        if (size() == _capacity)
        {
            _mp.erase(tail.prev->key);  // Erase tail if capacity is reached.
            erase_tail();
        }

        _mp[key] = node;    // Insert the node into the hash map
        insert_head(node);  // This node is the new head.
    }


    bool get(Key key, Value& outValue)
    {
        auto it = _mp.find(key);
        if (it == _mp.end())
        {
            return false;
        }

        Node* node = it->second;
        move_to_head(node);
        outValue = node->value;
        return true;
    }

    size_t size()
    {
        return _mp.size();
    }

private:
    template <typename Key, typename Value>
    struct LRUCacheNode
    {
        LRUCacheNode() : key{}, value{}, prev(nullptr), next(nullptr) {}
        LRUCacheNode(Key key, Value value, LRUCacheNode* prev, LRUCacheNode* next) :
            key(key), value(value), prev(prev), next(next) {}

        Key key;
        Value value;
        LRUCacheNode* prev;
        LRUCacheNode* next;
    };

    using Node = LRUCacheNode<Key, Value>;
    uint32_t _capacity;

    // Hash map + Doubly Linked List.
    std::unordered_map<Key, Node*> _mp{};
    Node head;      // head <-> ... <-> tail
    Node tail;      

    void erase_tail()
    {
        Node* node = tail.prev;
        if (node != &head)
        {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
    }

    void insert_head(Node* node)
    {
        node->prev = &head;
        node->next = head.next;
        node->next->prev = node;
        head.next = node;
    }

    void move_to_head(Node* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = head.next;
        node->prev = &head;
        head.next->prev = node;
        head.next = node;
    }
};