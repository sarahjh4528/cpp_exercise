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

    printVec(inList);
    int len = inList.size();
    int sortTo = 0;

    for (int i = 1; i < len; i++) {
        int j = 0, val = inList[i];
        while (j <= sortTo && inList[i] >= inList[j])
            j++;

        if (j <= sortTo) {
            inList.erase(inList.begin()+i);
            inList.insert(inList.begin()+j, val);
        }
        sortTo++;
    }
    printVec(inList);
    return 0;
}
