#include<bits/stdc++.h>
using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
int p2=0;
for(int i=0;i<array.size();i++)
{
	if(array[i]==sequence[p2] && p2<sequence.size())
	{
		p2++;
	}
}
	return p2==sequence.size();
}
