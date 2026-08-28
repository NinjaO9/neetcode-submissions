class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, h = matrix.size() - 1;
        int m_r = 0;

        while (l <= h)
        {
            m_r = (h - l)/2 + l;
            if (matrix[m_r][0] < target)
            {
                l = m_r + 1;
            }
            else if (matrix[m_r][0] >  target)
            {
                h = m_r - 1;
            }
            else return true;
        }
        m_r = h;
        if (m_r < 0 || m_r >= matrix.size()) return false;
        cout << matrix[m_r][0] << endl;
        h = matrix[0].size() - 1;
        l = 0;

        while (l <= h)
        {
            int m_c = (h - l)/2 + l;

            if (matrix[m_r][m_c] < target)
            {
                l = m_c + 1;
            }
            else if (matrix[m_r][m_c] > target)
            {
                h = m_c - 1;
            }
            else return true;
        }

        return false;
    }
};
