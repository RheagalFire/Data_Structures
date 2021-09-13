#include<bits/stdc++.h>
using namespace std;


int main()
{
	vector<int>v={100,80,60,70,60,75,85};
	vector<int>arr;
	stack<int>s1;
	int size=v.size();
	s1.push(0);
	arr.push_back(1);
	for(int i=1;i<size;i++)
		{
			
			if(v[i]<=v[s1.top()])
			{
				arr.push_back(1);
			}
			else
			{
				while(v[i]>v[s1.top()])
				{
					s1.pop();
				}

				arr.push_back(i-s1.top());
			}
			s1.push(i);
		}
	for(int i=0;i<arr.size();i++)
	{
		cout<<arr[i]<<" ";
	}

}

//output: 1 1 1 2 1 4 6
