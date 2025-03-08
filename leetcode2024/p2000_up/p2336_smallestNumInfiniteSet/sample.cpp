#include<bits/stdc++.h>
#include<iostream>
#include<unordered_set>

using namespace std;

/*
1 <= num <= 1000
At most 1000 calls will be made in total to popSmallest and addBack.
*/
class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
    }
    
    int popSmallest() {
    }
    
    void addBack(int num) {
    }
};

int main()
{
/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
    SmallestInfiniteSet s;
    s.addBack(2);    // 2 is already in the set, so no change is made.
    cout << "Added 2, no change" << endl;
    int output = s.popSmallest(); // return 1, since 1 is the smallest number, and remove it from the set.
    cout << "Pop smallest: " << output << endl;
    output = s.popSmallest(); // return 2, and remove it from the set.
    cout << "Pop smallest: " << output << endl;
    output = s.popSmallest(); // return 3, and remove it from the set.
    cout << "Pop smallest: " << output << endl;
    s.addBack(1);    // 1 is added back to the set.
    cout << "Added 1." << endl;
    output = s.popSmallest(); // return 1, since 1 was added back to the set and
    cout << "Pop smallest: " << output << endl;
    output = s.popSmallest(); // return 4, and remove it from the set.
    cout << "Pop smallest: " << output << endl;
    output = s.popSmallest(); // return 5, and remove it from the set.
    cout << "Pop smallest: " << output << endl;

    return 0;
}
