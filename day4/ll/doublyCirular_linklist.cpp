#include <iostream>
#include <vector>
using namespace std;
class Node
{
    int data;
    Node *next;
    Node *prev;

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
        newNode->prev = head;
        newNode->next = head;
        Node *ptr = head;
        for (int i = 1; i < arr.size(); i++)
        {
            newNode = new Node(arr[i]);
            Node *ptr = head;
            do
            {
                ptr = ptr->next;
            } while (ptr->next != head);
            ptr->next = newNode;
            newNode->prev = ptr;
            newNode->next = head;
            head->prev = newNode;
        }
        return head;
    }
    Node *insertHeadNodeOfLinklist(Node *head, int value)
    {
        Node *newNode = new Node(value);
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
        }
        else
        {
            Node *ptr = head;
            do
            {
                ptr = ptr->next;
            } while (ptr->next != head);
            ptr->next = newNode;
            newNode->prev = ptr;
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        return head;
    }
    void printLinklist(Node *head)
    {
        Node *ptr = head;
        do
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        } while (ptr != head);
        cout << endl;
    }
    Node *insertLastNodeOfLinklist(Node *head, int value)
    {
        Node *newNode = new Node(value);
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
        }
        Node *ptr = head;
        do
        {
            ptr = ptr->next;
        } while (ptr->next != head);

        ptr->next = newNode;
        newNode->prev = ptr;
        newNode->next = head;
        head->prev = newNode;
    }
    Node* insertKNodeIntoLinklist(Node* head,int value,int position){
        Node* newNode=new Node(value);
        if(head ==  NULL){
            head=newNode;
            newNode->prev=head;
            newNode->next=head;
        }else{
            
        }
    }
};
int main()
{
    Node obj;
    Node *head = NULL;
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    head = obj.convertArrayToLinklist(head, arr);
    head = obj.insertHeadNodeOfLinklist(head, 77);
    head = obj.insertLastNodeOfLinklist(head, 99);
    head = obj.insertKNodeIntoLinklist(head, 22,3);

    obj.printLinklist(head);

    return 0;
}