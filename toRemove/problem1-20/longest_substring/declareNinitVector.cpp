#include<vector>
#include<iostream>

using namespace std;

int main()
{
    // Declare a vector with 10 integers, and initialize to -1.
    vector<int> myVector(10, -1);
    for (auto i : myVector)
        cout << i << " ";
    cout << endl;
    return 0;
}
