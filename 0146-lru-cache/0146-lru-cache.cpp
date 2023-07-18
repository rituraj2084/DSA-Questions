class LRUCache {
private:
    int capacity;
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    list<int> lruList;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            // Key exists in the cache
            // Move the key to the front of the LRU list
            lruList.erase(cache[key].second);
            lruList.push_front(key);
            cache[key].second = lruList.begin();
            return cache[key].first;
        }
        return -1; // Key does not exist in the cache
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Key already exists, update the value and move it to the front of the LRU list
            lruList.erase(cache[key].second);
            lruList.push_front(key);
            cache[key] = { value, lruList.begin() };
        } else {
            // Key doesn't exist, add it to the cache
            if (cache.size() == capacity) {
                // Remove the least recently used key from the cache
                int lruKey = lruList.back();
                lruList.pop_back();
                cache.erase(lruKey);
            }
            lruList.push_front(key);
            cache[key] = { value, lruList.begin() };
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */