class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int prefix = 1;
        int postfix = 1;
        int size = nums.size();
        vector<int> res(size);

        for (int i = 0; i < size; i++)
        {
            res[i] = prefix;
            prefix *= nums[i];
        }

        for (int i = size - 1; i >= 0; i--)
        {
            res[i] *= postfix;
            postfix *= nums[i];
        }

        return res;
    }
};
