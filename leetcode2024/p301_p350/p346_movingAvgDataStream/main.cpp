/*
Runtime 4 ms Beats 91.57%
Memory 19.07 MB Beats 49.48%
*/
class MovingAverage {
    vector<int> v;  // Save the prefix sum
    int winSize;
public:
    MovingAverage(int size) {
        winSize = size;
        v.push_back(0);
    }
    
    double next(int val) {
        int vSize = v.size() - 1;
        if (vSize > 0)
            v.push_back(v[vSize]+val);
        else
            v.push_back(val);

        vSize++;
        if (vSize < winSize)
            return (double)v[vSize] / vSize;
        else
            return (double)(v[vSize]-v[vSize-winSize]) / winSize;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
