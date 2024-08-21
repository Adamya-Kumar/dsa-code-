#include <iostream>
#include <vector>
using namespace std;
class Node
{
    int data;
    Node *next;

public:
    Node() {}
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
    Node *insertHeadIntoLinklist(Node *head, int target)
    {

        Node *newNode = new Node(target);
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
        }
        Node *ptr = head;
        do
        {
            ptr = ptr->next;
        } while (ptr->next != head);

        ptr->next = newNode;
        newNode->next = head;
        head = newNode;
        return head;
    }
    Node *convertArrayToLinklist(vector<int> arr, Node *head)
    {
        int Size = arr.size();
        head = new Node(arr[0]);
        Node *ptr = head;
        Node *curr = NULL;
        for (int i = 1; i <= Size; i++)
        {
            curr = ptr;
            ptr->next = new Node(arr[i]);
            ptr = ptr->next;
        }
        curr->next = head;
        return head;
    }
    void printLinklist(Node *Head)
    {
        Node *head = Head;
        do
        {
            cout << head->data << " ";
            head = head->next;
        } while (head != Head);
        cout << endl;
    }
    Node* insertLastNodeIntoLinklist(Node* head,int target){
        Node* newNode=new Node(target);
        if(head == NULL){
            head=newNode;
            newNode->next=head;
        }else{
        Node* ptr;
        do{
            ptr=ptr->next;
        }while(ptr->next != head);
        ptr->next=newNode;
        newNode->next=head;
        }
        return head;
    }
    Node* insertAtKNodeIntoLinklist(Node* head,int target,int position){
        Node* newNode=new Node(target);
         if(head == NULL){
            head=newNode;
            newNode->next=head;
        }else{
            int index=1;
            Node* ptr=head;
            Node* curr;
            while(index != position){
                curr=ptr;
                ptr=ptr->next;
                index++;
            }
            newNode->next=ptr;
            curr->next=newNode;
        }
    return head;
    }
    Node* deleteHeadOfLinklist(Node* head){
        if(head == NULL){
            return head;
        }else{
            Node* ptr=head;
            do{
                ptr=ptr->next;
            }while(ptr->next != head);
            ptr->next=head->next;
            ptr=head;
            head=head->next;
            delete ptr;
        }
    return head;
    }
    Node* deleteLastNodeOfLinklist(Node* head){
        if(head == NULL){
            return head;
        }else{
            Node* ptr=head;
            Node* curr=NULL;
            do{
                curr=ptr;
                ptr=ptr->next;
            }while(ptr->next != head);
            curr->next=head;
            delete ptr;
        }
    return head;
    }
    Node* deleteKNodeOfLinklist(Node* head,int position){
        if(head == NULL){
            return head;
        }else{
            int index=1;
            Node* ptr=head;
            Node* curr=NULL;
            while(index != position){
                curr=ptr;
                ptr=ptr->next;
                index++;
            }
            curr->next=ptr->next;
            delete ptr;
        }
    return head;
    }
    
        int helper(Node* &temp){
            if(temp == NULL){
                return 1;
            }
          int carry=helper(temp->next);
            temp->data=temp->data+carry;
            if(temp->data < 10){
                return 0;
            }
                temp->data=0;
                return 1;
        }

    Node* add1ToLinklist(Node* head){
        int carry=helper(head);
        if(carry == 1){
            Node* newNode=new Node(carry);
            carry=0;
            newNode->next=head;
            head= newNode;
            
        }
    return head;
    }

};
int main()
{
    vector<int> arr = {9,9,9,9};
    Node *head = NULL;
    Node obj;
    // obj.printLinklist(head);
    head=obj.add1ToLinklist(head);
    obj.printLinklist(head);
    return 0;
}