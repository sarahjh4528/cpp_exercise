#include<iostream>
#include<bitset>

using std::cout;
using std::endl;
using std::string;

int main()
{
    string a = "11";
    string b = "1";
    char *pEnd;

    long aInt = strtol(a.c_str(), &pEnd, 2);
    long bInt = strtol(b.c_str(), &pEnd, 2);
    cout << aInt << ", " << bInt << endl;

    long sum = aInt + bInt;
    cout << "Sum: " << std::bitset<8>(sum).to_string() << endl;
    return 0;
}
