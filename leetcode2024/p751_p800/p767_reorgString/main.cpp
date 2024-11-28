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
Runtime 0 ms Beats 100.00%
Memory 8.43 MB Beats 66.20%

Let N be the total characters in the string.
Let k be the total unique characters in the string.
Time : O(Nlogk), priority_queue takes log(K) to insert
Space : O(K)

*/
    string reorganizeString(string s) {
        vector<int> cfreq(26, 0);
        for (auto c : s)
            cfreq[c-'a']++;

        priority_queue<pair<int, char>> pq;
        for (int i = 0; i < 26; i++) {
            if (cfreq[i] > 0)
                pq.push({cfreq[i], i+'a'});
        }

        string res = "1";
        while (!pq.empty()) {
            auto [f,c] = pq.top();
            pq.pop();
            if (res[res.length()-1] == c) {
                if (pq.empty())
                    return "";
                auto [f2, c2] = pq.top();
                pq.pop();
                res += c2;
                f2--;
                if (f2 > 0)
                    pq.push({f2, c2});
                pq.push({f,c});
            } else {
                res += c;
                f--;
                if (f > 0)
                    pq.push({f, c});
            }
        }
        return res.substr(1);
        
    }
};

int main()
{
    vector<string> vs = {
        "aab",
        "aaab"
    };
    Solution s;

    for (auto str : vs) {
        cout << str << endl;
        string output = s.reorganizeString(str);
        cout << "After reorg: " << output << endl;
    }
    return 0;
}
