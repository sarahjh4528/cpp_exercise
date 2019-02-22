#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> eCount;
        int level = nums.size()/2 + 1;
        for (auto i : nums) {
            if (++eCount[i] >= level)
                return i;
        }
        return -1;
    }
};

int main()
{
#if 0
    vector<int> nums = {3,2,3};
    vector<int> nums = {2,2,1,1,1,2,2};
    vector<int> nums = {1};
    vector<int> nums = {3,3,4};
#endif
    vector<int> nums = {1};
    Solution s;

    int majElm = s.majorityElement(nums);
    cout << majElm << endl;
    return 0;
}
