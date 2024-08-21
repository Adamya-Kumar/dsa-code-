#include <iostream>
#include<stack>
using namespace std;
    void addElement(stack<int>& st,int newEle){
        if(st.empty()){
          st.push(newEle);
            return;
        }
        int num = st.top();
        st.pop();
        addElement(st,newEle);
       
        st.push(num);
    }

int main(){
    stack<int> st;
        st.push(7);
        st.push(2);
        st.push(1);
        st.push(6);
        int cnt=0;
      cout<<st.size()<<endl;
    addElement(st,99);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
return 0;
}