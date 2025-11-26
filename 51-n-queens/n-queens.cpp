#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> pos(n, -1);                 // pos[row] = column index of queen in that row
        vector<bool> cols(n, false);            // occupied columns
        vector<bool> diag1(2*n - 1, false);     // / diagonal: row + col
        vector<bool> diag2(2*n - 1, false);     // \ diagonal: row - col + (n-1)
        vector<vector<string>> result;
        backtrack(0, n, pos, cols, diag1, diag2, result);
        return result;
    }

private:
    void backtrack(int row, int n, vector<int>& pos, vector<bool>& cols,
                   vector<bool>& diag1, vector<bool>& diag2,
                   vector<vector<string>>& result) {
        if (row == n) {
            result.push_back(buildBoard(pos, n));
            return;
        }
        for (int c = 0; c < n; ++c) {
            int d1 = row + c;
            int d2 = row - c + (n - 1);
            if (cols[c] || diag1[d1] || diag2[d2]) continue;
            // place
            pos[row] = c;
            cols[c] = diag1[d1] = diag2[d2] = true;
            backtrack(row + 1, n, pos, cols, diag1, diag2, result);
            // undo
            cols[c] = diag1[d1] = diag2[d2] = false;
            pos[row] = -1;
        }
    }

    vector<string> buildBoard(const vector<int>& pos, int n) {
        vector<string> board;
        board.reserve(n);
        for (int r = 0; r < n; ++r) {
            string row(n, '.');
            row[pos[r]] = 'Q';
            board.push_back(row);
        }
        return board;
    }
};

// Example usage:
// int main() {
//     Solution sol;
//     int n = 4;
//     auto ans = sol.solveNQueens(n);
//     for (auto &board : ans) {
//         for (auto &row : board) cout << row << '\n';
//         cout << '\n';
//     }
// }