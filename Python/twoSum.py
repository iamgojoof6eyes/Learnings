"""
Problem link: https://leetcode.com/problems/two-sum/

Objective: Return indices of the two numbers such that they add up to target.
"""


class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """

        compliment = {}  # Dictionary which store the elements in format key: number, value: index of the number

        to_return = []  # A list which will return the solution.

        for i, val in enumerate(nums):
            # Get the compliment number which should be added to make up the targeted number
            comp_num = target - val

            try:
                # Check in the dictionary if the compliment of the number, which we have created above, exists already or not
                second_comp = compliment[comp_num]

                # if the compliment exists it will extend the values in the to_return list, second_comp is nothing but index of the compliment number and i is the current number
                to_return.extend([second_comp, i])

            except KeyError:  # Catch the key error if the compliment doesn't exists
                compliment[val] = i  # Add the current numbr in the dict

        return to_return
