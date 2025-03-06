#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    void printVec(vector<char>& v) {
        for (auto i : v)
            cout << i << ' ';
        cout << endl;
    }

/*
maze.length == m
maze[i].length == n
1 <= m, n <= 100
maze[i][j] is either '.' or '+'.
entrance.length == 2
0 <= entrancerow < m
0 <= entrancecol < n
entrance will always be an empty cell.
*/
/*
Runtime 6 ms Beats 70.75%
Memory 34.89 MB Beats 96.06%

Fastest solution add one more parameter "step" in queue, and skip the for loop (TODO)
*/
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '*';
        vector<pair<int, int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        int res = 0;
        while (!q.empty()) {
            res++;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [x,y] = q.front();
                q.pop();
                for (auto& [dx,dy] : dirs) {
                    int nx = x + dx, ny = y + dy;
                    if (nx < 0 || nx == m || ny < 0 || ny == n || maze[nx][ny] != '.')
                        continue;
                    if (nx == 0 || nx == m-1 || ny == 0 || ny == n-1)
                        return res;
                    maze[nx][ny] = '*';
                    q.push({nx,ny});
                }
            }
        }
        return -1;
    }
};

int main()
{
#if 0
    vector<vector<char>> maze = { {'+','+','.','+'},{'.','.','.','+'},{'+','+','+','.'} };
    vector<int> entrance = {1,2};

    vector<vector<char>> maze = { {'+','+','+'},{'.','.','.'},{'+','+','+'} };
    vector<int> entrance = {1,0};

    vector<vector<char>> maze = { {'.','+'} };
    vector<int> entrance = {0,0};

    vector<vector<char>> maze = {
        {'+','.','+','+','+','+','+'},
        {'+','.','+','.','.','.','+'},
        {'+','.','+','.','+','.','+'},
        {'+','.','.','.','+','.','+'},
        {'+','+','+','+','+','.','+'}
    };
    vector<int> entrance = {0,1};
#endif
    vector<vector<char>> maze = {
        {'+','.','+','+','+','+','+'},
        {'+','.','+','.','.','.','+'},
        {'+','.','+','.','+','.','+'},
        {'+','.','.','.','+','.','+'},
        {'+','+','+','+','+','.','+'}
    };
    vector<int> entrance = {0,1};
    Solution s;

    for (auto& row : maze)
        s.printVec(row);

    int output = s.nearestExit(maze, entrance);
    cout << "Min steps from entrance to exit: " << output << endl;
    return 0;
}
