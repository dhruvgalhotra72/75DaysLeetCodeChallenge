class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // row check
        for (int i = 0; i < 9; i++) {
            bool seen[10] = {false};

            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    if (seen[num]) return false;
                    seen[num] = true;
                }
            }
        }

        // column check
        for (int j = 0; j < 9; j++) {
            bool seen[10] = {false};

            for (int i = 0; i < 9; i++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    if (seen[num]) return false;
                    seen[num] = true;
                }
            }
        }

        // 3x3 sub-box check
        for (int box = 0; box < 9; box++) {
            bool seen[10] = {false};

            int startRow = (box / 3) * 3;
            int startCol = (box % 3) * 3;

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {

                    char c = board[startRow + i][startCol + j];

                    if (c != '.') {
                        int num = c - '0';
                        if (seen[num]) return false;
                        seen[num] = true;
                    }
                }
            }
        }

        return true;
    }
};