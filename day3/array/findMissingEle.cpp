#include <iostream>
using namespace std;
int firstWay(int arr[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        int flag = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == i)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            return i;
    }
    return -1;
}
int Xor (int arr[], int n) {
    int x = 0;
    int x2 = 0;
    for (int i = 0; i < n-1; i++)
    {
        x = x ^ arr[i];
        x2 = x2 ^ (i + 1);
    }
        x=x^n;
        return (x ^ x2);
} 

int main()
{
    int arr[] = {1, 2, 4, 5};
    cout << Xor(arr, 5);
    return 0;
}