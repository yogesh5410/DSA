class Solution {
public:

    int countOfLessOrEqual(vector<vector<int>>& matrix, int x, int n) {
        int cnt = 0, c = n-1;
        for(int r = 0; r < n; r++) {
            while(c>=0 && matrix[r][c]>x) c--;
            cnt += (c+1);
        }
        return cnt;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0], r = matrix[n-1][n-1];
        int res = -1;
        while(l <= r) {
            int mid = (l + r)/2;
            if(countOfLessOrEqual(matrix, mid, n) >= k) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
};