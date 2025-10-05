#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        string s;
        cin >> s;
        
        ll mod = 998244353;
        ll len = 1, total = 0, res = 1;
        int n = s.size();

        for(int i=1; i<n; i++) {
            if(s[i-1]==s[i]) {
                len++;
            } else {
                total += len-1;
                res *= len;
                res %= mod;
                len = 1;
            }
        }

        total += len-1;
        res *= len;
        res %= mod;

        for(int i=2; i<=total; i++) {
            res *= i;
            res %= mod;
        }

        cout << total << " " << res << endl;
    }
}