#include <iostream>
#include <stack>
using namespace std;
class Stack{
    //tc O(1) , sc O(2*N)
    public:
    stack<pair<int,int>> st;
    void push(int data){
            if(st.empty()){
                st.push({data,data});
            }else{
                st.push({data,min(data,st.top().second)});
            }
    }
    int getMin(){
        if(!st.empty()){
            return st.top().second;
        }
    }
    void pop(){
        st.pop();   
    }
    int top(){
        return st.top().first;
    }
};
class MinNumInStackMoreOpitmal{
    public:
    stack<int> stk;
    void push(int data){
        if(stk.empty()){
             
        }
    }
};
int main(){
    Stack obj;
    obj.push(10);
    obj.push(20);
    obj.push(5);
    cout<<obj.top()<<endl;
    cout<<obj.getMin()<<endl;
    cout<<obj.top()<<endl;
    obj.pop();
    cout<<obj.getMin()<<endl;
    cout<<obj.top()<<endl;

return 0;
}