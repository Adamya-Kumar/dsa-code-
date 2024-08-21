#include <iostream>
#include<stack>
using namespace std;
    void insertEleAtBottom(stack<int>& st,int newEle){
        if(st.empty()){
          st.push(newEle);
            return;
        }
        int num = st.top();
        st.pop();
        insertEleAtBottom(st,newEle);
       
        st.push(num);
    }

    void revElement(stack<int>& st){
        if(st.empty()){
            return;
        }
        int num=st.top();
        st.pop();

        revElement(st);

    insertEleAtBottom(st,num);

    }
int main(){
    stack<int> st;
    st.push(3);
    st.push(4);
    st.push(7);
    st.push(9);
    revElement(st);
    for(int i=0;i<st.size();i++){
        cout<<st.top()<<" ";
        st.pop();
    }
return 0;
}