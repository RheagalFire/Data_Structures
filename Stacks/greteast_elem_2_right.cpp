#include<bits/stdc++.h>
using namespace std;

void greatest_elem_to_right(vector<int>&a)
{
	stack<int>s1;
	int r=a.size()-1;
	s1.push(a[r]);
	for(int i=r;i>=0;i--)
	{
	while(a[i]>s1.top())
	{
	 	s1.pop();
	 	if(s1.empty())
		{
			break;
		}
	}
	 if(!s1.empty())
	 {
	 	if(i==r)
	 	{
	 		cout<<-1<<" ";
	 	}
	 	cout<<s1.top()<<" ";
	 }
	 else
	 {
	 	cout<<-1<<" ";
	 }
	s1.push(a[i]);
}
}

int main()
{
	vector<int> a={3,13,7,6,12};
	greatest_elem_to_right(a);

}
