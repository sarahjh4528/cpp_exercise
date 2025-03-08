#include<bits/stdc++.h>
#include<iostream>
#include<unordered_set>

using namespace std;

/*
Runtime 0 ms Beats 100.00%
Memory 43.11 MB Beats 90.56%

Time: popSmallest, hash erase or smallest++, O(1), minHeap rm top O(log(n))
Space: O(n)
*/
class SmallestInfiniteSet {
    int smallest;
    unordered_set<int> addedHash;
    priority_queue<int, vector<int>, greater<int>> addedQ;
public:
    SmallestInfiniteSet() {
        smallest = 1;
    }
    
    int popSmallest() {
        int res;
        if (!addedQ.empty() && addedQ.top() < smallest) {
            res = addedQ.top();
            addedQ.pop();
            addedHash.erase(res);
        } else {
            res = smallest;
            smallest++;
        }
        return res;
    }
    
    void addBack(int num) {
        if (num >= smallest)
            return;
        if (!addedHash.count(num)) {
            addedHash.insert(num);
            addedQ.push(num);
        }
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
