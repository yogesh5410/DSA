#include<bits/stdc++.h>
using namespace std;

#define ll long long

int ans = 0;

int dfs(string& s, vector<vector<int>>& adj, int u) {    // pass references
    if(adj[u].size()==0) {
        return s[u-1]=='W'?1:-1;
    }

    int cnt = s[u-1]=='W'?1:-1;

    for(int v : adj[u]) {
        cnt += dfs(s, adj, v);
    }

    if(cnt==0) ans++;

    return cnt;
}



void solve() {
    // Write your code here
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> adj(n+1);
    for(int i=0; i<n-1; i++) {
        cin >> a[i];
        adj[a[i]].push_back(i+2);
    }
    string s;
    cin >> s;

    dfs(s, adj, 1);

    // vector<int> visited(n+1, false);        not needed in trees
    cout << ans << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while(tc--) {
        ans = 0;   // reset global counter
        solve();
    }

    return 0;
}