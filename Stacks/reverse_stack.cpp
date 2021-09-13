#include<bits/stdc++.h>
using namespace std;

void reverse_stack(stack<int>&s1)
{
	stack<int>s2;
	while(!s1.empty())
	{
		s2.push(s1.top());
		s1.pop();
	}

	s1=s2;
}

void recursive_print(stack<int>s)
{
	if(s.empty())
	{
		return;
	}
	cout<<s.top()<<" ";
	s.pop();
	recursive_print(s);
}	

int main()
{
	stack<int>s1;
	s1.push(10);
	s1.push(20);
	s1.push(30);
	s1.push(40);
	recursive_print(s1);
	reverse_stack(s1);
	cout<<endl;
	recursive_print(s1);


}
