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
        int zIndx = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (zIndx == -1 && nums[i] == 0)
                zIndx = i;
            else if (zIndx != -1 && nums[i] != 0) {
                nums[zIndx] = nums[i];
                nums[i] = 0;
                ++zIndx;
            }
        }
    }
};
int main()
{
#if 0
    vector<int> listToMove = {0,1,0,3,12};
    vector<int> listToMove = {0};
    vector<int> listToMove = {1,2,3,4,5,6};
    vector<int> listToMove = {1,2,3,4,5,0,0};
#endif
    vector<int> listToMove = {1,2,3,4,5,0,0};
    Solution s;
    s.moveZeroes(listToMove);
    s.printList(listToMove);
    return 0; 
}
