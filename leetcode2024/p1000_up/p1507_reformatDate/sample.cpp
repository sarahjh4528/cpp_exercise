/*
Constraints:

The given dates are guaranteed to be valid, so no error handling is necessary.
*/
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
    unordered_map<string, string> mmap = {
        {"Jan", "01"},
        {"Feb", "02"},
        {"Mar", "03"},
        {"Apr", "04"},
        {"May", "05"},
        {"Jun", "06"},
        {"Jul", "07"},
        {"Aug", "08"},
        {"Sep", "09"},
        {"Oct", "10"},
        {"Nov", "11"},
        {"Dec", "12"}
    };
public:
    void printVec(vector<int>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

    string reformatDate(string date) {
    }

};

int main()
{
    vector<string> vdate = {
        "20th Oct 2052",
        "6th Jun 1933",
        "26th May 1960"
    };
    Solution s;

    for (auto date : vdate) {
        cout << "Input : " << date << endl;
        string output = s.reformatDate(date);
        cout << "Output : " << output << endl;
    }
    vector<int> input = {1,2,3,4,5,6};
    s.printVec(input);
    return 0;
}
