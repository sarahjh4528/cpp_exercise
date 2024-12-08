/*
Constraints:

m == grid.length
n == grid{i}.length
1 <= m, n <= 300
grid{i}{j} is '0' or '1'.
*/
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    void printVec(vector<int>& v) {
        for (auto i : v)
            cout << i << ' ';
        cout << endl;
    }

    int numIslands(vector<vector<char>>& grid) {
    }
};

int main()
{
#if 0
    vector<vector<char>> grid = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
#endif
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    Solution s;

    int output = s.numIslands(grid);
    cout << "Number of islands: " << output << endl;

    return 0;
}
