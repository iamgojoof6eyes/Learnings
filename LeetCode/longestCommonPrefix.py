"""
Problem link: https://leetcode.com/problems/longest-common-prefix/

Objective: Find the longest common prefix string amongst an array of strings. If there is no common prefix, return an empty string "".
"""


class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        strs.sort()  # sort the string in alphabatical order
        j = 0
        
        while j < len(strs[0]) and strs[0][j] == strs[-1][j]: # Since the list is already sorted we just have to check the first and last element.
            j += 1
        return strs[0][0:j]
