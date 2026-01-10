#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;

int fact[100];
int invf[100];

int inv(int a) {
  return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}

void solve() {
    int n; cin >> n;
    int zero; cin >> zero;
    vector <int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end(), greater<int>());
    int maxx = v[0];

    int nummaxx = 0;

    for (int i = 0; i < n; i++) {
        if (v[i] != maxx) {
            zero -= (maxx - 1) - v[i];
        } else {
            nummaxx++;
        }
    }

    int ans;
    if (zero == n - nummaxx) {
        ans = fact[n] % mod;
        cout << ans << endl;
        return;
    }

    if (zero < 0) {
        cout << 0 << endl;
        return;
    }

    if (zero == 0) {
        ans = fact[nummaxx] * fact[n - nummaxx];
        ans %= mod;
        cout << ans << endl;
        return;
    }    

    if (zero < n - nummaxx) {
        ans = fact[nummaxx + zero] * fact[n - nummaxx - zero];
        ans %= mod;

        ans *= fact[n - nummaxx];
        ans %= mod;
        ans *= invf[zero];
        ans %= mod;
        ans *= invf[n - nummaxx - zero]; 
        ans %= mod;

        cout << ans << endl;
        return; 
    } else {
        ans = fact[n] % mod;
        cout << ans << endl;
        return;
    }
   
}

signed main() {
    fact[0] = 1;
    invf[0] = 1;
    for (int i = 1; i <= 50; i++) {
        fact[i] = fact[i - 1] * i;
        fact[i] %= mod;
        invf[i] = inv(fact[i]);
    }

    int t; cin >> t;
    while(t--) {
        solve();
    }   
}