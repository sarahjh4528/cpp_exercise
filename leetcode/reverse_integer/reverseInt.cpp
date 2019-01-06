#include<iostream>
#include<sstream>

using std::cout;
using std::endl;
using std::ostringstream;
using std::string;

class Solution {
public:
#if 1
    int reverse(int x) {
        ostringstream os, os2;
        os << x;

        string xStr = os.str();
        if (xStr.length() < 2)
            return x;
        
        int end = 0;
        if (x < 0){
            os2 << "-";
            ++end;
        }

        for (int i = (xStr.length() - 1); i >= end; --i) {
            os2 << xStr[i];
        }
        cout << os2.str() << endl;

        try {
            int ret = stoi(os2.str());
            return ret;
        } catch (const std::out_of_range& oor) {
            // reversed integer out of range
            return 0;
        }
    }
#else
    int reverse(int x) {
    // very simple C, runtime 5ms
        long long val = 0;
    	do
    	{
    		val = val * 10 + x % 10;
    		x /= 10;
    	} while (x);
    
    	return (val > INT_MAX || val < INT_MIN) ? 0 : val;
    }
#endif
};

int main()
{
//    int i = 123;
    int i = 1534236469;

    Solution s;
    int o = s.reverse(i);
    cout << o << endl;

    return 0;
}
