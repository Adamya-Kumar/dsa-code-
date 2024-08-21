#include <iostream>
#include<stack>
using namespace std;
 
int main(){
    stack<char> str;
    string name = "adamya";
    for(int i=0;i<name.length();i++){
       char temp = name[i];
        str.push(temp);
    }
    name="";
    while(!str.empty()){
        name.push_back(str.top());
        str.pop();
    }
    cout<<"result is : "<<name<<endl;
return 0;
}