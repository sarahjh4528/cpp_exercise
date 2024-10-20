/*
Runtime 301 ms Beats 5.11%
Fastest solution same design. Though no need to call extra function getNeighbours
*/
#include<bits/stdc++.h>
#include<iostream>
#include<queue>

using namespace std;

class Solution {
    vector<vector<int>> moves = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
public:
    void printVec(vector<int>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }
    
    vector<pair<int, int>> getNeighbours(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& visited) {
        vector<pair<int, int>> res;
        int row = grid.size(), col = grid[0].size();
        for (auto m : moves) {
            int x = i + m[0], y = j + m[1];
            if (x < 0 || x >= row || y < 0 || y >= col || grid[x][y] || visited[x][y])
                continue;
            res.push_back({x,y});
            visited[x][y] = 1;
        }
        return res;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        if (grid[0][0] != 0 || grid[row-1][col-1] != 0)
            return -1;

        queue<pair<int, int>> q;
        vector<vector<int>> visited(row, vector<int>(col, 0));
        q.push({0, 0});
        visited[0][0] = 1;
        int res = 0;
        while (!q.empty()) {
            res++;
            int qsize = q.size();
            for (int i = 0; i < qsize; i++) {
                auto cur = q.front();
                q.pop();
                int x = cur.first, y = cur.second; 
                if (x == row - 1 && y == col - 1)
                    return res;
                vector<pair<int, int>> neighbours = getNeighbours(x, y, grid, visited);
                for (auto n : neighbours)
                    q.push(n);
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
    vector<vector<int>> matrix = { {1,0,0},{1,1,0},{1,1,0} };
    Solution s;

    for (auto row : matrix)
        s.printVec(row);

    int output = s.shortestPathBinaryMatrix(matrix);
    cout << "Shortest path: " << output << endl;
    return 0;
}
