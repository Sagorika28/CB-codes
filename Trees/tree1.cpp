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

void postorder(node*root)
{
	if(root==NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<",";
}

void inorder(node*root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<",";
	inorder(root->right);
}

void levelorder(node*root)
{
	queue<node*> qu;
	qu.push(root);
	while(!qu.empty())
	{
		node*to_be_removed = qu.front();
		qu.pop();
		cout<<to_be_removed->data<<",";
		if(to_be_removed->left!=NULL)
			qu.push(to_be_removed->left);
		if(to_be_removed->right!=NULL)
			qu.push(to_be_removed->right);
	}
}


int main(int argc, char const *argv[])
{
	node*root = buildTree();
	preorder(root);
	cout<<endl;
	postorder(root);
	cout<<endl;
	inorder(root);
	cout<<endl;
	levelorder(root);
	cout<<endl;
	return 0;
}