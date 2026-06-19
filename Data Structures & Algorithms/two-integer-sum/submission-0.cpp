class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> targets;

        for (int i = 0; i < nums.size(); i++)
        {
            if (targets.contains(target - nums[i])) return {targets[target - nums[i]], i};
            targets[nums[i]] = i;
        }

        return {0,0};
    }
};


/*

[3,4,5,6]; 7

[0,1]

[{3, 0}, {4, 1}, {5, 2}, {6, 3}]



*/