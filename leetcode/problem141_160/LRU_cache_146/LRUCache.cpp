#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;

typedef list<int>::iterator LIT;

class LRUCache {
private:
    unordered_map<int, pair<int, LIT>> cacheMap;
    list<int> cacheQ;
    int cacheCap;
    void updateList(unordered_map<int, pair<int, LIT>>::iterator it) {
        cacheQ.erase((it->second).second);
        cacheQ.push_front(it->first);
        (it->second).second = cacheQ.begin();
    }
public:
    LRUCache(int capacity): cacheCap(capacity) {
    }
    
    int get(int key) {
        unordered_map<int, pair<int, LIT>>::iterator it = cacheMap.find(key);

        if (it != cacheMap.end()) {
            updateList(it);
            return (it->second).first;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        unordered_map<int, pair<int, LIT>>::iterator it = cacheMap.find(key);
        if (it != cacheMap.end()) {
            updateList(it);
            (it->second).first = value;
            return;
        }
        
        if (cacheQ.size() == cacheCap) {
            int key = cacheQ.back();
            cacheQ.pop_back();
            cacheMap.erase(key);
        }
        cacheQ.push_front(key);
        cacheMap[key] = {value, cacheQ.begin()};
    }
};
int main()
{
    LRUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);

    int val = cache.get(1);
    cout << val << endl;
    cache.put(3, 3);
    val = cache.get(2);
    cout << val << endl;
    cache.put(4, 4);
    val = cache.get(1);
    cout << val << endl;
    val = cache.get(4);
    cout << val << endl;

    return 0;
}
