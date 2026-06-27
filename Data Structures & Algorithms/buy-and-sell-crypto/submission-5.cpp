class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int p1 = 0;
        int p2 = p1;
        int maxi = 0;

        while (p2 < prices.size())
        {
            maxi = max(maxi, prices[p2] - prices[p1]);
            if (prices[p1] > prices[p2])
            {
                p1 = p2;
            }
            p2++;
        }
        maxi = max(maxi, prices[p2 - 1] - prices[p1]);

        return maxi;        
    }
};
