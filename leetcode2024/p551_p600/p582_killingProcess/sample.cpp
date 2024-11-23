/*
Constraints:

n == pid.length
n == ppid.length
1 <= n <= 5 * 104
1 <= pid[i] <= 5 * 10^4
0 <= ppid[i] <= 5 * 10^4
Only one process has no parent.
All the values of pid are unique.
kill is guaranteed to be in pid.
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

    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
    }
};

int main()
{
    vector<vector<int>> vpid = {
        {1,3,10,5},
        {1},
    };
    vector<vector<int>> vppid = {
        {3,0,5,3},
        {0},
    };
    vector<int> vkill = {5, 1};
    Solution s;

    for (int i = 0; i < vpid.size(); i++) {
        cout << "parent pid: " << endl;
        s.printVec(vppid[i]);
        cout << "pid: " << endl;
        s.printVec(vpid[i]);
        vector<int> output = s.killProcess(vpid[i], vppid[i], vkill[i]);
        cout << "Processes to kill: " << endl;
        s.printVec(output);
    }
    return 0;
}
