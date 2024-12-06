/*
Constraints:

0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
*/
#include<bits/stdc++.h>
#include<iostream>
#include<unordered_set>

using namespace std;

class Solution {
public:
    void printVec(vector<int>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

/*
Design: construct an unordered_set, guarantee unique number.

e.g.  100, 4, 200, 2, 3, 1
Loop through set, 100 doesn't have 99, start count, no 101, therefore seq length = 1,
4: yes, we have 3 in nset, skip
3, 2 in set, skip
2, 1 in set, skip
1, no 0 in set, start count, yes 2, +1, yes 3, + 1, yes 4, + 1 => consecutive seq len = 4;
*/
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() <= 1)
            return (nums.size());

        unordered_set nset(nums.begin(), nums.end());
        int res = 0;
        for (auto it = nset.begin(); it != nset.end(); it++) {
            int n = *it;
            if (!nset.count(n-1)) {
                while (nset.count(n+1))
                    n++;
                res = max(res, n - *it + 1);
            }
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> vnums = {
        {100,4,200,1,3,2},
        {0,3,7,2,5,8,4,6,0,1}
    };
    Solution s;

    for (auto nums : vnums) {
        s.printVec(nums);
        int output = s.longestConsecutive(nums);
        cout << "Longest consecutive seq length: " << output << endl;
    }

    return 0;
}
