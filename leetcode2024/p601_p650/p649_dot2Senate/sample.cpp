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
n == senate.length
1 <= n <= 10^4
senate[i] is either 'R' or 'D'.
*/
    string predictPartyVictory(string senate) {
    }
};

int main()
{
    vector<string> vsenate = { "RD", "RDD" };
    Solution s;

    for (auto senate : vsenate) {
        cout << "Input seq: " << senate << endl;
        string output = s.predictPartyVictory(senate);
        cout << "Victory party: " << output << endl;
    }
    return 0;
}
