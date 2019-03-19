#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int>& nums) {
        if (nums.empty())
            return false;
        if (nums.size() == 1)
            return true;

        int gap = 0;
        for (int i = nums.size() - 2; i >= 0; --i) {
            ++gap;
            if (nums[i] >= gap)
                gap = 0;
        }
        return (gap > 0)? false : true;
    }
};
int main()
{
#if 0
    vector<int> pos = {2,3,1,1,4};
    vector<int> pos = {3,2,1,0,4};
#endif
    vector<int> pos = {3,2,1,0,4};

    Solution s;
    bool jump = s.canJump(pos);

    for (auto i : pos)
        cout << i << " ";
    cout << endl;

    cout << "Can jump : " << jump << endl;
    return 0;
}
