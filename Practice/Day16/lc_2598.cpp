class Solution {
public:
    int modulo(int x, int y) {
        return ((x%y)+y)%y;
    }
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> mp;
        for(int num : nums) mp[modulo(num, value)]++;

        int cnt=INT_MAX, res=0;
        for(int i=0; i<value; i++) {
            if(mp.count(i)) cnt=min(cnt, mp[i]);
            else cnt=0;
        }

        res = cnt*value;

        for(int i=0; i<value; i++) {
            if(mp.count(i) && mp[i]>cnt) res++;
            else if(!mp.count(i) || mp[i]<=cnt) break; 
        }

        return res;
    }
};