#include <iostream>
#include <algorithm>
#include <sstream>
#include <math.h>
using namespace std;

string addBigNumber(string num, string num2)
// Has calculated 20,000 terms of fibonacci sequence in aproximately 1:56 minutes ver 1
// Has calculated 20,000 terms of fibonacci sequence in aproximately 1:52 minutes ver 1
{

    string sum;
    short carry = 0, len = num.length(), len2 = num2.length(), i = (len > len2 ? ceil(len / 18.0) : ceil(len2 / 18.0)) * 18;
    num = string(i - len, '0') + num;
    num2 = string(i - len2, '0') + num2;
    while (i)
    {
        i -= 18;
        long long part = stoll(num.substr(i, 18));
        long long part2 = stoll(num2.substr(i, 18));
        long long partSum = part + part2 + carry;
        carry = partSum / 1000000000000000000;
        string hold = to_string(partSum % 1000000000000000000);
        sum = (i ? string(18 - hold.length(), '0') + hold : to_string(partSum)) + sum;
    }
    return sum;
}

string addBigNumber1(string num, string num2)
// Has calculated 20,000 terms of fibonacci sequence in aproximately 1:54 minutes ver 1
{
    string sum;
    short carry = 0, len = num.length(), len2 = num2.length();
    for (short i = 1; (len > len2) ? i < len / 18 + 2 : i < len2 / 18 + 2; i++)
    {
        short pos = len - 18 * i, pos2 = len2 - 18 * i;
        long long part = (pos > -18) ? ((pos > -1) ? stoll(num.substr(pos, 18)) : stoll(num.substr(0, len % 18))) : 0;
        long long part2 = (pos2 > -18) ? ((pos2 > -1) ? stoll(num2.substr(pos2, 18)) : stoll(num2.substr(0, len2 % 18))) : 0;
        long long partSum = part + part2 + carry;
        if (!partSum)
            continue;
        carry = partSum / 1000000000000000000;
        string hold = to_string(partSum % 1000000000000000000);
        sum = (i < len / 18 + 1) ? string(18 - hold.length(), '0') + hold + sum : hold + sum;
    }
    return sum;
}

string addBigNumber2(string num, string num2)
// Has calculated 20,000 terms of fibonacci sequence in aproximately 2:21 minutes ver 1
{
    string sum;
    short carry = 0, len = num.length(), len2 = num2.length();
    len > len2 ? num2 = string(len - len2, '0') + num2 : num = string(len2 - len, '0') + num;
    for (short i = len > len2 ? --len : --len2; i > -1; i--)
    {
        // Asci code of 0 is 48 and then other numbers follows
        short part = num.at(i) + num2.at(i) + carry - 96;
        carry = part / 10;
        sum = to_string(part % 10) + sum;
    }
    if (carry)
        sum = to_string(carry) + sum;
    return sum;
}

void fibonacci()
{
    string input;
    int count;
    cout << "How many numbers of fibonacci sequence do you want? ";
    cin >> input;
    stringstream data(input);
    if (data >> count && count > 2)
    {
        string num = "1", num2 = num;
        cout << "term " << 1 << ": " << num << endl;
        cout << "term " << 2 << ": " << num << endl;
        for (int i = 3; i <= count; i++)
        {
            string hold = addBigNumber(num2, num);
            num = num2;
            num2 = hold;
            cout << "term " << i << ": " << num2 << endl;
        }
        cout << endl
             << string(30, '*') << endl
             << "Process finished" << endl
             << string(30, '*') << endl;
    }
    else
    {
        cout << "Enter a valid number greater than 2!!! Try again." << endl;
        fibonacci();
    }
}

int main()
{
    // cout << ceil(11 / 3.0);
    // fibonacci();
    // cout << addBigNumber("1000000000001000000", "999999999999999999");
    return 0;
}