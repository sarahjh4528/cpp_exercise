#include<iostream>
#include<sstream>

using namespace std;

void replaceSpace(string& s)
{
    if (s.empty())
        return;

    istringstream is(s);
    ostringstream os;
    string temp;

    is >> temp;
    os << temp;
    while (is >> temp) {
        os << "%20" << temp;
    }
    s = os.str();
}

int main()
{
    string s = "Replace all spaces in this string with %20";

    replaceSpace(s);
    cout << s << endl;
    return 0;
}
