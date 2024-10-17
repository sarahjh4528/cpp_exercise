/*
Runtime 4 ms Beats 91.65%
Memory 12.57 MB Beats 44.66%
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

/*
Design: Treat board combination as string
Final target : 123450
Take 1st example: 123405 => 123450 only takes one move, swap 5 and 0.

Starting from:
    1 2 3
    4 0 5
0 is at the 4th position, there are 3 possible swaps, 0-2, 0-4, 0-5,
Position wise: 1-4, 3-4, 5-4

Define a vector with all possible moves with 0 at the position.
0 : 1-0, 3-0
1 : 0-1, 2-1, 4-1
2 : 1-2, 5-2
3 : 0-3, 4-3
4 : 1-4, 3-4, 5-4
5 : 2-5, 4-5

vector<vector<int>> possibleMoves = {
    {1,3}, {0,2,4}, {1,5}, {0,4}, {1,3,5}, {2,4}
};
*/
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> moves = {
            {1,3}, {0,2,4}, {1,5}, {0,4}, {1,3,5}, {2,4}
        };
        string target ="123450";
        string start = "";
        for (auto row : board) {
            for (auto n : row)
                start += to_string(n);
        }
        if (start == target)
            return 0;
        unordered_map<string, int> visited;
        visited[start] = 1;
        queue<pair<string, int>> q;
        q.push({start, 0});
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            string curstr = cur.first;
            int curdist = cur.second;
            int p0 = curstr.find('0');
            for (auto i : moves[p0]) {
                string newstr = curstr;
                swap(newstr[i], newstr[p0]);
                if (newstr == target)
                    return curdist+1;
                if (!visited.count(newstr)) {
                    visited[newstr] = 1;
                    q.push({newstr, curdist+1});
                }
            }
        }
        return -1;
    }
};

int main()
{
#if 0
    vector<vector<int>> board = { {1,2,3},{4,0,5} };
    vector<vector<int>> board = { {1,2,3},{5,4,0} };
    vector<vector<int>> board = { {4,1,2},{5,0,3} };
#endif
    vector<vector<int>> board = { {4,1,2},{5,0,3} };
    Solution s;

    for (auto row : board)
        s.printVec(row);
    
    int output = s.slidingPuzzle(board);
    cout << "Take " << output << " moves to reach target 123450" << endl;
    
    return 0;
}
