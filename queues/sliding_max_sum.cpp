#include<bits/stdc++.h>
using namespace std;

/*
Given an array and a k,find the max of each and 
every contiguos subarray of size k.
*/

//Time Complexity : O(2nk)
vector<int> slide_max(vector<int>&a,int k)
{
	priority_queue<int>q(3,0);
	vector<int>arr;
	for(int i=0;i<a.size();i++)
	{
		if(i==(a.size()-k+1))
		{
			break;
		}
		priority_queue<int>q;

		for(int j=0;j<k;j++)
		{	
			q.push(a[i+j]);
		}
		arr.push_back(q.top());
		while(!q.empty())
		{
			q.pop();
		}
	}

	return arr;
}
//Time Complexity: O(n)
void sile_max_optimized(vector<int>&arr,int k)
{
	int i;
	deque<int>q;
	for(i=0;i<k;i++)
	{
		while(!q.empty() && arr[i]>=arr[q.back()])
			q.pop_back();
		q.push_back(i);
	}

	for(;i<arr.size();i++)
	{
		cout<<arr[q.front()]<<" ";
		while(!q.empty() && q.front()<=i-k)
			q.pop_front();
		while(!q.empty() && arr[i]>=arr[q.back()])
			q.pop_back();

		q.push_back(i);
	}

	cout<<arr[q.front()];
}

int main()
{
	vector<int>arr1={2,3,1,10,4,11,6,3,2,0};
	vector<int>arr2=slide_max(arr1,3);
	for(int i=0;i<arr2.size();i++)
	{
		cout<<arr2[i]<<" ";
	}
	cout<<endl;
	sile_max_optimized(arr1,3);
}
