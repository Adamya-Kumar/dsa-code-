#include <iostream>
#include <vector>
using namespace std;
pair<int, int> secondLargestAndSecondSmallest(vector<int> &arr, int n)
{
    int smallest = INT8_MAX;
    int largest = INT8_MIN;
    int Ssmallest = INT8_MAX;
    int Slargest = INT8_MIN;

    for (int i = 0; i < n; i++)
    {
        if (smallest > arr[i])
        {
            smallest = arr[i];
        }
        if (largest < arr[i])
        {
            largest = arr[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (smallest < arr[i] && Ssmallest > arr[i])
        {
            Ssmallest = arr[i];
        }
        if (largest > arr[i] && Slargest < arr[i])
        {
            Slargest = arr[i];
        }
    }
    return {Slargest, Ssmallest};
}
int s(vector<int> &arr, int n)
{
    int smallest = INT8_MAX;
    int Ssmallest = INT8_MAX;

    for (int i = 0; i < n; i++)
    {
        if (smallest > arr[i])
        {
            Ssmallest = smallest;
            smallest = arr[i];
        }
        else if (smallest < arr[i] && Ssmallest > arr[i])
        {
            Ssmallest = arr[i];
        }
    }
    return Ssmallest;
}
int l(vector<int> &arr, int n)
{

    int largest = INT8_MIN;
    int Slargest = INT8_MIN;

    for (int i = 0; i < n; i++)
    {
        if (largest < arr[i])
        {
            Slargest = largest;
            largest = arr[i];
        }
        else if (largest > arr[i] && Slargest < arr[i])
        {
            Slargest = arr[i];
        }
    }
    return Slargest;
}

pair<int, int> secondLargestAndSecondSmallestOptimal(vector<int> &arr, int n)
{
    return {l(arr, n), s(arr, n)};
}
int main()
{
    vector<int> arr{1, 2, 4, 7, 5};
    pair<int, int> ans = secondLargestAndSecondSmallest(arr, arr.size());
    cout << ans.first << " " << ans.second << endl;
    pair<int, int> Oans = secondLargestAndSecondSmallestOptimal(arr, arr.size());
    cout << Oans.first << " " << Oans.second << endl;
    return 0;
}