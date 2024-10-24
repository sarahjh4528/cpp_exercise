/*
Runtime 99 ms Beats 96.08%
Memory 185.86 MB Beats 7.00%
*/
class LRUCache {
    int size;
    unordered_map<int, list<pair<int, int>>::iterator> map;
    list<pair<int, int>> lru;
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if (!map.count(key))
            return -1;
        auto it = map[key];
        int val = it->second;
        lru.erase(it);
        lru.push_back({key, val});
        map[key] = --lru.end();

        return val;
            
    }
    
    void put(int key, int value) {
        if (map.count(key)) {
            auto it = map[key];
            map.erase(it->first);
            lru.erase(it);
        } else if (lru.size() == size) {
            auto tmp = lru.front();
            map.erase(tmp.first);
            lru.pop_front();
        }
        lru.push_back({key, value});
        map[key] = --lru.end();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
