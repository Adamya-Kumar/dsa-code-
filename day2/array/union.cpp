#include <iostream>
#include<set>
using namespace std;
void unionNum(int arr[],int num[],int n,int m){
    set<int> s;
    for(int i=0;i<n+m;i++){
        if(i < n){
            s.insert(arr[i]);
        }else{
            s.insert(num[i]);
        }
    }
    for(auto it : s){
        cout<<it<<" ";
    }
}   
int main(){
    int arr[]={1,2,3,4,5};
    int num[]={1,2,3};
    unionNum(arr,num,5,3);
return 0;
}