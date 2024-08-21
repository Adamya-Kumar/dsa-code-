#include<iostream>
using namespace std;
class Node{
    int data;
    Node* right;
    Node* left;
    public:
    Node(){}
    Node(int data){
        this->data=data;
        right=NULL;
        left=NULL;
    }
    void createNode(Node* &root){
        Node* left=new Node(2);
        Node* right=new Node(3);
        root->left=left;
        root->right=right;

        left=new Node(4);
        right=new Node(5);
        root->left->left=left;
        root->left->right=right;

        left=new Node(7);
        root->left->left->left=left;
        left=new Node(5);
        root->left->right->left=left;
        left=new Node(6);
        root->right->left=left;
        right=new Node(9);
        root->right->left->right=right;
       
    }
   void InOrderPrint(Node* root){
        if(root == NULL){
            return;
        }
        InOrderPrint(root->left);
        cout<<root->data<<" ";
        InOrderPrint(root->right);
   }
   void perOrderPrint(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    perOrderPrint(root->left);
    perOrderPrint(root->right);
   }
   void postOrderPrint(Node* root){
    if(root == NULL) return;
        postOrderPrint(root->left);
        postOrderPrint(root->right);
        cout<<root->data<<" ";
   }
};
int main(){
    Node obj;
    Node* root=new Node(1);
    obj.createNode(root);
    // obj.InOrderPrint(root);
    // cout<<endl;
    // obj.perOrderPrint(root);
    // cout<<endl;
    obj.postOrderPrint(root);
    return 0;
}