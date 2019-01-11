#include<iostream>
#include<vector>
#include<algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::min;
using std::max;

class Solution {
public:
#if 0
// Very slow!!!
    int maxArea(vector<int>& height) {
        int biggestSize = 0;
        int width = height.size() - 1;
        for (int i = 0; i < height.size() - 1; ++i) {
            for (int j = i + 1; j < height.size(); ++j) {
                int curWidth = j - i;
                int curHeight = (height[i] < height[j])? height[i] : height[j];
                int size = curWidth * curHeight;
                biggestSize = (biggestSize < size)? size : biggestSize;
            }
        }
        return biggestSize;
    }
#else
    int maxArea(vector<int>& height) {
        int biggest = 0;
        int mf = 0, mb = height.size() - 1; // mf: move forward; mb: move backward
        while (mf < mb) {
            int h = min(height[mf], height[mb]);
            biggest = max(biggest, ((mb-mf)*h));
            while (height[mf] <= h)
                ++mf;
            while (height[mb] <= h)
                --mb;
        }
        return biggest;
    }
#endif
};

int main()
{
    vector<int> in = {1,8,6,2,5,4,8,3,7};

    Solution s;
    int output = s.maxArea(in);
    cout << "Biggest size: " << output << endl;
    return 0;
}
