/*
 * Faster than 93% of cpp submissions.
 */
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    void printVec(const vector<int>& nums) {
        for (auto i : nums)
            cout << i << " ";
        cout << endl;
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> tMap;
        int nLen = nums.size();
        for (int i = 0; i < nLen; i++) {
            if (tMap.find(nums[i]) != tMap.end())
                return {tMap[nums[i]], i};
            else
                tMap[target - nums[i]] = i;
        }
        return {};
    }

};

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    Solution s;
    vector<int> ret = s.twoSum(nums, 9);
    s.printVec(ret);

    return 0;
}
