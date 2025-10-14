#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    // Write your code here
    int n;
    cin >> n;
    vector<int> a(n), bits(30);
    int k;
    for(int i=0; i<n; i++) {
        cin >> k;
        for(int j=0; j<30; j++) if(k & (1 << j)) bits[j]++; 
    }

    int gcd = 0;
    for(int i=0; i<30; i++) {
        if(bits[i] && gcd) gcd = __gcd(gcd, bits[i]);
        else if(bits[i]) gcd = bits[i];
    }

    if(gcd==0) {
        for(int i=0; i<n; i++) cout << i+1 << " ";
        cout << endl;
        return;
    }

    vector<int> factors;
    for(int i=1; i*i<=gcd; i++) {
        if(gcd%i==0) {
            factors.push_back(i);
            if(i != (gcd/i)) factors.push_back(gcd/i);
        }
    }

    sort(factors.begin(), factors.end());

    for(int f : factors) cout << f << " ";
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