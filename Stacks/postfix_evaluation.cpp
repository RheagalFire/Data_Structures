#include<bits/stdc++.h>
#include<string>
using namespace std;
/*
Postfix Evaluation
*/

int main()
{
	string s="231*+9-";
	stack<int>s1;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='*')
		{
			int x1=s1.top();
			s1.pop();
			int x2=s1.top();
			s1.pop();
			s1.push((x2*x1));
		}
		else if(s[i]=='+')
		{
			int x1=s1.top();
			s1.pop();
			int x2=s1.top();
			s1.pop();
			s1.push((x2+x1));
		}
		else if(s[i]=='-')
		{
			int x1=s1.top();
			s1.pop();
			int x2=s1.top();
			s1.pop();
			s1.push((x2-x1));
		}

		else

		{s1.push(s[i]-'0');}
		
	}

	cout<<s1.top();


}
//output : -4
