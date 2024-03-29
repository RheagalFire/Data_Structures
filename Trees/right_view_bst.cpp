#include<bits/stdc++.h>
using namespace std;

/* 
A Tree is balanced if each node in the tree follows the formula: |lh-rh|<=1 ; lh=right height , rh=right Height 
*/

struct Node
{
	int data;
	struct Node* right;
	struct Node* left;
	Node(int val)
	{
		data=val;
		right=NULL;
		left=NULL;
	}
};

void r_view(Node* root)
{
	if(root==NULL)
	{
		return;
	}
	queue<Node*> q;
	q.push(root);

	while(!q.empty())
	{
		int n=q.size();
		for(int i=0;i<n;i++)
		{
			Node* curr=q.front();
			q.pop();
			if(i==n-1)
			{
				cout<<curr->data<<" ";
			}
			if(curr->left!=NULL)
			{
				q.push(curr->left);
			}
			if(curr->right!=NULL)
			{
				q.push(curr->right);
			}
		}
	}
}

int main()
{
	Node* root= new Node(1);
	root->left =new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right->left=new Node(6);
	root->right->right=new Node(7);
	r_view(root);
}

//output:1 3 7
