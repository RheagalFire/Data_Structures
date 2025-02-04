"""
Valid Palindrome

Given a string s, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

## Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
"""

"""
What is a palindrome?
A palindrome is a string that reads the same forward and backward.
"""


def is_palindrome(s: str) -> bool:
    # assume left and right are pointers to the start and end of the string
    s = s.lower()
    left, right = 0, len(s) - 1

    # while the left pointer is less than the right pointer
    while left < right:
        # if the characters at the left and right pointers are not the same
        if not s[left].isalnum():
            left += 1
            continue
        if not s[right].isalnum():
            right -= 1
            continue
        if s[left] != s[right]:
            # return false
            return False
        # increment the left pointer
        left += 1
        # decrement the right pointer
        right -= 1
    # if we have checked all characters and they are the same
    # return true
    return True


if __name__ == "__main__":
    print(is_palindrome("a"))
