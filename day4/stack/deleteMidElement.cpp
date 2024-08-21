#include <iostream>
#include <stack>
using namespace std;
   void deleteMid(stack<int>& STACK ,int size,int count){
            //base case..
            if(count == size/2){
                STACK.pop();
                return;
            }
            //extra values..
            int num = STACK.top();
            STACK.pop();
            //recursive call
            deleteMid(STACK,size,count+1);
            //add the extra values..
            STACK.push(num);
   }
int main(){
    stack<int> STACK;
    int n = STACK.size();
    int cnt=0;
    deleteMid(STACK,n,cnt);
    
return 0;
}