#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    void printVec(vector<int>& vec) {
        for (auto n : vec)
            cout << n << " ";
        cout << endl;
    }

#if 0
    // 40ms, 16.6MB.
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hash;
        for (auto n : nums) {
            if (hash.find(n) != hash.end())
                return true;
            else
                hash.insert(n);
        }
        return false;
    }
    // 32ms, 17.8MB
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hash;
        for (auto n : nums)
            hash.insert(n);
        if (hash.size() == nums.size())
            return false;
        else
            return true;
            
    }
#else
    // 32ms, faster than 86%, 11.3MB less than 97%.
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() <= 1)
            return false;

        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i-1] == nums[i])
                return true;
        }
        return false;
    }
#endif
};

int main()
{
    vector<vector<int>> inputs = {
        {1,2,3,1},
        {1,2,3,4},
        {1,1,1,3,3,4,3,2,4,2}
    };

    Solution s;
    for (auto v : inputs) {
        s.printVec(v);
        bool hasDup = s.containsDuplicate(v);
        cout << "Has duplicate: " << hasDup << endl;
    }
    return 0;
}
