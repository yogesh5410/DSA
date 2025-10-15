class Solution {
public:

    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int res = 1, cnt1 = 0, cnt2 = 1;
        
        for(int i=1; i<n; i++) {
            if(nums[i-1] < nums[i]) cnt2++;
            else {
                cnt1 = cnt2;
                cnt2 = 1;
            }
            res = max({res, cnt2/2, min(cnt1, cnt2)});
        }

        return res;
    }
};

// time complexity = O(n)
// space complexity = O(1)