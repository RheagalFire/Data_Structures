#include<bits/stdc++.h>
using namespace std;


struct Pair
{
	int min;
	int max;
};


struct Pair mimmaxfinder(int arr[],int n)
{
	int i;
	struct Pair minmax;
	if(n==1)
	{
		minmax.min=arr[0];
		minmax.max=arr[0];
		return minmax;
	}
	if(arr[0] < arr[1])
	{
		minmax.min=arr[0];
		minmax.max=arr[1];
	}
	else
	{
		minmax.min=arr[1];
		minmax.max=arr[0];
	}
	for(i=2;i<n;i++)
	{
		if(arr[i]>minmax.max)
			minmax.max=arr[i];
		else if(arr[i]<minmax.min)
			minmax.min=arr[i];
	}
	return minmax;
}

int main()
{
	int arr[]={9,2,3,4,5,6,7};
	Pair minmax=mimmaxfinder(arr,7);
	cout<<minmax.min<<" "<<minmax.max;

}
