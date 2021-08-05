#include<bits/stdc++.h>
using namespace std;

//Diameter and Hieght in TREE
//Hieght==root to leaf 

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


int Hieght(Node* root)
{
	if(root==NULL)
	{
		return 0;
	}
	int lhieght=Hieght(root->left);
	int rhieght=Hieght(root->right);
	return max(lhieght,rhieght)+1;
}

int diameter(Node* root)
{
	if(root==NULL)
	{
		return 0;
	}

	int lhieght=Hieght(root->left);
	int rhieght=Hieght(root->right);
	int cur_h=lhieght+rhieght+1;

	int ldiam=diameter(root->left);
	int rdiam=diameter(root->right);

	return max(cur_h,max(ldiam,rdiam));

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
	cout<<Hieght(root)<<endl;
	cout<<diameter(root);

}

//output
//Hieght=3
//Diameter=5
