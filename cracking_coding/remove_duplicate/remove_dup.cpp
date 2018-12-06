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
    string inStr[5] = {
        "This string contains duplicated characters, remove them.",
        "aaaaaa",
        "",
        "aaabbb",
        "abababbaabb"
    };

    for (auto ist : inStr) {
        cout << "Orignal string: " << ist << endl;
        removeDuplicate(ist);
        cout << "After removing duplicated char: " << ist << endl;
    }
    return 0;
}
