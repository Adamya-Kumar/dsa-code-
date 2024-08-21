#include <iostream>
#include <vector>
using namespace std;
void leftShift(int arr[], int n, int d)
{
    d = d % n;

    int temp[d];
    // push value in temp array
    for (int i = 0; i < d; i++)
    {
        temp[i] = arr[i];
    }
    // left right
    for (int i = d; i < n; i++)
    {
        arr[i - d] = arr[i];
    }
    // add this temp val into arr[]
    for (int i = n - d; i < n; i++)
    {
        arr[i] = temp[i - (n - d)];
    }
}
void shiftZero(int arr[],int n){
    int i=0;
    for(int j=0;j<n;j++){
        if(arr[i] == 0 && arr[j] != 0 && j<n-1){
            
        }
    }
}
int main()
{
    // int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    // leftShift(arr, 8, 15);
    // for (int i = 0; i < 8; i++)
    //     cout << arr[i] << " ";

    int arr[]={0,1,0,3,12};
    shiftZero(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<< " ";  
    }
    return 0;
}