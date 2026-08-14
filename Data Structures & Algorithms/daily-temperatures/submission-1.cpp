class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> mstack;
        vector<int> result(temperatures.size());
        for (int i = 0; i < temperatures.size(); i++)
        {
            // Slight modification from previous submission - Remove condition cause at the end of the day I am still pushing the current pair to the stack.
            while (mstack.size() != 0 && mstack.top().first < temperatures[i])
            {
                int v = mstack.top().second;
                mstack.pop();
                result[v] = i - v;
            }
            mstack.push({temperatures[i], i});
        }

        return result;
    }
};
