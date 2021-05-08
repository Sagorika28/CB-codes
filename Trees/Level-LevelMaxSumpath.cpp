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

void inorder(node*root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

int maxsum(node*root) //max sum from root to leaf
{
	if(root==NULL)
		return 0;
	int left = maxsum(root->right);
	int right = maxsum(root->left);
	return max(left,right) + root->data;
}

int maxS=0;
int maxsum2(node*root) //max sum from leaf to leaf
{
	if(root == NULL)
		return 0;
	int left = maxsum2(root->left);
	int right = maxsum2(root->right);
	int cand = left + right + root->data;
	if(maxS<cand)
		maxS = cand;
	return max(left,right) + root->data;
}

int maxSum = INT_MIN;  ////max sum from node to node
int helper(Node* root) {
	if (root == NULL) {
		return 0;
	}
	int left = helper(root->left);
	int right = helper(root->right);

	int cand1 = root->val;
	int cand2 = left + root->val;
	int cand3 = right + root->val;
	int cand4 = left + right + root->val;

	maxSum = max(cand1, max(cand2, max(cand3, max(cand4, maxSum))));

	return max(left, max(right, 0)) + root->val;
	// return max(left, right) + root->val;


}
int maxPathSum(Node* root) {
	helper(root);
	return maxSum;
}

int main(int argc, char const *argv[])
{
	node*root = buildTree();
	inorder(root);
	cout<<endl;
	cout<<maxsum(root);
	cout<<endl;
	cout<<maxsum2(root);
	cout<<endl;
	cout<<maxPathSum(root);
	return 0;
}