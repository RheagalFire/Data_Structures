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
	if(arr[0] < arr[1])
	{
		minmax.min=arr[0];
		minmax.max=arr[1];
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
	int arr[]={1,2,3,4,5,6,7,8,9};
	Pair minmax=mimmaxfinder(arr,9);
	cout<<minmax.min<<" "<<minmax.max;

}
