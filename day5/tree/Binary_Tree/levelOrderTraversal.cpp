#include <iostream>
#include<vector>
#include<queue>
using namespace std;
class TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

public:
    TreeNode() {}
    TreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    TreeNode *createBTree(TreeNode *root)
    {
        int data;
        cout << "Enter the  data: " << endl;
        cin >> data;
        root = new TreeNode(data);
        if (data == -1)
        {
            return NULL;
        }
        cout << "Enter the left node of " << data << endl;
        root->left = createBTree(root->left);
        cout << "Enter the right node of " << data << endl;
        root->right = createBTree(root->right);
        return root;
    }
   vector<vector<int>> levelOrder(TreeNode* root){
            vector<vector<int>> ans;
            if(root ==  NULL) return ans;
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()){
                int size=q.size();
                vector<int> level;
                for(int i=0;i<size;i++){
                    TreeNode* node=q.front();
                    q.pop();
                    if(node->left!=NULL) q.push(node->left);
                    if(node->right!=NULL) q.push(node->right);
                    level.push_back(node->data);
                }
                ans.push_back(level);
            }
    return ans;
   }
};
int main()
{
    TreeNode obj;
    TreeNode *root = NULL;
    //1 2  4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    root = obj.createBTree(root);
    vector<vector<int>> ans=obj.levelOrder(root);
    for(auto pair : ans){
        cout<<"[ ";
        for(auto it :  pair){
            cout<<it<<" ";
        }
        cout<<"]";
    }
    return 0;
}