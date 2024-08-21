#include <iostream>
using namespace std;
int  comeOnces(int arr[],int n){
    int XOR=0;
    for(int i=0;i<n;i++){
        XOR=XOR ^ arr[i];
    }
    return XOR;
}

int main(){
    int arr[]={1,1,2,2,3,4,4,5,5};
    cout<<comeOnces(arr,9);
    print();
return 0;
}