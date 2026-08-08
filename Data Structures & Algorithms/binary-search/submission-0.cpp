class Solution {
public:
    int search(vector<int>& nums, int target) {

        int lower = 0, upper = nums.size() - 1;

        while (lower <= upper)
        {
            int cur = (upper-lower)/2 + lower;
            if (nums[cur] == target) return cur;
            if (nums[cur] < target)
            {
                lower = cur + 1;
            }
            else
            {
                upper = cur - 1;
            }
            
        }
        return -1;
        
    }
};
