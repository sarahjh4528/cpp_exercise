/*
Constraints:

1 <= capacity <= 3000
0 <= key <= 10^4
0 <= value <= 10^5
At most 2 * 10^5 calls will be made to get and put.
*/
#include<bits/stdc++.h>
#include<iostream>
#include<list>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
    }
   
    int get(int key) {
    }
   
    void put(int key, int value) {
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
