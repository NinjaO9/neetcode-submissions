class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int p1 = 0;
        int p2 = 0;
        int maxsize = 0;
        unordered_map<char, bool> seen;

        for (; p2 < s.length(); p2++)
        {
            if (seen.contains(s[p2]))
            {
                maxsize = max(maxsize, p2 - p1);
                while (seen[s[p2]])
                {
                    seen[s[p1]] = false;
                    p1++;
                }
            }
            seen[s[p2]] = true;
        }
        maxsize = max(maxsize, p2 - p1);

        return maxsize;
    }
};
