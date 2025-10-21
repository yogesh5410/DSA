class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<int, int> mp;
        for(int num : nums) mp[num]++;

        sort(nums.begin(), nums.end());

        int n = nums.size();
        int ans = 0;

        for(int i=nums[0]; i<=nums[n-1]; i++) {
            auto ub = upper_bound(nums.begin(), nums.end(), i+k);    // first element > i+k
            auto lb = lower_bound(nums.begin(), nums.end(), i-k);    // first element <= i-k

            int range = ub - lb;

            ans = max(ans, min(range, numOperations + mp[i]));
        }

        return ans;
    }
};