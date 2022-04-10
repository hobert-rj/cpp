#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
    int row, col;
input:
    cout << "Enter number of rows: ";
    cin >> row;
    cout << "Enter number of columns: ";
    cin >> col;
    if (row <= 0 || col <= 0)
    {
        cout << "Error! Enter number that is bigger than zero. Try again." << endl
             << "............" << endl;
        goto input;
    }
    int width = to_string(row * col).length() + 2;
    // cout << width << endl;
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            cout << setw(width) << i * j;
        }
        cout << endl;
    }
    return 0;
}