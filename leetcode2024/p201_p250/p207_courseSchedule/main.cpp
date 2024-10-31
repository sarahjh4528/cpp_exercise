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
Runtime 10 ms Beats 30.18%
Memory 20.46 MB Beats 17.46

Same design as fastest solution
*/
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int plen = prerequisites.size();
        if (plen <= 1)
            return true;
        unordered_map<int, vector<int>> preMap; // precourse for list of courses
        vector<int> degree(numCourses, 0);    // Pre course num for course i
        for (auto pr : prerequisites) {
            preMap[pr[1]].push_back(pr[0]);
            degree[pr[0]]++;
        }
        int taken = 0;
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (degree[i] == 0)
                q.push(i);  // Push courses without prerequisite
        }
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            taken++;
            for (auto cl : preMap[course]) {
                degree[cl]--;
                if (degree[cl] == 0)
                    q.push(cl);
            }               
        }
        return taken == numCourses;
    }
};

int main()
{
#if 0
    vector<vector<int>> prerequisites = {
        {1,0}
    };
    int numCourses = 2;
    vector<vector<int>> prerequisites = {
        {1,0}, {0,1}
    };
    int numCourses = 2;
#endif
    vector<vector<int>> prerequisites = {
        {1,0}, {0,1}
    };
    int numCourses = 2;

    Solution s;

    bool output = s.canFinish(numCourses, prerequisites);
    for (auto pre : prerequisites)
        s.printVec(pre);
    cout << "Can finish all courses: " << output << endl;
    return 0;
}
