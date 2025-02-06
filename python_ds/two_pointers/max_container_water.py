"""
You are given an integer array heights where heights[i] represents the height of the ithe bar.

You may choose any two bars to form a container. Return the maximum amount of water a container can store.

Input: height = [1,7,2,5,4,7,3,6]

Output: 36

https://neetcode.io/problems/max-water-container

"""

from typing import List

# BRUTE FORCE SOLUTION


def BruteForce_maxArea(heights: List[int]) -> int:
    # This is a brute force solution to find the maximum area of water that can be contained.
    # We will check every possible pair of heights to calculate the area and keep track of the maximum area found.

    area_container_pairs = []  # List to store the area of water for each pair of heights.

    for left_index, left_height in enumerate(heights):
        # Iterate over each height as the left boundary of the container.
        print(f"Left Index: {left_index}, Left Height: {left_height}")

        right_index = (
            left_index + 1
        )  # Start the right boundary just after the left boundary.
        print(f"Initial Right Index: {right_index}")

        for right_height in heights[left_index + 1 :]:
            # Iterate over each height after the left boundary as the right boundary of the container.
            print(f"Right Index: {right_index}, Right Height: {right_height}")

            min_height = min(
                left_height, right_height
            )  # The height of the container is limited by the shorter bar.
            print(f"Container Height (min of left and right): {min_height}")

            current_area = min_height * (
                right_index - left_index
            )  # Calculate the area of water the container can hold.
            print(f"Current Area: {current_area}")

            area_container_pairs.append(
                current_area
            )  # Add the current area to the list of areas.
            right_index += 1  # Move to the next right boundary.

    return max(area_container_pairs)  # Return the maximum area found.


def maxArea(heights: List[int]) -> int:
    # This function uses the two-pointer technique to find the maximum area of water that can be contained.
    # It is more efficient than the brute force approach.

    left_pointer = 0  # Start with the leftmost bar.
    right_pointer = len(heights) - 1  # Start with the rightmost bar.
    max_area = 0  # Initialize the maximum area to zero.

    while left_pointer < right_pointer:
        # Continue until the two pointers meet.

        # Calculate the area with the current pair of bars as boundaries.
        current_area = (right_pointer - left_pointer) * min(
            heights[left_pointer], heights[right_pointer]
        )
        max_area = max(
            max_area, current_area
        )  # Update the maximum area if the current area is larger.

        # Move the pointer pointing to the shorter bar inward, as this might increase the area.
        if heights[left_pointer] <= heights[right_pointer]:
            left_pointer += 1
        else:
            right_pointer -= 1

    return max_area  # Return the maximum area found.


if __name__ == "__main__":
    print(maxArea([1, 7, 2, 5, 4, 7, 3, 6]))
