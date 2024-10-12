#include<iostream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int inVal):val(inVal), next(NULL) {};
};

ListNode *buildList(string inStr)
{
    ListNode *start, *cur;
    istringstream is(inStr);
    string item;
    vector<int> v;
    cout << "stringstream string: " << is.str() << endl;
    while (getline(is, item, ',')) {
//        string::size_type sz;
        cout << item << endl;
        v.push_back(stoi(item));
//        v.push_back(stoi(item, &sz));
    }
    cout << "v length: " << v.size() << endl;
    return start;
}

string listToString(ListNode *list)
{
    ostringstream os;

    os << "[";
    while(list) {
        if (os.str().length() > 1)
            os << ", " << list->val;
        else
            os << list->val;
        list = list->next;
    }
    os << "]";
    cout << os.str() << endl;
    return os.str();
}

int main()
{
    ListNode *start, *cur;

    ListNode *newNode = new ListNode(0);
    string input;
    cin >> input;
    ListNode *l1 = buildList(input);
    cout << listToString(l1) << endl;

    return 0;
}
