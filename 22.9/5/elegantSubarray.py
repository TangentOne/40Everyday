"""
给你一个由 正 整数组成的数组 nums 。
如果 nums 的子数组中位于 不同 位置的每对元素按位 与（AND）运算的结果等于 0 ，则称该子数组为 优雅 子数组。
返回 最长 的优雅子数组的长度。
子数组 是数组中的一个 连续 部分。
注意：长度为 1 的子数组始终视作优雅子数组。
"""

class Solution:
    def longestNiceSubarray(self, nums: List[int]) -> int:
        ans = 1

        for right in range(1, len(nums)):
            length = 1
            left = right - 1
            sub = nums[right]
            while left >= 0 and nums[left] & sub == 0:
                print("from", left, "to", right)
                print(nums[left], "&", sub, "=", nums[left] & sub)
                sub = sub | nums[left]
                length += 1
                left -= 1
                print(length)

            ans = max(ans, length)
        return ans
