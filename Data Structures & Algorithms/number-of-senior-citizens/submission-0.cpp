class Solution {
public:
    int countSeniors(vector<string>& details) {
        int elders = 0;
        for (const auto& s : details)
        {
            string sub = s.substr(11, 2);
            if (stoi(sub) > 60) elders++;
        }
        return elders;
    }
};