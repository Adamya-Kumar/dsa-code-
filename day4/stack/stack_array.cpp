#include <iostream>
using namespace std;
class Stack{
    int *arr;
    int size;
    int top;
    public:
    Stack(int size){
        this->size=size;
        top=-1;
        arr=new int[size];
    }
    void push(int ele){
        top++;
        arr[top]=ele;
    }
    void pop(){
        cout<<arr[top]<<"this delete from stack.."<<endl;
        top--;
    }
    bool isEmpty(){
        if(top == -1){
            return true;
        }
    return false;
    }
    bool isFull(){
        if(top == size-1){
            return true;
        }
    return false;
    }
    void show(){
        for(int i=0;i<=top;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    void peek(){
        if(top != -1 && top <size){
            cout<<arr[top];
        }
    }
};
int main(){
    Stack obj(5);
    obj.push(10);
    obj.push(20);
    obj.push(30);
    obj.push(40);
    obj.show();
    // cout<<obj.isFull();
    obj.peek();
return 0;
}