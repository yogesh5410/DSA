#include<bits/stdc++.h>
using namespace std;

int main() {
    int tc; 
    cin >> tc;
    while(tc--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; i++) cin >> a[i];

        if(n<2) {
            cout << "NO" << endl;
        } else {
            vector<long long> prefixOdd(n, 0), prefixEven(n, 0);
            prefixEven[0] = a[0];
            prefixOdd[1] = a[1];
            for(int i=1; i<n; i++) {
                if(i%2==1) {
                    prefixOdd[i] = prefixOdd[i-1] + a[i];
                    prefixEven[i] = prefixEven[i-1];
                } else {
                    prefixOdd[i] = prefixOdd[i-1];
                    prefixEven[i] = prefixEven[i-1] + a[i];
                }
            }

            unordered_map<long long,int> mp;
            mp.reserve(2*n);
            mp.max_load_factor(0.7);
            bool flag = 0;
            mp[0] = 1;
            for(int i=0; i<n; i++) {
                long long key = prefixEven[i] - prefixOdd[i];
                if(mp.find(key)!=mp.end()) {
                    cout << "YES" << endl;
                    flag = 1;
                    break;
                } 
                mp[key]=1;
            }
            if(!flag) cout << "NO" << endl;
        }
    }
    return 0;
}