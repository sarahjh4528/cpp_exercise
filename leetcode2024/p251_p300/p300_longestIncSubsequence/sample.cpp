/*
Constraints:

1 <= nums.length <= 2500
-10^4 <= nums[i] <= 10^4
*/
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    void printVec(vector<int>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

/*
Example:
10, 9, 2, 5
lower bound of 2 will return 9's iterator, replace value of 9 with 2, we can add 5 later
NOTE: Only replacing the number, not adding 2 in addition to 9.

res always represents the sequence with correct number of of increasing numbers
res is always in sorted order, therefore comparing with last one is enough.
*/

    int lengthOfLIS(vector<int>& nums) {
    }
};

int main()
{
    vector<vector<int>> vnums = {
        {10,9,2,5,3,7,101,18},
        {0,1,0,3,2,3},
        {7,7,7,7,7,7,7}
    };
    Solution s;

    for (int i = 0; i < vnums.size(); i++) {
        s.printVec(vnums[i]);
        int output = s.lengthOfLIS(vnums[i]);
        cout << "Longest increasong subsequence: " << output << endl;
    }
    
    return 0;
}