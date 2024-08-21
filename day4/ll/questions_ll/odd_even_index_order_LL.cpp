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
    Node *reordrerLinklist(Node *head)
    {

        vector<int> ans;
        Node *temp = head;
        while (temp != NULL && temp->next != NULL)
        {
            cout << temp->data << endl;
            ans.push_back(temp->data);
            temp = temp->next->next;
        }
        if (temp)
            ans.push_back(temp->data);
        temp = head->next;
        while (temp != NULL && temp->next != NULL)
        {
            
            ans.push_back(temp->data);
            temp = temp->next->next;
        }
        if (temp)
            ans.push_back(temp->data);

        int index=0;
        temp=head;
        while(temp!= NULL){
            temp->data=ans[index];
            index++;
            temp=temp->next;
        }
        return head;
    }
   Node* reordrerLinklistnew(Node* head){
        Node* odd=head;
        Node* even=head->next;
        Node* evenHead=head->next;
        while(even!= NULL && even->next !=NULL){
            odd->next=odd->next->next;
            even->next=even->next->next;
            odd=odd->next;
            even=even->next;
        }
        odd->next=evenHead;
    return head;
    }
};

int main()
{
    vector<int> arr{2, 4, 6, 8, 10};
    Node *head = NULL;
    Linklist obj;
    // convert array into linkist..
    obj.convertArrayToLinklist(arr, head);
    // head = obj.reordrerLinklist(head);
    head=obj.reordrerLinklistnew(head);
    cout<<head->data<<endl;
    obj.printLinklist(head);
    return 0;
}