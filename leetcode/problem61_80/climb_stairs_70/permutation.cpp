#include<iostream>
#include<vector>

using namespace std;

void printVector(vector<int>& iList) {
    for (auto i : iList)
        cout << i << " ";
    cout << endl;
}

/* each number in the list should be unique, otherwise this function generates
 * duplicate lists
 */
void generatePermutations(vector<int>& intSet, int index) {
    if (index == intSet.size()) {
        printVector(intSet);
    }
    for (int i = index; i < intSet.size(); ++i) {
        swap(intSet[i], intSet[index]);
        generatePermutations(intSet, index + 1);
        swap(intSet[i], intSet[index]);
    }
}

int main()
{
#if 0
    vector<int> mySet = {1,2,3};
#endif
    vector<int> mySet = {1,1,2,2};
    
    generatePermutations(mySet, 0);
    return 0;
}
