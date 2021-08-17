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

void print_(Node* head)
{
	if(head==NULL)
		return;
	cout<<head->data<<" ";
	print_(head->next);
}

int main()
{
	Node* head=NULL;
	insert_at_head(head,2);
	insert_at_head(head,3);
	insert_at_tail(head,4);
	print_(head);
}
