#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    // Write your code here
    ll n;
    cin >> n;
    ll k = n/2;

    if(n%2==0) {
        cout << (k+1)*(k+1) << endl;
    } else {
        cout << 2*(k+1)*(k+2) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int tc;
    // cin >> tc;
    //while(tc--) {
        solve();
    //}

    return 0;
}