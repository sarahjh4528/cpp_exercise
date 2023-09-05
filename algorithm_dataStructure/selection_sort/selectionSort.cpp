#include<iostream>
#include<vector>

using namespace std;

void printVec(vector<int>& v)
{
    for (auto i : v)
        cout << i << " ";
    cout << endl;
}

int main() {
    vector<int> inList = {1, 5, 94, 33, 4, 66, 9, 22, 77, 20};

    int start = 0, maxIndex = inList.size() - 1;

    printVec(inList);
    while (start < maxIndex) {
        int smIndex = start;
        for (int i = start; i <= maxIndex; i++)
            smIndex = (inList[i] < inList[smIndex])? i : smIndex;

        if (smIndex > start)
            swap(inList[start], inList[smIndex]);
        start++;
    }
    printVec(inList);
    return 0;
}
