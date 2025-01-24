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
1 <= s.length <= 30
s consists of lowercase English letters, digits, and square brackets '[]'.
s is guaranteed to be a valid input.
All the integers in s are in the range [1, 300].
*/
/*
Runtime 0 ms Beats 100.00%
Memory 9.74 MB Beats 23.48%

Time: O(k*n), k:max digits, n: str length()
Space: O(k*n)

TODO: Implement recursive function
*/
    string decodeString(string s) {
        stack<string> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ']') {
                st.push(string(1, s[i]));
            } else {
                string token = "";
                while (!st.empty() && st.top()[0] != '[') {
                    token = st.top() + token;
                    st.pop();
                }
                st.pop();   // pop '['
                string nstr = "";
                while (!st.empty() && isdigit(st.top()[0])) {
                    nstr = st.top() + nstr;
                    st.pop();
                }
                int n = stoi(nstr);
                string curStr = "";
                while (n > 0) {
                    curStr += token;
                    n--;
                }
                st.push(curStr);
            }
        }
        string res = "";
        while (!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};

int main()
{
    vector<string> vs = {
        "3[a]2[bc]",
        "3[a2[c]]",
        "2[abc]3[cd]ef"
    };
    Solution s;

    for (auto str : vs) {
        cout << "Orig str: " << str << endl;
        string output = s.decodeString(str);
        cout << "After decode: " << output << endl;
    }
    return 0;
}
