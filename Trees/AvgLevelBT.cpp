#include <iostream>
#include <queue>
#include <vector>
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

void levelorder(node*root)
{
	queue<node*> qu;
	vector<double> result;
	qu.push(root);
	while(!qu.empty())
	{
		int count=qu.size();
		int temp = count;
		double sum = 0.0;
		while(temp--) //loop runs for each level before it ends
		{
		node*to_be_removed = qu.front();
		sum+=to_be_removed->data;
		cout<<to_be_removed->data<<" "; //to print each level in separate lines
		qu.pop();
		if(to_be_removed->left!=NULL)
			qu.push(to_be_removed->left);
		if(to_be_removed->right!=NULL)
			qu.push(to_be_removed->right);
		}
		cout<<endl;
		double avg = sum/count;
		result.push_back(avg); //for calculating avg at each level
	}
	cout<<"Average of each level : "<<endl;
	for (int i = 0; i < result.size(); ++i)
	{
		cout<<result[i]<<" ";
	}
}

int main(int argc, char const *argv[])
{
	node*root = buildTree();
	levelorder(root);
	cout<<endl;
	return 0;
}