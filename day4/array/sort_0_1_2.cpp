#include <bits/stdc++.h>
using namespace std;
void sort(vector<int> &arr)
{
    int n = arr.size();
    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            cnt0++;
        else if (arr[i] == 1)
            cnt1++;
        else
            cnt2++;
    }
    for (int i = 0; i < cnt0; i++)
    {
        arr[i] = 0;
    }
    for (int i = cnt0; i < cnt0 + cnt1; i++)
    {
        arr[i] = 1;
    }
    for (int i = cnt0 + cnt1; i < n; i++)
    {
        arr[i] = 2;
    }
}
// void swap(int *x, int *y)
// {
//     int temp = *x;
//     *x = *y;
//     *y = temp;
// }
void OptimalSort(vector<int> &arr)
{
    int mid = 0;
    int low = 0;
    cout << "run" << endl;
    int high = arr.size() - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else if (arr[mid] == 2)
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}
int main()
{
    vector<int> arr{0, 1, 2, 1, 2, 1, 2, 0, 0, 0, 0};
    // sort(arr);
    OptimalSort(arr);
    for (auto it : arr)
    {
        cout << it << " ";
    }
    return 0;
}