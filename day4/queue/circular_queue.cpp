#include <iostream>
using namespace std;
class CiruclarQueue{
    int *arr;
    int front;
    int rear;
    int size;
    public:
    CiruclarQueue(int size){
        this->size=size;
        front=-1;
        rear=-1;
        arr=new int[size];
    }
    void inqueue(int data){
        if(front == -1 && rear ==-1){
            front++;
            rear++;
            arr[rear]=data;
        }
        if(front > 0 && rear == size-1){
            rear=0;
            arr[rear]= data;
            rear++;
        }
        else if(rear < size-1){
            rear++;
            arr[rear]=data;
        }else if(rear == (front-1)%(size-1)){
            cout<<"Queue is full"<<endl;
        }else{
            rear++;
            arr[rear]=data;
        }
    }
    void show(){
        cout<<arr[front]<<" ";
    }
    void dequeue(){
        if(front == -1 && rear == -1){
            cout<<"queue is empty"<<endl;
        }else{
               front++; 
        }
    }
    bool isEmpty(){
        if(front == -1 && rear == -1 ){
            return true;
        }else if(rear == (front-1)%(size-1)){
                return true;
        }else{
            return false;
        }
    }
    bool isFull(){
        if(rear == (front-1)%(size-1)){
            return true;
        }else{
            return false;
        }
    }
};
int main(){
      CiruclarQueue obj(7);
      obj.inqueue(10);
      obj.inqueue(20);
      obj.inqueue(30);
      obj.inqueue(40);
      
     obj.dequeue();
     obj.dequeue();
     obj.dequeue();
     obj.dequeue();
     obj.dequeue();
     obj.show();
      cout<<obj.isEmpty();
      cout<<obj.isFull();
      
return 0;
}