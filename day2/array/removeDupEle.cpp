#include <iostream>
using namespace std;
void removeDul(int arr[],int n){
    int i=0;
    for(int j=0;j<n;j++){
        if(arr[i] != arr[j]){
            i++;
            arr[i]=arr[j];
        }
    }
    for(int k=i+1;k<n;k++)
        arr[k]=0;
}
int main(){
    int arr[]={1,1,2,2,2,3,3,4,4,4,4};
    removeDul(arr,11);
    for(int i=0;i<11;i++)
    cout<<arr[i]<<" ";
return 0;
}