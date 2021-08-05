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

int height(Node* root)
{
	if(root==NULL)
	{
		return 0;
	}
	int lhieght=height(root->left);
	int rhieght=height(root->right);
	return max(lhieght,rhieght)+1;
}


bool balanced(Node* root)

{
	if(root==NULL)
	{
		return true;
	}
	if(balanced(root->left)==false)
		return false;
	if(balanced(root->right)==false)
		return false;
	int lh=height(root->left);
	int rh=height(root->right);
	if(abs(rh-lh)<=1)
	{
		return true;
	}
	else
	{
		return false;
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
	cout<<balanced(root);
	

}
//output = 1 (TRUE)
