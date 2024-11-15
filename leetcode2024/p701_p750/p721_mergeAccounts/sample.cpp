#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    void printVec(vector<string>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }
/*
Fastest solution : Union Find. TODO
*/
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
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
