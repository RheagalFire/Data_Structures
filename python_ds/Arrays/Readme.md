## Quick Reference Files

### Two Sum (Hash Map Solution)
```
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
       num_dict = {}
        for i, num in enumerate(nums):
            complement = target - num
            if complement in num_dict:
                return [num_dict[complement], i]
            num_dict[num] = i
        return []
```
### Maximum Subarray
(Sliding Window Technique)
```
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_sum = -float(inf)
        curr_sum,start,end,temp_start = 0,0,0,0 
        for index,i in enumerate(nums):
            curr_sum+=i
            if(curr_sum>max_sum):
                max_sum = curr_sum
                start = temp_start
                end = index   
            if(curr_sum<0):
                curr_sum = 0
                temp_start = index+1
        print(nums[start:end+1])
        return max_sum
 ```
 ### Best time to sell and buy a stock
 ```
 class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        buy = prices[0]
        profit = 0
        for sell in prices[1:]:
            if sell>buy:
                profit = max(profit,sell-buy)
            else:
                buy = sell
        return profit
 ```
