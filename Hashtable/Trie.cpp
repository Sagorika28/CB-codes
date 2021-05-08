#include <iostream>
using namespace std;

class node
{
	public:
	char data;
	bool isItTerminal;
	node **children;

	node(char data)
	{
		this->data = data;
		this->isItTerminal = false;
		this->children = new node*[26];
		for (int i = 0; i < 26; ++i)
		{
			this->children[i] = NULL;
		}
	}
};

node*insert(node*root, string data)
{
    node*temp = root;
    for (int i = 0; i < data.size(); ++i)
    {
    	char ch = data[i];
    	if(temp->children[ch-'a']==NULL)
    		temp->children[ch-'a'] = new node(ch);
    	temp = temp->children[ch-'a'];
    }
    temp->isItTerminal = true;
    return root;
}

bool search(node*root, string word)
{
	node*temp = root;
	for (int i = 0; i < word.size(); ++i)
	{
		char ch = word[i];
    	if(temp->children[ch-'a']==NULL)
    		return false;
    	temp = temp->children[ch-'a'];
	}
	return temp->isItTerminal;
}

void recurse(node* root, string word, string osf) {
	if(root->isItTerminal == true) {
		cout<<word + osf + root->data<<endl;
	}
	node* temp = root;
	for(int i=0;i<26;i++) {
		if(temp->children[i]!=NULL) {
			recurse(temp->children[i], word, osf+temp->data);
		}
	}
}

void startsWith(node*root, string word)
{
	node*temp = root;
	for(int i=0;i<word.size();i++) {
		char ch = word[i];
		temp = temp->children[ch-'a'];
	}
	recurse(temp, word.substr(0, word.size()-1), "");
}

int main(int argc, char const *argv[])
{
	node*root = new node('\0');
	root=insert(root,"apple");
	root=insert(root,"app");
	root=insert(root,"appy");
	root=insert(root,"bag");
	root=insert(root,"bagged");
	root=insert(root,"boom");
	//cout<<search(root,"appy");
	startsWith(root, "ap");
	return 0;
}