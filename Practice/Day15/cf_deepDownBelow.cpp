#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    // Write your code here
    ll n;
    cin >> n;
    vector<pair<ll, ll>> a;

    ll k, x;
    for(int i=0; i<n; i++) {
        cin >> k;
        ll val = 0;
        for(int j=0; j<k; j++) {
            cin >> x;
            val = max(val, x+1-j);
        }
        a.push_back({val, k});
    }

    sort(a.begin(), a.end());

    ll sum = 0, res = 0;
    for(int i=0; i<n; i++) {
        res = max(a[i].first-sum, res);
        sum += a[i].second;
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