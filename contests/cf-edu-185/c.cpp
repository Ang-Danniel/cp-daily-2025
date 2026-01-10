#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    ll k; cin >> k;
    vector <ll> q(n, 0);
    vector <ll> r(n, 0);

    int in;
    for (int i = 0; i < n; i++) {
        cin >> in;
        q[i] = in;
    }
    for (int i = 0; i < n; i++) {
        cin >> in;
        r[i] = in;
    }

    sort(q.begin(), q.end());
    sort(r.begin(), r.end());


    int i, j; 
    ll x, y;
    i = 0; j = n - 1;
    
    int ans = 0;

    while(i < n && j >= 0) {
        y = r[j] + 1ll;
        x = q[i] * y + r[j];

        j--;
        if (x > k) continue;
        i++;
        ans++;
    }
    cout << ans << "\n";
}

signed main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}
