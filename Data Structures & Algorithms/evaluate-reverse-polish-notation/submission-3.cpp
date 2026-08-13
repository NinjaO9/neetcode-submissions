class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.size() == 0) return 0;
        stack<int> nums;

        for (const string& t : tokens)
        {
            int a = 0, b = 0;
            if (t == "+")
            {
                a = nums.top();
                nums.pop();
                b = nums.top();
                nums.pop();
                nums.push(a + b);
            }
            else if (t == "-")
            {
                a = nums.top();
                nums.pop();
                b = nums.top();
                nums.pop();
                nums.push(b - a);
            }
            else if (t == "*")
            {
                a = nums.top();
                nums.pop();
                b = nums.top();
                nums.pop();
                nums.push(a * b);
            }
            else if (t == "/")
            {
                a = nums.top();
                nums.pop();
                b = nums.top();
                nums.pop();
                nums.push(b / a);
            }
            else nums.push(stoi(t));
        } 
        return nums.top();
    }
};
