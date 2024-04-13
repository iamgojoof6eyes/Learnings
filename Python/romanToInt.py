"""
Problem link: https://leetcode.com/problems/roman-to-integer/

Objective: Convert the roman numbers to integers
"""


class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        rom_dict = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000
        }
        total = 0  # store the number in integer form which will be returned
        prev_num = 0  # number just before the current number
        for i in s:
            num = rom_dict[i]
            if prev_num and prev_num < num:
                # have calulated this thing already and applied it here.
                total += num - 2 * prev_num
            else:
                total += num
            prev_num = num  # update the prev_num varibale with current number
        return total
