class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int freq[9] = {0};

        // Checking rows
        for (int i = 0; i < 9; i++)
        {
            fill(begin(freq), end(freq), 0);
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.') continue;
                if (freq[board[i][j] - '1'] == 1) return false;
                freq[board[i][j] - '1']++;
            }
        }
        
        // Checking columns
        for (int i = 0; i < 9; i++)
        {
            fill(begin(freq), end(freq), 0);
            for (int j = 0; j < 9; j++)
            {
                if (board[j][i] == '.') continue;
                if (freq[board[j][i] - '1'] == 1) return false;
                freq[board[j][i] - '1']++;
            }
        }

        // Checking boxes
        for (int i = 0; i < 3; i++)
        {
            fill(begin(freq), end(freq), 0);
            for (int j = 0; j < 3; j++)
            {
                fill(begin(freq), end(freq), 0);
                for (int r = 0; r < 3; r++)
                {
                    for (int c = 0; c < 3; c++)
                    {
                        if(board[r + (3 * i)][c + (3 * j)] == '.') continue;
                        if(freq[board[r + (3 * i)][c + (3 * j)] - '1'] == 1) return false;
                        freq[board[r + (3 * i)][c + (3 * j)] - '1']++;
                    }
                }
            }
        }
        return true;
    }
};
