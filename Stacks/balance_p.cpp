//valid parenthesis 
//whether input string is valid or not.

//1. open brackets must be closed by same type of bracket.
//2. open brackets must be closed in correct order.

//eg. ([]) : TRUE
//({]) : False 
#include<bits/stdc++.h>
using namespace std;

bool check_balance(stack<char>&s1,string s)
{
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='{' || s[i]=='(' || s[i]=='[')
		{
			s1.push(s[i]);
		}
		else
		{
			if(s[i]=='}' && s1.top()!='{') return false;
			else if(s[i]==')' && s1.top()!='(') return false;
			else if(s[i]==']' && s1.top()!='[') return false;
			else s1.pop();
		}
	}

	return s1.empty();
}

int main()
{
	stack<char>s1;
	string s="[{}]";
	cout<< check_balance(s1,s);
	

}
