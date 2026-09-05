class Solution {
public:
    int lengthOfLastWord(string s) {
        int l = 0;
        int m = 0;
        for (const auto& c : s)
        {
            if(c == ' ')
            {
                m = max(m,l);
                l = 0;
            }
            else
            {
                m = 0;
                l++;
            }
        }
        return max(m,l);
    }
};