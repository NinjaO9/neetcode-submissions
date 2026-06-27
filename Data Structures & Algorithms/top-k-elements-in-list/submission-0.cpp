#include <queue>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqmap;
        priority_queue<pair<int, int>>  pq;
        vector<int> result;

        for (const int& i : nums)
        {
            freqmap[i]++;
        }

        for (const auto& p : freqmap)
        {
            pq.push({p.second, p.first});
        }

        for (int i = 0; i < k; i++ )
        {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;

    }
};
