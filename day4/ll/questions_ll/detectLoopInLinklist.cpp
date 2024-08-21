#include <iostream>
#include <vector>
#include<map>
using namespace std;
class Node
{

public:
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};
class Linklist
{
public:
    void convertArrayToLinklist(vector<int> arr, Node *&head)
    {
        int size = arr.size();
        Node *newNode = new Node(arr[0]);
        head = newNode;
        Node *ptr = head;
        for (int i = 1; i < size; i++)
        {
            Node *newNode = new Node(arr[i]);
            ptr->next = newNode;
            ptr = newNode;
        }
    }
    Node *deleteHeadIntoLinklist(Node *head)
    {
        if (head == NULL)
            return head;
        else
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        return head;
    }
    void printLinklist(Node *head)
    {
        Node *ptr = head;
        while (ptr)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
    Node *deletelastNodeInLinklist(Node *head)
    {
        Node *temp = head;
        Node *prev = NULL;
        while (temp->next)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        delete temp;
        return head;
    }
    Node *deleteKValueNodeIntoLinkList(Node *head, int target)
    {
        Node *prev = NULL;
        Node *curr = head;
        while (curr->data != target)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        delete curr;
        return head;
    }
    Node *insertNodeToHeadOfLinklist(Node *head, int value)
    {
        Node *newNode = new Node(value);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        return head;
    }
    Node *insertNodeToLastofLinklist(Node *head, int target)
    {
        Node *temp = head;
        Node *newNode = new Node(target);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        return head;
    }

    Node *insertAtKPosistionInLinklist(Node *head, int target, int position)
    {
        Node *newNode = new Node(target);
        int index = 1;
        Node *temp = head;
        Node *prev = NULL;
        if (head == NULL)
        {
            head = newNode;
        }
        while (index != position)
        {
            prev = temp;
            temp = temp->next;
            index++;
        }
        prev->next = newNode;
        newNode->next = temp;
        return head;
    }
     Node* returnTailNode(Node* head){
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    
   return temp;
   }
   bool delectLoopInLinklist_brutForce(Node* head){
        map<Node*,int> mpp;
        while(head != NULL){
            if(mpp[head]){
                return true;
            }
            mpp[head]++;
            head=head->next;
        }
        return false;
   }
   bool delectLoopInLinklist_optimalWay(Node* head){
        Node* fast=head;
        Node* slow=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(fast == slow) return true;
        }
    return false;
   }
};

int main()
{
    vector<int> arr{1, 2, 3, 4, 5, 6,7,8,9};
    Node *head = NULL;
    Linklist obj;
    //convert array into linkist..
    obj.convertArrayToLinklist(arr, head);
    Node* tailNode=obj.returnTailNode(head);
    tailNode->next=head->next->next;
    //    if(obj.delectLoopInLinklist_brutForce(head)){
    //         cout<<"loop in the linklist"<<endl;
    //    }else{
    //         cout<<"No-loop in the linklist"<<endl;
    //    }


    //optimal way..
 if(obj.delectLoopInLinklist_optimalWay(head)){
            cout<<"loop in the linklist"<<endl;
       }else{
            cout<<"No-loop in the linklist"<<endl;
       }

    
    return 0;
}