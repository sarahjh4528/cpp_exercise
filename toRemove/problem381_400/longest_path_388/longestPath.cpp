#include<iostream>
#include<sstream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {
        if (input.length() == 0)
            return 0;

        istringstream ss(input);
        int res = 0;
        unordered_map<int, int> levelPathLen;
        string line;

        // get string separated by \n
        while (getline(ss, line)) {
            int level = 0;
            int i = 0;
            while (i < line.length() && line[i] == '\t') {
                level += 1;
                i += 1;
            }
            bool isFile = false;
            int curLen = 0;
            for (int j = i; j < line.length(); ++j) {
                if (line[j] == '.')
                    isFile = true;
                ++curLen;
            }
            curLen = (level == 0)? curLen : curLen + levelPathLen[level-1];  // level number == / count
            if (isFile)
                res = max(res, curLen+level);
            else
                levelPathLen[level] = curLen;
        }
        return res;
    }
};

int main()
{
#if 0
    string dirStr = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
    string dirStr = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
#endif
    string dirStr = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";

    Solution s;
    int len = s.lengthLongestPath(dirStr);
    cout << "Longest path len: " << len << endl;
    return 0;
}
