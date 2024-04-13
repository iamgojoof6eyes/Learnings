"""
Problem link: https://leetcode.com/problems/palindrome-number/

Objective: Return `True` if x is a palindrome, and `False` otherwise.

Palindrome is a word or integer which reads the same if you read it from start or from end. For e.g.: Lol, 121 etc.
"""


class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        x = str(x)
        if x == x[::-1]:  # x[::-1] this will reverse the entire string
            return True
        else:
            return False
