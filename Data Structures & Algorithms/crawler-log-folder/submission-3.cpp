class Solution {
public:
    int minOperations(vector<string>& logs) {
        int deep = 0;
        for (const auto& s : logs)
        {
            if (s == "../")
            {
               if (deep != 0)deep--; 
            }
            else if (s == "./") continue;
            else deep++;
        }
        return deep;
    }
};