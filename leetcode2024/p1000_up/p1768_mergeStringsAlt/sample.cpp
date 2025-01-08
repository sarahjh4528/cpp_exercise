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

    string mergeAlternately(string word1, string word2) {
    }
};

int main()
{
    vector<string> vword1 = {
        "abc", "ab", "abcd"
    };
    vector<string> vword2 = {
        "pqr", "pqrs", "pq"
    };
    Solution s;

    for (int i = 0; i < vword1.size(); i++) {
        cout << vword1[i] << " : " << vword2[i] << endl;
        string output = s.mergeAlternately(vword1[i], vword2[i]);
        cout << "Merged string: " << output << endl;
    }
    

    vector<int> input = {1,2,3,4,5,6};
    s.printVec(input);
    return 0;
}
