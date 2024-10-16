/*
Runtime 165 ms Beats 57.18%
Memory 102.72 MB Beats 20.60%
Fastest solution similar design, just different data structure.
*/
class RandomizedSet {
    unordered_map<int, list<int>::iterator> hash;
    list<int> lst;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (hash.count(val))
            return false;
        lst.push_back(val);
        hash[val] = --lst.end();
        return true;
    }
    
    bool remove(int val) {
        if (!hash.count(val))
            return false;
        lst.erase(hash[val]);
        hash.erase(val);
        return true;
    }
    
    int getRandom() {
        int i = rand() % lst.size();
        auto it = lst.begin();
        while (i > 0) {
            it++;
            i--;
        }

        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
