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
  bool delectLoopInLinklist(Node* head){
        Node* fast=head;
        Node* slow=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(fast == slow) return true;
        }
    return false;
  }
    int lengthOfLoopInLinklist(Node* head){
        map<Node*,int> mpp;
        Node* temp=head;
        int cnt=1;
        int len=0;
        while(temp!=NULL){
            if(mpp[temp]){
              return len=cnt-mpp[temp];
            }
            mpp[temp]=cnt;
            cnt++;
            temp=temp->next;
        }
        return -1;
    }
    int findLength(Node* slow,Node* fast){
            int cnt=1;
            fast=fast->next;
            while(fast!=slow){
                cnt++;
                fast=fast->next;
            }
        return cnt;
    }
    int lengthOfLoopInLinklist_optimalWay(Node* head){
        Node* fast=head;
        Node* slow=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(fast == slow){
              return this->findLength(slow,fast);
            }
        }
    return 0;
    }
     Node* revrseLinklist(Node* head){
        Node* temp=head;
        Node* prevNode=NULL;
        Node* nextNode=NULL;
        while(temp!=NULL){
         nextNode=temp->next;
        temp->next=prevNode;
        prevNode=temp;
        temp=nextNode;
        }
     return prevNode;
     }
};

int main()
{
    vector<int> arr{1, 2, 3, 4, 5, 6,7,8,9};
    Node *head = NULL;
    Linklist obj;
    //convert array into linkist..
    obj.convertArrayToLinklist(arr, head);
    // Node* tailNode=obj.returnTailNode(head);
    // tailNode->next=head->next->next;
    // //code write here..
    // // int len=obj.lengthOfLoopInLinklist(head);
    // int len=obj.lengthOfLoopInLinklist_optimalWay(head);
    // cout<<len<<endl;
    head=obj.revrseLinklist(head);
    obj.printLinklist(head);
    return 0;
}