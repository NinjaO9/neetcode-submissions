class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        vector<int> mleft(n);
        vector<int> mright(n);

        for (int i = 1; i < n; i++)
        {
            mleft[i] = max(mleft[i - 1], height[i - 1]);
        }
        for (int i = n - 2; i > -1; i--)
        {
            mright[i] = max(mright[i + 1], height[i + 1]);
        }

        int water = 0;

        for (int i = 0; i < n; i++)
        {
            int res = min(mleft[i], mright[i]) - height[i];
            if (res < 0) continue;
            water += res;
        }

        return water;
    }
};
