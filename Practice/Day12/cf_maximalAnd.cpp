#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    // Write your code here
    int n, k;
    cin >> n >> k;
    vector<long long> bits(32, 0);
    long long val;

    for(int i=0; i<n; i++) {
        cin >> val;
        for(int j=0; j<32; j++) {
            if(val & (1LL << j)) bits[j]++;
        }
    }

    long long res = 0;
    for(int i=30; i>=0; i--) {
        int req = n - bits[i];
        if(req && (req <= k)) {
            k -= (n - bits[i]);
            res += (1LL << i);
        } else if(req==0) {
            res += (1LL << i);
        }
    }

    cout << res << endl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while(tc--) {
        solve();
    }

    return 0;
}