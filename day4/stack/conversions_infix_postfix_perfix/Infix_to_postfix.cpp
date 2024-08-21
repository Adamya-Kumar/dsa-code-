#include <iostream>
#include <stack>
using namespace std;
int priority(char opt){
    if(opt == '^'){
        return 3;
    }else if(opt == '*' || opt == '/'){
        return 2;
    }else if(opt == '+' || opt == '-'){
        return 1;
    }else{
        return -1;
    }
}
string convertInfixToPostfix(string str){
    stack<int> st;
    string ans="";
    for(int i=0;i<str.size();i++){
        if((str[i] >= 'A' && 'Z' <= str[i]) ||
        (str[i] >= 'a' && 'z' <= str[i]) ||
        (str[i] >= '0' && '9' <= str[i])){
            ans.push_back(str[i]);
        }else if(str[i] == '('){
            st.push(str[i]);
        }else if(str[i] == ')'){
            while(st.empty() && st.top() != '(' ){
                ans.push_back(st.top());
                st.pop();
            }
        st.pop();
        }else{
            if(st.empty() && priority(str[i])<= priority(str[i])){
                ans.push_back(st.top());
                st.pop();
            }
            st.push(str[i]);
        }
    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
int main(){
    string expression="a+b*(c^d-e)";
    cout<<expression<<endl;
    string ans=convertInfixToPostfix(expression);
    cout<<ans<<endl;
return 0;
}