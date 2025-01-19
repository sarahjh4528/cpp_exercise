#include<bits/stdc++.h>
#include<iostream>
#include<map>
//#include<set>

using namespace std;

class Solution {
public:
    void printVec(vector<int>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << ", ";
    }

/*
n == grid.length == grid[i].length
1 <= n <= 200
1 <= grid[i][j] <= 10^5
*/
/*
Design: Use vector<int> as key, though cannot use unordered_map, or unordered_set
Got compilation error if use unordered_map or unordered_set
Can not select set either, since there could be duplicate col or row elements, set will eliminate dup.

Time: O(n*n), Space O(n*n)
*/
/*
Runtime 8 ms Beats 87.77%
Memory 29.00 MB Beats 83.82%
*/
    int equalPairs(vector<vector<int>>& grid) {
        int res = 0, n = grid.size();
        vector<int> v(n, 0);
        map<vector<int>, int> gmap;
        for (int col = 0; col < n; col++) {
            int i = 0;
            while (i < n) {
                v[i] = grid[i][col];
                i++;
            }
            gmap[v]++;
        }
        for (int i = 0; i < n; i++)
            if (gmap.count(grid[i]))
                res += gmap[grid[i]];
        return res;
    }
};

int main()
{
#if 0
    vector<vector<int>> grid = { {3,2,1},{1,7,6},{2,7,7} };
    vector<vector<int>> grid = { {3,1,2,2},{1,4,4,5},{2,4,2,2},{2,4,2,2} };
    vector<vector<int>> grid = { {3,1,2,2},{1,4,4,4},{2,4,2,2},{2,5,2,2} };
#endif
    vector<vector<int>> grid = { 
        {3,1,2,2},
        {1,4,4,4},
        {2,4,2,2},
        {2,5,2,2} 
    };
    Solution s;

    for (auto row : grid)
        s.printVec(row);
    cout << endl;
    int output = s.equalPairs(grid);
    cout << "Pair of equal row and col: " << output << endl;
    return 0;
}
