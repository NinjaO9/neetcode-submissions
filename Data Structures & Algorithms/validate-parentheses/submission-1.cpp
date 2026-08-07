class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (const auto& c : s)
        {
            switch(c)
            {
                case ')':
                if (st.size() == 0 || st.top() != '(') return false;
                st.pop();
                continue;
                case '}':
                if (st.size() == 0 ||st.top() != '{') return false;
                st.pop();   
                continue;
                case ']':
                if (st.size() == 0 ||st.top() != '[') return false;
                st.pop();
                continue;
                default:
                st.push(c);
            }
        }
        return st.size() == 0;
    }
};
