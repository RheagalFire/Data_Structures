#include<iostream>
using namespace std;

 
/*
Case 1: 
Node's Subtree Finding. 
Take entire subtree of 5. 
Decrement from the node itself. 
k=0(ans current node)
Case 2:
Node Ancestors
Distance of all ancestors from target node. 
for all ancestors search other subtree nodes at (k-d).

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

//Case 1 

void print_strees_nodes(Node* root,int k)
{
	if(root==NULL || k<0)
	{
		return;
	}
	if(k==0)
	{
		cout<<root->data<<" ";
	}

	print_strees_nodes(root->left,k-1);
	print_strees_nodes(root->right,k-1);
}

int printNodesatk(Node* root,Node* target,int k)
{

	if(root==NULL)
	{
		return -1;
	}
	if(root==target)
	{
		print_strees_nodes(root,k);
		return 0;
	}
	int dl=printNodesatk(root->left,target,k);
	if(dl!=-1)
	{
		if(dl+1==k)
		{
			cout<<root->data<<" ";
		}
		else
		{
			print_strees_nodes(root->right,k-dl-2);
		}

		return 1+dl;
	}

	int dr=printNodesatk(root->right,target,k);
	if(dr!=-1)
	{
		if(dr+1==k)
		{
			cout<<root->data<<" ";
		}
		else
		{
			print_strees_nodes(root->left,k-dl-2);
		}

		return 1+dr;
	}


	return -1;


}


int main()
{
	struct Node* root= new Node(1);
	root->left =new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	// root->left->right=new Node(5);
	// root->right->left=new Node(6);
	// root->right->right=new Node(7);
	printNodesatk(root,root->left,1);

}
