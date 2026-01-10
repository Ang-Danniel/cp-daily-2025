#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll euclid(ll a, ll b, ll &x, ll &y) {
    if (!b) return x = 1, y = 0, a;
    ll d = euclid(b, a % b, y, x);
    return y -= a/b * x, d;
}

ll crt(ll a, ll m, ll b, ll n) {
    if (n > m) swap(a, b), swap(m, n);
    ll x, y, g = euclid(m, n, x, y);
    if ((a-b) % g != 0) return -1;

    x = (b - a) % n * x % n / g * m + a;
    return x < 0 ? x + m * n / g : x;
}

void solve() {
    int n; cin >> n;
    vector <ll> p(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i] >> r[i];
    }

    ll a = r[0];
    ll m = p[0];
    ll b, m2;
    ll ans = a;
    for (int i = 1; i < n; i++) {
        b = r[i];
        m2 = p[i];
        a = crt(a, m, b, m2);
        m *= m2 / gcd(m, m2);

        if (a == -1) {
            cout << "Impossible\n";
            return;
        }
    }
    cout << a << "\n";
}

signed main() {
    int t; cin >> t;
    int i = 1;
    while(t--) {
        cout << "Case " << i << ": ";
        solve();
        i++;
    }
}