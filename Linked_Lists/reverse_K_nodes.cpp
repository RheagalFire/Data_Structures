#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;

	Node(int val)
	{
		data=val;
		next=NULL;
	}
};


void insert_at_head(Node* &head,int val)
{
	if(head)
	{

		Node* new_n=new Node(val);
		new_n->next=head;
		head=new_n;
	}
	else
	{
		Node* new_n=new Node(val);
		head=new_n;

	}

}

void insert_at_tail(Node* &head,int val)
{
	if(head)
	{
		Node* new_n=new Node(val);
		Node* p=head;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=new_n;
	}
	else
	{
		Node* new_n=new Node(val);
		head=new_n;
	}
}

void insert_at_pos(Node* &head,int pos,int val)
{
	if(pos==0)
	{
		Node* new_=new Node(val);
		new_->next=head;
		head=new_;
	}
	else
	{int pre=pos-1;
		Node* p=head;
		Node* new_=new Node(val);
		while(pre)
		{
			p=p->next;
			pre--;
		}
		new_->next=p->next;
		p->next=new_;}

}

bool search(Node* &head, int val)
{
	Node* p=head;
	while(p)
	{
		if(p->data==val)
		{
			return true;
		}
		p=p->next;
	}
	return false;
}

void print_(Node* head)
{
	if(head==NULL)
		return;
	cout<<head->data<<" ";
	print_(head->next);
}

void delete_t_value(Node* &head,int val)
{
	if(head->data==val)
	{
		Node* temp=head;
		head=head->next;
		delete temp;
	}
	else
	{Node* temp=head;
		while(temp->next->data!=val)
		{
			temp=temp->next;
		}
		Node* todelete=temp->next;
		temp->next=temp->next->next;
	
		delete todelete;}

}

void delete_t_pos(Node* &head,int pos)
{
	if(pos==0)
	{
		Node* temp=head;
		head=head->next;
		delete temp;
	}
	else
	{int pre=pos-1;
		Node* temp=head;
		while(pre)
		{
			temp=temp->next;
			pre--;
		}
		Node* todel=temp->next;
		temp->next=temp->next->next;
		delete todel;}
}
//Complexity = O(n)
Node* reverse(Node* &head)
{
	if( head==NULL || head->next==NULL)
	{
		return head;
	}
	Node* newhead=reverse(head->next);
	head->next->next=head;
	head->next=NULL;
	return newhead;
}
// Three Pointer Recursive Algorithm 
Node* reverse_k(Node* &head,int k)
{
		Node* prevptr=NULL;
		Node* currptr=head;
		Node* nextptr;

		int count=0;
		while(currptr!=NULL && count<k)
		{
				nextptr=currptr->next;
				currptr->next=prevptr;
				prevptr=currptr;
				currptr=nextptr;
				count++;
		}
		if(nextptr!=NULL)
		{
			head->next=reverse_k(nextptr,k);
		}

		return prevptr;
}
int main()
{
	Node* head=NULL;
	insert_at_head(head,2);
	insert_at_head(head,3);
	insert_at_tail(head,4);
	insert_at_tail(head,5);
	insert_at_pos(head,0,7);
	insert_at_tail(head,9);
	cout<<search(head,9)<<endl;
	// print_(head);
	// cout<<endl;
	// delete_t_pos(head,1);
	print_(head);
	cout<<endl;
	Node* new_head=reverse_k(head,2);
	print_(new_head);
	// Node* new_h=reverse(head);
	// print_(new_h);


}
