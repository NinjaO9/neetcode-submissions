class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::priority_queue<pair<int, int>> maxH;
        int n = nums.size(), p1 = 0, p2 = 0;
        if (n == 0) return {};
        if (n < k) return {*max_element(nums.begin(), nums.end())};
        vector<int> maxvs;
        while (p2 != n)
        {
            if (p2 - p1 < k)
            {
                maxH.push({nums[p2], p2});
                p2++;
            }
            else
            {
                maxvs.push_back(maxH.top().first);
                p1++;
                while (!maxH.empty() && maxH.top().second < p1) maxH.pop();
                maxH.push({nums[p2], p2});
                p2++;
            }
        }
        maxvs.push_back(maxH.top().first);
        return maxvs;
        
    }
};
