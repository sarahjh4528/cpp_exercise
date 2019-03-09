#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    int missingNumber(vector<int>& nums) {
        int diff = 0, totalNum = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            diff += i;
            diff -= nums[i];
        }
        diff += totalNum;
        return diff;
    }
};
int main()
{
#if 0
    vector<int> mList = {3, 0, 1};
    vector<int> mList = {9,6,4,2,3,5,7,0,1};
#endif
    vector<int> mList = {9,6,4,2,3,5,7,0,1};
    Solution s;
    int missNum = s.missingNumber(mList);
    cout << "Missing number: " << missNum << endl;
    return 0;
}
