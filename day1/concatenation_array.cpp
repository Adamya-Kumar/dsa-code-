#include <iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> nums{1,2,1};
    vector<int> ans(2*3,0);
   for(int i=0;i<nums.size();i++){
        ans[i]=nums[i];
        ans[i+3]=nums[i];
   }
   for(auto it : ans){
        cout<<it<<" ";
   }
return 0;
}