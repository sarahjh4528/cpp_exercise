#include<iostream>

using namespace std;

bool isUnique(string inStr)
{
    int charCount[256] = {0};
    int strLen = inStr.length();
    if (strLen == 0)
        return false;

    for (int i = 0; i != strLen; ++i) {
        if (charCount[inStr[i]] == 0)
            charCount[inStr[i]] += 1;
        else
            return false;
    }
    return true;
}

int main()
{
    string inStr[5] = {"abcde", "aaaaa", "aca", "a,i3@,", ""};

    for (auto istr : inStr) {
        bool allUnique = false; 
        allUnique = isUnique(istr);
        if (allUnique) 
            cout << "String " << istr << " contains all unique char." << endl;
        else
            cout << "String " << istr << " contains duplicate char or empty." << endl;
    }
    return 0;
}
