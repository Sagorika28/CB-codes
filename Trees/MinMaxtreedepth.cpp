#include <iostream>
#include <climits>
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

node*buildTree()
{
	int data;
	cin>>data;
	node*root;
	if(data != -1)
		root = new node(data);
	else
		return NULL;
	root->left = buildTree();
	root->right = buildTree();
	return root;
}

void preorder(node*root)
{
	if(root==NULL)
		return;
	cout<<root->data<<",";
	preorder(root->left);
	preorder(root->right);
}

int minheight(node*root)
{
	if(root==NULL)
		return 0;
	if(root->left==NULL and root->right==NULL)
		return 1;
	int lh = INT_MAX;
	int rh = INT_MAX;
	if(root->left!=NULL)
		lh=minheight(root->left);
	if(root->right!=NULL)
		rh=minheight(root->right);
	return 1+min(lh,rh); 
}

int maxheight(node*root)
{
	if(root==NULL)
		return 0;
	int lh=maxheight(root->left);
	int rh=maxheight(root->right);
	return 1+max(lh,rh); 
}

int main(int argc, char const *argv[])
{
	node*root = buildTree();
	preorder(root);
	cout<<endl;
	cout<<minheight(root)<<endl;
	cout<<maxheight(root)<<endl;
	return 0;
}