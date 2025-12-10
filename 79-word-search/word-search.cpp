class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, string& word, int r, int c, int idx) {
        // If we have matched all characters
        if (idx == (int)word.size()) {
            return true;
        }

        // Boundary checks
        if (r < 0 || r >= (int)board.size() || c < 0 || c >= (int)board[0].size()) {
            return false;
        }

        // Character mismatch
        if (board[r][c] != word[idx]) {
            return false;
        }

        // Mark as visited (modify in-place)
        char temp = board[r][c];
        board[r][c] = '#'; // any sentinel not in ['A'-'Z'] is fine

        // Explore 4 directions
        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        for (int k = 0; k < 4; ++k) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (dfs(board, word, nr, nc, idx + 1)) {
                board[r][c] = temp; // backtrack before returning
                return true;
            }
        }

        // Backtrack
        board[r][c] = temp;
        return false;
    }
};
