#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    // Write your code here
    ll n, x, m;
    cin >> n >> x >> m;
    ll s, e;
    ll ns=x, ne=x;

    for(int i=0; i<m; i++) {
        cin >> s >> e;
        if(ns<=e && ne>=s) {
            ns = min(s, ns);
            ne = max(e, ne);
        }
    }

    cout << ne-ns+1 << endl;

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