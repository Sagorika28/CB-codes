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

class Pair {
public:
	int height;
	int diameter;
};


Pair diameter(node* root) {
	if (root == NULL) {
		Pair p;
		p.diameter = 0;
		p.height = 0;
		return p;
	}

	Pair result;
	Pair left = diameter(root->left); //calculates height and diameter of left subtree
	Pair right = diameter(root->right);  //calculates height and diameter of right subtree
	result.height = max(left.height, right.height) + 1;	//returns max height of tree
	result.diameter = max(left.diameter, max(right.diameter, left.height + right.height)); //returns the max diameter either from left or right tree or the total height from left to right subtree
	return result;

}

int diameterOfBinaryTree(node* root) {
	Pair p = diameter(root);
	return p.diameter;
}

int main(int argc, char const *argv[])
{
	node*root = buildTree();
	preorder(root);
	cout<<endl;
	cout<<diameterOfBinaryTree(root)<<endl;
	return 0;
}