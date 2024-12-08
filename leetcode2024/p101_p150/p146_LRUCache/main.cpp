#include<bits/stdc++.h>
#include<iostream>
#include<list>

using namespace std;
/*
Runtime 99 ms Beats 96.08%
Memory 185.86 MB Beats 7.00%
*/
class LRUCache {
    int size;
    unordered_map<int, list<pair<int, int>>::iterator> map; // key : [key, val]::iterator
    list<pair<int, int>> lru;   // [key, val], push_back, erase from front()
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
        map[key] = prev(lru.end());

        return val;
    }
    
    void put(int key, int value) {
        if (map.count(key)) {
            auto it = map[key];
            lru.erase(it);
        } else if (lru.size() == size) {
            auto [k,v] = lru.front();
            map.erase(k);
            lru.pop_front();
        }
        lru.push_back({key, value});
        map[key] = prev(lru.end());
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
