#include <vector>
using namespace std;

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
	sort(arrayOne.begin(),arrayOne.end());
	sort(arrayTwo.begin(),arrayTwo.end());
  int x=0;
	int y=0;
	int curr_sum=INT_MAX;
	int small_sum=INT_MAX;
	vector<int>pair;
	while(x<arrayOne.size() && y<arrayTwo.size())
	{
		int first_num=arrayOne[x];
		int second_num=arrayTwo[y];
		if(first_num<second_num)
		{
			curr_sum=second_num-first_num;
			x++;
		}
		else if(second_num<first_num)
		{
			curr_sum=first_num-second_num;
			y++;
		}
		else 
		{
			return vector<int>{first_num,second_num};
		}
		
		if(small_sum>curr_sum)
		{
			small_sum=curr_sum;
			pair={first_num,second_num};
		}
	}
  return pair;
}
