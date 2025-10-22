class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        map<int, int> critical_points;
        set<int> candidates;
        map<int, int> freq;

        for(int num : nums) {
            freq[num]++;
            critical_points[num-k]++;
            critical_points[num+k+1]--;
            candidates.insert(num-k);
            candidates.insert(num+k+1);
            candidates.insert(num);
        }

        int adj = 0;
        int res = 0;
        // line sweep
        for(int num : candidates) {
            adj += critical_points.count(num) ? critical_points[num] : 0;
            int f = freq.count(num) ? freq[num] : 0;
            res = max(res, min(numOperations + f, adj));
        }

        return res;

    }
};