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
void print_(Node* head)
{
	if(head==NULL)
		return;
	cout<<head->data<<" ";
	print_(head->next);
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
int main()
{
	Node* head=NULL;
	insert_at_head(head,2);
	insert_at_head(head,3);
	insert_at_tail(head,4);
	insert_at_tail(head,5);
	insert_at_pos(head,0,7);
	print_(head);
	cout<<endl;
	Node* new_h=reverse(head);
	print_(new_h);

}
