class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        queue<pair<pair<int, int>, int>> q;

        int fresh = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    visited[i][j] = true;
                } else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int ans = 0;
        int rotten = 0;

        while(!q.empty()) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int time = q.front().second;
            q.pop();

            ans = max(ans, time);

            if(i - 1 >= 0 && !visited[i - 1][j] && grid[i - 1][j] == 1) {
                q.push({{i - 1, j}, time + 1});
                visited[i - 1][j] = true;
                rotten++;
            }

            if(i + 1 < n && !visited[i + 1][j] && grid[i + 1][j] == 1) {
                q.push({{i + 1, j}, time + 1});
                visited[i + 1][j] = true;
                rotten++;
            }

            if(j - 1 >= 0 && !visited[i][j - 1] && grid[i][j - 1] == 1) {
                q.push({{i, j - 1}, time + 1});
                visited[i][j - 1] = true;
                rotten++;
            }

            if(j + 1 < m && !visited[i][j + 1] && grid[i][j + 1] == 1) {
                q.push({{i, j + 1}, time + 1});
                visited[i][j + 1] = true;
                rotten++;
            }
        }

        if(rotten != fresh)
            return -1;

        return ans;
    }
};