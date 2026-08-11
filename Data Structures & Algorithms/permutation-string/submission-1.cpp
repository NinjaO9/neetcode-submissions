class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        int freq[26] = {0};
        int window[26] = {0};

        for (const char& c : s1)
        {
            freq[c - 'a']++;
        }

        int p1 = 0, p2 = 0;
        for (; p2 < s1.length(); p2++)
        {
            window[s2[p2] - 'a']++;
        }

        int n = s2.length();
        int matches = 0;

        for (int i = 0; i < 26; i++)
        {
            if (freq[i] == window[i]) matches++;
        }
        if (matches == 26) return true;
        
        while (p2 != n)
        {
            if (s2[p1] != s2[p2])
            {  
                window[s2[p1] - 'a']--;
                window[s2[p2] - 'a']++;

                if (freq[s2[p1] - 'a'] == window[s2[p1] - 'a']) matches++;
                else if (freq[s2[p1] - 'a'] == window[s2[p1] - 'a'] + 1) matches--;

                if (freq[s2[p2] - 'a'] == window[s2[p2] - 'a']) matches++;
                else if (freq[s2[p2] - 'a'] == window[s2[p2] - 'a'] - 1) matches--;
                // I hate all the ([[]]) stuff man :cry:
            }

            p1++;
            p2++;
            if (matches == 26) return true;
        }
        
        if (matches == 26) return true;
        return false;
    }
};
