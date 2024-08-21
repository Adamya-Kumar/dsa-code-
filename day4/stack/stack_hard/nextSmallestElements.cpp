#include <iostream>
#include<stack>
#include<vector>
using namespace std;
void nextSmallerElement(vector<int>& arr,vector<int>& ans,int n){
    stack<int> st;
    st.push(-1);
    for(int i=n-1;i>=0;i--){
        while(st.top() >= arr[i]){
            st.pop();
        }
        ans[i]=st.top();
        st.push(arr[i]);
    }
}
int main(){
        vector<int> arr{2,1,4,3};
        vector<int> ans(4);
nextSmallerElement(arr,ans,arr.size());
  for(auto itr : ans){
    cout<<itr<<" ";
  }
return 0;
}