class Solution {
public:
    int scoreOfString(string s) {
        int p = 0;
        int score = 0;

        for (int i = 1; i < s.size(); i++)
        {
            score += abs(s[p] - s[i]);
            p++;
        }
        return score;
    }
};