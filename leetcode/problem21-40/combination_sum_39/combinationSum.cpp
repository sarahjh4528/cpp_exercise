#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution
{
private:
    vector<vector<int>> res;
    vector<int> tmp;
public:
    void combinationSumHelper(vector<int>& candidates, int start, int end, int sum, int target) {
        if (sum == target) {
            res.push_back(tmp);
            return;
        } else if (sum > target) {
            // not a good combincation
            return;
        }
        for (int i = start; i <= end && candidates[i] <= target-sum; ++i) {
            sum += candidates[i];
//            cout << "sum : " << sum << ", cur num " << candidates[i] << endl;
            tmp.push_back(candidates[i]);
            combinationSumHelper(candidates, i, end, sum, target);
            sum -= candidates[i];
            tmp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        if (candidates.empty() || candidates[0] > target)
            return {{}};
        int i = candidates.size() - 1;
        while (candidates[i] > target)
            --i;

        combinationSumHelper(candidates, 0, i, 0, target);
        return res;
    }
};
int main()
{
#if 0
    vector<int> nums = {2,3,6,7};
    int target = 7;

    vector<int> nums = {2};
    int target = 1;
#endif
    vector<int> nums = {2,3,6,7};
    int target = 7;

    Solution s;
    vector<vector<int>> combinations = s.combinationSum(nums, target);
    for (auto v : combinations) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
