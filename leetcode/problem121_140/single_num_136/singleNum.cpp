#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    int singleNumber(vector<int>& nums) {
        int xOrSum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            xOrSum ^= nums[i];
        }
        return xOrSum;
    }
};
int main()
{
#if 0
    vector<int> iList = {2,2,1};
    vector<int> iList = {4,1,2,1,2};
#endif
    vector<int> iList = {4,1,2,1,2};

    Solution s;
    int sNumber = s.singleNumber(iList);
    cout << "Single number: " << sNumber << endl;
    return 0;
}
