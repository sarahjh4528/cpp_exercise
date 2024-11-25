/*
Constraints:

1 <= s1.length, s2.length <= 10^4
s1 and s2 consist of lowercase English letters.
*/
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

    bool checkInclusion(string s1, string s2) {
    }
};

int main()
{
    vector<string> vs1 = {
        "ab",
        "ab",
        "adc",
        "abc",
        "trinitrophenylmethylnitramine"
    };
    vector<string> vs2 = {
        "eidbaooo",
        "eidboaoo",
        "dcda",
        "bbbca",
        "dinitrophenylhydrazinetrinitrophenylmethylnitramine"
    };
    Solution s;

    for (int i = 0; i < vs1.size(); i++) {
        cout << "s1 (" << vs1[i] << ")" << endl;
        cout << "s2 (" << vs2[i] << ")" << endl;
        bool output = s.checkInclusion(vs1[i], vs2[i]);
        cout << "Permutation in string: " << output << endl;
    }

    return 0;
}
