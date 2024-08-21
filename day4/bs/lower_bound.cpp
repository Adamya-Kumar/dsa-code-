#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
int bs(vector<int> nums,int start,int end,int val){
  int ans=0;
    while(start <= end){
        int mid = start + (end - start)/2;
        if(nums[mid] >= val){
            ans=mid;
            end = mid - 1;
        }else{
            start = mid +1;
        }
    }
return ans;
}
int main(){
     vector<int> nums{1, 2, 3, 4, 6, 7, 8, 9, 10};
        cout<< bs(nums, 0, nums.size() - 1, 5);

        auto it=lower_bound(nums.begin(),nums.end(),7);
        cout<<it-nums.begin()<<" "<<endl;
return 0;
}