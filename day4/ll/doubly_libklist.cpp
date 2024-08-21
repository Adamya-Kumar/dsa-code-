#include <iostream>
#include <vector>
#include<stack>
using namespace std;
class Node
{
    int data;
    Node *prev;
    Node *next;

public:
    Node() {}
    Node(int data)
    {
        this->data = data;
        prev = NULL;
        next = NULL;
    }
    Node *convertArrayToLinklist(Node *head, vector<int> arr)
    {
        Node *newNode = new Node(arr[0]);
        head = newNode;
        Node *ptr = head;
        for (int i = 1; i < arr.size(); i++)
        {
            newNode = new Node(arr[i]);
            ptr->next = newNode;
            newNode->prev = ptr;
            ptr = ptr->next;
        }
        return head;
    }
    void printLinklist(Node *head)
    {
        Node *temp = head;
        while (temp !=NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    Node *deleteHeadNodeInLinklist(Node *head)
    {
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
        return head;
    }
    Node *deleteLastNodeInLinklist(Node *head)
    {
        Node *ptr = head;
        Node *back;
        while (ptr->next)
        {
            back = ptr;
            ptr = ptr->next;
        }
        back->next = NULL;
        delete ptr;
        return head;
    }
    Node *deleteKNodeInLinklist(Node *head, int position)
    {
        Node *curr = head;
        Node *back;
        int index = 1;
        while (index != position)
        {
            back = curr;
            curr = curr->next;
            index++;
        }
        back->next = curr->next;
        curr->next->prev = back;
        return head;
    }
    Node *insertNodeAtHeadOfLinklist(Node *head, int target)
    {
        Node *newNode = new Node(target);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        return head;
    }
    Node *insertNodeAtLastOfLinklist(Node *head, int target)
    {
        Node *ptr = head;
        Node *newNode = new Node(target);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            while (ptr->next)
            {
                ptr = ptr->next;
            }

            ptr->next = newNode;
            newNode->prev = ptr;
        }
        return head;
    }
    Node* insertAtKNodeIntoLinklist(Node* head,int target,int position){
        Node* newNode=new Node(target);
        int index=1;
        Node* curr=head;
        Node* back;
        while(index != position){
            back=curr;
            curr=curr->next;
            index++;
        }
       back->next= newNode;
       newNode->prev=back;
       newNode->next=curr;
       curr->prev = newNode;
        
    return head;
    }
    Node* reverse_ll_brutForce(Node* head){
          Node* temp=head;
        stack<int> stk;
        while(temp->next){
            stk.push(temp->data);
            temp=temp->next;
        }
        temp=head;
        int val=0;
         while(temp->next){
            val= stk.top();
              stk.pop();
            temp->data=val;
            temp=temp->next;
        }
    return head;
    }
    Node* reverse_ll_optimalway(Node* head){
        Node* curr=head;
        Node* prev=NULL;
        while(curr!=NULL){
            prev=curr->prev;
            curr->prev=curr->next;
            curr->next=prev;
            curr=curr->prev;
        }
        head=prev->prev;
        return head;
    }
};

int main()
{
    Node *head = NULL;
    Node obj;
    vector<int> vec = {1, 2, 3, 4, 5, 6};
    head = obj.convertArrayToLinklist(head, vec);
    // head=obj.deleteHeadNodeInLinklist(head);
    // head=obj.deleteLastNodeInLinklist(head);
    // head = obj.deleteKNodeInLinklist(head, 3);
    // insert data into linkist..
    // head = obj.insertNodeAtHeadOfLinklist(head, 99);
    // head = obj.insertNodeAtLastOfLinklist(head, 87);
    // head= obj.insertAtKNodeIntoLinklist(head,33,3);
    obj.printLinklist(head);
    // head=obj.reverse_ll_brutForce(head);
    head=obj.reverse_ll_optimalway(head);
    obj.printLinklist(head);
    return 0;
}