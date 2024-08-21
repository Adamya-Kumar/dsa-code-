#include <iostream>
#include<queue>
using namespace std;
int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    cout<<q.size()<<endl;
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    cout<<q.size()<<endl;
    q.pop();
    if(q.empty()) cout<<"queue is empty"<<endl;
    else cout<<"queue is not empty"<<endl;
    q.push(99);
    q.push(367);
    q.push(91);
    q.pop();
    cout<<q.front()<<endl;
return 0;
}