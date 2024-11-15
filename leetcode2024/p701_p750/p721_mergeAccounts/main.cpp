#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
    void dfs(unordered_map<string, vector<string>>& adjacent, string email, unordered_map<string, bool>& visited, vector<string>& v) {
        v.push_back(email);
        visited[email] = true;
        for (auto m : adjacent[email]) {
            if (!visited.count(m))
                dfs(adjacent, m, visited, v);
        }
    }
public:
    void printVec(vector<string>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }
/*
Runtime 67 ms Beats 33.83%
Memory 57.58 MB Beats 5.94%

Fastest solution : Union Find. TODO
*/
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, vector<string>> adjacent;
        for (auto account : accounts) {
            string email1 = account[1];
            for (int i = 2; i < account.size(); i++) {
                adjacent[email1].push_back(account[i]);
                adjacent[account[i]].push_back(email1);
            }
        }
        unordered_map<string, bool> visited;
        vector<vector<string>> res;
        for (auto account : accounts) {
            string email1 = account[1];
            if (!visited.count(email1)) {
                vector<string> cur;
                dfs(adjacent, email1, visited, cur);
                sort(cur.begin(), cur.end());
                cur.insert(cur.begin(), account[0]);
                res.push_back(cur);
            }
        }
        return res;
    }
};

int main()
{
#if 0
    vector<vector<string>> accounts = {
        {"John","johnsmith@mail.com","john_newyork@mail.com"},
        {"John","johnsmith@mail.com","john00@mail.com"},
        {"Mary","mary@mail.com"},
        {"John","johnnybravo@mail.com"},
    };
    vector<vector<string>> accounts = {
        {"Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"},
        {"Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"},
        {"Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"},
        {"Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"},
        {"Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"}
    };
#endif
    vector<vector<string>> accounts = {
        {"John","johnsmith@mail.com","john_newyork@mail.com"},
        {"John","johnsmith@mail.com","john00@mail.com"},
        {"Mary","mary@mail.com"},
        {"John","johnnybravo@mail.com"},
    };
    Solution s;

    vector<vector<string>> output = s.accountsMerge(accounts);
    for (auto v : output)
        s.printVec(v);
    return 0;
}
