#include <iostream>
#include <queue>
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
int sum = 0;
node* GSM(node*root)
{

	if(root==NULL)
		return 0;
	GSM(root->right);
	sum += root->data;
	root->data = sum;
	GSM(root->left);
	return root;
}

int main(int argc, char const *argv[])
{
	node*root = buildTree();
	GSM(root);
	preorder(root);
	return 0;
}