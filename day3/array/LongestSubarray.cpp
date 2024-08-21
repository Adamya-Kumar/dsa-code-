#include <bits/stdc++.h>
using namespace std;
int burtForce(int arr[], int n)
{
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; i++)
        {
            for (int k = i; k < j; k++)
            {
                sum += arr[k];
                if (sum == k)
                    len = max(len, j - i + 1);
            }
        }
    }
    return len;
}
void maping(int arr[], int n)
{
    map<int, int> gquiz1;
    
    gquiz1.insert(pair<int, int>(1, 40));
    gquiz1.insert(pair<int, int>(2, 30));
    gquiz1.insert(pair<int, int>(3, 30));
    gquiz1.insert(pair<int, int>(4, 30));
    gquiz1.insert(pair<int, int>(8, 30));
    gquiz1.insert(pair<int, int>(9, 30));
  

    // for(auto it : gquiz1){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }
    // auto f = gquiz1.find(3);

    // for(auto it=gquiz1.find(3);it!= gquiz1.end();it++){
    //     cout<<it->first<<endl;
    // }
    auto itr = gquiz1.find(9);
    cout<<itr-<<endl;
    if(gquiz1.find(9) != gquiz1.end()){
        cout<<"enter in this"<<endl;
    }
   
}

int main()
{
    int arr[] = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
    // int ans=burtForce(arr,10);
    // cout<<ans<<endl;

    maping(arr, 10);
    return 0;
}