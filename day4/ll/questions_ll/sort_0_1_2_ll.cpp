#include <iostream>
#include <vector>
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
    Node* sort_0_1_2_LL(Node* head){
        Node* temp=head;
        int cnt0=0,cnt1=0,cnt2=0;
        while(temp){
            if(temp->data == 0){
                cnt0++;
            }else if( temp->data == 1){
                cnt1++;
            }else{
                cnt2++;
            }
            temp=temp->next;
        }
        
        temp=head;
        while(temp){
            if(cnt0 != 0){
                temp->data=0;
                cnt0--;
            } 
            else if(cnt1 != 0){
                temp->data=1;
                cnt1--;
            }
           else if( cnt2 != 0){
                temp->data=2;
                cnt2--;
            }
            temp=temp->next;
        }
    return head;
    }
    Node* sort_0_1_2_LL_optimalWay(Node* head){
        Node* temp=head;
        Node* zero=new Node(-1);
        cout<<zero->data<<endl;
        Node* one=new Node(-1);
        Node* oneHead=one;
        Node* two=new Node(-1);
        Node* twoHead=two;
        while(temp){
            Node* newNode=new Node(temp->data);
            if(temp->data == 0){
                zero->next=newNode;
                zero=zero->next;
            }else if( temp->data == 1){
                one->next=newNode;
                one=one->next;
            }else{
                two->next=newNode;
                two=two->next;
            }

            temp=temp->next;
        }
        Node* check=zero;
         while(check){
            cout<<check->data<<" ";
            check=check->next;
        }
        cout<<endl;
        zero->next=oneHead->next;
        one->next=twoHead->next;
       
    return zero;
    }
    int getMiddle(Node* head) {
        Node* fast=head;
        Node* slow=head;
        while(fast != NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        
        return slow->data;
    }
};

int main()
{
    // vector<int> arr{1 ,0 , 2 ,1 ,2};
    Node *head = NULL;
    Linklist obj;
    //convert array into linkist..
    // obj.convertArrayToLinklist(arr, head);
    // head=obj.sort_0_1_2_LL(head);
    // head=obj.sort_0_1_2_LL_optimalWay(head);
    // obj.printLinklist(head);
    //get middle element of linklist..
    vector<int> ll{1,2,3,4,5,6};
    obj.convertArrayToLinklist(ll,head);
    obj.printLinklist(head);
    int mid=obj.getMiddle(head);
    cout<<mid<<endl;
    unsigned int val= -7;
    cout<<val;
    return 0;
}