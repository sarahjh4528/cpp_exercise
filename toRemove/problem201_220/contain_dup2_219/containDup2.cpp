#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>

using namespace std;

class Solution
{
public:
// 32ms
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.empty())
            return false;
    
        unordered_map<int, int> nMap;
        int minDist = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            if (nMap.find(nums[i]) != nMap.end()) {
                minDist = min(minDist, i - nMap[nums[i]]);
            }
            nMap[nums[i]] = i;
        }
        if (minDist <= k)
            return true;
        else
            return false;
    }
};

int main()
{
#if 0
    vector<int> nums = {1,2,3,1};
    int k = 3;

    vector<int> nums = {1,0,1,1};
    int k = 1;

    vector<int> nums = {1,2,3,1,2,3};
    int k = 2;

    vector<int> nums = {99,99};
    int k = 2;

    vector<int> nums = {};
    int k = 0;

    vector<int> nums = {1,2,3,4,5,6,7,8,9,9};
    int k = 3;
#endif
    vector<int> nums = {};
    int k = 0;

    Solution s;
    bool dupk = s.containsNearbyDuplicate(nums, k);
    cout << "Contains nearby dup : " << dupk << endl;
    return 0;
}
