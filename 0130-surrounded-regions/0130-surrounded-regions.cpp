class Solution {
public:
    void solve(vector<vector<char>>& board) {
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        queue<pair<int, int>> q;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
                    if (board[i][j] == 'O') {
                        q.push({i, j});
                        board[i][j] = '#';
                    }
                }
            }
        }
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (auto& x : dir) {
                int ix = i + x.first;
                int jx = j + x.second;
                if (ix >= 0 && jx >= 0 && ix < m && jx < n &&
                    board[ix][jx] == 'O') {
                    board[ix][jx] = '#';
                    q.push({ix, jx});
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};