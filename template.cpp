#include<bits/stdc++.h>
using namespace std;

#define ll long long

// time complexity: O(n log log n)
vector<int> sieve(int n) {
    vector<bool> isPrime(n+1, true);
    isPrime[0] = isPrime[1] = false;
    
    for(int p=2; p*p<=n; p++) {
        if(isPrime[p]==true) {
            for(int i=p*p; i<=n; i+=p) {
                isPrime[i] = false;
            }
        }
    }

    vector<int> primes;
    for(int i=1; i<=n; i++) if(isPrime[i]==true) primes.push_back(i);

    return primes;
}

// time complexity: O(n + m)
int KMP(vector<int>& a, vector<int>& p) {
    int n = a.size(), m = p.size();
    if (m == 0 || n < m) return 0;

    // Build LPS array
    vector<int> lps(m);
    for (int i = 1, j = 0; i < m; i++) {
        while (j > 0 && p[i] != p[j]) j = lps[j - 1];
        if (p[i] == p[j]) j++;
        lps[i] = j;
    }

    // Search pattern
    int cnt = 0;
    for (int i = 0, j = 0; i < n; i++) {
        while (j > 0 && a[i] != p[j]) j = lps[j - 1];
        if (a[i] == p[j]) j++;
        if (j == m) cnt++, j = lps[j - 1];
    }
    return cnt;
}

void solve() {
    // Write your code here
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