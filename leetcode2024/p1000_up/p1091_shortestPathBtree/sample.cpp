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
        queue<pair<int,int>> q;
        q.push(make_pair(0,0));
        grid[0][0] = -1;
        int res = 0;
        while (!q.empty()) {
            int qsize = q.size();
            res++;
            for (int i = 0; i < q.size(); i++) {
                auto [x,y] = q.front();
                q.pop();
                for (int nx = max(0, x-1), curmaxX = min(n-1, x+1); nx <= curmaxX; nx++) {
                    for (int ny = max(0, y-1), curmaxY = min(n-1, y+1); ny <= curmaxY; ny++) {
                        if (grid[nx][ny] != 0)
                            continue;
                        if (nx == n-1 && ny == n-1)
                            return res+1;
                        q.push(make_pair(nx,ny));
                        grid[nx][ny] = -1;
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
    vector<vector<int>> matrix = { {0,1},{1,0} };
    Solution s;

    for (auto row : matrix)
        s.printVec(row);

    int output = s.shortestPathBinaryMatrix(matrix);
    cout << "Shortest path: " << output << endl;
    return 0;
}
