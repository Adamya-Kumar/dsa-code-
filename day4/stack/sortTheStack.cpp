#include <iostream>
#include<stack>
using namespace std;
void sorting(stack<int>& st,int newEle){
    if((st.empty()) || (!st.empty() && st.top() <= newEle)){
        st.push(newEle);
        return;
    }
    int num = st.top();
    st.pop();
    sorting(st,newEle);
    st.push(num);
}
void sortStack(stack<int>& st){
    if(st.empty()){
        return ;
    }
    int num = st.top();
    st.pop();

    sortStack(st);

    sorting(st,num);
}
void show(stack<int> st){
    if(st.empty()){
        return ;
    }
    cout<<st.top()<<" ";
    st.pop();
    show(st);
    
}

int main(){
    stack<int> st;
    st.push(5);
    st.push(-2);
    st.push(9);
    st.push(-7);
    st.push(3);
    sortStack(st);
    show(st);
return 0;
}