#include<bits/stdc++.h>
#include<string>
using namespace std;

int main()
{
    int n;

    int q;
    string strings[n];
    string queries[q];
    cin>>n;
    
    cin>>q;
    
    for(int i=0;i<n;i++)
    {
        
        cin>>strings[i];


    }
    for(int i=0;i<q;i++)
    {
        cin>>queries[i];


    }

for(int i=0;i<q;i++)
{
    int count=0;
    for(int j=0;j<n;j++)
    {
        if(strings[j]==queries[i])
            count++;
    }
    cout<<count<<endl;
}
return 0 ;

}
