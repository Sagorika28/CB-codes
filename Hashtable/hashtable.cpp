#include <iostream>
using namespace std;

template <typename T>
class node
{
	public:
	string key;
	T value;
	node<T>*next;

	node(string key, T value)
	{
		this->key = key;
		this->value = value;
		this->next = NULL;
	}
};

template <typename T>
class hashtable
{
	public:
		int ts;
		int cs;
		node<T> **arr; //pointer to a pointer 

		hashtable(int ts=7)
	{
		this->ts = ts;
		this->cs = 0;
		arr = new node<T>*[this->ts];
		for (int i = 0; i < this->ts ; ++i)
		{
			arr[i] = NULL;
		}
	}

	void display()
	{
		for (int i = 0; i < this->ts ; ++i)
		{
			node<T>*temp = this->arr[i];
			if(temp==NULL)
			{
				cout<<"Empty\n";
				continue;
			}
			while(temp != NULL)
			{
				cout<<"("<<temp->key<<","<<temp->value<<") -> ";
				temp = temp->next;
			}
			cout<<endl;
		}
	}

	int hashfunc(string key)
	{
		int sum=0;
		int factor = 1;
		for (int i = 0; i < key.size(); ++i)
		{
			sum = (sum%this->ts) + ((int)(key[i])*factor)%this->ts;
			sum = sum%this->ts;
			factor = ((factor%this->ts)*(37%this->ts))%this->ts;
		}
		return (int)sum;
	}

	void rehash()
	{
		int old_size = this->ts;
		this->ts = this->ts*2;
		node<T> **old_table = this->arr;
		this->arr = new node<T> *[this->ts];
		for (int i = 0; i < this->ts ; ++i)
		 {
		 	this->arr[i]=NULL;
		 } 

		 for (int i = 0; i < old_size; ++i)
		 {
		 	node<T>*temp = old_table[i];
		 	while(temp != NULL)
		 	{
		 		insert(temp->key, temp->value);
		 		temp=temp->next;
		 	}
		 }
	}

	void insert(string key, T value)
	{
		int idx = hashfunc(key);
		node<T>* new_node = new node<T>(key,value);
		if(this->arr[idx] == NULL)
			this->arr[idx] = new_node;
		else
		{
			new_node->next = this->arr[idx];
			this->arr[idx] = new_node;
		}
		this->cs++;
		double loadFactor = (double) (this->cs)/this->ts;
		if(loadFactor > 0.5)
			rehash();
	}

	T search(string key)
	{
		int idx = hashfunc(key);
		node<T>*temp = this->arr[idx];
		while(temp != NULL)
		{
			if(temp->key == key)
				return temp->value;
			temp = temp->next;
		}
		return NULL;
	}
};

int main(int argc, char const *argv[])
{
	hashtable<int> *hash = new hashtable<int>();
	(*hash).insert("mango",27);
	(*hash).insert("apple",7);
	(*hash).insert("appy",2);
	(*hash).insert("apipie",207);
	(*hash).insert("banana",217);
	(*hash).insert("mangopie",27);
	(*hash).insert("api",217);
	(*hash).insert("bananapie",272);
	(*hash).insert("piepie",17);
	(*hash).insert("appypie",272);
	(*hash).display();

	int getval;
	getval = (*hash).search("api");
	if(getval==NULL)
		cout<<"Not found";
	else
		cout<<getval;	

	return 0;
}


