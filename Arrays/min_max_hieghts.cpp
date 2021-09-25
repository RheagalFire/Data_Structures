#include<bits/stdc++.h>
using namespace std;


int getMinDiff(int arr[], int n, int k) {
        int i,j;
       sort(arr,arr+n);
       int ans = arr[n-1]-arr[0];
       
       for(i=0;i<n-1;i++)
       {
           if(arr[i+1]>=k)
           {
              int currMin = min(arr[i+1]-k, arr[0]+k);
            int currMax = max(arr[i]+k, arr[n-1]-k);
           ans = min(ans, currMax-currMin);
               
           }
       }
       return ans;
  
  int main()
  {
    int arr[]={1, 5, 8, 10};
    int n = size(arr)/size(arr[0]);
    int k=2;
    cout<<getMinDiff(arr,n);
  }
  
  //output: 5
   
