/*
Runtime 9 ms Beats 92.04%
Memory 22.62 MB Beats 93.46%
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
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n-1][n-1] != 0)
            return -1;
        if (n == 1 && grid[0][0] == 0)
            return 1;
        int res = 0;
        queue<pair<int, int>> q;
        q.push(make_pair(0,0));
        grid[0][0] = -1;
        while (!q.empty()) {
            res++;
            int qsize = q.size();
            for (int i = 0; i < q.size(); i++) {
                auto cur = q.front();
                q.pop();
                for (int nx = max(0, cur.first-1), maxX = min(n-1, cur.first+1); nx <= maxX; nx++) {
                    for (int ny = max(0, cur.second-1), maxY = min(n-1, cur.second+1); ny <= maxY; ny++) {
                        if (nx == n-1 && ny == n-1)
                            return res+1;
                        if (grid[nx][ny] == 0) {
                            grid[nx][ny] = -1;
                            q.push(make_pair(nx, ny));
                        }
                    }
                }
            }
        }
        return -1;
    }
};

int main()
{
#if 0
    vector<vector<int>> matrix = { {0,1},{1,0} };
    vector<vector<int>> matrix = { {0,0,0},{1,1,0},{1,1,0} };
    vector<vector<int>> matrix = { {1,0,0},{1,1,0},{1,1,0} };
#endif
    vector<vector<int>> matrix = { {0,0,0},{1,1,0},{1,1,0} };
    Solution s;

    for (auto row : matrix)
        s.printVec(row);

    int output = s.shortestPathBinaryMatrix(matrix);
    cout << "Shortest path: " << output << endl;
    return 0;
}
