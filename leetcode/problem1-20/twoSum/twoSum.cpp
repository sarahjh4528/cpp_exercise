#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.empty())
            return {};

        vector<int> res;
        unordered_map<int, int> numNindex;
        numNindex[target-nums[0]] = 1;
        for (int i = 1; i < nums.size(); ++i) {
            int curNum = nums[i];
            if (numNindex[curNum]) {
                res.push_back(numNindex[curNum] - 1);
                res.push_back(i);
                break;
            } else {
                numNindex[target-curNum] = i+1;
            }
        }
        return res;
    }
};
int main()
{
    vector<int> nums = {2,7,11,15};
    int target = 9;

    Solution s;
    vector<int> indices = s.twoSum(nums, target);
    for (auto i : indices) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
