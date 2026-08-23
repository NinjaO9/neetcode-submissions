class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        int n = position.size();
        for (int i = 0; i < n; i++)
        {
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.begin(), cars.end()); // ascending order

        stack<double> fleet;
        for (int i = n - 1; i >= 0; i--)
        {
            double time = (target - cars[i].first + 0.0) / cars[i].second;

            if (fleet.empty() || fleet.top() < time)
            {
                fleet.push(time);
            } 
        }
        return fleet.size();
    }
};
