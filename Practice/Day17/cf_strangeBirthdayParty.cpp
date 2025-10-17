#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    // Write your code here
    ll n, m;
    cin >> n >> m;
    vector<ll> k(n), c(m);
    for(int i=0; i<n; i++) cin >> k[i];
    for(int i=0; i<m; i++) cin >> c[i];

    sort(k.begin(), k.end());
    
    ll cost = 0, p=0;
    for(int i=n-1; i>=0; i--) {
        if(p < m && c[p] < c[k[i]-1]) {
            cost += c[p];
            p++;
        } else {
            cost += c[k[i]-1];
        }
    }

    cout << cost << endl;
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