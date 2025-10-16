#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    // Write your code here
    int n, w;
    cin >> n >> w;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    
    sort(a.begin(), a.end());

    multiset<int> s;

    int cnt = 0;
    for(int i=n-1; i>=0; i--) {
        auto it = s.lower_bound(a[i]);
        if(it!=s.end()) {
            int val = *it;
            s.erase(it);
            if(val-a[i] > 0) s.insert(val-a[i]);
        } else {
            cnt++;
            s.insert(w-a[i]);
        }
    }

    cout << cnt << endl;
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