#include <iostream>
#include <vector>
using namespace std;
void leftRotateOnePlaced(int arr[], int n)
{
    int temp = arr[0];
    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
}
void leftRotateKPlaced(vector<int> &arr, int n, int k)
{
    n = n - 1;
    vector<int> temp;

    // stored value  upto k..
    for (int i = 0; i < k; i++)
    {
        temp[i] = arr[i];
    }
    // shifing values that before k .
    for (int i = k - n; i < n; i++)
    {
        arr[i - (k - n)] = arr[i];
    }
    // move temp value to arr[]
    for (int i = k + 1; i < n; i++)
    {
        arr[i] = temp[i - (k - n)];
    }
}
void reverse(vector<int> &arr, int l, int r)
{
    while (l <= r)
    {
        int temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;
        l++;
        r++;
    }
}
void leftRotateKPlacedAdvanceCode(vector<int> &arr, int n, int k)
{
    reverse(arr, 0, k - 1);
    reverse(arr, k, n - 1);
    reverse(arr, 0, n - 1);
}

int main()
{
    // int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // leftRotateOnePlaced(arr, 9);
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // leftRotateKPlaced(vec, 9, 3);
    leftRotateKPlacedAdvanceCode(vec,9,3);
    return 0;
}