#include <iostream>
#include<stack>
using namespace std;
bool isVaildParenthesis(string s)
{
    stack<char> STACK;
    for(int i=0;i<s.length();i++){
        char smb = s[i];
        if(smb == '(' || smb == '[' || smb == '{'){
            STACK.push(smb);
        }else{
            if(!STACK.empty()){
                if((smb == ')' && STACK.top()== '(') ||
                    (smb == '}' && STACK.top() == '{') || 
                    (smb == ']' && STACK.top() == '[')
                ){
                    STACK.pop();
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }
    }
    return STACK.empty();
}
int main()
{
    // string str = "[{()}]"; //balanced
    string str = "[{(}"; //Unbalanced
    if (isVaildParenthesis(str))
    {
        cout << "Balnaced" << endl;
    }
    else
    {
        cout << "Unbalnaced" << endl;
    }
    return 0;
}