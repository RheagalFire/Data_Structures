#include <vector>
using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
  sort(array.begin(),array.end());
	vector<vector<int>> tri;
	for(int i=0;i<array.size()-2;i++)
	{
		int left=i+1;
		int right=array.size()-1;
		while(left<right)
		{
			int curr_sum=array[i]+array[left]+array[right];
			if(curr_sum==targetSum)
			{
				tri.push_back({array[i],array[left],array[right]});
				left++;
				right--;
			}
			else if(curr_sum<targetSum)
			{
				left++;
			}
			else if(curr_sum>targetSum)
			{
				right--;
			}
		}
	}
  return tri;
}
