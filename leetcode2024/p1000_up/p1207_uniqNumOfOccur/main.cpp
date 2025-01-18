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
/*
Runtime 0 ms Beats 100.00%
Memory 12.00 MB Beats 25.82%

Time: O(n), n: arr size
Space : O(n)
*/
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> amap;
        for (auto n : arr)
            amap[n]++;
        unordered_set<int> freq;
        for (auto it : amap) {
            if (freq.count(it.second))
                return false;
            freq.insert(it.second);
        }
        return true;
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
