#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node * next;
};

void evenafterodd(node * head){
    node* curr=new node();
    curr=head;
    node* odd=new node();
    node* even=new node();
    node* Ehead=new node();
    Ehead=NULL;
    node* ohead=new node();
    ohead=NULL;
    ///////TO SET INITIAL ODD NODE////////////
    while(curr!=NULL){
        ////////CONNECT ALL EVEN ELEMENTS/////////
        if((curr->data)%2==0){
            if(Ehead==NULL){
                //cout<<"    ///////TO SET INITIAL Even NODE////////////";
                Ehead=curr;
                even=curr;
            }
            else{
                //cout<<"    ////////CONNECT ALL EVEN ELEMENTS/////////";
                even->next=curr;
                even=curr;
            }
        }
        ////////CONNECT ALL odd ELEMENTS/////////
        else if((curr->data)%2!=0){
            if(ohead==NULL){
                //cout<<"    ///////TO SET INITIAL ODD NODE////////////";
                ohead=curr;
                odd=curr;
            }
            else{
                //cout<<"CONNECT ALL odd ELEMENTS";
                odd->next=curr;
                odd=curr;
            }
        }
        curr=curr->next;
    }
    odd->next=Ehead;
    even->next=NULL;
    node * iterate=new node();
    iterate=ohead;
    while(iterate!=NULL){
        cout<<iterate->data<<" ";
        iterate=iterate->next;
    }
    
    
}

int main() {
	int n;
	cin>>n;
	node * head=NULL;
	node * tail=NULL;
	for(int i=0; i<n;i++){
	    int data;
	    cin>>data;
	    node * temp=new node ();
	    temp->data=data;
	    if(head==NULL){
	        head=temp;
	        tail=temp;
	        tail->next=NULL;
	    }
	    else{
	        tail->next=temp;
	        tail=temp;
	        tail->next=NULL;
	    }
	    
	}
	evenafterodd(head);
	
return 0;
}