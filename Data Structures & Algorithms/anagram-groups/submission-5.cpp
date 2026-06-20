class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        if (strs.size() == 1) return {{strs[0]}};
        unordered_map<string, vector<string>> hgroups;
        vector<vector<string>> groups;

        for (const string s : strs)
        {
            string hash = getFrequencyHash(s);
            hgroups[hash].push_back(s);
        }

        for (const pair<string, vector<string>> vs : hgroups)
        {
            groups.push_back(vs.second);
        }

        return groups;
    }

    string getFrequencyHash(const string& s)
    {
        int arr[26] = {0};
        string h;
        for (const char c : s)
        {
            arr[c - 'a'] += 1;
        }

        for (int i = 0; i < 26; i++)
        {
            h.push_back((char)('a' + i));
            h += to_string(arr[i]);
        }
        return h;
    }
};


/*

idea:

Create frequency hash of string using similar technique to the other anagram question.
Then use the hash to connect anagrams together using a hashmap.

*/