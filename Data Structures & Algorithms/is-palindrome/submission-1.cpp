class Solution {
public:
    bool isPalindrome(string s) {
        s.erase(remove_if(s.begin(), s.end(), [](unsigned char ch){
            return !isalnum(ch);
        }), s.end());
        cout << s << endl;
        int p1 = 0;
        int p2 = s.size() - 1;

        while (p1 < p2)
        {
            if (tolower(s[p1]) != tolower(s[p2])) return false;
            p1++;
            p2--;
        }
        return true;
    }
};
