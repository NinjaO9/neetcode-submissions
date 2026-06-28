class Solution {
public:
    char delim = '#';

    string encode(vector<string>& strs) {
        string ecode;
        int size = 0;
        for (const string& s : strs)
        {
            size = s.size();
            ecode += to_string(size);
            ecode.push_back(delim);
            ecode += s;
        }
        cout << ecode << endl;
        return ecode;
    }

    vector<string> decode(string s) {
        vector<string> dcode;
        string curstring;
        int spos = 0;
        while (spos < s.size())
        {
            curstring = "";
            int ssize = getStringSize(s, spos, delim);
            for (int i = 0; i < ssize && spos < s.size(); i++)
            {
                curstring.push_back(s[spos]);
                spos++;
            }
            dcode.push_back(curstring);
        }
        return dcode;

    }

    int getStringSize(string& s, int& spos, char delim)
    {
        int res = 0;
        while (s[spos] != delim)
        {
            res *= 10;
            res += s[spos] - '0';
            spos++;
        }
        spos++;
        return res;
    }

};
