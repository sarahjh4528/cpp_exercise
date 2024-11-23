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

/*
Design: Scan through parent array, build hash table, key:value, ppid : vector<pid>
Find all child processes by BFS.

Runtime 41 ms Beats 90.37%
Memory 64.67 MB Beats 86.13%

Time: O(n), Space: O(n)
*/
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> pmap;
        for (int i = 0; i < pid.size(); i++)
            pmap[ppid[i]].push_back(pid[i]);
        
        vector<int> res;
        queue<int> q;
        q.push(kill);
        while (!q.empty()) {
            int qsize = q.size();
            for (int i = 0; i < qsize; i++) {
                int n = q.front();
                q.pop();
                res.push_back(n);
                if (pmap.count(n)) {
                    for (auto x : pmap[n])
                        q.push(x);
                }
            }
        }
        return res;
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
