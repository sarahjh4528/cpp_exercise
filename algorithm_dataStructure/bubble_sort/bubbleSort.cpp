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

    int end = inList.size() - 1; // Last element index

    printVec(inList);
    while (end > 0) {
        for (int i = 0; i < end; i++) {
            if (inList[i] > inList[i+1])
                swap(inList[i], inList[i+1]);
        }
        end--;
    }
    printVec(inList);
    return 0;
}
