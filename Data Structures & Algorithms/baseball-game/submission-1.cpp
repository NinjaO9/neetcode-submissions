class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> record;
        for (const auto& op : operations)
        {
            int n = record.size();
            switch(op[0])
            {
                case '+':
                record.push_back(record[n - 1] + record[n - 2]);
                break;
                case 'D':
                record.push_back(record[n - 1] * 2);
                break;
                case 'C':
                record.pop_back();
                break;
                default:
                record.push_back(stoi(op));
            }
        }
        int total = 0;
        for (const auto& i : record) total += i;
        return total;
    }
};