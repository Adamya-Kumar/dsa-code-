#include <bits/stdc++.h>
using namespace std;

int leftSide(vector<int> &arr, int n, int key) {
  int start = 0;
  int end = n - 1;
  int ans = -1;
  int mid = start + (end - start) / 2;
  while (start <= end) {
    if (arr[mid] == key) {
      ans = mid;
      end = mid - 1;
    }
    if (arr[mid] > key) {
      end = mid - 1;
    }
    if (arr[mid] < key) {
      start = mid + 1;
    }
    mid = start + (end - start) / 2;
  }
  return ans;
}
int rightSide(vector<int> &arr, int n, int key) {
  int start = 0;
  int end = n - 1;
  int ans = -1;
  int mid = start + (end - start) / 2;
  while (start <= end) {
    if (arr[mid] == key) {
      ans = mid;
      start = mid + 1;
    }
    if (arr[mid] > key) {
      end = mid - 1;
    }
    if (arr[mid] < key) {
      start = mid + 1;
    }
    mid = start + (end - start) / 2;
  }
  return ans;
}
void firstAndLastPosition(vector<int> &arr, int n, int k) {
  pair<int, int> p;
  p.first = leftSide(arr, n, k);
  p.second = rightSide(arr, n, k);
  cout<<"Total occ is : "<<(p.second-p.first)+1<<endl;
 
}
int main(){
    vector<int> arr{0, 0, 1, 1, 2, 2, 2, 2};
    firstAndLastPosition(arr,arr.size(),2);
    return 0;
}