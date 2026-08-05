class Solution:
    def maxArea(self, heights: List[int]) -> int:
        left = 0
        right = len(heights) - 1
        maxarea = 0

        while left < right:
            lower = min(heights[left], heights[right])
            maxarea = max(maxarea, abs(left - right) * lower)
            if lower == heights[left]:
                left += 1
            elif lower == heights[right]:
                right -= 1
        
        return maxarea
        