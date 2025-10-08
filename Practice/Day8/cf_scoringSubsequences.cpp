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



void solve() {
    // Write your code here
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    vector<int> res;
    int ptr = 0;
    for(int i=0; i<n; i++) {
        while(a[ptr] < i+1-ptr) ptr++;
        res.push_back(i+1-ptr);
    }

    for(int r : res) cout << r << " ";
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