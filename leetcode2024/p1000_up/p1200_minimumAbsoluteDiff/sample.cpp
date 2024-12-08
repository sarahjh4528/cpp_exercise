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
        cout << " , ";
    }

    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
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
        cout << endl;
    }

    return 0;
}
