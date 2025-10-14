#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll bs1(ll l, ll r, ll val) {
    ll ans = 0;
    while(l<=r) {
        ll mid = (l+r)/2;
        if(((mid*(mid+1))/2) < val) {
            ans = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    return ans;
}

ll bs2(ll l, ll r, ll val) {
    ll ans = 0;
    while(l<=r) {
        ll mid = (l+r)/2;
        if(((mid*(mid+1))/2) > val) {
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    return ans;
}

void solve() {
    // Write your code here
    ll n, x;
    cin >> n >> x;

    if(n*n <= x) cout << 2*n-1 << endl;
    else if(x<=((n*(n+1))/2)) cout <<  1 + bs1(1, n, x) << endl;
    else cout << 2*n - 1 - bs2(1, n-1, n*n - x) + 1 << endl;
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