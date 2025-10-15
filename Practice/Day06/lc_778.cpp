class Solution {
public:

    vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        priority_queue<pair<int, pair<int, int>>, 
            vector<pair<int, pair<int, int>>>,
            greater<>> pq;
        
        vector<vector<bool>> visited(n, vector<bool> (n, false));

        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = true;

        int res = 0;

        while(true) {
            int height = pq.top().first;
            auto cell = pq.top().second;

            pq.pop();

            int x = cell.first;
            int y = cell.second;

            res = max(res, height);

            if(x==n-1 && y==n-1) break;

            for(auto [dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;

                if(nx >=0 && ny >= 0 && nx < n && ny < n) {
                    if(!visited[nx][ny]) {
                        pq.push({grid[nx][ny], {nx, ny}});
                        visited[nx][ny] = true;
                    }
                } 
            }
        }

        return res;
    }
};

// time complexity : O(n*n*log(n*n))
// space complexity : O(n*n)