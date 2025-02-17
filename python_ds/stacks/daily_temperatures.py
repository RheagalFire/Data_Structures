"""
You are given an array of integers temperatures where temperatures[i] represents the daily temperatures on the ith day.

Return an array result where result[i] is the number of days after the ith day before a warmer temperature appears on a future day.
If there is no day in the future where a warmer temperature will appear for the ith day, set result[i] to 0 instead.

Example 1:
Input: temperatures = [30,38,30,36,35,40,28]

Output: [1,4,1,2,1,0,0]

https://neetcode.io/problems/daily-temperatures
"""


def daily_temperatures(temperatures: list[int]) -> list[int]:
    """
    This function finds the number of days until a warmer temperature occurs for each day.

    Intuition:
    - We use a monotonic decreasing stack to efficiently find the next warmer temperature
    - The stack stores (index, temperature) pairs
    - For each temperature, we compare it with temperatures on the stack:
        - If current temp is warmer than stack top, we've found next warmer day for that stack item
        - Keep popping and calculating days until we find a warmer temp on stack
    - Add current temp to stack since we haven't found its next warmer day yet

    Time Complexity: O(n) - we process each temperature once
    Space Complexity: O(n) - in worst case (decreasing temperatures) we store all temps in stack

    Example:
    temperatures = [30,38,30,36,35,40,28]
    - For 30: Add to empty stack
    - For 38: 38 > 30, so pop 30 and calculate days (1), then add 38
    - For 30: Add to stack since 30 < 38
    And so on...
    """
    # Initialize result array with 0s - default if no warmer temp is found
    result = [0] * len(temperatures)

    # Stack to store (index, temperature) pairs
    # We use a stack to keep track of temperatures we haven't found a warmer day for yet
    stack = []

    # Process each temperature
    for curr_idx, curr_temp in enumerate(temperatures):
        # While stack is not empty and we found a warmer temperature
        # Keep popping until we find a temperature that's warmer than current
        while stack and curr_temp > stack[-1][1]:
            prev_idx, prev_temp = stack.pop()
            # Calculate number of days between current warmer temp and previous temp
            result[prev_idx] = curr_idx - prev_idx

        # Add current temperature to stack since we haven't found its next warmer day
        stack.append((curr_idx, curr_temp))

    return result
