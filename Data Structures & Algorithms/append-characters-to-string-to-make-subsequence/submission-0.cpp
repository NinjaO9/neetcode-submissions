class Solution {
public:
    int appendCharacters(string s, string t) {
        int p1 = 0, p2 = 0;
        int n1 = s.size(), n2 = t.size();
        while(p1 < n1 && p2 < n2){
            if (s[p1] == t[p2]) p2++;
            p1++;
        }
        return n2 - p2;
    }
};