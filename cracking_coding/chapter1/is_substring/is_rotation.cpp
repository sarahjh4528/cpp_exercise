#include<iostream>

using namespace std;

bool isRotation(string s1, string s2)
{
    if (s1.length() != s2.length())
        return false;
    string s1s2 = s1 + s2;
    return isSubstring(s1s2, s2);
}

int main()
{
    string s1 = "apple";
    string s2 = "pleap";

    bool is_rotate = isRotation(s1, s2);
    return 0;
}
