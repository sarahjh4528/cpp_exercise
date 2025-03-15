#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
    void sumHelper(int k, int rn, int from, vector<int>& v, vector<vector<int>>& res) {
        if (rn == 0 && v.size() == k) {
            res.push_back(v);
            return;
        } else if (v.size() == k || rn <= 0) {
            return;
        }
        for (int i = from; i <= 9; i++) {
            v.push_back(i);
            sumHelper(k, rn-i, i+1, v, res);
            v.pop_back();
        }
    }

public:
    void printVec(vector<int>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

/*
2 <= k <= 9
1 <= n <= 60
*/
/*
Runtime 0 ms Beats 100.00%
Memory 8.64 MB Beats 79.96%
*/
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        if (k > n)
            return res;
            
        vector<int> v;
        sumHelper(k, n, 1, v, res);
        return res;
    }
};

int main()
{
    vector<int> vk = {3,3,4};
    vector<int> vn = {7,9,1};
    Solution s;

    for (int i = 0; i < vk.size(); i++) {
        cout << "k = " << vk[i] << ", n = " << vn[i] << endl;
        vector<vector<int>> output = s.combinationSum3(vk[i], vn[i]);
        for (auto row : output)
            s.printVec(row);
    }
    return 0;
}
