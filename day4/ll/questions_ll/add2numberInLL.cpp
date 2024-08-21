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
    {  int cnt=0;
        Node *ptr = head;
        while (ptr != NULL)
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
    Node* add2NumberLL(Node* head1,Node* head2){
        int carry=0;
        Node* ptr1=head1;
        Node* ptr2=head2;
        Node* sum=NULL;
        Node* newNode=new Node(-1);
        sum=newNode;
        Node* curr=newNode;
        while(ptr1 !=NULL  && ptr2 != NULL){
            int sum=ptr1->data + ptr2->data + carry;
           
            if(sum > 9 ){
              int temp=sum %10;
                carry=sum/10;
                sum=temp;
            }
            Node* newNode=new Node(sum);
            curr->next=newNode;
            curr=curr->next;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        while(ptr1 !=NULL){
            int sum=ptr1->data+carry;
             if(sum > 9 ){
              int temp=sum %10;
                carry=sum/10;
                sum=temp;
            }
            Node* newNode=new Node(sum);
            curr->next=newNode;
            curr=curr->next;
            ptr1=ptr1->next;
        }
        while(ptr2 !=NULL){
            int sum=ptr2->data+carry;
             if(sum > 9 ){
              int temp=sum %10;
                carry=sum/10;
                sum=temp;
            }
            Node* newNode=new Node(sum);
            curr->next=newNode;
            curr=curr->next;
            ptr2=ptr2->next;
        }
        if(carry != 0){
            Node* newNode=new Node(carry);
            curr->next=newNode;
            curr=curr->next;
        }
        return sum->next;
    }
    Node* add2NumberLLnew(Node* head1,Node* head2){
        int carry=0;
        Node* ptr1=head1;
        Node* ptr2=head2;
        Node* sum=NULL;
        Node* newNode=new Node(-1);
          sum=newNode;
        Node* curr=newNode;
        while(ptr1 !=NULL  || ptr2 != NULL){
            int sum=carry;
            if(ptr1) sum+= ptr1->data;
            if(ptr2) sum+= ptr2->data;
            Node* newNode=new Node(sum%10);
            carry=sum/10;
            curr->next=newNode;
            curr=curr->next;
            if(ptr1) ptr1=ptr1->next;
            if(ptr2) ptr2=ptr2->next;
        }
        if(carry != 0){
            Node* newNode=new Node(carry);
            curr->next=newNode;
            curr=curr->next;
        }
        return sum->next;
    }
};

int main()
{
    vector<int> arr1{3,5};
    vector<int> arr2{4,5,9,9};
    Node *head1 = NULL;
    Node *head2 = NULL;
    Linklist obj;
    //convert array into linkist..
    obj.convertArrayToLinklist(arr1, head1);
    obj.convertArrayToLinklist(arr2, head2);
    //add2number
        // Node* sumHead=obj.add2NumberLL(head1,head2);
        Node* sumHead=obj.add2NumberLLnew(head1,head2);
        obj.printLinklist(sumHead);
    return 0;
}