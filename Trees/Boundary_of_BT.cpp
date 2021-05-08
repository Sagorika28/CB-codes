#include <iostream>
#include <vector>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode*left;
    TreeNode*right;
    

    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode*buildTree()
{
    int data;
    cin>>data;
    TreeNode*root;
    if(data != -1)
        root = new TreeNode(data);
    else
        return NULL;
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void preorder(TreeNode*root)
{
    if(root==NULL)
        return;
    cout<<root->val<<",";
    preorder(root->left);
    preorder(root->right);
}


 vector <int> result;
     
     void storeRightSide(TreeNode*root)
     {
         if(root==NULL)
         return;
         if(root->right!=NULL)
         {
             storeRightSide(root->right);
             result.push_back(root->val);
         }
         else if(root->left!=NULL)
         {
             storeRightSide(root->left);
             result.push_back(root->val);
         }
     }
     
     void storeLeftSide(TreeNode*root)
     {
         if(root==NULL)
         return;
         if(root->left!=NULL)
         {
             result.push_back(root->val);
             storeLeftSide(root->left);
         }
         else if(root->right!=NULL)
         {
             result.push_back(root->val);
             storeLeftSide(root->right);
         }
     }
     
     void storeLeaves(TreeNode*root)
     {
         if(root==NULL)
         return;
         
         if(root->left==NULL and root->right==NULL)
         result.push_back(root->val);
         
         storeLeaves(root->left);
         storeLeaves(root->right);
     }
     
     
     
    vector <int> boundaryOfBinaryTree(TreeNode*root) 
    {
        // write your code here
        if(root==NULL)
        return result;
        if(root->left!=NULL)
            storeLeftSide(root);
        else
            result.push_back(root->val);
        storeLeaves(root);
        if(root->right!=NULL)
        {
            storeRightSide(root);
            result.pop_back(); //to remove the repeated root
        }
        return result;
    }

int main(int argc, char const *argv[])
{
    TreeNode*root = buildTree();
    preorder(root);
    cout<<endl;
    vector<int> arr;
    arr=boundaryOfBinaryTree(root);
    for (int i = 0; i < arr.size(); ++i)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}