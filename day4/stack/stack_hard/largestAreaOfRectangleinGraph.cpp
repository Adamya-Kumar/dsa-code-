#include <bits/stdc++.h>
using namespace std;
vector<int> nextMove(vector<int> &hieghts)
{
    stack<int> s;
    int n = hieghts.size();
    vector<int> ans(n);
    s.push(-1);
    for (int i = n - 1; i >= 0; i--)
    {
        while (s.top() != -1 && hieghts[s.top()] >= hieghts[i])
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
vector<int> prevMove(vector<int> &hieghts)
{
    stack<int> s;
    int n = hieghts.size();
    vector<int> ans(n);
    s.push(-1);
    for (int i = 0; i < n; i++)
    {
        while (s.top() != -1 && hieghts[s.top()] >= hieghts[i])
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);  
    }
    return ans;
}
int findLargestArea(vector<int> &hieghts)
{

    int n = hieghts.size();
    vector<int> next(n);
    next = nextMove(hieghts);
    vector<int> prev(n);
    prev = prevMove(hieghts);
    int result = -1;
    for (int i = 0; i < n; i++)
    {
        int l = hieghts[i];
        if (next[i] == -1)
            next[i] = n;
        int b = next[i] - prev[i] - 1;
        int newArea = l * b;
        result = max(result, newArea);
    }
    return result;
}
int main()
{
    vector<int> hieghts = {2, 1, 5, 6, 2, 3};
    int ans = findLargestArea(hieghts);
    cout << ans << endl;
    return 0;
}