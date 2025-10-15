class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, 1);
        unordered_map<int, int> fillDay;
        set<int> dry;

        for(int i=0; i<n; i++) {
            int lake = rains[i];
            if(lake==0) {
                dry.insert(i);
            } else {
                ans[i]=-1;
                if(fillDay.count(lake)) {
                    auto it = dry.upper_bound(fillDay[lake]);
                    if(it == dry.end()) return {};
                    ans[*it] = lake;
                    dry.erase(it);
                }
                fillDay[lake] = i;
            }
        }
        return ans;
    }
};