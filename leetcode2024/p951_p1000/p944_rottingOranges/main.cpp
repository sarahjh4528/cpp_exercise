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
        int res = 0, row = grid.size(), col = grid[0].size();
        vector<vector<int>> visited(row, vector<int>(col, 0));
        queue<pair<int, int>> q;
        int fresh = 0, turnrot = 0;
        vector<vector<int>> dirs = {{1,0},{-1,0}, {0,1},{0,-1}};
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1)
                    fresh++;
                if (grid[i][j] == 2)
                    q.push(make_pair(i,j));
            }
        }
        if (fresh == 0)
            return 0;
        if (q.size() == 0)
            return -1;

        while (!q.empty()) {
            res++;      // First round should be counted, therefore return res-1
            int qsize = q.size();
            for (int i = 0; i < qsize; i++) {
                auto [x,y] = q.front();
                q.pop();
                for (auto dir : dirs) {
                    int dx = x + dir[0];
                    int dy = y + dir[1];
                    if (dx >= 0 && dy >= 0 && dx < row && dy < col && grid[dx][dy] == 1 && !visited[dx][dy]) {
                        turnrot++;
                        grid[dx][dy] = 2;
                        q.push(make_pair(dx,dy));
                        visited[dx][dy] = 1;
                    }
                }
            }
        }
        return  (fresh == turnrot)? res-1 : -1;
    }

};

int main()
{
#if 0
    vector<vector<int>> grid = { {2,1,1},{1,1,0},{0,1,1} };
    vector<vector<int>> grid = { {2,1,1},{0,1,1},{1,0,1} };
    vector<vector<int>> grid = { {0,2} };
#endif
    vector<vector<int>> grid = { {0,2} };
    Solution s;

    int output = s.orangesRotting(grid);
    cout << "Minumum elapsed minutes to rotting oranges: " << output << endl;
    return 0;
}
