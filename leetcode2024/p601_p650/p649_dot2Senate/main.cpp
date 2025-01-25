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
/*
Runtime 0 ms Beats 100.00%
Memory 11.67 MB Beats 25.92%

Time: O(n), n : senate length
Space; O(n)
*/
    string predictPartyVictory(string senate) {
        int num = senate.size();
        queue<int> rq, dq;
        for (int i = 0; i < num; i++) {
            if (senate[i] == 'R')
                rq.push(i);
            else
                dq.push(i);
        }
        while (!rq.empty() && !dq.empty()) {
            int ri = rq.front(), di = dq.front();
            rq.pop();
            dq.pop();
            if (ri < di)  // D is banned, push R to end of queue.
                rq.push(ri + num);
            else
                dq.push(di + num);
        }
        return (rq.empty())? "Dire" : "Radiant";
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
