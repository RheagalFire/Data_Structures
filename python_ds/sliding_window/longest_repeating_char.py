"""
You are given a string s consisting of only uppercase english characters and an integer k. You can choose up to k characters of the string and replace them with any other uppercase English character.

After performing at most k replacements, return the length of the longest substring which contains only one distinct character.


Example :
Input: s = "XYYX", k = 2

Output: 4


https://neetcode.io/problems/longest-repeating-substring-with-replacement
"""


def longest_repeating_char_brute_force(s: str, k: int) -> int:
    """
    Intuition:
    - We will use a sliding window approach to find the longest substring with at most k replacements.
    - We will use a hashmap to store the frequency of each character in the current window.
    - We will use a variable to store the maximum frequency of any character in the current window.
    - We will use a variable to store the result.
    """
    result = 0
    # A brute force approach
    for i in range(len(s)):
        freq_elements = {}
        maximum_frequency_element = 0
        for j in range(i, len(s)):
            freq_elements[s[j]] = 1 + freq_elements.get(s[j], 0)
            maximum_frequency_element = max(
                maximum_frequency_element, freq_elements[s[j]]
            )
            window_length = j - i + 1
            if window_length - maximum_frequency_element <= k:
                result = max(result, window_length)
    return result


def optimized_longest_repeating_char(s: str, k: int) -> int:
    """
    Intuition:
    - We will use a sliding window approach with two pointers to find the longest substring with at most k replacements.
    - We will use a hashmap to store the frequency of each character in the current window.
    - We will use a variable to store the maximum frequency of any character in the current window.
    """

    left = 0
    freq_element = {}
    maximum_frequency_element = 0
    result = 0
    for right in range(len(s)):
        # Add the current character to the hashmap
        freq_element[s[right]] = freq_element.get(s[right], 0) + 1
        # Update the maximum frequency element
        maximum_frequency_element = max(
            maximum_frequency_element, freq_element[s[right]]
        )
        # Calculate the window size
        window_size = right - left + 1

        # If the window size is greater than the maximum frequency element plus k, we need to shrink the window
        while window_size - maximum_frequency_element > k:
            # Remove the leftmost character from the hashmap
            freq_element[s[left]] -= 1
            # Move the left pointer to the right
            left += 1

        # Update the result
        result = max(result, window_size)
    return result


if __name__ == "__main__":
    print(longest_repeating_char_brute_force("XYYX", 2))
    print(optimized_longest_repeating_char("XYYX", 2))
