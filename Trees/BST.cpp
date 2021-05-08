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

bool search(node*root, int key) //searching in an element
{
	if(root == NULL)
		return false;

	if(root->data == key)
		return true;

	if(key<root->data)
		return search(root->left,key);

	else
		return search(root->right,key);
}

node* deleteFromBST(node* root, int key) {
	if(root == NULL) {
		return NULL;
	}
	if(key < root->data) {
		root->left = deleteFromBST(root->left, key);
	} else if(key > root->data) {
		root->right = deleteFromBST(root->right, key);
	} else {
		if(root->left == NULL and root->right == NULL) {
			delete root;
			return NULL;
		} else if(root->right==NULL) {
			node *temp = root->left;
			delete root;
			return temp;
		} else if(root->left == NULL) {
			node *temp = root->right;
			delete root;
			return temp;
		} else {
			node *right_root = root->right;
			node *to_be_swap = right_root;
			while(to_be_swap->left != NULL) {
				to_be_swap = to_be_swap->left;
			}
			root->data = to_be_swap->data;
			root->right = deleteFromBST(root->right, root->data);
		}
	}
	return root;
}


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
	// int num;
	// cin>>num;
	// cout<<search(root,num);
	// cout<<endl;
	int key;
	cin>>key;
	root = deleteFromBST(root,key);
	inorder(root);
	return 0;
}