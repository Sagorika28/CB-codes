#include <iostream>
using namespace std;

class node
{
public:
	int data;
	node*left;
	node*right;

	node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

node* insertInBST(node*root, int data) //to create a BST
{
	if(root==NULL)
		{
			root=new node(data);
			return root;
		}

	if(data < root->data)
		root->left = insertInBST(root->left, data);

	else
		root->right = insertInBST(root->right, data);
	return root;
}

void inorder(node*root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

bool helper(node*root)
{
	if(root == NULL)
		return false;
	bool left = helper(root->left);
	bool right = helper(root->right);
	if(left == false)
		root->left = NULL;
	if(right == false)
		root->right = NULL;
	return left or right or root->data==1;	
}

node*pruning(node*root)
return helper(root)?root:NULL;

int main(int argc, char const *argv[])
{
	node*root = NULL;
	int n;
	cin>>n;
	while(n--)
	{
		int data;
		cin>>data;
		root=insertInBST(root,data);
	}
	inorder(root);
	cout<<endl;
	
	pruning(root);
	inorder(root);
	cout<<endl;
	return 0;
}