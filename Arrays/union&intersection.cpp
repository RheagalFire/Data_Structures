#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>arr, int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
 
        // If the element is present at the middle itself
        if (arr[mid] == x)
            return mid;
 
        // If element is smaller than mid, then it can only
        // be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
 
        // Else the element can only be present in right
        // subarray
        return binarySearch(arr, mid + 1, r, x);
    }
 
    // We reach here when element is not present in array
    return -1;
}

int intersection(vector<int>&a,vector<int>&b)
{
	if(b.size()<a.size())
	{
		vector<int> temp=b;
		b=a;
		a=temp;
	}
	int count=0;
	sort(a.begin(),a.end());
	for(int i=0;i<b.size();i++)
	{
		if(binarySearch(a,0,a.size(),b[i])!=-1)
			count+=1;
	}

	return count;
}


int union_(vector<int>&a,vector<int>&b)
{
	if(b.size()<a.size())
	{
		vector<int> temp=b;
		b=a;
		a=temp;
	}
	int count=a.size();
	sort(a.begin(),a.end());
	for(int i=0;i<b.size();i++)
	{
		if(binarySearch(a,0,a.size(),b[i])==-1)
			count+=1;
	}

	return count;
}


int main()
{
	vector<int>a={1,2,3,4,5};
	vector<int>b={5,7,8};
	cout<<intersection(a,b);
	//cout<<union_(a,b);

	
}
