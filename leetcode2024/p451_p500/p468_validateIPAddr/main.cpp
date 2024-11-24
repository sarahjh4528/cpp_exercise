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

    string validIPAddress(string queryIP) {
        regex ipv4("(([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])");
        regex ipv6("((([0-9a-fA-F]){1,4})\\:){7}([0-9a-fA-F]){1,4}");
        
    }
};

int main()
{
    vector<string> vqueryIP = {
        "172.16.254.1",
        "2001:0db8:85a3:0:0:8A2E:0370:7334",
        "256.256.256.256"
    };
    Solution s;

    for (auto ip : vqueryIP) {
        cout << ip << endl;
        string output = svalidIPAddress(ip);
        cout << output << endl;
    }

    return 0;
}
