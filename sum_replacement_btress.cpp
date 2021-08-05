#include<bits/stdc++.h>
using namespace std;

//Sum Replacement in Binary Tree

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


void sum_replace(Node* root)
{
	if(root==NULL)
	{
		return;
	}

	sum_replace(root->left);
	sum_replace(root->right);
	if(root->left)
	{
		root->data+=root->left->data;

	}
	if(root->right)
	{
		root->data+=root->right->data;
	}

}
void preorder(Node* root)
{
	if(root==NULL)
	{
		return;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);

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
	preorder(root);
	sum_replace(root);
	cout<<endl;
	preorder(root);

}

//output
//1 2 4 5 3 6 7 
//28 11 4 5 16 6 7
