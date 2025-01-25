#include<bits/stdc++.h>
#include<iostream>

using namespace std;

/*
1 <= t <= 10^9
Each test case will call ping with strictly increasing values of t.
At most 104 calls will be made to ping.
*/
class RecentCounter {
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
    }
};

int main()
{
    RecentCounter recentCounter;
    int output = recentCounter.ping(1);     // requests = [1], range is [-2999,1], return 1
    cout << "Input 1, recent calls within 3000ms: " << output << endl;
    output = recentCounter.ping(100);   // requests = [1, 100], range is [-2900,100], return 2
    cout << "Input 100, recent calls within 3000ms: " << output << endl;
    output = recentCounter.ping(3001);  // requests = [1, 100, 3001], range is [1,3001], return 3
    cout << "Input 3001, recent calls within 3000ms: " << output << endl;
    output = recentCounter.ping(3002);  // requests = [1, 100, 3001, 3002], range is 
    cout << "Input 3002, recent calls within 3000ms: " << output << endl;
    return 0;
}
