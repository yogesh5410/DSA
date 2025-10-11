class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        // count the freq of powers
        map<int, int> cnt;
        for(int p : power) cnt[p]++;
        
        // store unique power in val 
        vector<int> val;
        for(auto [k, v] : cnt) val.push_back(k);
        int n = val.size();
        
        // dp[i] = max power sum possible upto ith unique power
        vector<long long> dp(n, 0);

        // base case
        dp[0] = 1LL*val[0]*cnt[val[0]];

        // processing begin
        for(int i=1; i<n; i++) {

            // set ptr to last val which is at least 2 less than current
            int j = i-1;
            while(j>=0 && val[j]+2 >= val[i]) j--;

            // if ptr exist take max of last and sum of ...
            if(j>=0) dp[i] = max(dp[i-1], dp[j] + 1LL*val[i]*cnt[val[i]]);

            // take max of current, last;
            else dp[i] = max(dp[i-1], 1LL*val[i]*cnt[val[i]]);
        }

        return dp[n-1];
    }
};