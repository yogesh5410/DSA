#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    // Write your code here
    ll n, k;
    cin >> n >> k;
    
    vector<ll> factors;

    for(ll i=1; i*i<=n; i++) {
        if(n%i==0) {
            factors.push_back(i);
            if(n/i != i) factors.push_back(n/i);
        }
    }

    sort(factors.begin(), factors.end());

    ll res = 1;
    for(ll f : factors) if(f<=k) res = f; else break;

    cout << n/res << endl;
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