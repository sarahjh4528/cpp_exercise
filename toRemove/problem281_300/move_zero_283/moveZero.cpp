#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    void printList(vector<int>& l) {
        for (auto i : l)
            cout << i << " ";
        cout << endl;
    }
    void moveZeroes(vector<int>& nums) {
        int totalZeros = 0, zeros = 0;
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] == 0) {
                ++zeros;
                while (i+zeros < nums.size() && nums[i+zeros] == 0)
                    ++zeros;
                if (i+zeros == nums.size())
                    break;
            }
            if (zeros > 0) {
                totalZeros += zeros;
                nums.erase(nums.begin() + i, nums.begin() + i + zeros);
                zeros = 0;
            }
            ++i;
        }
        if (totalZeros > 0) {
            vector<int> zList(totalZeros, 0);
            nums.insert(nums.end(), zList.begin(), zList.end());
        }
    }
};
int main()
{
#if 0
    vector<int> listToMove = {0,1,0,3,12};
#endif
    vector<int> listToMove = {0};
    Solution s;
    s.moveZeroes(listToMove);
    s.printList(listToMove);
    return 0; 
}
