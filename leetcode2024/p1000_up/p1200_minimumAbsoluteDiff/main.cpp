/*
Constraints:

2 <= arr.length <= 10^5
-10^6 <= arr[i] <= 10^6
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
Runtime 15 ms Beats 87.32%
Memory 35.99 MB Beats 71.69%
*/
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int minDiff = INT_MAX;
        vector<vector<int>> res;
        for (int i = 1; i < arr.size(); i++) {
            int curdiff = arr[i] - arr[i-1];
            if (curdiff < minDiff) {
                res = {};
                res.push_back({arr[i-1], arr[i]});
                minDiff = curdiff;
            } else if (curdiff == minDiff) {
                res.push_back({arr[i-1], arr[i]});
            }
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> varr = {
        {4,2,1,3},
        {1,3,6,10,15},
        {3,8,-10,23,19,-4,-14,27}
    };
    Solution s;

    for (int i = 0; i < varr.size(); i++) {
        cout << "Input: " << endl;
        s.printVec(varr[i]);
        vector<vector<int>> output = s.minimumAbsDifference(varr[i]);
        cout << "Min diff pairs: " << endl;
        for (auto v : output)
            s.printVec(v);
    }

    return 0;
}
