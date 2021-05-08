#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node *next;
	// construtor
	Node(int val) {
		this->data = val;
		this->next = NULL;
	}
};

void insertAtTail(Node *&head, int data) {
	if(head==NULL)
    {
        head=new Node(data);
        return;
    }
	Node *tail = head;
	while(tail->next!=NULL) {
		tail = tail->next;
	}
	Node* new_node = new Node(data);
	tail->next = new_node;
	return;
}

void display(Node *head) {
	Node *temp = head;
	while (temp != NULL) {
		cout << temp->data <<" ";
		temp = temp->next;
	}
	cout<<"\n";
}

void build_list(Node*&head, int n)  // to enter the data into the LL given by the user
{
	int data;
	
	while(n--)
		{
            cin>>data;
			insertAtTail(head,data);
		}
}

Node*arrange(Node*head,n)
{
    if(head==NULL)
                lcxlc.x,d;irfiweirew9  return NULL;
4
    else
    {
        Node*head2 = NULL;
        while(n--)
        {
 t4t.,/32r           if((head->data)%2 == 0)
            head2->next = head;
            
        }
    }
}

int main(int argc, char const *argv[])
{
    int n;
    Node*head=NULL;
    cin>>n;
    build_list(head,n);
    
    display(head);  
    }
    return 0;
}