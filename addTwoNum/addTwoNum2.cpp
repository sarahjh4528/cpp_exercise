#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

/*using std::cin;
using std::find_if;
using std::vector;
using std::string;
*/

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    void printNode(ListNode* node) {
        if (node == nullptr) {
            return ;
        }
    
        string result;
        while (node) {
            result += to_string(node->val) + ", ";
            node = node->next;
        }
        cout << "[" << result.substr(0, result.length() - 2) << "]" << endl;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *start=NULL, *prev=NULL;
        bool carry = false;

        while (l1 || l2) {
            //cout << l1->val << ", " << l2->val << endl;
            int sum = 0;
            sum += (l1)? l1->val:0;
            sum += (l2)? l2->val:0;

            sum = (carry)? sum + 1 : sum;
            ListNode *newNode = new ListNode(0);
            if (sum >= 10) {
               carry = true;
               newNode->val = sum - 10;
            } else {
               carry = false;
               newNode->val = sum;
            }
            //printNode(newNode);

            if (!start) {
                start = prev = newNode;
            } else {
                prev->next = newNode;
                prev = newNode;
            }
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        if (carry) {
            ListNode *lastNode = new ListNode(1);
            prev->next = lastNode;
        }
        return start;
    }
};

#if 0
void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}
#endif

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    //trimLeftTrailingSpaces(input);
    //trimRightTrailingSpaces(input);
    //input = input.substr(1, input.length() - 2);
    istringstream ss(input);
    //ss.str(input);
    cout << ss.str() << endl;
    string item;
    //char delim = ',';
    while (getline(ss, item, ',')) {
        output.push_back(stoi(item));
    }
    cout << "vector size: " << output.size() << endl;
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* l1 = stringToListNode(line);
        cout << listNodeToString(l1) << endl;
        getline(cin, line);
        ListNode* l2 = stringToListNode(line);
        cout << listNodeToString(l2) << endl;
        
        ListNode* ret = Solution().addTwoNumbers(l1, l2);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
