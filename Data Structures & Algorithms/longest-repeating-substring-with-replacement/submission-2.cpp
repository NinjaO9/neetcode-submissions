class Solution {
public:
    int characterReplacement(string s, int k) {
        if (!s.length()) return 0;
        int freq[26] = {0};
        int largest = 0;
        int p1 = 0, p2 = 0;
        while (p2 != s.length())
        {
            int size = p2 - p1;
            if (size - *max_element(freq, freq + 26) <= k)
            {
                freq[s[p2] - 'A']++;
                p2++;
                largest = max(largest, size);
            }
            else
            {
                freq[s[p1] - 'A']--;
                p1++;
            }
        }
        if (p2 - p1 - *max_element(freq, freq + 26) <= k)
        {
            largest = max(largest, p2 - p1);
        }
        return largest;
        
    }
};
