#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution
{
public:
    void getPermutations(vector<int>& nums, int start, vector<int>& cur, vector<vector<int>>& perms) {
        if (start == nums.size()) {
            perms.push_back(cur);
            return;
        }

        for (int i = start; i < nums.size(); ++i) {
            cur.push_back(nums[i]);
            swap(nums[i], nums[start]);
            getPermutations(nums, start+1, cur, perms);
            swap(nums[i], nums[start]);
            cur.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty())
            return {};
        if (nums.size() == 1)
            return {nums};

        vector<vector<int>> ret;
        vector<int> curPerm;
        getPermutations(nums, 0, curPerm, ret);
        return ret;
    }
};

int main()
{
#if 0
    vector<int> nums = {1,2,3};
    vector<int> nums = {1,2,3,5};
#endif
    vector<int> nums = {1,2,3,5};

    Solution s;
    vector<vector<int>> output = s.permute(nums);
    for (auto v : output) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
