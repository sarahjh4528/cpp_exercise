#include<iostream>

using namespace std;

void reverseTheString(string& istr) {
    if (istr.length() == 0)
        return;

    int fIndx = 0, bIndx = istr.length() - 1;

    while (fIndx < bIndx) {
        char temp;
        temp = istr[bIndx];
        istr[bIndx] = istr[fIndx];
        istr[fIndx] = temp;
        --bIndx;
        ++fIndx;
    }
}
int main()
{
    string inStr = "Please reverse this string!";

    cout << "Original string: " << inStr << endl;
    reverseTheString(inStr);
    cout << "Reversed string: " << inStr << endl;
    return 0;
}
