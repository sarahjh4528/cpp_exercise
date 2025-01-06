#include<bits/stdc++.h>
#include<iostream>

using namespace std;

/*
1 <= price <= 10^5
At most 10^4 calls will be made to next.
*/

class StockSpanner {
    stack<pair<int, int>> st;
public:
    StockSpanner() {
    }
    
    int next(int price) {
        int span = 1;
        while (!st.empty() && st.top().first <= price) {
            auto [p, s] = st.top();
            st.pop();
            span += s;
        }
        st.push({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
int main()
{
    StockSpanner stockSpanner;
    int output = stockSpanner.next(100); // return 1
    cout << "In price 100 " << ", span = " << output << endl;
    output = stockSpanner.next(80);  // return 1
    cout << "In price 80 " << ", span = " << output << endl;
    output = stockSpanner.next(60);  // return 1
    cout << "In price 60 " << ", span = " << output << endl;
    output = stockSpanner.next(70);  // return 2
    cout << "In price 70 " << ", span = " << output << endl;
    output = stockSpanner.next(60);  // return 1
    cout << "In price 60 " << ", span = " << output << endl;
    output = stockSpanner.next(75);  // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
    cout << "In price 75 " << ", span = " << output << endl;
    output = stockSpanner.next(85);  // return 6
    cout << "In price 85 " << ", span = " << output << endl;
    return 0;
}
