#include<bits/stdc++.h>
using namespace std;

//Brute Force solution
int max_h(vector<int>&a)
{
	int max_area=INT_MIN;
	for(int i=0;i<a.size();i++)
	{
		int left=i-1;int curr=i;int right=i+1;
		int curr_area=a[curr];
		while(a[right]>=a[curr] && right!=a.size())
		{
			curr_area+=a[curr]*1;
			right++;
			if(curr_area>max_area)
				max_area=curr_area;
		}

		while(a[left]>=a[curr] && left!=-1)
		{
			curr_area+=a[curr]*1;
			left--;
			if(curr_area>max_area)
				max_area=curr_area;
		}
	}
	return max_area;
}


int opt_max_h(vector<int>&a)
{
	vector<int>next_smaller;
	vector<int>prev_smaller;
	prev_smaller.push_back(-1);
	stack<int>s1;
	stack<int>s2;
	s1.push(0);
	for(int i=1;i<a.size();i++)
	{
		while(a[i]<a[s1.top()])
		{
			s1.pop();
			if(s1.empty())
		{
			break;
		}
		}
		if(!s1.empty())
		{
			prev_smaller.push_back(s1.top());
		}
		else
		{
			prev_smaller.push_back(-1);
		}

		s1.push(i);

	}

	next_smaller.push_back(a.size());
	s2.push(a.size()-1);
	for(int i=a.size()-2;i>=0;i--)
	{
		while(a[i]<a[s2.top()])
		{
			s2.pop();
			if(s2.empty())
		{
			break;
		}
		}

		if(!s2.empty())
		{
			next_smaller.push_back(s2.top());
		}
		else
		{
			next_smaller.push_back(a.size());
		}

		s2.push(i);
	}
	int max_area=INT_MIN;
	for(int i=0;i<a.size();i++)
	{
		int curr=0;
		curr=a[i]*(next_smaller[a.size()-1-i]-prev_smaller[i]-1);
		if(curr>max_area)
		{
			max_area=curr;
		}
	}

	return max_area;
}

int main()
{

	vector<int>a={6,2,5,4,5,1,6};

	cout<<opt_max_h(a);

	return 0;
}
