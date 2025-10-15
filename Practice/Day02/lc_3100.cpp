class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        // int empty = 0, full = numBottles, cnt = 0;
        // while(full) {
        //     cnt += full;
        //     empty += full;
        //     if(empty >= numExchange) {
        //         full = 1;
        //         empty -= numExchange;
        //         numExchange++;
        //     } else {
        //         full = 0;
        //     }
        // }
        // return cnt;
        double a = 1.0, b = (2.0)*numExchange - 3.0, c = (-2.0)*numBottles + 1;
        double delta = b*b - 4*a*c;
        double x = (-b + sqrt(delta)) / (2*a);
        int val = floor(x);
        return numBottles + val;
    }
};