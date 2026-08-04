class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;
        while (i != j)
        {
            int res = numbers[i] + numbers[j];
            if (res > target)
            {
                j--;
            }
            else if (res < target)
            {
                i++;
            }
            else
            {
                return {i + 1, j + 1};
            }
        }
        return {1,1}; // Shouldnt happen as we are guaranteed a solution
        
    }
};
