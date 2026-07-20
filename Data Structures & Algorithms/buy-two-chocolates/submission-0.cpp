class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());
        int mon = money;
        for (int i = 0; i < 2; i++)
        {
            money -= prices[i];
            if (money < 0) return mon;
        }
        return money;
    }
};