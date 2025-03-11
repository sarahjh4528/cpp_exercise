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
n == nums1.length == nums2.length
1 <= n <= 10^5
0 <= nums1[i], nums2[j] <= 10^5
1 <= k <= n
*/
/*
Runtime 68 ms Beats 51.60%
Memory 94.80 MB Beats 82.50%

Same solution as fastest solution.

Time: O(n)+O(nlog(n))+O(n*log(k)) => O(nlog(n))
Space: O(n)+O(k) => O(n)
*/
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int size = nums1.size();
        vector<pair<int, int>> vn(size);
        for (int i = 0; i < nums1.size(); i++) {
            vn[i].first = nums2[i];
            vn[i].second = nums1[i];
        }
        sort(vn.rbegin(), vn.rend());
        long long res = 0, curSum = 0;
        priority_queue<int, vector<int>, greater<int>> minQ;
        for (int i = 0; i < k; i++) {
            minQ.push({vn[i].second});
            curSum += vn[i].second;
        }
        res = curSum * vn[k-1].first;
        for (int i = k; i < size; i++) {
            auto& [n2, n1] = vn[i];
            if (n1 > minQ.top()) {
                curSum -= minQ.top();
                minQ.pop();
                curSum += n1;
                minQ.push(n1);
                res = max(res, curSum * n2);
            }
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> vnum1 = {
        {1,3,3,2},
        {4,2,3,1,1}
    };
    vector<vector<int>> vnum2 = {
        {2,1,3,4},
        {7,5,10,9,6}
    };
    vector<int> vk = {3,1};
    Solution s;

    for (int i = 0; i < vnum1.size(); i++) {
        s.printVec(vnum1[i]);
        s.printVec(vnum2[i]);
        long long output = s.maxScore(vnum1[i], vnum2[i], vk[i]);
        cout << "Maximum subseq score: " << output << endl;
    }
    return 0;
}
