#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD = 998244353;

ll binpow(ll a, ll b) {
    if (b == 0) return 1; // fucking
    if (b == 1) return a % MOD;
    ll mid = b / 2;
    ll res = binpow(a, mid);
    res %= MOD;
    res *= res;
    res %= MOD;

    if (b % 2 == 1) res *= a;
    res %= MOD;

    return res;
}

signed main() {
    ll n, m, q; cin >> n >> m >> q;
    ll x;
    for (int i = 1; i <= q; i++) {
        cin >> x;
    }

    ll ans = binpow(m, n - q);
    cout << ans;
}