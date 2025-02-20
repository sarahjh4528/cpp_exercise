#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    void printVec(vector<int>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

/*
1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] is 1 or 0.
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]
*/
    void dfs(vector<vector<int>>& m, vector<bool>& visited, int i) {
        for (int j = 0; j < m.size(); j++) {
            if (!visited[j] && m[i][j] == 1) {
                visited[j] = 1;
                dfs(m, visited, j);
            }
        }
    }

/*
Runtime 0 ms Beats 100.00%
Memory 19.38 MB Beats 82.27%
*/
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n);
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i])
                continue;
            res++;
            dfs(isConnected, visited, i);
        }
        return res;
    }
};

int main()
{
#if 0
    vector<vector<int>> connected = { {1,1,0}, {1,1,0}, {0,0,1} };
    vector<vector<int>> connected = { {1,0,0}, {0,1,0}, {0,0,1} };
#endif
    vector<vector<int>> connected = { {1,0,0}, {0,1,0}, {0,0,1} };
    Solution s;

    for (auto row : connected)
        s.printVec(row);

    int output = s.findCircleNum(connected);
    cout << "Num of provinces: " << output << endl;
    return 0;
}
