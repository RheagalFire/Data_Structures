#include<bits/stdc++.h>
using namespace std;

void rearrnge(vector<int>&arr)
{
	int j=0;
	for(int i=0;i<arr.size();i++)
	{
		if(arr[i]<0)
		{
			if(i!=j)
			{
				swap(arr[i],arr[j]);

			}
			j++;
		}
	}
}

int main()
{
	vector<int>arr={-1, 2, -3, 4, 5, 6, -7, 8, 9 };
	rearrnge(arr);
	for(int i=0;i<arr.size();i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}

//Output:  -1 -3 -7 4 5 6 2 8 9
