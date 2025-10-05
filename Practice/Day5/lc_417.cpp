class Solution {
public:
    int m, n;
    vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; 

    void dfs(vector<vector<bool>>& visited, vector<vector<int>>& heights, int i, int j) {
        visited[i][j] = true;

        for(auto d : dirs) {
            int x = i + d.first;
            int y = j + d.second;

            if(x < m && y < n && x >=0 && y >= 0) {
                if(!visited[x][y]) {
                    if(heights[x][y] >= heights[i][j]) {
                        dfs(visited, heights, x, y);
                    }
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> atlantic(m, vector<bool> (n, false));
        vector<vector<bool>> pacific(m, vector<bool> (n, false));

        for(int i=0; i<m; i++) {
            dfs(atlantic, heights, i, n-1);
            dfs(pacific, heights, i, 0);
        }

        for(int j=0; j<n; j++) {
            dfs(atlantic, heights, m-1, j);
            dfs(pacific, heights, 0, j);
        }

        vector<vector<int>> res;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(pacific[i][j] && atlantic[i][j]) res.push_back({i, j});
            }
        }

        return res;

    }
};

// time complexity : O(m*n)
// space complexity : O(m*n)