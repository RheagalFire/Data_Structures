#include <vector>
using namespace std;
// hash maps approach 0(n) solution
vector<int> twoNumberSum(vector<int> array, int targetSum) {
  unordered_set<int> nums;
	for(int num:array)
	{
		int potential=targetSum-num;
		if(nums.find(potential)!=nums.end())
		{
			return vector<int>{potential,num};
		}
		else
		{
			nums.insert(num);
		}
	}
	return {};
}

//O(nlogn)
vector<int> twoNumberSum(vector<int> array, int targetSum) {
	sort(array.begin(),array.end());
  int left=0;
	int right=array.size()-1;
	int curr_sum=0;
	while(left<right)
	{
		curr_sum=array[left]+array[right];
		if(curr_sum==targetSum)
		{
			return {array[left],array[right]};
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
  return {};
}

