class NestedIterator {
private:
    vector<NestedInteger>& nList;
    queue<int> itQueue;
    void buildItQueue(vector<NestedInteger>& inList) {
        if (inList.empty())
            return;
        for (int i = 0; i < inList.size(); ++i) {
            if (inList[i].isInteger())
                itQueue.push(inList[i].getInteger());
            else
                buildItQueue(inList[i].getList());
        }
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) : nList(nestedList) {
        buildItQueue(nList);
    }

    int next() {
        int temp = itQueue.front();
        itQueue.pop();
        return temp;
    }

    bool hasNext() {
         return (!itQueue.empty());
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
