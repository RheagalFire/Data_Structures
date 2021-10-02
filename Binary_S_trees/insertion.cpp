#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* left;
	struct Node* right;


	Node(int val)
	{
		data=val;
		right=NULL;
		left=NULL;
	}
};


Node* insert_node(Node* root,int val)
{
	if(root==NULL)
	{
		return new Node(val);
	}
	if(val>root->data)
	{
			root->right=insert_node(root->right,val);
	}
	else if(val<root->data)
	{
		root->left=insert_node(root->left,val);
	}
	return root;
}


void preorder(Node* root)
{
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

int main()
{
	Node* root=new Node(10);
	insert_node(root,20);
	insert_node(root,5);
	insert_node(root,6);
	preorder(root);

	
}
