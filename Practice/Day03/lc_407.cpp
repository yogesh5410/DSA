class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        // calculate size of grid
        int m = heightMap.size();
        int n = heightMap[0].size();

        // define min-heap & visited 
        priority_queue<pair<int, pair<int, int>>, 
            vector<pair<int, pair<int, int>>>, 
            greater<>> pq;
        vector<vector<bool>> visited(m, vector<bool> (n, false));

        // push boundary to min-heap
        for(int i=0; i<m; i++) {
            pq.push({heightMap[i][0], {i, 0}});
            pq.push({heightMap[i][n-1], {i, n-1}});
            visited[i][0] = visited[i][n-1] = true;
        }
        for(int j=1; j<n-1; j++) {
            pq.push({heightMap[0][j], {0, j}});
            pq.push({heightMap[m-1][j], {m-1, j}});
            visited[0][j] = visited[m-1][j] = true;
        }

        // define directions
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // total water
        int water = 0;

        // begin processing
        while(!pq.empty()) {
            int height = pq.top().first;
            auto cell = pq.top().second;
            pq.pop();
            
            int x = cell.first;
            int y = cell.second;

            for(auto [dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;
                if(nx >= 0 && nx < m && ny >=0 && ny < n && !visited[nx][ny]) {

                    if(heightMap[nx][ny] < height) {
                        water += height - heightMap[nx][ny];
                        heightMap[nx][ny] = height;
                    }

                    pq.push({heightMap[nx][ny], {nx, ny}});
                    visited[nx][ny] = true;
                } 
            }
        }
        return water;
    }
};