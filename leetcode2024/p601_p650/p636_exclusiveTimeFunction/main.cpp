/*
Runtime 12 ms Beats 78.61%
Memory 18.37 MB Beats 35.93%
*/
#include<bits/stdc++.h>
#include<iostream>
#include<stack>
#include<sstream>

using namespace std;

class Solution {
    void getJobDetails(string& job, int& id, int& time, string& action) {
        stringstream ss(job);
        string token;
        getline(ss, token, ':');
        id = stoi(token);
        getline(ss, token, ':');
        action = token;
        getline(ss, token, ':');
        time = stoi(token);
    }

public:
    void printVec(vector<string>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        stack<pair<int, int>> st;   // pair<jobid, startime>
        int id, time;
        string action;
        for (auto log : logs) {
            getJobDetails(log, id, time, action);
            if (action == "start")
                st.push(make_pair(id, time));
            else {
                auto curjob = st.top();
                st.pop();
                int runtime = time - curjob.second + 1;
                res[id] += runtime;
                if (!st.empty())
                    res[st.top().first] -= runtime;
            }
        }

        return res;
    }

};

int main()
{
    vector<vector<string>> nlogs = {
        {"0:start:0","1:start:2","1:end:5","0:end:6"},
        {"0:start:0","0:start:2","0:end:5","0:start:6","0:end:6","0:end:7"},
        {"0:start:0","0:start:2","0:end:5","1:start:6","1:end:6","0:end:7"}
    };
    vector<int> vn = {2,1,2};

    Solution s;
    for (int i = 0; i < vn.size(); i++) {
        s.printVec(nlogs[i]);
        vector<int> output = s.exclusiveTime(vn[i], nlogs[i]);
        cout << "Output: ";
        for (auto t : output)
            cout << t << " ";
        cout << endl;
    }

    return 0;
}
