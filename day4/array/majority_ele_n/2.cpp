#include <iostream>
#include <vector>
#include<map>
using namespace std;
int findMajor(vector<int> &nums)
{
    int n = nums.size();
    int cnt;
    for (int i = 0; i < n; i++)
    {
        cnt=0;
        for (int j = 0; j < n; j++)
        {
            if (nums[i] == nums[j])
            {
                cnt++;
            }
        }
        if (cnt > n / 2)
        {
            return nums[i];
        }
    }
}
int findMajorBetter(vector<int> nums){
    int n=nums.size();
    map<int,int> mpp;
    //nlogn
    for(int i=0;i<n;i++){
        mpp[nums[i]]++;
    }
    //n
    for(auto it : mpp){
        if(it.second > (n/2)){
            return it.first;
        }
    }
}
int findMajorOptimal(vector<int> nums){
    int n=nums.size();
    int element;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(cnt == 0){
            cnt=1;
            element=nums[i];
        }else if(nums[i] == element){ cnt++;}
        else{ cnt--;}
    }
    int cnt1=0;
    for(int i=0;i<n;i++){
        if(nums[i] == element) cnt1++;
    }
    if(cnt1 > (n/2)){
        return element;
    }
    return -1;
}
int main()
{
    vector<int> nums = {3, 2, 3, 3, 3, 2, 2};
    // cout<<findMajor(nums);   //n^2
    //cout<<findMajorBetter(nums);  //nlogn
    cout<<findMajorOptimal(nums);  //nlogn


    return 0;
}