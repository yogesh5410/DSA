#include<bits/stdc++.h>
using namespace std;

#define ll long long

// time complexity: O(n log log n)
vector<ll> sieve(ll n) {
    vector<bool> isPrime(n+1, true);
    isPrime[0] = isPrime[1] = false;
    
    for(ll p=2; p*p<=n; p++) {
        if(isPrime[p]==true) {
            for(int i=p*p; i<=n; i+=p) {
                isPrime[i] = false;
            }
        }
    }

    vector<ll> primes;
    for(ll i=1; i<=n; i++) if(isPrime[i]==true) primes.push_back(i);

    return primes;
}



void solve() {
    // Write your code here
    ll n;
    cin >> n;

    ll v = min(n-1, 100000LL);
    vector<ll> primes = sieve(v);

    ll factor = 1;

    for(ll p : primes) {
        if(n%p==0) {
            factor = p;
            break;
        }
    }

    if(factor==1) factor = n;

    ll multiple = n/factor;

    ll a = (factor-1)*multiple;
    ll b = multiple;
    
    cout << a << " " << b << endl;
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