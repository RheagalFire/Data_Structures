class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
    '''
    This function returns next permutation of a number.
    you check i,j pairs from the right.If it is sorted then decrement i and j until not sorted.
    Once you reach there compare i with last number in the array, if k > i swap k and i else go on decreasing k. 
    After doing this swap the number from left to right after i.
    '''
        i = len(nums)-2
        while (i!=-1) and (nums[i]>=nums[i+1]):
            i-=1
        if(i==-1):
            nums.reverse()
            return
        k = len(nums) - 1
        while (nums[k] <= nums[i]):
            k -= 1
        
        nums[i],nums[k] = nums[k],nums[i]
        left = i+1 
        right = len(nums)-1
        while(left<right):
            nums[right],nums[left] = nums[left],nums[right]
            left+=1
            right-=1
