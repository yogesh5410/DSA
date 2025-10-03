class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int cnt = 0, full = numBottles, empty = 0;
        while(full) {
            cnt += full;
            empty += full;
            full = empty/numExchange;
            empty = empty%numExchange;
        }
        return cnt;
    }
};