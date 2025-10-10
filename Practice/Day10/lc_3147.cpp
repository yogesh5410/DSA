class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int sum = 0;
        int n = energy.size();
        int res = INT_MIN;
        for(int i=n-k; i<n; i++) {
            sum = 0;
            for(int j=i; j>=0; j-=k) {
                sum += energy[j];
                res = max(res, sum);
            }
        }
        return res;
    }
};

// time complexity => O(n)
// space complexity => O(1)