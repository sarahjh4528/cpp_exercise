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
1 <= arr.length <= 1000
-1000 <= arr[i] <= 1000
*/
    bool uniqueOccurrences(vector<int>& arr) {
    }
};

int main()
{
    vector<vector<int>> varr = {
        {1,2,2,1,1,3},
        {1,2},
        {-3,0,1,-3,1,1,1,-3,10,0}
    };
    Solution s;

    for (auto arr : varr) {
        s.printVec(arr);
        bool output = s.uniqueOccurrences(arr);
        cout << "Arr elements has unique count: " << output << endl;
    }

    return 0;
}
