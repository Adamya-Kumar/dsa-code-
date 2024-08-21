#include <iostream>
#include<deque>
using namespace std;
int main(){
    deque<int> q;
    //push
    q.push_front(99);
    q.push_front(90);
    q.push_front(79);
    q.push_back(10);
    q.push_back(20);
    q.push_back(30);
    q.push_back(40);

    //pop
    q.pop_front();
    q.pop_front();
    q.pop_back();
    q.pop_back();
    //show
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    cout<<q.empty()<<endl;

return 0;
}