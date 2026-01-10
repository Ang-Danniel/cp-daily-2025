#include <bits/stdc++.h>
#define ll long long
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        ll w = 0;
        ll m = 0;
        
        ll in; 
        for (int i = 0; i < n; ++i) {
            cin >> in;
            if (in) {
                m++;
                w += in;
            } 
        }

        ll ans = n - 1 - w + m;
        ans = max(0ll, ans);
        ans = m - ans;

        cout << ans << "\n";
    }
}