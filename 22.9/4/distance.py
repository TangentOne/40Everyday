# -*- coding = utf-8 -*-
# @Author : 马宇翔
# @Software : PyCharm

"""
给你一个下标从 0 开始的字符串 s ，该字符串仅由小写英文字母组成，s 中的每个字母都 恰好 出现 两次 。另给你一个下标从 0 开始、长度为 26 的的整数数组 distance 。
字母表中的每个字母按从 0 到 25 依次编号（即，'a' -> 0, 'b' -> 1, 'c' -> 2, ... , 'z' -> 25）。
在一个 匀整 字符串中，第 i 个字母的两次出现之间的字母数量是 distance[i] 。如果第 i 个字母没有在 s 中出现，那么 distance[i] 可以 忽略 。
如果 s 是一个 匀整 字符串，返回 true ；否则，返回 false 
"""

from typing import List

class Solution:
    def checkDistances(self, s: str, distance: List[int]) -> bool:

        first = []
        second = []
        myDistance = []
        for i in range(26):
            first.append(-1)
            second.append(0)
            myDistance.append(0)          

        # 创建字母表
        myWords = []
        for i in range(26):
            myWords.append(chr(97 + i))

        i = 0
        for word in s:
            myIndex = myWords.index(word)
            if first[myIndex] == -1:
                first[myIndex] = i
            else:
                second[myIndex] = i
            i += 1

        myDistance = [second[i] - first[i] - 1 for i in range(26)]

        i = 0
        for j in first:
            if j == -1:
                distance[i] = 0
            i += 1

        if distance == myDistance:
            return True
        else:
            return False
