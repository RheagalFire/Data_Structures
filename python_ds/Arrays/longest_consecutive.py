"""
https://neetcode.io/problems/longest-consecutive-sequence
Given an array of integers nums, return the length of the longest consecutive sequence of elements that can be formed.

A consecutive sequence is a sequence of elements in which each element is exactly 1 greater than the previous element. The elements do not have to be consecutive in the original array.

You must write an algorithm that runs in O(n) time.

Input: nums = [2,20,4,10,3,4,5]

Output: 4

"""


def longest_consecutive(nums: list[int]) -> int:
    """
    This function finds the length of the longest consecutive sequence in an unsorted list of integers.

    Intuition:
    The logic behind this function is to first sort the array, which allows us to easily identify consecutive numbers.
    By iterating through the sorted array, we can count consecutive numbers by checking if each number is exactly one more than the previous number.
    If a number is not consecutive, we compare the current sequence length with the longest sequence found so far and update accordingly.
    This approach ensures that we efficiently find the longest consecutive sequence in O(n log n) time due to the sorting step.

    When to apply:
    This logic is applicable when you need to find the longest sequence of consecutive numbers in an array where the order of elements is not important.
    It is particularly useful when the input size is manageable, and the overhead of sorting is acceptable.

    Cases:
    - The array can contain duplicates, which are ignored in terms of counting consecutive sequences.
    - The array can be unsorted, as the sorting step will handle this.
    - The function handles both positive and negative integers.
    """

    # Sort the array
    nums.sort()

    # Initialize the longest and current sequence length variables
    longest = 0
    current = 1

    # Iterate through the sorted array
    for i in range(1, len(nums)):
        # If the current element is exactly 1 greater than the previous element
        if nums[i] == (nums[i - 1] + 1):
            # Increment the current sequence length
            current += 1
        elif nums[i] == nums[i - 1]:
            # If the current element is the same as the previous, continue without resetting
            continue
        else:
            # Update the longest sequence length if the current is greater
            longest = max(longest, current)
            # Reset the current sequence length
            current = 1

    # Return the maximum of the longest sequence found and the current sequence length
    return max(longest, current)


"""
ASCII Diagram for the logic:

Initial Array: [2, 20, 4, 10, 3, 4, 5]
Sorted Array:  [2, 3, 4, 4, 5, 10, 20]

Iterate through sorted array:
Index:  0  1  2  3  4  5  6
Value: [2, 3, 4, 4, 5, 10, 20]
        ^  ^  ^     ^
        |  |  |     |
        |  |  |     +-- Not consecutive, update longest, reset current
        |  |  +-- Consecutive, increment current
        |  +-- Consecutive, increment current
        +-- Start

Longest sequence found: [2, 3, 4, 5] with length 4
"""

if __name__ == "__main__":
    print(longest_consecutive([2, 20, 4, 10, 3, 4, 5]))
    # [2,3,4,5,10,20]
