#include <iomanip>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    // int rowmax = 10, colmax = 8, rowmin = -10, colmin = -5;
    int rowmax = 0, colmax = 0, rowmin = 0, colmin = 0;
input:
    cout << "Enter number of start row: ";
    cin >> rowmin;
    cout << "Enter number of end row: ";
    cin >> rowmax;
    cout << "Enter number of start column: ";
    cin >> colmin;
    cout << "Enter number of end column: ";
    cin >> colmax;
    if ((rowmax - rowmin) <= 0 || (colmax - colmin) <= 0)
    {
        cout << "Error! Start and end diffrence can not be zero or lower than zero. Try again." << endl
             << "............" << endl;
        goto input;
    }
    int width = to_string(max(abs(rowmax), abs(rowmin)) * max(abs(colmax), abs(colmin))).length() + 2;
    cout << setw(width + 2) << '*' + string(floor(width / 2), ' ');
    for (int j = colmin; j <= colmax; j++)
    {
        cout << setw(width) << j;
    }
    cout << endl
         << string(width + 2, ' ') << string(width * (colmax - colmin + 1), '-') << endl;
    for (int i = rowmin; i <= rowmax; i++)
    {
        cout << setw(width) << i << " |";
        for (int j = colmin; j <= colmax; j++)
        {
            cout << setw(width) << i * j;
        }
        cout << endl;
    }
    return 0;
}