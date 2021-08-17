#include<bits/stdc++.h>
using namespace std;

//maximum path sum from root
/*
For each Node compute: 
1. Node val 
2. Max path through left child + node val 
3. Max path through right child + node val 
4. Max path through left + right + node val 
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

int maxi=-1;

int maxutil(Node* root,int &ans)
{
	if(root==NULL)
		return 0;
	int left=maxutil(root->left,ans);
	int right=maxutil(root->right,ans);

	int nodemax=max(max(root->data,root->data+left+right),
		max(root->data+left,root->data+right));

	ans=max(ans,nodemax);
	int singlepathsum=max(root->data,max(root->data+left,root->data+right));
	return singlepathsum;

}


int maxsum(Node* root)
{
	int ans=maxi;
	maxutil(root,ans);
	return ans;
}


void inorder(Node* root)
{
	if(root==NULL)
	{
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

int main()
{
	struct Node* root= new Node(1);
	root->left =new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right->left=new Node(6);
	root->right->right=new Node(7);
	cout<<maxsum(root)<<endl;
	inorder(root);

}
