#include<bits/stdc++.h>
#include<iostream>
#include<queue>

using namespace std;

class Solution {
public:
    void printVec(vector<int>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

/*
Constraints:

1 <= k <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
*/
/*
Runtime 18 ms Beats 89.09%
Memory 61.56 MB Beats 43.32%

Time: O(nlog(n))
Space: O(k)

In theory, quick select avg time complexity, O(n), worst case O(n^2), though
the solution runs much slower than following solution.
*/
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minQ;
        for (auto n : nums) {
            if (minQ.size() < k)
                minQ.push(n);
            else if (n > minQ.top()) {
                minQ.push(n);
                minQ.pop();
            }
        }
        return minQ.top();
    }
};

int main()
{
    vector<vector<int>> input = {
        {3,2,1,5,6,4},
        {3,2,3,1,2,4,5,5,6}
    };
    vector<int> nk = {2, 4};
    Solution s;

    for (int i = 0; i < nk.size(); i++) {
        s.printVec(input[i]);
        int output = s.findKthLargest(input[i], nk[i]);
        cout << nk[i] << "th largest element of array: " << output << endl;
    }
    return 0;
}
