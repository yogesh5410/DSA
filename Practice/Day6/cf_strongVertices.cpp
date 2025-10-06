#include<bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n), diff(n);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];


        for(int i=0; i<n; i++) diff[i] = a[i] - b[i];

        int mx = *max_element(diff.begin(), diff.end());

        vector<int> res;

        for(int i=0; i<n; i++) if(mx==diff[i]) res.push_back(i+1);

        sort(res.begin(), res.end());

        cout << res.size() << endl;
        for(int val : res) cout << val << " ";
        cout << endl;
    }
}