#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    // Write your code here
    ll n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    vector<int> res;
    res.push_back(a[0]);

    for(int i=1; i+1<n; i++) {
        int v1 = a[i]-a[i-1], v2 = a[i+1]-a[i];
        if(v1>0 && v2<0) res.push_back(a[i]);
        else if(v1<0 && v2>0) res.push_back(a[i]);
    }
    res.push_back(a[n-1]);

    cout << res.size() << endl;
    for(int el : res) cout << el << " ";
    cout << endl;
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