#include<bits/stdc++.h>
#include<iostream>
#include<list>

using namespace std;

class LRUCache {
    int size;
    list<pair<int, int>> lru;
    unordered_map<int, list<pair<int, int>>::iterator> lmap;
public:
    LRUCache(int capacity) {
        size = capacity;
    }
   
    int get(int key) {
        if (!lmap.count(key))
            return -1;

        auto it = lmap[key];
        int val = it->second;
        lru.erase(it);
        lru.push_back(make_pair(key, val));
        lmap[key] = prev(lru.end());
        return val;
    }
   
    void put(int key, int value) {
        if (lmap.count(key)) {
            auto it = lmap[key];
            lru.erase(it);
        } else if (lru.size() == size) {
            auto it = lru.front();
            lru.erase(lmap[it.first]);
            lmap.erase(it.first);
        }
        lru.push_back(make_pair(key, value));
        lmap[key] = prev(lru.end());
    }
};

int main()
{
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
    LRUCache lRUCache(2);
    lRUCache.put(1, 1); // cache is {1=1}
    cout << "Put 1:1" << endl;
    lRUCache.put(2, 2); // cache is {1=1, 2=2}
    cout << "Put 2:2" << endl;
    int output = lRUCache.get(1);    // return 1
    cout << "Get key 1: " << output << endl;
    lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    cout << "Put 3:3" << endl;
    output = lRUCache.get(2);    // returns -1 (not found)
    cout << "Get key 2 : " << output << endl;
    lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    cout << "Put 4:4" << endl;
    output = lRUCache.get(1);    // return -1 (not found)
    cout << "Get key 1 : " << output << endl;
    output = lRUCache.get(3);    // return 3
    cout << "Get key 3 : " << output << endl;
    output = lRUCache.get(4);    // return 4
    cout << "Get key 4 : " << output << endl;
    return 0;
}
