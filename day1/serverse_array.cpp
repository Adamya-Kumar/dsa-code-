#include<bits/stdc++.h>
#include<vector>
using namespace std;

void revserArray(vector<int>& arr){
    int n=arr.size();
    int i=0;
    int j=n-1;
    while(i < j){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
}   

int main(){
    vector<int> arr{2,7,5,9,8};
    revserArray(arr);
    for(auto it :arr){
        cout<<it<<" ";
    }

return 0;
}