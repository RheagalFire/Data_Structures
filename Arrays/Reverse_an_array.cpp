#include<bits/stdc++.h>
using namespace std;

void reverse_arr(int arr[],int start,int end)
{
	if(start>=end)
		return;
	int temp=arr[start];
	arr[start]=arr[end];
	arr[end]=temp;
	reverse_arr(arr,start+1,end-1);
}

void print(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}

int main()
{
	int arr[]={1,2,3,4,5,6,7};
	int n=sizeof(arr)/sizeof(arr[0]);
	print(arr,n);
	cout<<endl;
	reverse_arr(arr,0,n-1);
	print(arr,n);
	return 0;
}
