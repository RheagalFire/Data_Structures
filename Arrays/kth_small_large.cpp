#include<bits/stdc++.h>
using namespace std;


int get_k_large(int arr[],int n,int k)
{
	priority_queue<int>q;

	for(int i=0;i<n;i++)
	{
		q.push((-1)*arr[i]);
		if(q.size()>k)
	{
		q.pop();
	}

	}
	
	return (-1)*q.top();

}
int get_k_small(int arr[],int n,int k)
{
	priority_queue<int>q;
	for(int i=0;i<n;i++)
	{
		q.push(arr[i]);
		if(q.size()>k)
	{
		q.pop();
	}

	}
	
	return q.top();

}


int main()
{
	int arr[]={600,212,33,46,51,100};
	cout<<get_k_small(arr,6,1)<<" ";
	cout<<get_k_large(arr,6,1);
}
