#include<iostream>
using namespace std;

 
/*
Flatten a Binaary Tree. 
1. Recursively Flatten the subtrees.
2. Store the left tail and right tail
3. Store the right subtree in 'temp' and make left subtree as right subtree.
4. Join Right subtree with left tail. 
5. Return the right tail. 
*/ 


struct Node
{
	int data;
	struct Node* left;
	struct Node* right;

	Node(int val)
	{
		data=val;
		left=right=NULL;
	}
};

void flatten(Node* root)
{
	if(root==NULL || (root->left==NULL && root->right==NULL))
	{
		return;
	}
	if(root->left!=NULL)
	{
		flatten(root->left);
		Node* temp=root->right;
		root->right=root->left;
		root->left=NULL;

		Node* t=root->right;
		while(t->right!=NULL)
		{
			t=t->right;
		}
		t->right=temp;
	}
	flatten(root->right);
	
}

void inorder(Node* root)
{
	if(root==NULL)
	{
		return;
	}
	inorder(root->left);
	cout<<root->data;
	inorder(root->right);
}


int main()
{
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	//Building Tree

	struct Node* root= new Node(1);
	root->left =new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right->left=new Node(6);
	root->right->right=new Node(7);
	flatten(root);
	inorder(root);
	return 0;
}
//output - 1,2,3,4,5,6,7
