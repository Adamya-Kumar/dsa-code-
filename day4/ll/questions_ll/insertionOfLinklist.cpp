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

   Node* findTheIntersectionLinklist_bruntForce(Node* head1,Node* head2){
        map<Node*,int> mpp;
        Node* temp=head1;
        while(temp!= NULL){
            mpp[temp]++;
            temp=temp->next;
        }
      temp=head2;
      while(temp!=NULL){
        if(mpp[temp]){
            return temp;
        }
        temp=temp->next;
      }
    return new Node(-1);
   }
    int sizeOfLinklkist(Node* head){
        Node* temp=head;
        int cnt=1;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
    return cnt;
    }
Node* collsionPoint(Node* smallerhead,Node* largerHead,int d){
    Node* temp=largerHead;
    while(d==1){
        temp=temp->next;
        d--;
    }
    while(temp != smallerhead){
        temp=temp->next;
        smallerhead=smallerhead->next;
    }
    
return temp;
}
bool findTheIntersectionLinklist_betterWay(Node* head1,Node* head2){
        int size1=this->sizeOfLinklkist(head1);
        int size2=this->sizeOfLinklkist(head2);
        Node* temp;
        if(size1 > size2){
            temp =this->collsionPoint(head2,head1,size1-size2);
        }else if(size1 < size2){
           temp=this->collsionPoint(head1,head2,size2-size1);
        }
    if(temp == NULL){
        return false;
    }else{
        return true;
    }
                
}
Node* findTheIntersectionLinklist_optimalWay(Node* head1,Node* head2){
    Node* temp1=head1;
    Node* temp2=head2;
    if(temp1 == NULL || temp2 == NULL){
        return NULL;
    }
    while(temp1 != temp2){
        temp1=temp1->next;
        temp2=temp2->next;
        if(temp1 == temp2) return temp1;
        if(temp1 == NULL) temp1=head2;
        if(temp2 == NULL) temp2=head1;
    }
return temp1;
}

};

int main()
{
      Linklist obj;
    vector<int> arr1{3,1};
    Node* head1=NULL;
    obj.convertArrayToLinklist(arr1, head1);
    vector<int> arr2{1,2,4,5};
    Node* head2=NULL;
    obj.convertArrayToLinklist(arr2, head2);
    vector<int> arrI{4,6,2};
    Node* inter=NULL;
    obj.convertArrayToLinklist(arrI, inter);
    //connect inetrsection of linklist..
   Node* head1Tail=obj.returnTailNode(head1);
   Node* head2Tail=obj.returnTailNode(head2);
    
    head1Tail->next=inter;
    head2Tail->next=inter;
    //code start here..
    // Node* intersectionNode=obj.findTheIntersectionLinklist_bruntForce(head1,head2);
    // cout<<intersectionNode->next<<" "<<intersectionNode->data<<endl;
    //better way..
    //  bool val=obj.findTheIntersectionLinklist_betterWay(head1,head2);
    //optimal way..
    Node* intersectionNode=obj.findTheIntersectionLinklist_optimalWay(head1,head2);
    cout<<intersectionNode->next<<" "<<intersectionNode->data<<endl;
  
    return 0;
}