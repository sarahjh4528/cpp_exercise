#include<iostream>

using namespace std;

void removeDuplicate(string& istr) {
    int charCount[256] = {0};
    int copyIndex = 0;

    for (int i = 0; i != istr.length(); ++i) {
        if (charCount[istr[i]] == 0) {
            if (i != copyIndex)
                istr[copyIndex] = istr[i];
            ++charCount[istr[i]];
            ++copyIndex;
        }
    }
    istr.erase(copyIndex, (istr.length() - copyIndex));
}

int main()
{
    string inStr = "This string contains duplicated characters, remove them.";

    cout << "Orignal string: " << inStr << endl;
    removeDuplicate(inStr);
    cout << "After removing duplicated char: " << inStr << endl;
    return 0;
}
