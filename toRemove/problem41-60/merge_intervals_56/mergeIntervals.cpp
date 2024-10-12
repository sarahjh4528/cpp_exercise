#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution
{
public:
    vector<Interval> buildIntervals() {
#if 0
        vector<int> vStart = {1,2,8,15};
        vector<int> vStop = {3,6,10,18};

        vector<int> vStart = {1,4};
        vector<int> vStop = {4,5};

        vector<int> vStart = {1,2};
        vector<int> vStop = {4,3};
#endif
        vector<int> vStart = {1,2};
        vector<int> vStop = {4,3};
        vector<Interval> ret;

        for (int i = 0; i < vStart.size(); ++i) {
            Interval newIv(vStart[i], vStop[i]);
            ret.push_back(newIv);
        }
        return ret;
    }

    void printIntervals(vector<Interval>& intervals) {
        for (auto i : intervals)
            cout << i.start << "," << i.end << " ";
        cout << endl;
    }

    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.empty())
            return vector<Interval> {};

        sort(intervals.begin(), intervals.end(), [](auto &left, auto &right) {return left.start < right.start;});

        vector<Interval> mergedRet;
        bool mergeDone = false;

        for (int i = 0; i < intervals.size(); ++i) {
            int segStart = intervals[i].start, segEnd = intervals[i].end;
            int j = i + 1;
            for (; j < intervals.size(); ++j) {
                if (intervals[j].start > segEnd) {
                    --j;
                    break;
                } else {
                    segEnd = max(segEnd, intervals[j].end);
                }
            }
            Interval newItv(segStart, segEnd);
            mergedRet.push_back(newItv);
            i = j;
        }
        return mergedRet;
    }
};

int main()
{
    Solution s;

    vector<Interval> intervals = s.buildIntervals();
    s.printIntervals(intervals);

    vector<Interval> mergedIntervals = s.merge(intervals);
    s.printIntervals(mergedIntervals);
    return 0;
}
