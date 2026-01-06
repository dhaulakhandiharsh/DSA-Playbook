class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int startX, startY;
        int totalKeys = 0;

        // Find start position and count keys
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '@') {
                    startX = i;
                    startY = j;
                }
                if (grid[i][j] >= 'a' && grid[i][j] <= 'f') {
                    totalKeys++;
                }
            }
        }

        int targetMask = (1 << totalKeys) - 1;

        queue<pair<pair<int,int>, pair<int,int>>> q;
        // {{x, y}, {keysMask, steps}}
        q.push({{startX, startY}, {0, 0}});

        vector<vector<vector<bool>>> visited(
            m, vector<vector<bool>>(n, vector<bool>(1 << totalKeys, false))
        );
        visited[startX][startY][0] = true;

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            int x = curr.first.first;
            int y = curr.first.second;
            int mask = curr.second.first;
            int steps = curr.second.second;

            if (mask == targetMask) return steps;

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                int newMask = mask;

                if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                char cell = grid[nx][ny];

                if (cell == '#') continue;

                // If lock, check key
                if (cell >= 'A' && cell <= 'F') {
                    if (!(mask & (1 << (cell - 'A')))) continue;
                }

                // If key, collect it
                if (cell >= 'a' && cell <= 'f') {
                    newMask |= (1 << (cell - 'a'));
                }

                if (!visited[nx][ny][newMask]) {
                    visited[nx][ny][newMask] = true;
                    q.push({{nx, ny}, {newMask, steps + 1}});
                }
            }
        }

        return -1;
    }
};