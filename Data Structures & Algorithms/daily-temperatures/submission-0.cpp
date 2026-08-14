class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> mstack;
        vector<int> result(temperatures.size());
        for (int i = 0; i < temperatures.size(); i++)
        {
            if (mstack.size() == 0)
            {
                mstack.push({temperatures[i], i});
            }
            else
            {
                while (mstack.size() != 0 && mstack.top().first < temperatures[i])
                {
                    int v = mstack.top().second;
                    mstack.pop();
                    result[v] = i - v;
                }
                mstack.push({temperatures[i], i});
            }
        }

        return result;
    }
};
