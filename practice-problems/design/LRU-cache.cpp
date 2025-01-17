#include <unordered_map>
#include <list> // for linked list
#include <utility>

using namespace std;

class LRUCache {
    private:
        int _capacity;
        list<pair<int, int>> cache; // doubly linked list to store KV store
        unordered_map<int, list<pair<int, int>>::iterator> hashmap; // key to iterator mapping

    public:
        LRUCache(int capacity) : _capacity(capacity) {}

        int get(int key) {
            // if key is not in the cache, return -1
            if (hashmap.find(key) == hashmap.end()) {
                return -1;
            }

            // move the accessed KV pair to the front of the list
            auto it = hashmap[key];
            int value = it->second;
            cache.erase(it);
            cache.push_front({key, value});
            hashmap[key] = cache.begin();

            return value;
        }

        void put(int key, int value) {
            // if the key already exist, update its value and move it to the front
            if (hashmap.find(key) != hashmap.end()) {
                auto it = hashmap[key];
                cache.erase(it);
            } else if (cache.size() == _capacity) {
                // if the cache is at capacity, remove the least recently used item
                auto lru = cache.back(); // back of the list is the least recently used
                hashmap.erase(lru.first);
                cache.pop_back();
            }

            // Insert the new KV pair at the front of the list
            cache.push_front({key, value});
            hashmap[key] = cache.begin();
        }
};


