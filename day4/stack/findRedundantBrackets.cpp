#include <iostream>
#include <stack>
using namespace std;
bool findRedundantBrackets(string &str)
{
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        char val = str[i];
        if ((val == '(') ||
            (val == '*') || (val == '+') || (val == '/') || (val == '-'))
        {
            st.push(val);
        }
        else
        {
            bool isReduntant = true;
            if (val == ')')
            {
                while (st.top() != '(')
                {
                    if ((st.top() == '+') || (st.top() == '-') || (st.top() == '/') || (st.top() == '*'))
                    {
                        isReduntant = false;
                    } 
                    st.pop();
                }
                if(isReduntant == true){
                    return true;
                    st.pop();
                }
            }
        }
    }
    return false;
}
int main()
{
    string str = "(a+ b)";
    if (findRedundantBrackets(str))
    {
        cout << "Redundant" << endl;
    }
    else
    {
        cout << "not Redundant" << endl;
    }
    return 0;
}