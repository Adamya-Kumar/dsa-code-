#include <iostream>

#include <unordered_map> 
using namespace std;
int findUnique(int *arr, int size)
{
    unordered_map<int,int> mapping;
    for(int i=0;i<size;i++){
        mapping[arr[i]]++;
    }
    for(auto it : mapping){
        if(it.second == 1){
            return it.first;
        }
    }
}
int main(){
    int arr[]={2 ,4 ,7, 2, 7};
    int size= sizeof(arr)/sizeof(int);
   cout<<"this is the unique value in array : "<<findUnique(arr,size)<<endl;
return 0;
}