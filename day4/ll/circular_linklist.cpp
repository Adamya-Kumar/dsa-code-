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
};
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Node *head = NULL;
    Node obj;
    head = obj.convertArrayToLinklist(arr, head);
    head = obj.insertHeadIntoLinklist(head, 88);
    head = obj.insertLastNodeIntoLinklist(head, 99);
    head = obj.insertAtKNodeIntoLinklist(head, 55,3);
    //pop
    head=obj.deleteHeadOfLinklist(head);
    head=obj.deleteLastNodeOfLinklist(head);
    head=obj.deleteKNodeOfLinklist(head,2);
    obj.printLinklist(head);
    return 0;
}