"""
https://neetcode.io/problems/generate-parentheses

You are given an integer n. Return all well-formed parentheses strings that you can generate with n pairs of parentheses.

Example:
Input: n = 1

Output: ["()"]

"""


def generate_parenthesis_using_backtracking(n: int) -> list[str]:
    """
    Intuition:
    - We will use a backtracking approach to generate all well-formed parentheses strings.
    - We will use a helper function to generate the parentheses strings.
    """
    results = []

    def backtrack(current_string, open_count, close_count):
        # If the current string is of length 2 * n, we have a valid parentheses string
        if len(current_string) == 2 * n:
            # Add the current string to the results
            results.append(current_string)
            return
        # If the number of open parentheses is less than n, we can add an open parenthesis
        if open_count < n:
            # Add an open parenthesis to the current string and call the backtrack function again
            backtrack(current_string + "(", open_count + 1, close_count)
        # If the number of close parentheses is less than the number of open parentheses, we can add a close parenthesis
        if close_count < open_count:
            # Add a close parenthesis to the current string and call the backtrack function again
            backtrack(current_string + ")", open_count, close_count + 1)

    # Start the backtracking process with an empty string and 0 open and close parentheses
    backtrack("", 0, 0)
    return results


def generate_parenthesis_using_backtracking_stack(n: int) -> list[str]:
    """
    Intuition:
    - We will use a stack to generate the parentheses strings.
    - The stack helps us keep track of the current sequence of parentheses we're building.
    - We can add an open parenthesis '(' if we haven't used all n open parentheses yet.
    - We can add a closing parenthesis ')' if we have more open than closed parentheses.
    - We will use a helper function to generate the parentheses strings.
    """
    results = []

    def backtrack_using_stack(stack, open_count, close_count):
        # Base Case: If the number of open and close parentheses are equal to n, we have a valid parentheses string
        if open_count == close_count == n:
            results.append("".join(stack))
            return
        # If the number of open parentheses is less than n, we can add an open parenthesis
        if open_count < n:
            backtrack_using_stack(stack + ["("], open_count + 1, close_count)
        # If the number of close parentheses is less than the number of open parentheses, we can add a close parenthesis
        if close_count < open_count:
            backtrack_using_stack(stack + [")"], open_count, close_count + 1)

    backtrack_using_stack([], 0, 0)
    return results


if __name__ == "__main__":
    print(generate_parenthesis_using_backtracking(3))
    print(generate_parenthesis_using_backtracking_stack(3))
