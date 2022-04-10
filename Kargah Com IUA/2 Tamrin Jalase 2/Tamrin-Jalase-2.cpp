#include <iostream>
#include <sstream>
using namespace std;

int menu();

// تمرین اضافی جمع کننده اعداد بزرگ
string addBigNumber(string num, string num2)
{
    string sum;
    short carry = 0, numLength = num.length(), num2Length = num2.length();
    for (int i = 1; (numLength > num2Length) ? i < numLength / 18 + 2 : i < num2Length / 18 + 2; i++)
    {
        short pos = numLength - 18 * i, pos2 = num2Length - 18 * i;
        long long part = (pos > -18) ? ((pos > -1) ? stoll(num.substr(pos, 18)) : stoll(num.substr(0, numLength % 18))) : 0;
        long long part2 = (pos2 > -18) ? ((pos2 > -1) ? stoll(num2.substr(pos2, 18)) : stoll(num2.substr(0, num2Length % 18))) : 0;
        long long partSum = part + part2 + carry;
        if (!partSum)
            continue;
        carry = partSum / 1000000000000000000;
        string hold = to_string(partSum % 1000000000000000000);
        sum = (i < numLength / 18 + 1) ? string(18 - hold.length(), '0') + hold + sum : hold + sum;
    }
    return sum;
}

// تمرین اول با کمی تغییر
void sumOfnNumbers()
{
    float sum;
    int count = 1;
    string message = "Enter the word \"end\" or \"result\" to stop process and get the results!";
    cout << string(message.length(), '*') << endl;
    cout << message << endl;
    cout << string(message.length(), '*') << endl;
    while (1)
    {
        string input;
        float num;
        cout << count << " Enter number to add: ";
        cin >> input;
        stringstream data(input);
        if (data >> num)
        {
            sum += num;
            count++;
        }
        else if (data.str() == "end" || data.str() == "result")
        {
            break;
        }
        else
            cout << "Enter a valid number!!! Try again." << endl;
    }
    cout << string(30, '*') << endl
         << "Process finished" << endl
         << "In total " << count - 1 << " numbers were added. "
         << "Total sum is equal to: " << sum << endl
         << string(30, '*') << endl;
    menu();
}

// تمرین دوم
void sumOfEvenTwoDigitNumbers()
{
    int sum = 0;
    for (int i = 10; i < 100; i += 2)
    {
        sum += i;
    }
    cout << string(30, '*') << endl
         << "Process finished" << endl
         << "Total sum of 2 digit even numbers is equal to: " << sum << endl
         << string(30, '*') << endl;
    menu();
}
// تمرین دوم با کمی تغییر
void sumOfEvenOrOddnDigitNumbers()
{
    string input, input1;
    long long sum = 0;
    int digitsCount;
    bool isOdd;
    cout << "Enter number of digits: ";
    cin >> input;
    cout << "Odd or Even? Enter \"1\" if odd or \"0\" if even : ";
    cin >> input1;
    stringstream data(input), data1(input1);
    if (data >> digitsCount && data1 >> isOdd && digitsCount > 0)
    {
        long long Efirst = stoll(((digitsCount > 1) ? '1' : '0') + string(digitsCount - 1, '0'));
        long long Elimit = stoll('1' + string(digitsCount, '0'));
        sum = (isOdd ? (Efirst + Elimit) * (Elimit - Efirst) / 4 : (Efirst + Elimit - 2) * (Elimit - Efirst) / 4);
        cout << string(30, '*') << endl
             << "Process finished" << endl
             << "Total sum of " << digitsCount << " digit " << (isOdd ? "odd " : "even ")
             << "numbers is equal to: " << sum << endl
             << string(30, '*') << endl;
    }
    else
    {
        cout << "Enter valid parameters!!! Try again." << endl;
        sumOfEvenOrOddnDigitNumbers();
    }
    menu();
}

// تمرین سوم با کمی تغییر
void drawRightTriangle()
{
    string input;
    int height;
    cout << "Enter number of digits: ";
    cin >> input;
    stringstream data(input);
    if (data >> height && height > 0)
    {
        for (int i = 1; i <= height; i++)
        {
            for (int j = 1; j <= i; j++)
                cout << '*';
            cout << endl;
        }
        cout << string(30, '*') << endl
             << "Process finished" << endl
             << string(30, '*') << endl;
    }
    else
    {
        cout << "Enter a valid and positive number!!! Try again." << endl;
        drawRightTriangle();
    }
    menu();
}

// تمرین چهارم با کمی تغییر
void fibonacci()
{
    string input;
    int count;
    cout << "How many numbers of fibonacci sequence do you want? ";
    cin >> input;
    stringstream data(input);
    if (data >> count)
    {
        string num = "1", num2 = num;
        cout << "term " << 1 << ": " << num << endl;
        for (int i = 1; i < count; i++)
        {
            string hold = addBigNumber(num2, num);
            // cout << "hold" << hold << endl;
            num = num2;
            num2 = hold;
            cout << "term " << i + 1 << ": " << num << endl;
        }
        cout << endl
             << string(30, '*') << endl
             << "Process finished" << endl
             << string(30, '*') << endl;
    }
    else
    {
        cout << "Enter a valid and positive integer!!! Try again." << endl;
        fibonacci();
    }
    menu();
}

// تمرین پنجم با کمی تغییر
void baseConversionFrom10()
{
    string result, input, input1;
    long long num, base;
    cout << "Enter the number that you want to convert: ";
    cin >> input;
    cout << "Enter the base you want to convert to: ";
    cin >> input1;
    stringstream data(input), data1(input1);
    if (data >> num && data1 >> base && base > 1 && base != 10)
    {
        while (num >= base)
        {
            if (base < 10)
                result = to_string(num % base) + result;
            else
                result = '(' + to_string(num % base) + ')' + result;
            num /= base;
        }
        if (base < 10)
            result = to_string(num % base) + result;
        else
            result = '(' + to_string(num % base) + ')' + result;
        cout << string(30, '*') << endl
             << "Process finished" << endl
             << "Converted number is equal to: " << result << " in base: " << base << endl
             << string(30, '*') << endl;
    }
    else if (base == 10)
        cout << string(30, '*') << endl
             << "Process finished" << endl
             << "Coversion from base 10 to 10 makes no diffrence! " << endl
             << string(30, '*') << endl;
    else
    {
        cout << "Enter a valid and positive integer!!! Minimum base is two! Maximum input: 18 digits! Try again." << endl;
        baseConversionFrom10();
    }
    menu();
}

// تمرین ششم با کمی تغییر
void sumOfDigits()
{
    string input;
    long long num;
    cout << "Enter the number: ";
    cin >> input;
    stringstream data(input);
    if (data >> num)
    {
        short result = 0;
        for (int i = 0; i < input.length(); i++)
        {
            if ((int)input.at(i) > 48 && (int)input.at(i) < 58)
            {
                result += (int)input.at(i) - 48;
            }
        }
        cout << string(30, '*') << endl
             << "Process finished" << endl
             << "Total sum of digits is equal to: " << result << endl
             << string(30, '*') << endl;
    }
    else
    {
        cout << "Enter a valid and positive integer!!! Try again." << endl;
        sumOfDigits();
    }
    menu();
}

// منو
int menu()
{
    string input;
    cout << string(60, '-') << endl
         << "1. Calculate total sum of n numbers. " << endl
         << "2. Calculate total sum of two digit even numbers. " << endl
         << "22. Calculate total sum of n digit even or odd numbers. " << endl
         << "3. Draw right triangle with *. " << endl
         << "4. Calculate n numbers of fibonacci sequence. " << endl
         << "5. Base conversion from 10 to n. " << endl
         << "6. Calculate sum of digits of a numbers. " << endl
         << "0. Exit program. " << endl
         << string(60, '-') << endl
         << "Enter menu number: ";
    cin >> input;
    if (input == "1")
        sumOfnNumbers();
    else if (input == "2")
        sumOfEvenTwoDigitNumbers();
    else if (input == "22")
        sumOfEvenOrOddnDigitNumbers();
    else if (input == "3")
        drawRightTriangle();
    else if (input == "4")
        fibonacci();
    else if (input == "5")
        baseConversionFrom10();
    else if (input == "6")
        sumOfDigits();
    else if (input == "0")
        return 0;
    else
    {
        cout << "Enter a valid menu number!!! Try again." << endl;
        menu();
    }
    return 0;
}

int main()
{
    menu();
    return 0;
}