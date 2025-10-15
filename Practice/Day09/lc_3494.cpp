class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = mana.size();
        int m = skill.size();
        vector<long> time(m, 0);

        for(int i=0; i<n; i++) {
            long total = 0;
            for(int j=m-1; j>=0; j--) {
                total += mana[i]*skill[j];;
            }
            long time_comp = 0;
            for(int j=0; j<m; j++) {
                time_comp = max(time_comp, time[j]+total);
                total -= mana[i]*skill[j];
            }
            time[m-1] = time_comp;
            for(int j=m-2; j>=0; j--) {
                time[j] = time[j+1] - mana[i]*skill[j+1];
            }
        }

        return time[m-1];
    }
};

// time complexity => O(n*m)
// space complexity => O(m)