/*
Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.
*/
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

    int orangesRotting(vector<vector<int>>& grid) {
    }

};

int main()
{
#if 0
    vector<vector<int>> grid = { {2,1,1},{1,1,0},{0,1,1} };
    vector<vector<int>> grid = { {2,1,1},{0,1,1},{1,0,1} };
    vector<vector<int>> grid = { {0,2} };
#endif
    vector<vector<int>> grid = { {2,1,1},{1,1,0},{0,1,1} };
    Solution s;

    int output = s.orangesRotting(grid);
    cout << "Minumum elapsed minutes to rotting oranges: " << output << endl;
    return 0;
}
