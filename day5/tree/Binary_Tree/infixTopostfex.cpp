#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int periroty(char val){
    if(val == '^'){
        return 3;
    }else if(val == '*' || val == '/'){
        return 2;
    }else if(val == '+' || val == '-'){
        return 1;
    }else{
        return -1;
    }
}
vector<char> InfixToPostFix(string express){
    vector<char> ans;
    stack<char> st;
    for(int i=0;i<express.length();i++){
        if((express[i] >= 'A' && 'Z' <= express[i]) ||
        (express[i] >= 'a' && 'z' <= express[i]) ||
        (express[i] >= '0' && '9' <= express[i])
        ){
                ans.push_back(express[i]);
        }else if(express[i] == '('){
                st.push(express[i]);
        }else if(express[i] == ')'){
            while(!st.empty() || st.top()!= '('){
                ans.push_back(st.top());
                st.pop();
            }
            st.pop();
        }else{
            while(!st.empty() &&  periroty(express[i])<=periroty(st.top())){
                st.push(express[i]);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
    }
return ans;
}
int main(){
    string expression="a+b*(c^d-e)";
    vector<char> ans=InfixToPostFix(expression);    
    for(auto it:ans){
        cout<<it<<" ";
    }
return 0;
}