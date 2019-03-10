#include<iostream>
#include<vector>

using namespace std;

class NumArray
{
private:
    vector<int> myArr;
public:
    NumArray(vector<int> nums) {
        myArr.insert(myArr.begin(), nums.begin(), nums.end());
    }
    
    int sumRange(int i, int j) {
        int sum = 0;
        while (i < j) {
            sum = sum + myArr[i] + myArr[j];
            ++i;
            --j;
        }
        return (i == j)? sum + myArr[i] : sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
    
int main()
{
    vector<int> nums = {-2, 0, 3, -5, 2, -1};

    NumArray obj(nums);
#if 0
    int i = 0, j = 2;
    int i = 2, j = 5;
    int i = 0, j = 5;
#endif
    int i = 0, j = 5;
    int param_1 = obj.sumRange(i, j);
    cout << "Sum of elements from " << i << " to j " << j << " is " << param_1 << endl;
    return 0;
}
