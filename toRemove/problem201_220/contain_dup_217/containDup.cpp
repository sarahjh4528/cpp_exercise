#include<iostream>
#include<vector>
//#include<unordered_map>
//#include<algorithm>
#include<set>

/*
 * My solution : unordered_map
 * A better solution : sort, then loop and compare, if same, return true
 */
using namespace std;

class Solution
{
public:
    void printList(const vector<int>& nums) {
        for (auto i : nums)
            cout << i << " ";
        cout << endl;
    }

#if 0
// 44ms
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> numCount;
        for (auto i : nums) {
            if (numCount[i])
                return true;
            else
                numCount[i] = 1;
        }
        return false;
    }
#endif

// 40ms
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.size() < 2)
            return false;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i-1])
                return true;
        }
        return false;
    }

#if 0
// 60ms
    bool containsDuplicate(vector<int>& nums) {
        set<int> nSet(nums.begin(), nums.end());
        if (nums.size() == nSet.size())
            return false;
        else
            return true;
    }
#endif
};

int main()
{
#if 0
    vector<int> inList = {1,2,3,4};
    vector<int> inList = {1,2,3,1};
    vector<int> inList = {1,1,1,3,3,4,3,2,4,2};
#endif
    vector<int> inList = {1,1,1,3,3,4,3,2,4,2};

    Solution s;
    s.printList(inList);
    bool dup = s.containsDuplicate(inList);
    cout << "Contains dup : " << dup << endl;
    return 0;
}
