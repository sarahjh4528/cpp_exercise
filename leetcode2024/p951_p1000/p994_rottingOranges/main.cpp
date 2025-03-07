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
/*
Runtime 3 ms Beats 30.32%
Memory 16.57 MB Beats 93.91%

Same design as fastest solution.

Time: O(m*n), Space O(m*n)
*/

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int fresh = 0, m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    fresh++;
                else if (grid[i][j] == 2)
                    q.push(make_pair(i, j));

            }
        }
        if (fresh == 0)
            return 0;
        if (q.size() == 0)  // no rotting orange
            return -1;

        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        int res = 0;
        while (!q.empty() && fresh > 0) {
            res++;
            int qsize = q.size();
            for (int i = 0; i < qsize; i++) {
                auto [x,y] = q.front();
                q.pop();
                for (auto& [dx,dy] : dirs) {
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        fresh--;
                        q.push(make_pair(nx, ny));
                    }
                }
            }     
        }
        return (fresh == 0)? res : -1;
    }

};

int main()
{
#if 0
    vector<vector<int>> grid = { {2,1,1},{1,1,0},{0,1,1} };
    vector<vector<int>> grid = { {2,1,1},{0,1,1},{1,0,1} };
    vector<vector<int>> grid = { {0,2} };
#endif
    vector<vector<int>> grid = { {2,1,1},{0,1,1},{1,0,1} };
    Solution s;

    int output = s.orangesRotting(grid);
    cout << "Minumum elapsed minutes to rotting oranges: " << output << endl;
    return 0;
}
