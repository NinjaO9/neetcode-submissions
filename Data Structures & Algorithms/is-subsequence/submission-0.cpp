class Solution {
public:
    bool isSubsequence(string s, string t) {
        int p = 0;
        for (const auto& c : t)
        {
            if (c == s[p])
            {
                p++;
                if (p == s.length())
                {
                    break;
                }
            }
        }
        return p == s.length();
    }
};