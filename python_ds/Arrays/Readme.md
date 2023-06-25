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
 
### Contains Duplicate
```
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        seen = {}
        for i in nums:
            if i in seen:
                return True
            else:
                seen[i] = 1
        return False
```
### Three Sum to Zero
```class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        result = []
        for i in range(len(nums)-2):
            if(i>0 and nums[i]==nums[i-1]):
                continue
            left = i+1 
            right = len(nums)-1
            while left < right:
                current_sum = nums[i] + nums[left] + nums[right]
                if current_sum < 0:
                    left += 1
                    while left < right and nums[left] == nums[left - 1]:
                        left += 1
                elif current_sum > 0:
                    right -= 1
                    while left < right and nums[right] == nums[right + 1]:
                        right -= 1
                else:
                    result.append([nums[i], nums[left], nums[right]])
                    left += 1
                    right -= 1
                    while left < right and nums[left] == nums[left - 1]:
                        left += 1
                    while left < right and nums[right] == nums[right + 1]:
                        right -= 1
        return result
```
### Maximum Product Subarray
```
class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        prev_max = nums[0]
        prev_min = nums[0]
        ans = nums[0]
        for i in nums[1:]:
            if(i<0):
                temp = prev_max
                prev_max = prev_min
                prev_min = temp
            prev_max = max(i,prev_max*i)
            prev_min = min(i,prev_min*i)
            ans = max(ans,prev_max)
        return ans
```
