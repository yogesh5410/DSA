class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        vector<int> pairs(n);

        sort(potions.begin(), potions.end());

        for(int i=0; i<n; i++) {
            long long val = (success + spells[i] - 1) / spells[i];
            auto it = lower_bound(potions.begin(), potions.end(), val);
            int cnt = potions.end() - it;
            pairs[i] = cnt;
        }

        return pairs;
    }
};