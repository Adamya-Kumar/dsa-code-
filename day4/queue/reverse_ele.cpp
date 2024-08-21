#include <iostream>
#include<deque>
#include<stack>
using namespace std;
void show(deque<int> d){
    if(d.empty()){
        return;
    }
    cout<<d.front()<< " ";

    d.pop_front();
    show(d);
}
void better(deque<int>& d){
        if()
}
int main(){
    deque<int> d(6);
    stack<int> s;
    d.push_back(1); 
    d.push_back(2); 
    d.push_back(3); 
    d.push_back(4); 
    d.push_back(5); 
    d.push_back(6); 
    // for(auto itr : d){
       
    //     s.push(itr);
    //     d.pop_front();
    // }
    
    // while(!s.empty()){
    //    int it= s.top();
    //      s.pop();
    //     d.push_back(it);
    // }
    // show(d);
    better(d);
    show(d);
return 0;
}