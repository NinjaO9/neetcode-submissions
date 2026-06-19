class Solution {
public:
    bool isAnagram(string s, string t) {
        int freqtable[26] = {0};

        for (const char c : s)
        {
            freqtable[c - 'a'] += 1;
        }

        for (const char c : t)
        {
            freqtable[c - 'a'] -= 1;
            if (freqtable[c - 'a'] < 0) return false;
        }

        for (int i = 0; i < 26; i++)
        {
            if (freqtable[i] != 0) return false;
        }
        return true;
    }
};
