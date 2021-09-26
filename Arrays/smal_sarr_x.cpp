#include<bits/stdc++.h>
using namespace std;


int smallestSubWithSum(int arr[], int n, int x)
    {
         
        //two pointer approach 
        int start=0;int end=0;
        int curr_sum=0; int min_len=INT_MAX;
        
        while(end<n)
        {
            while(curr_sum<=x && end<n)
            {
                curr_sum+=arr[end];
                end++;
            }
            while(curr_sum>x && start<n)
            {
                if(end-start<min_len)
                {
                    min_len=end-start;
                }
                curr_sum-=arr[start];
                start++;
            }
        }
        
        return min_len;
         
    }

int main()
{
  //pass the array 
  //{1, 4, 45, 6, 0, 19}
  //x=51
}

//output = 3
