#include<iostream>

using namespace std;

bool isTwoStringAnagram(string& s1, string& s2)
{
    int charCount[256] = {0};

    if (s1.length() != s2.length())
        return false;

    for (auto c1 : s1)
        ++charCount[c1];

    for (auto c2 : s2)
        --charCount[c2];

    for (int i = 0; i != 256; ++i)
        if (charCount[i] != 0)
            return false;

    return true;
}

int main()
{
//    string s1 = "abcde";
//    string s2 = "cdbae";
//    string s2 = "dbae";
    string s1 = "aaaaa";
    string s2 = "aaaaa";

    bool isAnagram = isTwoStringAnagram(s1, s2);
    if (isAnagram)
        cout << "String 1 : " << s1 << ", and string 2: " << s2 << ", is anagram." << endl;
    else
        cout << "String 1 : " << s1 << ", and string 2: " << s2 << ", is NOT anagram." << endl;

    return 0;
}
