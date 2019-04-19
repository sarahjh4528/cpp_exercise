/*
Design and implement a TwoSum class. It should support the following operations: add and find.
add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.
Example 1:
add(1); add(3); add(5);
find(4) -> true
find(7) -> false

Example 2:
add(3); add(1); add(2);
find(3) -> true
find(6) -> false
*/
/* 152ms, faster than 49.33%, 23.6MB, less than 97.62%
 * To improve, record min and max, if target is less than half of min or
 * bigger than 2 * max, return false, no need to go into the loop.
 */

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class TwoSum {
private:
    unordered_map<int, int> nMap;

    bool twoSumHelper(int val) {
        for (auto it : nMap) {
            int target = val - (it.first);
            if (nMap.find(target) != nMap.end()) {
                if (target == it.first && nMap[target] < 2)
                    continue;
                return true;
            }
        }
        return false;
    }
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        ++nMap[number];
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        return twoSumHelper(value);
    }

    void clear() {
        nMap.clear();
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */

int main()
{
    vector<vector<int>> inputs = {
        {1, 3, 5},
        {3, 1, 2},
        {0, -1, 1},
    };
    vector<vector<int>> targets = {
        {4, 7},
        {3, 6},
        {0},
    };
    TwoSum ts;
    for (int i = 0; i < inputs.size(); ++i) {
        for (auto num : inputs[i])
            ts.add(num);

        for (auto t : targets[i]) {
            bool findSum = ts.find(t);
            cout << "Find sum " << t << " : " << findSum << endl;
        }
        ts.clear();
    }
    return 0;
}
