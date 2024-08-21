#include <iostream>
using namespace std;
class Node
{

public:
    int data;
    Node *next;
    Node() {}
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
class Stack
{
public:
    void push(Node *&top, int data)
    {
        Node *newNode = new Node(data);
        if (top == NULL)
        {
            top = newNode;
            return;
        }
        newNode->next = top;
        top = newNode;
    }
    auto pop(Node* &top){
        Node* temp=top;
        top=top->next;
        delete temp;
    }
    void top(Node* &top){
        cout<<top->data<<endl;
    }
    int size(Node* top){
        Node* temp=top;
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
};
int main()
{
    Node *top = NULL;
    Stack obj;
    obj.push(top, 10);
    obj.push(top, 20);
    obj.push(top, 30);
    obj.push(top, 40);
     obj.top(top);
    cout<<obj.size(top);
    return 0;
}