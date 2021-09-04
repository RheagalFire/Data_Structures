#include<bits/stdc++.h>
using namespace std;

void sort_(int a[],int n)
{
	int low=0;int mid=0;int high=n-1;
	while(mid<=high)
	{
		switch(a[mid])
		{
			case 0:
			swap(a[low],a[mid]);
			low++;mid++;
			break;

			case 1: 
			mid++;
			break;

			case 2:
			swap(a[mid],a[high]);
			high--;
			break;
		}
	}
}



int main()
{
	int a[]={ 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
	int n=sizeof(a) / sizeof(a[0]);
	cout<<n<<endl;
	sort_(a,n);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}
