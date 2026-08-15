class Solution {
public:
    string minWindow(string s, string t) {
        // So many varibles son im crine :sob:
        int p1 = 0, p2 = 0;
        int bestLen = -1, bestStart = 0;
        int potential = 0, matches = 0;
        unordered_map<char, int>freq;

        for (const char& c : t)
        {
            freq[c]++;
        }

        potential = freq.size();

        while (p2 != s.length())
        {
            if (freq.contains(s[p2]))
            {
                freq[s[p2]]--;
                if (freq[s[p2]] == 0) matches++;
            }
            p2++;

            while (matches == potential)
            {
                int len = p2 - p1;
                if (bestLen == -1) 
                {
                    bestLen = len;
                    bestStart = p1;
                }
                else if (len < bestLen)
                {
                    bestLen = len;
                    bestStart = p1;
                }
                if (freq.contains(s[p1])) 
                {
                    freq[s[p1]]++;
                    if (freq[s[p1]] > 0) matches--;
                }
                p1++;
            }

        }


        return bestLen != -1 ? s.substr(bestStart, bestLen) : "";
    }
};
