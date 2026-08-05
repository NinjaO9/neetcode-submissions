class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if nums == []: return 0

        nums.sort()
        tab = {}
        for num in nums:
            tab[num] = 1
        maxconsec = 1
        for num in nums:
            if num - 1 in tab:
                tab[num] = tab[num - 1] + 1
                maxconsec = max(maxconsec, tab[num])
        return maxconsec
        