#include<bits/stdc++.h>
using namespace std;
long long subArray(vector<long long> &arr,int k){
  int right=0;
  int n=arr.size();
  int left=0;
  long long maxLen=0;
  long long sum=arr[0];
  while(right < n){
      if(left <= right && sum > k){
        sum -= arr[left];
        left++;
      }if(sum == k){
          maxLen = max((int) maxLen,right-left+1);
      }
      right++;
      if(right < n) sum += arr[right];
  }
 return maxLen;
}
int main() {
    vector<long long> vec= {1,2,3,1,1,1,1,3,3};
    cout<<subArray(vec,6);

    return 0;
}