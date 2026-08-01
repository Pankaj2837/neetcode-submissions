class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 9x9 boolean arrays for tracking seen numbers
        // Rows, Cols, aur Boxes ke liye (Index 0-8 for numbers '1'-'9')
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool boxes[9][9] = {false};
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                // 1. Khaali cell ko skip karo
                if (board[r][c] == '.') continue;

                // 2. Character '1'-'9' ko Integer index 0-8 mein convert karo
                int num = board[r][c] - '1';

                // 3. Box ID calculate karo (0 to 8)
                // (r / 3) row group (0, 1, 2) deta hai aur * 3 usko 1D index banata hai
                int boxIndex = (r / 3) * 3 + (c / 3);

                // 4. Check karo kya yeh number pehle kisi Row, Col, ya Box mein aa chuka hai
                if (rows[r][num] || cols[c][num] || boxes[boxIndex][num]) {
                    return false; // Duplicate found!
                }

                // 5. Mark as seen
                rows[r][num] = true;
                cols[c][num] = true;
                boxes[boxIndex][num] = true;
            }
        }

        return true;
    }
};