class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int cnt1 = 1, cnt2 = 1, flag = 1;
        int n = nums.size();

        for(int i = 1; i<n; i++) {
            if(nums[i-1] < nums[i]) cnt2++;
            else {
                cnt1 = cnt2;
                cnt2 = 1;
            }
            if(max(cnt2/2, min(cnt1, cnt2)) >= k) return true;
        }
        return false;
    }
};