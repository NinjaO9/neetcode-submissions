class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:

        def twoSum(nums: List[int], target : int) -> List[List[int]]:
            if len(nums) == 0: return []
            i = 0
            j = len(nums) -1 
            res = []
            while i < j:
                r = nums[i] + nums[j]
                if r > target:
                    j = j - 1
                elif r < target:
                    i = i + 1
                else:
                    res.append([nums[i], nums[j], -target])
                    i = i + 1
                    j = j - 1
                    while i < j and nums[i] == nums[i - 1]:
                        i = i + 1
                    while j > i and nums[j] == nums[j + 1]:
                        j = j - 1
            return res
        
        res = []
        l = len(nums)
        nums.sort()
        for i in range(l):
            if i > 0 and nums[i] == nums[i - 1]: continue # Dedupe valid pairs

            ts = twoSum(nums[i+1:l:], -nums[i]) # Idea here: x + y + z = 0 === x + y = -z
            if len(ts) != 0:
                res = res + ts
            
        return res
        