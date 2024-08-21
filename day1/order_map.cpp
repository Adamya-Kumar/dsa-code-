#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int main()
{
    int cnt = 0;
   
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }
    for (int i = 0; i < nums.size(); i++)
    {

        if (mp[i] > 0)
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}