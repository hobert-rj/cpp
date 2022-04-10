#include <iostream>
using namespace std;

int *returnArr(int *arr)
{
    /* Some operations on arr[] */
    arr[0] = 10;
    arr[1] = 20;

    return arr;
}

int main()
{
    int arr[2];
    int *result = returnArr(arr);
    printf("%d %d", result[0], result[1]);
    return 0;
}

