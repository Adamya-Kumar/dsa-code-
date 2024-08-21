#include <iostream>
#include <vector>
using namespace std;
int bs(vector<int> &nums, int low, int high, int target)
{
    if (low > high)
    {
        return -1;
    }
     int mid = low+(high-low) / 2;
   
    if (nums[mid] == target){
        return mid;
    }   
     if (nums[mid] > target)
    {
        return bs(nums, low, mid - 1, target);
    }
    else
    {
       return bs(nums, mid + 1, high, target);
    }
}
int main()
{
    vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << bs(nums, 0, nums.size() - 1, 3);

    return 0;
}