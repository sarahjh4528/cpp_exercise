/*
Runtime 0 ms Beats 100.00%
Memory 9.22 MB Beats 6.99%
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

    string mergeAlternately(string word1, string word2) {
        int i = 0, j = 0, len1 = word1.length(), len2 = word2.length();
        string res = "";
        while (i < len1 && j < len2) {
            res = res + word1[i] + word2[j];
            i++;
            j++;
        }
        if (i < len1)
            res += word1.substr(i);
        else
            res += word2.substr(j);
        return res;
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
