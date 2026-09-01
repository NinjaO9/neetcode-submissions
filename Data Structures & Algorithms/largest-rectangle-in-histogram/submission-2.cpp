class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> shiftstore(heights.size());
        int mv = 0;

        stack<int> shifts;

        // Left pass
        for (int i = 0; i < heights.size(); i++)
        {
            mv = max(heights[i], mv);
            while (!shifts.empty() && heights[i] < heights[shifts.top()])
            {
                int t = shifts.top();
                shifts.pop();
                shiftstore[t] += i - t;
            }
            shifts.push(i);
        }

        while (!shifts.empty())
        {
            int t = shifts.top();
            shifts.pop();
            shiftstore[t] += heights.size() - t;
        }

        // Right pass
        for (int i = heights.size() - 1; i > -1; i--)
        {
            while (!shifts.empty() && heights[i] < heights[shifts.top()])
            {
                int t = shifts.top();
                shifts.pop();
                shiftstore[t] += t - i;
            }
            shifts.push(i);
        }

        while (!shifts.empty())
        {
            int t = shifts.top();
            shifts.pop();
            shiftstore[t] += t + 1;
        }

        for (int i = 0; i < heights.size(); i++)
        {
            shiftstore[i]--; // remove double counting
            mv = max(mv, shiftstore[i] * heights[i]);
        }

        return mv;
    }

    /*

    On a given recantangle, we can 'shift' to a direction so long as the next bar > this bar

    By shifting, we can maximize our space. Taking in example 1, we can look at either
        one of the h[i] = 2 blocks. Both can shift 1 in a direction and 2 in the other.
    
    So, we can use a monotomic increasing stack to understnad how much we can shift a bar.
        Then, when we reach a bar that is smaller, or once we reach the end, we can 
        pop the values and attribute then appropriately. We can keep a pop counter in the
        event of a pop, and that gets assigned to the bar's index to indicate the shift
        count in any one direction.

    We do one look in the left direction, and another look in the right. This way, we can 
        understand the total amount of shifts a rectange can have.

    On the initial shift checks, we can store the max value we find in the array as a 
        default. Then, when doing our total shift checks, we can compare the shifts to the 
        max value.
    
    */
};
