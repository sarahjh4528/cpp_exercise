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
    int equalPairs(vector<vector<int>>& grid) {
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
