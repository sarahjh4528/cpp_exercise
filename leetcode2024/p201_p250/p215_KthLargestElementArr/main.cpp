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

    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minQ;
        for (auto n : nums) {
            minQ.push(n);
            if (minQ.size() > k)
                minQ.pop();
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
