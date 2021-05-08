#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
	int data;
	node*left;
	node*right;
	int vc;

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

int vertexCover(node*root)
{
	if(root==NULL)  return 0;
	if(root->left==NULL and root->right==NULL)	return 0;
	if(root->vc!=0)
		return root->vc;
	int including = 1 + vertexCover(root->left) + vertexCover(root->right);
	int excluding = 0;
	if(root->left!=NULL)
		excluding = excluding + 1 + vertexCover(root->left->left) + vertexCover(root->left->right); 
	if(root->right!=NULL)
		excluding = excluding + 1 + vertexCover(root->right->left) + vertexCover(root->right->right); 
	
	root->vc = min(including,excluding);
	return root->vc;
}


int main(int argc, char const *argv[])
{
	node*root = buildTree();
	preorder(root);
	cout<<endl;
	cout<<vertexCover(root);
	return 0;
}