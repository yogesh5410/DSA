#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        long long x, y;
        cin >> n >> x >> y;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        const long long BASE = 1000000007LL; // large prime > y
        unordered_map<long long, int> mp;
        mp.reserve(n * 2);                   // avoid rehashing
        mp.max_load_factor(0.7);

        long long cnt = 0;
        for (int i = 0; i < n; i++) {
            long long r1 = a[i] % x;
            long long r2 = a[i] % y;

            long long need_r1 = (x - r1) % x;
            long long target = need_r1 * BASE + r2;

            auto it = mp.find(target);
            if (it != mp.end()) cnt += it->second;

            long long key = r1 * BASE + r2;
            mp[key]++;
        }
        cout << cnt << "\n";
    }
}
