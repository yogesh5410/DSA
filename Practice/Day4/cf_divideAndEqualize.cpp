#include<bits/stdc++.h>
using namespace std;

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

int main() {
    int tc;
    cin >> tc;
    
    while(tc--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; i++) cin >>  a[i];

        vector<int> primes = sieve(1000);
        int m = primes.size();

        unordered_map<int, int> mp;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                while(a[i]%primes[j] == 0) {
                    a[i] /= primes[j];
                    mp[primes[j]]++;
                }
            }
            if(a[i]>1) mp[a[i]]++;
        }

        bool flag = true;
    
        for(auto& [k, v] : mp) {
            if(v%n!=0) flag = false;
        }

        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}