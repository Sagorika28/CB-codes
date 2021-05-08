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

vector<int> v;
    int max_level = 0;
    
    void helper(node*root, int level)
    {
        if(root == NULL)
            return;
        if(level>max_level)
        {
            max_level = level;
            v.push_back(root->data);
        }
        helper(root->right, level+1);
        helper(root->left, level+1);
    }
    
    vector<int> rightSideView(node* root) {
        helper(root,1);
        return v; 
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
	levelorder(root);
	cout<<endl;
	vector <int>v = rightSideView(root);
	cout<<v;
	return 0;
}