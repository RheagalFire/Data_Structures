"""

Given an array of integers numbers that is sorted in non-decreasing order.

Return the indices (1-indexed) of two numbers, [index1, index2], such that they add up to a given target number target and index1 < index2. Note that index1 and index2 cannot be equal, therefore you may not use the same element twice.

There will always be exactly one valid solution.


Input: numbers = [1,2,3,4], target = 3

Output: [1,2]

https://neetcode.io/problems/two-integer-sum-ii

"""

from typing import List


def two_sum_using_hashmap(numbers: List[int], target: int) -> List[int]:
    hashmap = {}
    # Store the number as key and its index as value in the hashmap
    for i, num in enumerate(numbers):
        hashmap[num] = i

    for i in numbers:
        if target - i in hashmap:
            return [hashmap[i] + 1, hashmap[target - i] + 1]
    return []


def two_sum_using_two_pointers(numbers: List[int], target: int) -> List[int]:
    # Initialize two pointers, one at the beginning (left_pointer) and one at the end (right_pointer) of the array.
    left_pointer = 0
    right_pointer = len(numbers) - 1

    # The intuition behind using two pointers is that by moving the pointers inward, we can find the pair of numbers that add up to the target efficiently.
    # If the sum of the numbers at the two pointers is less than the target, we need a larger sum, so we move the left pointer to the right.
    # If the sum is greater than the target, we need a smaller sum, so we move the right pointer to the left.
    # This way, we can find the correct pair in linear time.

    while left_pointer < right_pointer:
        total_sum = numbers[left_pointer] + numbers[right_pointer]
        if total_sum == target:
            return [left_pointer + 1, right_pointer + 1]
        elif total_sum < target:
            left_pointer += 1
        else:
            right_pointer -= 1

    return []


if __name__ == "__main__":
    print(two_sum_using_hashmap([1, 2, 3, 4], 3))
    print(two_sum_using_two_pointers([1, 2, 3, 4], 3))
