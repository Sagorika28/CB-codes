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
////
void insertAtHead(Node *&head, int data) {
	Node* new_node = new Node(data);
	new_node->next = head;
	head = new_node;
}

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

int len(Node*head) ///to find the length of the LL
{
	int len=0;
	while(head!=NULL)
		{
			head=head->next;
			len++;
		}
	return len;
}

void insertAtPos(Node *&head, int data, int pos) {
	if(head == NULL or pos == 0) {
		insertAtHead(head, data);
		return;
	}

	else if(pos>=len(head))
	{
		insertAtTail(head , data);
		return;
	}

	else
	{
		int i = 0;
		Node *temp = head;
		while(i<pos-1) 
		{
			temp = temp->next;
			i++;
		}
	Node *new_node = new Node(data);
	new_node->next = temp->next;
	temp->next = new_node;
	}
}

void deleteAtHead(Node *&head) {

	if(head==NULL)
		return;

	Node *temp = head;
	head = head->next;
	temp->next = NULL;
	delete temp;
	return;
}

void deleteAtTail(Node *&head) {
	Node *tail = head;
	while(tail->next->next!=NULL) {
		tail = tail->next;
	}
	Node *temp = tail->next;
	tail->next = NULL;
	delete temp;
	return;
}

void deleteAtPos(Node *&head, int pos) {
	if(pos == 0) {
		deleteAtHead(head);
		return;
	}
	int i = 0;
	Node *temp = head;
	while(i<pos-1) {
		temp = temp->next;
		i++;
	}
	Node *to_be_del = temp->next;
	temp->next = temp->next->next;
	to_be_del->next = NULL;
	delete to_be_del;
	return;

}

Node* midNode(Node *head) {  ///to find the middle node of the LL
	if(head->next == NULL or head==NULL)  
		return head;

	Node *slow = head;
	Node *fast = head;
	while(fast->next!=NULL and fast->next->next!=NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
} 

void display(Node *head) {
	Node *temp = head;
	while (temp != NULL) {
		cout << temp->data << ", ";
		temp = temp->next;
	}
	cout<<"\n";
}

void reversePI(Node *&head) {  ////to reverse the LL using pointers iteratively 
	Node *prev = NULL;
	Node *curr = head;
	Node *Next;
	while(curr!=NULL) {
		Next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = Next;
	}
	head = prev;
	return;
}

Node* reversePR(Node *head) {	////to reverse the LL using pointers recursively
	if(head->next == NULL or head==NULL) { 
		return head;
	}

	Node *smallHead = reversePR(head->next);
	head->next->next = head;
	head->next = NULL;
	return smallHead;
} 

void reverseDR1(Node *&head, Node *tail, bool &flag) {	////to reverse the LL by swapping data directly
	if(flag == true) {
		return;
	}
	if(tail == NULL) {
		return;
	}
	reverseDR1(head, tail->next, flag);
	if(flag == false and head!=tail and head->next!=tail) {
		int temp = head->data;
		head->data = tail->data;
		tail->data = temp;
		head = head->next;
	} else if((head==tail or head->next == tail) and flag == false) {
		int temp = head->data;
		head->data = tail->data;
		tail->data = temp;
		flag = true;
	} 
} 

bool search(Node*head, int key) /// to search for an element in the LL
{
	if(head==NULL)
		return false;
	else if (head->data==key)
		return true;
	else
		return search(head->next, key);
}

void build_list(Node*&head)  // to enter the data into the LL given by the user
{
	int data;
	cin>>data;

	while(data!=-1)
		{
			insertAtTail(head,data);
			cin>>data;
		}
}

Node* k_end(Node*head, int k) // to find the 'K'th node from end
{
	if(head->next == NULL or head==NULL) 
		return head;

	Node *slow = head;
	Node *fast = head;

	for(int jump=1;jump<=k;jump++)
		fast = fast->next;
 
	while(fast!=NULL) {
		slow = slow->next;
		fast = fast->next;
	}
	return slow;

}

Node*merge(Node*a, Node*b)  //// to merge 2 sorted LL's
{
	if(a==NULL)
		return b;
	else if(b==NULL)
		return a;

	//compare a and b for smaller element
	Node*c;
	if(a->data < b->data)
		{
			c=a;
			c->next=merge(a->next,b);
		}
	else
		{
			c=b;
			c->next=merge(a,b->next);
		}
	return c;
}

Node*mergeSort (Node* head)
{
	// base case
	if(head==NULL || head->next == NULL)
		return head;

	// rec case
	// 1. mid point
	Node*mid = midNode(head);

	Node*a = head;
	Node*b = mid->next;
	mid->next = NULL; //to make it a separate linked list

	// 2. recursively sort
	a=mergeSort(a);
	b=mergeSort(b);

	// 3. merge a and b
	Node*c = merge(a,b);
	return c;
}

int main(int argc, char const *argv[])
{
	
	Node *head=NULL;
	/*insertAtHead(head, 10);
	insertAtHead(head, 20);
	insertAtHead(head, 30);
	insertAtHead(head, 40);
	insertAtHead(head, 50);
	insertAtHead(head, 60);
	insertAtHead(head, 70);
	insertAtHead(head, 80);
	display(head);
	reversePI(head);
	display(head);
	head = reversePR(head);
	display(head);
	Node *temp = head;
	bool flag = false;
	Node *heapmover = head;
	reverseDR1(heapmover, head, flag);
	display(head); */


// to build a user defined LL

	build_list(head);
	display(head);


	// to search for an element

	int key;
	cin>>key;
	if(search(head,key)==true)
	{
		cout<<"Found";
	}
	else
		cout<<"Not Found";


	// for finding 'k'th node from end
	int k;
	cin>>k;
	Node*m=k_end(head, k); 
	cout<<m->data;


///for 2 linked lists merge : 
	
	int n1, n2;
    Node*a=NULL;
    Node*b=NULL;

    cin>>n1; //size of a
    build_list(a,n1);
    cin>>n2; //size of b
    build_list(b,n2);
	a=merge(a,b);
    display(a);  
	return 0;
}

	