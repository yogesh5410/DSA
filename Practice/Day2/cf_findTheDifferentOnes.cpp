#include<bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
    for(int i=0; i<n; i++) cin >> a[i];
    b[0]=-1;
    for(int i=1; i<n; i++) {
        if(a[i-1]!=a[i]) b[i]=i-1;
        else b[i]=b[i-1];
    }

    int q;
    cin >> q;
    int l, r;
    for(int i=0; i<q; i++) {
        cin >> l >> r;
        if(b[r-1]!=-1 && b[r-1]!=b[l-1]) cout << b[r-1]+1 << " " << r << endl;
        else cout  << -1 << " " << -1 << endl;
    }
    }
}