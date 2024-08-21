#include <iostream>
#include <vector>
#include <stack>
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
    bool CheckLinklistIsPalindrome_brutForce(Node *head)
    {
        stack<int> stk;
        Node *temp = head;
        while (temp != NULL)
        {
            stk.push(temp->data);
            temp = temp->next;
        }
        temp = head;
        while (temp != NULL)
        {
            if (temp->data == stk.top())
            {
                stk.pop();
            }
            else
            {
                return false;
            }
            temp = temp->next;
        }
        return true;
    }
    Node *findMiddleNodeOfLinklist(Node *head)
    {
        Node *fast = head;
        Node *slow = head;
        while (fast != NULL && fast->next != NULL && fast->next->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    Node *revserse_Linklist(Node *head)
    {
        Node *curr = head;
        Node *prev = NULL;
        Node *next;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    bool CheckLinklistIsPalindrome_optimalway(Node *head)
    {
        Node *slow = findMiddleNodeOfLinklist(head);
        Node *revHead = revserse_Linklist(slow->next);
        // compairing
        Node *second = revHead;
        Node *first = head;
        while (second != NULL)
        {
            if (first->data == second->data)
            {
                first = first->next;
                second = second->next;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    vector<int> arr{1, 1,1};
    Node *head = NULL;
    Linklist obj;
    // convert array into linkist..
    obj.convertArrayToLinklist(arr, head);
    // if(obj.CheckLinklistIsPalindrome_brutForce(head)){
    //     cout<<"plaindrome"<<endl;
    // }else{
    //     cout<<"Not palindrome"<<endl;
    // }
    // cout<<obj.CheckLinklistIsPalindrome_optimalway(head)<<endl;
    // cout<<obj.CheckLinklistIsPalindrome_optimalway(head);
    if (obj.CheckLinklistIsPalindrome_optimalway(head))
    {
        cout << "plaindrome" << endl;
    }
    else
    {
        cout << "Not palindrome" << endl;
    }

    return 0;
}